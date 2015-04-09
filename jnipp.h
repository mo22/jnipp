//
// jnipp
// Copyright 2015 Moritz Moeller
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _JNIPP_H_INCLUDED
#define _JNIPP_H_INCLUDED

#include <jni.h>

#include <string>

#include <stdexcept>

#include <assert.h>

#ifdef JNIPP_USE_BOOST
    #include <boost/type_traits.hpp>
    #define JNIPP_ENABLE_IF_C boost::enable_if_c
    #define JNIPP_IS_BASE_OF boost::is_base_of
#else
    #include <type_traits>
    #define JNIPP_ENABLE_IF_C std::enable_if
    #define JNIPP_IS_BASE_OF std::is_base_of
#endif

#ifndef JNIPP_THREAD_LOCAL
    #if defined(__GNUC__)
        #define JNIPP_THREAD_LOCAL __thread
    #elif defined(_MSC_VER)
        #define JNIPP_THREAD_LOCAL __declspec(thread)
    #else
        #define JNIPP_THREAD_LOCAL thread_local
    #endif
#endif

namespace jnipp {

//#define JNIPP_RLOG(...) LOG(__VA_ARGS__)
#ifndef JNIPP_RLOG
#define JNIPP_RLOG(...)
#endif

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

template <typename T> class LocalRef;
template <typename T> class GlobalRef;
template <typename T> class WeakRef;
template <typename T, typename A1=void, typename A2=void> class Ref;

template <typename R, typename... A> class Method;


class String;
class Class;
class Object;
template <typename T> class Array;

////////////////////////////////////////////////////////////////////////////////

/**
 * provide JNIEnv* pointer. at your entry point you need to put a local Env::Scope scope(your_jni_env);
 */
class Env
{
protected:
    static JNIEnv** _cur() {
        static JNIPP_THREAD_LOCAL JNIEnv* value = nullptr;
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
    static JNIEnv* get() {
        JNIEnv* res = peek();
        if (!res) throw std::logic_error("EnvScope: no environment set");
        assert(res && "EnvScope: no environment set");
        return res;
    }
    static void pushLocalFrame(jint capacity) {
        assert( get()->PushLocalFrame(capacity) == 0 );
    }
    static void popLocalFrame() {
        get()->PopLocalFrame(nullptr);
    }
    static void ensureLocalCapacity(jint capacity) {
        assert( get()->EnsureLocalCapacity(capacity) == 0 );
    }
    static void throwException(Ref<Object> exception);
    static void throwException(Ref<Class> cls, Ref<String> message);
    static void throwException(const char* cls, const char* message);
    static bool hasException() {
        return get()->ExceptionCheck();
    }
    static LocalRef<Object> getException();
    static JavaVM* getVM() {
        JavaVM* res = nullptr;
        assert( get()->GetJavaVM(&res) == 0 );
        return res;
    }
};

////////////////////////////////////////////////////////////////////////////////

/**
 * monitor / lock object
 * can be passed/returned by rvalue
 * automatically unlocks on destruction
 */
class Monitor {
protected:
    jobject _object;
public:
    Monitor(jobject object) : _object(object) {
        Env::get()->MonitorEnter(_object);
    }
    Monitor(const Monitor& other) = delete;
    Monitor(const Monitor&& other) : _object(other._object) {
        const_cast<Monitor*>(&other)->_object = nullptr;
    }
    ~Monitor() {
        if (_object) {
            Env::get()->MonitorExit(_object);
            _object = nullptr;
        }
    }
};

////////////////////////////////////////////////////////////////////////////////

/**
 * base object class implementation
 */
class Object {
protected:
    jobject _value;
    JNIEnv* env() const {
        return Env::get();
    }
    void __clear() { // @TODO: see if we can get rid of this.
        _value = nullptr;
    }
    template<typename A> friend class LocalRef;
    template<typename A> friend class GlobalRef;
    template<typename A, typename A1, typename A2> friend class Ref;
public:
    Object(jobject value) : _value(value) {
    }
    operator jobject() const {
        return _value;
    }
    LocalRef<String> toString() const;
    LocalRef<Class> getClass() const;
    jboolean isInstanceOf(Ref<Class> cls) const;
    Monitor lock() const;
};

/**
 * a java string
*/
class String : public Object
{
public:
    using Object::Object;

    static LocalRef<String> create(const char* value);
    static LocalRef<String> create(std::string value);

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

    operator const char*() const {
        return c_str();
    }
    operator const std::string() const {
        return std_str();
    }

    bool operator == (const char* str) const {
        return std_str() == str;
    }
    bool operator != (const char* str) const {
        return std_str() != str;
    }
};

/**
 * a java class
*/
class Class : public Object
{
public:
    using Object::Object;

    static LocalRef<Class> forName(const char* name);

    operator jclass() const {
        return (jclass)(jobject)*this;
    }

    LocalRef<String> getName() const;
    jboolean isAssignableFrom(Ref<Class> other);
    LocalRef<Class> getSuperclass() const;
};

/**
 * generic object array
*/
template <class T>
class Array : public Object
{
public:
    using Object::Object;

    operator jarray() const {
        return (jarray)(jobject)*this;
    }
    operator jobjectArray() const {
        return (jobjectArray)(jobject)*this;
    }

    jsize length() const {
        return env()->GetArrayLength((jarray)*this);
    }

    LocalRef<T> get(jsize index) const {
        return LocalRef<T>( env()->GetObjectArrayElement((jobjectArray)*this, index) );
    }

    void set(jsize index, Ref<T> value) {
        env()->SetObjectArrayElement((jobjectArray)*this, index, value);
    }

    LocalRef<T> operator[](jsize index) const {
        return get(index);
    }

    static LocalRef<Array<T>> construct(jsize length, jclass elementClass) {
        return LocalRef<Array<T>>( Env::get()->NewObjectArray(length, elementClass, nullptr) );
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

/**
 * typed array
*/
template <typename T>
struct _Array {
};

#define M(type,tag) \
template <> struct _Array<type> { \
    using arrayType = type ## Array; \
    static jarray construct(jsize length) { return Env::get()->New ## tag ## Array(length); } \
    static void getRegion(arrayType array, jsize index, jsize length, type* buffer) { return Env::get()->Get ## tag ## ArrayRegion(array, index, length, buffer); } \
    static type* getElements(arrayType array, jboolean* isCopy) { return Env::get()->Get ## tag ## ArrayElements(array, isCopy); } \
    static void releaseElements(arrayType array, type* data, jint mode) { Env::get()->Release ## tag ## ArrayElements(array, data, mode); } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

template<typename T>
class _ElementArray : public Object {
private:
    T* _data;
    bool _dirty;
public:
    using arrayType = typename _Array<T>::arrayType;
    using Object::Object;

    _ElementArray(jobject value) : Object(value), _data(nullptr) {
    }

    _ElementArray(const _ElementArray& other) : Object(other), _data(nullptr) {
    }

    ~_ElementArray() {
        unlock();
    }

    operator jobject() const {
        unlock();
        return Object::operator jobject();
    }

    operator jarray() const {
        return (jarray)_value;
    }
    operator arrayType() const {
        return (arrayType)_value;
    }

    jsize length() const {
        return env()->GetArrayLength((jarray)*this);
    }

    static LocalRef<Array<T>> construct(jsize length) {
        return LocalRef<Array<T>>( _Array<T>::construct(length) );
    }

    void lock() const {
        if (!_data) {
            const_cast<_ElementArray<T>*>(this)->_data = _Array<T>::getElements((arrayType)*this, nullptr);
            //LOG("Array::lock this=%p _data=%p", this, _data);
            const_cast<_ElementArray<T>*>(this)->_dirty = false;
        }
    }
    void unlock() const {
        if (_data) {
            T* data = _data;
            const_cast<_ElementArray<T>*>(this)->_data = nullptr;
            //LOG("Array::unlock this=%p _data=%p _dirty=%d", this, data, _dirty);
            _Array<T>::releaseElements((arrayType)*this, data, _dirty ? 0 : JNI_ABORT);
        }
    }

    T get(jsize index) const {
        lock();
        return _data[index];
    }
    T& getRef(jsize index) {
        lock();
        _dirty = true;
        return _data[index];
    }
    void set(jsize index, T value) {
        lock();
        _dirty = true;
        _data[index] = value;
    }

    T operator[](jsize index) const {
        return get(index);
    }
    T& operator[](jsize index) {
        return getRef(index);
    }
    operator const T*() const {
        lock();
        return _data;
    }
    operator T*() {
        lock();
        _dirty = true;
        return _data;
    }
};

#define M(type,tag) \
template<> class Array<type> : public _ElementArray<type> { \
public: \
    using _ElementArray::_ElementArray; \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

////////////////////////////////////////////////////////////////////////////////

/**
 * simple ref base class.
 * does _not_ free the reference on destruction
 * use Ref<X> when passing objects as parameters
 * use LocalRef<X> for returning new objects
 */
template <typename T>
class RefBase {
protected:
    T _impl;
public:
    explicit RefBase(jobject value) : _impl(value) {
    }
    RefBase(const RefBase<T>& value) : _impl((jobject)value) {
    }
    // @TODO: how do we access value._impl ?
    template <typename S>
    RefBase(const RefBase<S>& value) : _impl( static_cast<S>(value.__impl()) ) {
    }
    //template <typename S>
    //Ref(const Ref<S>& value) : _impl((jobject)value) {
    //}
    const T& __impl() const {
        return _impl;
    }

    const T* operator->() const {
        return &_impl;
    }
    T* operator->() {
        return &_impl;
    }
    const T& operator*() const {
        return _impl;
    }
    T& operator*() {
        return _impl;
    }

    // disallow use of []
private:
    void operator[](int idx) const { // !!! use (*ref)[idx]
    }
public:

    template <typename S>
    bool operator == (const Ref<S>& other) {
        return Env::get()->IsSameObject((jobject)*this, (jobject)*other);
    }
    template <typename S>
    bool operator != (const Ref<S>& other) {
        return !Env::get()->IsSameObject((jobject)*this, (jobject)*other);
    }
    operator jobject() const {
        return (jobject)_impl;
    }
    operator bool() const {
        return (jobject)*this != nullptr && !Env::get()->IsSameObject((jobject)*this, NULL);
    }
};

/**
 * Ref specializations for easier access of Strings and Arrays
*/

template <typename T, typename A1, typename A2>
class Ref : public RefBase<T> {
public:
    using RefBase<T>::RefBase;
};

/**
 * ref specialization for strings
*/
template <typename T>
class Ref<T, typename JNIPP_ENABLE_IF_C<JNIPP_IS_BASE_OF<String, T>::value>::type> : public RefBase<T> {
protected:
    bool _free = false;
public:
    using RefBase<T>::RefBase;
    Ref(const char* value) : RefBase<T>( Env::get()->NewStringUTF(value) ), _free(true) {
    }
    ~Ref() {
        if (_free) {
            Env::get()->DeleteLocalRef( (jobject)*this );
        }
    }
    operator const char*() const {
        return (*this)->std_str().c_str();
    }
    const char* c_str() const {
        return (*this)->std_str().c_str();
    }

    bool operator == (const char* str) const {
        return **this == str;
    }
    bool operator != (const char* str) const {
        return **this != str;
    }
};

/**
 * ref specialization for classes
*/
template <typename T>
class Ref<T, void, typename JNIPP_ENABLE_IF_C<JNIPP_IS_BASE_OF<Class, T>::value>::type> : public RefBase<T> {
public:
    using RefBase<T>::RefBase;
    operator jclass() const {
        return (jclass)(**this);
    }
};

/**
 * ref specialization for object arrays
*/
template <typename T>
class Ref<Array<T>> : public RefBase<Array<T>> {
public:
    using RefBase<Array<T>>::RefBase;
    LocalRef<T> operator[] (jsize index) {
        return (*this)->get(index);
    }
    typename Array<T>::Iterator begin() const {
        return (*this)->begin();
    }
    typename Array<T>::Iterator end() const {
        return (*this)->end();
    }
};

/**
 * ref specialization for typed array
*/
#define M(type,tag) \
template <> \
class Ref<Array<type>> : public RefBase<Array<type>> { \
public: \
    using RefBase<Array<type>>::RefBase; \
    type operator[] (jsize index) const { \
        return (*this)->get(index); \
    } \
    type& operator[] (jsize index) { \
        return (*this)->getRef(index); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M


/**
 * java local ref
 * calls DeleteLocalRef on destruction
*/
template <typename T>
class LocalRef : public Ref<T> {
protected:
    void __clear() {
        this->_impl.__clear();
    }
    template<typename S> friend class LocalRef;
public:
    explicit LocalRef(jobject value) : Ref<T>(value) {
        JNIPP_RLOG("LocalRef::LocalRef(jobject) this=%p jobject=%p", this, (jobject)*this);
    }
    template <typename S>
    LocalRef(LocalRef<S>&& value) : Ref<T>((jobject)value) {
        value.__clear();
        JNIPP_RLOG("LocalRef::LocalRef(LocalRef&&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    template <typename S>
    LocalRef(const Ref<S>& value) : Ref<T>(Env::get()->NewLocalRef((jobject)value)) {
        JNIPP_RLOG("LocalRef::LocalRef(Ref&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    ~LocalRef() {
        if ((jobject)*this) {
            JNIPP_RLOG("LocalRef::~LocalRef() this=%p jobject=%p", this, (jobject)*this);
            if (Env::peek()) Env::get()->DeleteLocalRef((jobject)*this);
            this->__clear();
        }
    }
    static bool is(jobject value) {
        return Env::get()->GetObjectRefType(value) == JNILocalRefType;
    }
};

/**
 * java global ref
 * calls DeleteGlobalRef on destruction
 */
template <typename T>
class GlobalRef : public Ref<T> {
protected:
    void __clear() {
        this->_impl.__clear();
    }
public:
    GlobalRef() : Ref<T>((jobject)nullptr) {
        JNIPP_RLOG("GlobalRef::GlobalRef() this=%p", this);
    }
    explicit GlobalRef(jobject value) : Ref<T>(Env::get()->NewGlobalRef(value)) {
        JNIPP_RLOG("GlobalRef::GlobalRef(jobject) this=%p jobject=%p", this, (jobject)*this);
    }
    template <typename S>
    GlobalRef(GlobalRef<S>&& value) : Ref<T>((jobject)value) {
        JNIPP_RLOG("GlobalRef::GlobalRef(GlobalRef&&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
        value.__clear();
    }
    template <typename S>
    GlobalRef(const Ref<S>& value) : Ref<T>(Env::get()->NewGlobalRef((jobject)value)) {
        JNIPP_RLOG("GlobalRef::GlobalRef(Ref&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    ~GlobalRef() {
        if ((jobject)*this) {
            JNIPP_RLOG("GlobalRef::~GlobalRef() this=%p jobject=%p", this, (jobject)*this);
            if (Env::peek()) Env::get()->DeleteGlobalRef((jobject)*this);
            this->__clear();
        }
    }
    template <typename S>
    void set(const Ref<S>& value) {
        if (*this) Env::get()->DeleteGlobalRef((jobject)*this);
        this->_impl = T(Env::get()->NewGlobalRef((jobject)value));
    }
    static bool is(jobject value) {
        return Env::get()->GetObjectRefType(value) == JNIGlobalRefType;
    }
};

/**
 * java weak ref
 * operator bool will return false if the weak reference is gone
 * cannot be used directly - will be cast to LocalRef instead to make sure the reference is not GCed
 */
template <typename T>
class WeakRef {
public:
    WeakRef() : Ref<T>((jobject)nullptr) {
        JNIPP_RLOG("WeakRef::WeakRef() this=%p", this);
    }
    explicit WeakRef(jobject value) : Ref<T>(Env::get()->NewWeakGlobalRef(value)) {
        JNIPP_RLOG("WeakRef::WeakRef(jobject) this=%p jobject=%p", this, (jobject)*this);
    }
    template <typename S>
    WeakRef(WeakRef<S>&& value) : Ref<T>((jobject)value) {
        JNIPP_RLOG("WeakRef::WeakRef(WeakRef&&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
        value.clear();
    }
    template <typename S>
    WeakRef(const Ref<S>& value) : Ref<T>(Env::get()->NewWeakGlobalRef((jobject)value)) {
        JNIPP_RLOG("WeakRef::WeakRef(Ref&) this=%p value=<%p> jobject=%p", this, &value, (jobject)*this);
    }
    ~WeakRef() {
        if (*this) {
            JNIPP_RLOG("WeakRef::~WeakRef() this=%p jobject=%p", this, (jobject)*this);
            if (Env::peek()) Env::get()->DeleteWeakGlobalRef((jobject)*this);
            this->clear();
        }
    }
    template <typename S>
    bool operator == (const Ref<S>& other) {
        return Env::get()->IsSameObject((jobject)*this, (jobject)*other);
    }
    template <typename S>
    bool operator != (const Ref<S>& other) {
        return !Env::get()->IsSameObject((jobject)*this, (jobject)*other);
    }
    operator bool() const {
        return (jobject)*this != nullptr && !Env::get()->IsSameObject((jobject)*this, NULL);
    }
    void clear() {
        this->_impl.clear();
    }
    template <typename S>
    void set(const Ref<S>& value) {
        if (*this) Env::get()->DeleteWeakGlobalRef((jobject)*this);
        this->_impl = T(Env::get()->NewGlobalRef((jobject)value));
    }
    static bool is(jobject value) {
        return Env::get()->GetObjectRefType(value) == JNIWeakGlobalRefType;
    }
};

////////////////////////////////////////////////////////////////////////////////

/**
 * templates for converting function arguments
*/

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
            JNIEnv* env = Env::get();
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
        return LocalRef<R>( Env::get()->CallObjectMethod(target, getMethodID(), _ConvertArg(args)...) );
    }
};

template<typename... A>
class Method<void, A...> : public MethodBase
{
public:
    using MethodBase::MethodBase;
    void call(jobject target, typename _AsRef<A>::R... args) {
        return Env::get()->CallVoidMethod(target, getMethodID(), _ConvertArg(args)...);
    }
};

#define M(type,tag) \
template<typename... A> \
class Method<type, A...> : public MethodBase \
{ \
public: \
    using MethodBase::MethodBase; \
    type call(jobject target, typename _AsRef<A>::R... args) { \
        return Env::get()->Call ## tag ## Method(target, getMethodID(), _ConvertArg(args)...); \
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
            JNIEnv* env = Env::get();
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
        return LocalRef<R>( Env::get()->CallNonvirtualObjectMethod(target, getMethodID(), _ConvertArg(args)...) );
    }
};

template<typename... A>
class NonvirtualMethod<void, A...> : public NonvirtualMethodBase
{
public:
    using NonvirtualMethodBase::NonvirtualMethodBase;
    void call(jobject target, typename _AsRef<A>::R... args) {
        return Env::get()->CallNonvirtualVoidMethod(target, getMethodID(), _ConvertArg(args)...);
    }
};

#define M(type,tag) \
template<typename... A> \
class NonvirtualMethod<type, A...> : public NonvirtualMethodBase \
{ \
public: \
    using NonvirtualMethodBase::NonvirtualMethodBase; \
    type call(jobject target, typename _AsRef<A>::R... args) { \
        return Env::get()->CallNonvirtual ## tag ## Method(target, getMethodID(), _ConvertArg(args)...); \
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
            JNIEnv* env = Env::get();
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
        return LocalRef<R>( Env::get()->CallStaticObjectMethod(getClass(), getMethodID(), _ConvertArg(args)...) );
    }
};

template<typename... A>
class StaticMethod<void, A...> : public StaticMethodBase
{
public:
    using StaticMethodBase::StaticMethodBase;
    void call(typename _AsRef<A>::R... args) {
        return Env::get()->CallStaticVoidMethod(getClass(), getMethodID(), _ConvertArg(args)...);
    }
};

#define M(type,tag) \
template<typename... A> \
class StaticMethod<type, A...> : public StaticMethodBase \
{ \
public: \
    using StaticMethodBase::StaticMethodBase; \
    type call(typename _AsRef<A>::R... args) { \
        return Env::get()->CallStatic ## tag ## Method(getClass(), getMethodID(), _ConvertArg(args)...); \
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
            JNIEnv* env = Env::get();
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
        return LocalRef<R>( Env::get()->NewObject(getClass(), getMethodID(), _ConvertArg(args)...) );
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
            JNIEnv* env = Env::get();
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
        return LocalRef<R>( Env::get()->GetObjectField(target, getFieldID()) );
    }
    void set(jobject target, Ref<R> value) {
        Env::get()->SetObjectField(target, getFieldID(), value);
    }
};

#define M(type,tag) \
template <> \
class Field<type> : public FieldBase \
{ \
public: \
    using FieldBase::FieldBase; \
    type get(jobject target) const { \
        return Env::get()->Get ## tag ## Field(target, getFieldID()); \
    } \
    void set(jobject target, type value) { \
        Env::get()->Set ## tag ## Field(target, getFieldID(), value); \
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
            JNIEnv* env = Env::get();
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
        return LocalRef<R>( Env::get()->GetStaticObjectField(getClass(), getFieldID()) );
    }
    operator LocalRef<R>() const {
        return get();
    }
    LocalRef<R> operator->() const {
        return get();
    }
    void set(Ref<R> value) {
        Env::get()->SetStaticObjectField(getClass(), getFieldID(), value);
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
        return Env::get()->GetStatic ## tag ## Field(getClass(), getFieldID()); \
    } \
    operator type() const { \
        return get(); \
    } \
    void set(type value) { \
        Env::get()->SetStatic ## tag ## Field(getClass(), getFieldID(), value); \
    } \
    void operator=(type value) { \
        set(value); \
    } \
};
JNIPP_M_FOR_ALL_TYPES
#undef M

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
    LocalRef<Object> res ( get()->ExceptionOccurred() );
    get()->ExceptionClear();
    return res;
}

inline void Env::throwException(Ref<Object> exception)
{
    get()->Throw((jthrowable)(jobject)*exception);
}
inline void Env::throwException(Ref<Class> cls, Ref<String> message) {
    Constructor<Object,String> method(cls, "(Ljava/lang/String;)V");
    throwException(method.construct(message));
}
inline void Env::throwException(const char* cls, const char* message) {
    throwException(Class::forName(cls), String::create(message));
}

////////////////////////////////////////////////////////////////////////////////

inline LocalRef<String> Object::toString() const {
    Method<String> method("java/lang/Object", "toString", "()Ljava/lang/String;");
    return method.call(*this);
}

inline LocalRef<Class> Object::getClass() const {
    return LocalRef<Class>( env()->GetObjectClass((jobject)*this) );
}

inline jboolean Object::isInstanceOf(Ref<Class> cls) const {
    return env()->IsInstanceOf((jobject)*this, (jclass)*cls);
}

inline Monitor Object::lock() const {
    return Monitor((jobject)*this);
}

inline LocalRef<String> String::create(const char* value) {
    return LocalRef<String>( Env::get()->NewStringUTF(value) );
}

inline LocalRef<String> String::create(std::string value) {
    return LocalRef<String>( Env::get()->NewStringUTF(value.c_str()) );
}

inline LocalRef<Class> Class::forName(const char* name) {
    return LocalRef<Class>( (jobject)Env::get()->FindClass(name) );
}

inline LocalRef<String> Class::getName() const {
    static Method<String> method("java/lang/Class", "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

inline jboolean Class::isAssignableFrom(Ref<Class> other) {
    return env()->IsAssignableFrom((jclass)*this, (jclass)*other);
}

inline LocalRef<Class> Class::getSuperclass() const {
    return LocalRef<Class>( env()->GetSuperclass((jclass)*this) );
}


////////////////////////////////////////////////////////////////////////////////

}

#endif


