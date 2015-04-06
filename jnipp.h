/*

- functions always take Ref<> as argument, and return LocalRef<>

[ ] some sugar to implicit cast const char* to Ref<String> ?
[ ] some sugar to use array subscript on Ref<Array<Object>> ?

[ ] generator: add cast operators to superclasses? (operator Ref<Object> etc.)

[ ] safe cast operator

[ ] Fields - how do we implement those in generated classes?

[ ] Arrays get/set for object arrays
[ ] Arrays create?
[ ] Array<jbyte> - cast to jbyte*, array access and set, all lock the array before usage. provide unlock/commit method.

*/

#ifndef _JNIPP_H_INCLUDED
#define _JNIPP_H_INCLUDED

#include <jni.h>
#include <string>
#include <stdexcept>
#include <assert.h>

namespace jnipp {

#define JNIPP_RLOG(...)
//#define JNIPP_RLOG(...) LOG(__VA_ARGS__)

////////////////////////////////////////////////////////////////////////////////

#define JNIPP_M_FOR_ALL_TYPES \
    M(jboolean, Boolean) \
    M(jchar, Char) \
    M(jbyte, Byte) \
    M(jshort, Short) \
    M(jint, Int) \
    M(jlong, Long) \
    M(jfloat, Float) \
    M(jdouble, Double)

template <class T> class LocalRef;
template <class T> class GlobalRef;
template <class T> class WeakRef;
template <class T> class Ref;

class String;
class Class;
class Object;
template <class T> class Array;

////////////////////////////////////////////////////////////////////////////////

/**
 * provide JNIEnv* pointer. at your entry point you need to put a local EnvScope scope();
 */
class Env
{
protected:
    static JNIEnv** _cur() {
        static /*thread_local*/ JNIEnv* value = nullptr;
        return &value;
    }
public:
    class Scope {
        private:
            JNIEnv* _prev;
        public:
        Scope(JNIEnv* env) {
            _prev = *(_cur());
            *(_cur()) = env;
        }
        Scope(JavaVM* vm) {
            JNIEnv* env = nullptr;
            assert(vm->AttachCurrentThread((void**)&env, NULL) == JNI_OK);
            _prev = *(_cur());
            *(_cur()) = env;
        }
        ~Scope() {
            *(_cur()) = _prev;
        }
    };
public:
    static JNIEnv* peek() {
        return *(_cur());
    }
    static JNIEnv* cur() {
        JNIEnv* res = peek();
        if (!res) throw std::logic_error("EnvScope: no environment set");
        assert(res && "EnvScope: no environment set");
        return res;
    }
    static void pushLocalFrame(jint capacity) {
        assert( cur()->PushLocalFrame(capacity) == 0 );
    }
    static void popLocalFrame() {
        cur()->PopLocalFrame(nullptr);
    }
    static void ensureLocalCapacity(jint capacity) {
        assert( cur()->EnsureLocalCapacity(capacity) == 0 );
    }
    static void throwException(Ref<Object> exception);
    static bool hasException() {
        return cur()->ExceptionCheck();
    }
    static LocalRef<Object> getException();
    static JavaVM* getVM() {
        JavaVM* res = nullptr;
        assert( cur()->GetJavaVM(&res) == 0 );
        return res;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Monitor {
protected:
    jobject _object;
public:
    Monitor(jobject object) : _object(object) {
        Env::cur()->MonitorEnter(_object);
    }
    Monitor(const Monitor& other) = delete;
    Monitor(const Monitor&& other) : _object(other._object) {
        const_cast<Monitor*>(&other)->_object = nullptr;
    }
    ~Monitor() {
        if (_object) {
            Env::cur()->MonitorExit(_object);
            _object = nullptr;
        }
    }
};

////////////////////////////////////////////////////////////////////////////////

/**
 * simple ref
 */
template <typename T>
class Ref {
protected:
    T _impl;
public:
    explicit Ref(jobject value) : _impl(value) {
    }
    Ref(const Ref<T>& value) : _impl((jobject)value) {
    }
    //template <typename S>
    //explicit Ref(const Ref<S>& value) : _impl((jobject)value) {
    //}
    // @TODO: need to make sure this only works on compatible classes?
    template <typename S>
    Ref(const Ref<S>& value) : _impl((jobject)value) {
    }

    const T* operator->() const {
        return &_impl;
    }
    const T& operator*() const {
        return _impl;
    }
    // disallow use of []
private:
    void operator[](int idx) const { // !!! use (*ref)[idx]
    }
public:
    // @TODO: does not work.
    //template <typename S>
    //S operator[](jsize idx) const {
    //    LOG("Ref []");
    //    return _impl[idx];
    //}
    template <typename S>
    bool operator == (const Ref<S>& other) {
        return Env::cur()->IsSameObject((jobject)*this, (jobject)*other);
    }
    template <typename S>
    bool operator != (const Ref<S>& other) {
        return !Env::cur()->IsSameObject((jobject)*this, (jobject)*other);
    }
    operator jobject() const {
        return (jobject)_impl;
    }
    operator bool() const {
        return (jobject)*this != nullptr && !Env::cur()->IsSameObject((jobject)*this, NULL);
    }
};

/*
// @TODO: try to add implicit conversion from "string" to LocalRef<String>?
template <>
class Ref<String> {
    using T = String;
protected:
    T _impl;
public:
    explicit Ref(jobject value) : _impl(value) {
    }
    template <typename S>
    Ref(const Ref<S>& value) : _impl((jobject)value) {
    }
    const T* operator->() const {
        return &_impl;
    }
    const T& operator*() const {
        return _impl;
    }
    operator jobject() const {
        return (jobject)_impl;
    }
    operator bool() const {
        return _impl;
    }
};
*/


/**
 * local ref
*/
template <typename T>
class LocalRef : public Ref<T> {
public:
    explicit LocalRef(jobject value) : Ref<T>(value) {
        JNIPP_RLOG("LocalRef::LocalRef(jobject) this=%p jobject=%p", this, (jobject)*this);
    }
    template <typename S>
    LocalRef(LocalRef<S>&& value) : Ref<T>((jobject)value) {
        value.clear();
        JNIPP_RLOG("LocalRef::LocalRef(LocalRef&&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    template <typename S>
    LocalRef(const Ref<S>& value) : Ref<T>(Env::cur()->NewLocalRef((jobject)value)) {
        JNIPP_RLOG("LocalRef::LocalRef(Ref&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    ~LocalRef() {
        if (*this) {
            JNIPP_RLOG("LocalRef::~LocalRef() this=%p jobject=%p", this, (jobject)*this);
            Env::cur()->DeleteLocalRef((jobject)*this);
            this->clear();
        }
    }
    void clear() {
        this->_impl.clear();
    }
    static bool is(jobject value) {
        return Env::cur()->GetObjectRefType(value) == JNILocalRefType;
    }
};

/**
 * global ref
 */
template <typename T>
class GlobalRef : public Ref<T> {
public:
    GlobalRef() : Ref<T>((jobject)nullptr) {
        JNIPP_RLOG("GlobalRef::GlobalRef() this=%p", this);
    }
    explicit GlobalRef(jobject value) : Ref<T>(Env::cur()->NewGlobalRef(value)) {
        JNIPP_RLOG("GlobalRef::GlobalRef(jobject) this=%p jobject=%p", this, (jobject)*this);
    }
    template <typename S>
    GlobalRef(GlobalRef<S>&& value) : Ref<T>((jobject)value) {
        JNIPP_RLOG("GlobalRef::GlobalRef(GlobalRef&&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
        value.clear();
    }
    template <typename S>
    GlobalRef(const Ref<S>& value) : Ref<T>(Env::cur()->NewGlobalRef((jobject)value)) {
        JNIPP_RLOG("GlobalRef::GlobalRef(Ref&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    ~GlobalRef() {
        if ((jobject)*this) {
            JNIPP_RLOG("GlobalRef::~GlobalRef() this=%p jobject=%p", this, (jobject)*this);
            if (Env::peek()) Env::cur()->DeleteGlobalRef((jobject)*this);
            this->clear();
        }
    }
    void clear() {
        this->_impl.clear();
    }
    template <typename S>
    void set(const Ref<S>& value) {
        if (*this) Env::cur()->DeleteGlobalRef((jobject)*this);
        this->_impl = T(Env::cur()->NewGlobalRef((jobject)value));
    }
    static bool is(jobject value) {
        return Env::cur()->GetObjectRefType(value) == JNIGlobalRefType;
    }
};

/**
 * weak ref
 */
template <typename T>
class WeakRef {
public:
    WeakRef() : Ref<T>((jobject)nullptr) {
        JNIPP_RLOG("WeakRef::WeakRef() this=%p", this);
    }
    explicit WeakRef(jobject value) : Ref<T>(Env::cur()->NewWeakGlobalRef(value)) {
        JNIPP_RLOG("WeakRef::WeakRef(jobject) this=%p jobject=%p", this, (jobject)*this);
    }
    template <typename S>
    WeakRef(WeakRef<S>&& value) : Ref<T>((jobject)value) {
        JNIPP_RLOG("WeakRef::WeakRef(WeakRef&&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
        value.clear();
    }
    template <typename S>
    WeakRef(const Ref<S>& value) : Ref<T>(Env::cur()->NewWeakGlobalRef((jobject)value)) {
        JNIPP_RLOG("WeakRef::WeakRef(Ref&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    ~WeakRef() {
        if (*this) {
            JNIPP_RLOG("WeakRef::~WeakRef() this=%p jobject=%p", this, (jobject)*this);
            if (Env::peek()) Env::cur()->DeleteWeakGlobalRef((jobject)*this);
            this->clear();
        }
    }
    template <typename S>
    bool operator == (const Ref<S>& other) {
        return Env::cur()->IsSameObject((jobject)*this, (jobject)*other);
    }
    template <typename S>
    bool operator != (const Ref<S>& other) {
        return !Env::cur()->IsSameObject((jobject)*this, (jobject)*other);
    }
    operator bool() const {
        return (jobject)*this != nullptr && !Env::cur()->IsSameObject((jobject)*this, NULL);
    }
    void clear() {
        this->_impl.clear();
    }
    template <typename S>
    void set(const Ref<S>& value) {
        if (*this) Env::cur()->DeleteWeakGlobalRef((jobject)*this);
        this->_impl = T(Env::cur()->NewGlobalRef((jobject)value));
    }
    static bool is(jobject value) {
        return Env::cur()->GetObjectRefType(value) == JNIWeakGlobalRefType;
    }
};


////////////////////////////////////////////////////////////////////////////////

class _ObjectBase {
private:
    jobject _value;
protected:
    inline JNIEnv* env() const {
        return Env::cur();
    }
public:
    inline _ObjectBase(jobject value) : _value(value) {
    }
    inline operator jobject() const {
        return _value;
    }
    inline void clear() {
        _value = nullptr;
    }
    inline LocalRef<String> toString() const;
    inline LocalRef<Class> getClass() const;
    inline jboolean isInstanceOf(Ref<Class> cls) const;
    inline Monitor lock() const;
};

////////////////////////////////////////////////////////////////////////////////

#define M(type,tag) \
inline type _ConvertArg(type value) { \
    return value; \
}
JNIPP_M_FOR_ALL_TYPES
#undef M

inline jstring _ConvertArg(jstring value) {
    return value;
}
inline jobject _ConvertArg(jobject value) {
    return value;
}
inline jclass _ConvertArg(jclass value) {
    return value;
}
template <typename S>
inline jobject _ConvertArg(const Ref<S>& value) {
    return (jobject)value;
}

template <typename T>
struct _AsRef {
    using R = Ref<T>;
};
#define M(type,tag) \
template <> struct _AsRef<type> { \
    using R = type; \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

////////////////////////////////////////////////////////////////////////////////

class MethodBase {
protected:
    jclass _cls;
    const char* _clsName;
    const char* _name;
    const char* _signature;
    jmethodID _methodID;
public:
    MethodBase(const char* clsName, const char* name, const char* signature) : _cls(nullptr), _clsName(clsName), _name(name), _signature(signature), _methodID(0) {
    }
    MethodBase(Ref<Class> cls, const char* name, const char* signature);
    jmethodID getMethodID() const {
        if (_methodID == 0) {
            JNIEnv* env = Env::cur();
            if (_cls == 0) {
                const_cast<MethodBase*>(this)->_cls = env->FindClass(_clsName);
                if (!_cls) throw std::invalid_argument(std::string() + "Method: clsName not found: " + _clsName);
                assert(_cls && "Method: clsName not found");
            }
            jmethodID res = env->GetMethodID(_cls, _name, _signature);
            if (!res) throw std::invalid_argument(std::string() + "Method: method not found: " + _clsName + "." + _name + " (" + _signature + ")");
            assert(res && "Method: method not found");
            const_cast<MethodBase*>(this)->_methodID = res;
        }
        return _methodID;
    }
    operator jmethodID() const {
        return getMethodID();
    }
};

template <typename R, typename... A>
class Method : public MethodBase
{
public:
    using MethodBase::MethodBase;
    LocalRef<R> call(jobject target, typename _AsRef<A>::R... args) {
        return LocalRef<R>( Env::cur()->CallObjectMethod(target, getMethodID(), _ConvertArg(args)...) );
    }
};

template<typename... A>
class Method<void, A...> : public MethodBase
{
public:
    using MethodBase::MethodBase;
    void call(jobject target, typename _AsRef<A>::R... args) {
        return Env::cur()->CallVoidMethod(target, getMethodID(), _ConvertArg(args)...);
    }
};

#define M(type,tag) \
template<typename... A> \
class Method<type, A...> : public MethodBase \
{ \
public: \
    using MethodBase::MethodBase; \
    type call(jobject target, typename _AsRef<A>::R... args) { \
        return Env::cur()->Call ## tag ## Method(target, getMethodID(), _ConvertArg(args)...); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

////////////////////////////////////////////////////////////////////////////////

class NonvirtualMethodBase {
protected:
    jclass _cls;
    const char* _clsName;
    const char* _name;
    const char* _signature;
    jmethodID _methodID;
public:
    NonvirtualMethodBase(const char* clsName, const char* name, const char* signature) : _cls(nullptr), _clsName(clsName), _name(name), _signature(signature), _methodID(0) {
    }
    NonvirtualMethodBase(Ref<Class> cls, const char* name, const char* signature);
    jmethodID getMethodID() const {
        if (_methodID == 0) {
            JNIEnv* env = Env::cur();
            if (_cls == 0) {
                const_cast<NonvirtualMethodBase*>(this)->_cls = env->FindClass(_clsName);
                if (!_cls) throw std::invalid_argument(std::string() + "NonvirtualMethod: clsName not found: " + _clsName);
                assert(_cls && "NonvirtualMethod: clsName not found");
            }
            jmethodID res = env->GetMethodID(_cls, _name, _signature);
            assert(res && "NonvirtualMethod: method not found");
            const_cast<NonvirtualMethodBase*>(this)->_methodID = res;
        }
        return _methodID;
    }
    operator jmethodID() const {
        return getMethodID();
    }
};

template <typename R, typename... A>
class NonvirtualMethod : public NonvirtualMethodBase
{
public:
    using NonvirtualMethodBase::NonvirtualMethodBase;
    LocalRef<R> call(jobject target, typename _AsRef<A>::R... args) {
        return LocalRef<R>( Env::cur()->CallNonvirtualObjectMethod(target, getMethodID(), _ConvertArg(args)...) );
    }
};

template<typename... A>
class NonvirtualMethod<void, A...> : public NonvirtualMethodBase
{
public:
    using NonvirtualMethodBase::NonvirtualMethodBase;
    void call(jobject target, typename _AsRef<A>::R... args) {
        return Env::cur()->CallNonvirtualVoidMethod(target, getMethodID(), _ConvertArg(args)...);
    }
};

#define M(type,tag) \
template<typename... A> \
class NonvirtualMethod<type, A...> : public NonvirtualMethodBase \
{ \
public: \
    using NonvirtualMethodBase::NonvirtualMethodBase; \
    type call(jobject target, typename _AsRef<A>::R... args) { \
        return Env::cur()->CallNonvirtual ## tag ## Method(target, getMethodID(), _ConvertArg(args)...); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

////////////////////////////////////////////////////////////////////////////////

class StaticMethodBase {
protected:
    jclass _cls;
    const char* _clsName;
    const char* _name;
    const char* _signature;
    jmethodID _methodID;
public:
    StaticMethodBase(const char* clsName, const char* name, const char* signature) : _cls(nullptr), _clsName(clsName), _name(name), _signature(signature), _methodID(0) {
    }
    StaticMethodBase(Ref<Class> cls, const char* name, const char* signature);
    jmethodID getMethodID() const {
        if (_methodID == 0) {
            JNIEnv* env = Env::cur();
            if (_cls == 0) {
                const_cast<StaticMethodBase*>(this)->_cls = env->FindClass(_clsName);
                if (!_cls) throw std::invalid_argument(std::string() + "StaticMethod: clsName not found: " + _clsName);
                assert(_cls && "StaticMethod: clsName not found");
            }
            jmethodID res = env->GetStaticMethodID(_cls, _name, _signature);
            assert(res && "StaticMethod: method not found");
            const_cast<StaticMethodBase*>(this)->_methodID = res;
        }
        return _methodID;
    }
    jclass getClass() const {
        getMethodID();
        return _cls;
    }
    operator jmethodID() const {
        return getMethodID();
    }
    operator jclass() const {
        return getClass();
    }
};

template <typename R, typename... A>
class StaticMethod : public StaticMethodBase
{
public:
    using StaticMethodBase::StaticMethodBase;
    LocalRef<R> call(typename _AsRef<A>::R... args) {
        return LocalRef<R>( Env::cur()->CallStaticObjectMethod(getClass(), getMethodID(), _ConvertArg(args)...) );
    }
};

template<typename... A>
class StaticMethod<void, A...> : public StaticMethodBase
{
public:
    using StaticMethodBase::StaticMethodBase;
    void call(typename _AsRef<A>::R... args) {
        return Env::cur()->CallStaticVoidMethod(getClass(), getMethodID(), _ConvertArg(args)...);
    }
};

#define M(type,tag) \
template<typename... A> \
class StaticMethod<type, A...> : public StaticMethodBase \
{ \
public: \
    using StaticMethodBase::StaticMethodBase; \
    type call(typename _AsRef<A>::R... args) { \
        return Env::cur()->CallStatic ## tag ## Method(getClass(), getMethodID(), _ConvertArg(args)...); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

////////////////////////////////////////////////////////////////////////////////


template <typename R, typename... A>
class Constructor {
protected:
    jclass _cls;
    const char* _clsName;
    const char* _signature;
    jmethodID _methodID;
public:
    Constructor(const char* clsName, const char* signature) : _cls(nullptr), _clsName(clsName), _signature(signature), _methodID(0) {
    }
    Constructor(Ref<Class> cls, const char* signature);
    jmethodID getMethodID() const {
        if (_methodID == 0) {
            JNIEnv* env = Env::cur();
            if (_cls == 0) {
                const_cast<Constructor*>(this)->_cls = env->FindClass(_clsName);
                if (!_cls) throw std::invalid_argument(std::string() + "Constructor: clsName not found: " + _clsName);
                assert(_cls && "Constructor: clsName not found");
            }
            jmethodID res = env->GetMethodID(_cls, "<init>", _signature);
            assert(res && "Constructor: method not found");
            const_cast<Constructor*>(this)->_methodID = res;
        }
        return _methodID;
    }
    jclass getClass() const {
        getMethodID();
        return _cls;
    }
    operator jmethodID() const {
        return getMethodID();
    }
    operator jclass() const {
        return getClass();
    }
    LocalRef<R> construct(typename _AsRef<A>::R... args) const {
        return LocalRef<R>( Env::cur()->NewObject(getClass(), getMethodID(), _ConvertArg(args)...) );
    }
};

////////////////////////////////////////////////////////////////////////////////

class FieldBase {
protected:
    jclass _cls;
    const char* _clsName;
    const char* _name;
    const char* _signature;
    jfieldID _fieldID;
public:
    FieldBase(const char* clsName, const char* name, const char* signature) : _cls(nullptr), _clsName(clsName), _name(name), _signature(signature), _fieldID(0) {
    }
    FieldBase(Ref<Class> cls, const char* name, const char* signature);
    jfieldID getFieldID() const {
        if (_fieldID == 0) {
            JNIEnv* env = Env::cur();
            if (_cls == 0) {
                const_cast<FieldBase*>(this)->_cls = env->FindClass(_clsName);
                if (!_cls) throw std::invalid_argument(std::string() + "Field: clsName not found: " + _clsName);
                assert(_cls && "Field: clsName not found");
            }
            jfieldID res = env->GetFieldID(_cls, _name, _signature);
            assert(res && "Field: field not found");
            const_cast<FieldBase*>(this)->_fieldID = res;
        }
        return _fieldID;
    }
    operator jfieldID() const {
        return getFieldID();
    }
};

template <typename R>
class Field : public FieldBase
{
public:
    using FieldBase::FieldBase;
    LocalRef<R> get(jobject target) const {
        return LocalRef<R>( Env::cur()->GetObjectField(target, getFieldID()) );
    }
    void set(jobject target, Ref<R> value) {
        Env::cur()->SetObjectField(target, getFieldID(), value);
    }
};

#define M(type,tag) \
template <> \
class Field<type> : public FieldBase \
{ \
public: \
    using FieldBase::FieldBase; \
    type get(jobject target) const { \
        return Env::cur()->Get ## tag ## Field(target, getFieldID()); \
    } \
    void set(jobject target, type value) { \
        Env::cur()->Set ## tag ## Field(target, getFieldID(), value); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

// make a ConcreteField that is bound to a specific instance?

////////////////////////////////////////////////////////////////////////////////

class StaticFieldBase {
protected:
    jclass _cls;
    const char* _clsName;
    const char* _name;
    const char* _signature;
    jfieldID _fieldID;
public:
    StaticFieldBase(const char* clsName, const char* name, const char* signature) : _cls(nullptr), _clsName(clsName), _name(name), _signature(signature), _fieldID(0) {
    }
    StaticFieldBase(Ref<Class> cls, const char* name, const char* signature);
    jfieldID getFieldID() const {
        if (_fieldID == 0) {
            JNIEnv* env = Env::cur();
            if (_cls == 0) {
                const_cast<StaticFieldBase*>(this)->_cls = env->FindClass(_clsName);
                if (!_cls) throw std::invalid_argument(std::string() + "StaticField: clsName not found: " + _clsName);
                assert(_cls && "StaticField: clsName not found");
            }
            jfieldID res = env->GetStaticFieldID(_cls, _name, _signature);
            assert(res && "StaticField: field not found");
            const_cast<StaticFieldBase*>(this)->_fieldID = res;
        }
        return _fieldID;
    }
    jclass getClass() const {
        getFieldID();
        return _cls;
    }
    operator jfieldID() const {
        return getFieldID();
    }
    operator jclass() const {
        return getClass();
    }
};

template <typename R>
class StaticField : public StaticFieldBase
{
public:
    using StaticFieldBase::StaticFieldBase;
    LocalRef<R> get() const {
        return LocalRef<R>( Env::cur()->GetStaticObjectField(getClass(), getFieldID()) );
    }
    operator LocalRef<R>() const {
        return get();
    }
    LocalRef<R> operator->() const {
        return get();
    }
    void set(Ref<R> value) {
        Env::cur()->SetStaticObjectField(getClass(), getFieldID(), value);
    }
    void operator=(Ref<R> value) {
        set(value);
    }
};

#define M(type,tag) \
template <> \
class StaticField<type> : public StaticFieldBase \
{ \
public: \
    using StaticFieldBase::StaticFieldBase; \
    type get() const { \
        return Env::cur()->GetStatic ## tag ## Field(getClass(), getFieldID()); \
    } \
    operator type() const { \
        return get(); \
    } \
    void set(type value) { \
        Env::cur()->SetStatic ## tag ## Field(getClass(), getFieldID(), value); \
    } \
    void operator=(type value) { \
        set(value); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

////////////////////////////////////////////////////////////////////////////////

template <class T>
class Array : public _ObjectBase
{
public:
    using _ObjectBase::_ObjectBase;

    operator jarray() const {
        return (jarray)(jobject)*this;
    }
    jsize length() const {
        return env()->GetArrayLength((jarray)*this);
    }
    LocalRef<T> operator[](jsize index) const {
        //LOG("Array[]");
        return LocalRef<T>( env()->GetObjectArrayElement((jobjectArray)(jobject)*this, index) );
    }
    /*
    void operator[](jsize index, Ref<T> value) {
        env()->SetObjectArrayElement((jobjectArray)(jobject)*this, index, (jobject)value);
        // @TODO
    }
    */
    static LocalRef<Array<T>> newArray(jsize length) {
        jclass elementClass = nullptr;
        return LocalRef<Array<T>>( Env::cur()->NewObjectArray(length, elementClass, nullptr) );
    }

    class Iterator
    {
    private:
        const Array<T>* _obj;
        size_t _idx;
    public:
        Iterator(const Array<T>* obj, size_t idx) : _obj(obj), _idx(idx) {
        }
        bool operator != (const Iterator& that) {
            return that._idx != _idx;
        }
        const Iterator& operator++() {
            _idx++;
            return *this;
        }
        LocalRef<T> operator* () const {
            return (*_obj)[_idx];
        }
    };

    Iterator begin() const {
        return Iterator(this, 0);
    }
    Iterator end() const {
        return Iterator(this, length());
    }
};

template<>
class Array<jbyte> : public _ObjectBase {
public:
    using _ObjectBase::_ObjectBase;

    operator jarray() const {
        return (jarray)(jobject)*this;
    }
    jsize length() const {
        return env()->GetArrayLength((jarray)*this);
    }

    operator jbyteArray() const {
        return (jbyteArray)(jarray)*this;
    }

    // get/set methods?
    // lock whole range instead?
    // create new?

    jbyte operator[](jsize index) const {
        //LOG("Array<jbyte>[]");
        jbyte buffer;
        Env::cur()->GetByteArrayRegion((jbyteArray)*this, index, 1, &buffer);
        return buffer;
    }
};

////////////////////////////////////////////////////////////////////////////////

class String : public _ObjectBase
{
public:
    using _ObjectBase::_ObjectBase;

    static LocalRef<String> create(const char* value) {
        return LocalRef<String>( Env::cur()->NewStringUTF(value) );
    }

    static LocalRef<String> create(std::string value) {
        return LocalRef<String>( Env::cur()->NewStringUTF(value.c_str()) );
    }

    // @TODO: cast to superclass... hhmm?
    operator Object&() const {
        return *this;

    }

    operator jstring() const {
        return (jstring)(jobject)*this;
    }

    jsize length() const {
        return env()->GetStringLength((jstring)*this);
    }

    const char* c_str() const {
        return std_str().c_str();
    }

    std::string std_str() const {
        const char* data = env()->GetStringUTFChars((jstring)*this, nullptr);
        std::string res = data;
        env()->ReleaseStringUTFChars((jstring)*this, data);
        return res;
    }
};

class Class : public _ObjectBase
{
public:
    using _ObjectBase::_ObjectBase;

    static LocalRef<Class> forName(const char* name) {
        return LocalRef<Class>( (jobject)Env::cur()->FindClass(name) );
    }

    operator jclass() const {
        return (jclass)(jobject)*this;
    }

    LocalRef<String> getName() const {
        static Method<String> method("java/lang/Class", "getName", "()Ljava/lang/String;");
        return method.call(*this);
    }

    jboolean isAssignableFrom(Ref<Class> other) {
        return env()->IsAssignableFrom((jclass)*this, (jclass)*other);
    }

    LocalRef<Class> getSuperclass() const {
        return LocalRef<Class>( env()->GetSuperclass((jclass)*this) );
    }

};

class Object : public _ObjectBase
{
public:
    using _ObjectBase::_ObjectBase;
};

////////////////////////////////////////////////////////////////////////////////

inline MethodBase::MethodBase(Ref<Class> cls, const char* name, const char* signature) : _cls((jclass)(jobject)cls), _clsName(nullptr), _name(name), _signature(signature), _methodID(0) {
}

inline StaticMethodBase::StaticMethodBase(Ref<Class> cls, const char* name, const char* signature) : _cls((jclass)(jobject)cls), _clsName(nullptr), _name(name), _signature(signature), _methodID(0) {
}

inline FieldBase::FieldBase(Ref<Class> cls, const char* name, const char* signature) : _cls((jclass)(jobject)cls), _clsName(nullptr), _name(name), _signature(signature), _fieldID(0) {
}

inline StaticFieldBase::StaticFieldBase(Ref<Class> cls, const char* name, const char* signature) : _cls((jclass)(jobject)cls), _clsName(nullptr), _name(name), _signature(signature), _fieldID(0) {
}

template <typename R, typename... A>
inline Constructor<R, A...>::Constructor(Ref<Class> cls, const char* signature) : _cls((jclass)(jobject)cls), _clsName(nullptr), _signature(signature), _methodID(0) {
}

////////////////////////////////////////////////////////////////////////////////

inline LocalRef<Object> Env::getException() {
    LocalRef<Object> res ( cur()->ExceptionOccurred() );
    cur()->ExceptionClear();
    return res;
}

inline void Env::throwException(Ref<Object> exception)
{
    cur()->Throw((jthrowable)(jobject)*exception);
}

////////////////////////////////////////////////////////////////////////////////

inline LocalRef<String> _ObjectBase::toString() const {
    Method<String> method("java/lang/Object", "toString", "()Ljava/lang/String;");
    return method.call(*this);
}

inline LocalRef<Class> _ObjectBase::getClass() const {
    return LocalRef<Class>( env()->GetObjectClass((jobject)*this) );
}

inline jboolean _ObjectBase::isInstanceOf(Ref<Class> cls) const {
    return env()->IsInstanceOf((jobject)*this, (jclass)*cls);
}

inline Monitor _ObjectBase::lock() const {
    return Monitor((jobject)*this);
}

////////////////////////////////////////////////////////////////////////////////

}

#endif


