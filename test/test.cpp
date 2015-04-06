#include <string>
#include <stdio.h>
#include <iostream>
#include <assert.h>

#include <v8.h>
#include <libplatform/libplatform.h>
using namespace v8;

void LOG(const char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
    printf("\n");
    va_end(va);
}


#include "jnipp.h"
namespace jni = jnipp;
template <typename T> using JLocalRef = jnipp::LocalRef<T>;
using JString = jnipp::String;

////////////////////////////////////////////////////////////////////////////////

Isolate* gIsolate = NULL;
Persistent<Context> gContext;

////////////////////////////////////////////////////////////////////////////////

std::string cast(Handle<String> str)
{
    if (str.IsEmpty()) return "<empty>";
    return *String::Utf8Value(str);
}

std::string cast(Handle<Value> obj)
{
    if (obj.IsEmpty()) return "<empty>";
    return cast(obj->ToString());
}

/*

std::string getSignatureForClass(jclass cls)
{
    JNIEnv* env = jni::EnvScope::cur();
    if (env->CallBooleanMethod(cls, jni::MID(cls, "isPrimitive", "()Z"))) {
        std::string name = cast( (jstring)env->CallObjectMethod(cls, jni::MID(cls, "getName", "()Ljava/lang/String;")) );
        if (name == "void") return "V";
        if (name == "boolean") return "Z";
        if (name == "double") return "D";
        if (name == "float") return "I";
        if (name == "int") return "I";
        if (name == "long") return "J";
        if (name == "byte") return "B";
        assert(false);
    } else if (env->CallBooleanMethod(cls, jni::MID(cls, "isArray", "()Z"))) {
        jclass comp = (jclass)env->CallObjectMethod(cls, jni::MID(cls, "getComponentType", "()Ljava/lang/Class;"));
        return "[" + getSignatureForClass(comp);
    } else {
        std::string name = cast( (jstring)env->CallObjectMethod(cls, jni::MID(cls, "getName", "()Ljava/lang/String;")) );
        for (auto i=name.begin(); i<name.end(); i++) if (*i == '.') *i = '/';
        return "L" + name + ";";
    }
}
*/

////////////////////////////////////////////////////////////////////////////////

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    const char* flags = "--harmony --es_staging";
    V8::SetFlagsFromString(flags, strlen(flags));

    V8::InitializeICU();
    V8::InitializePlatform(platform::CreateDefaultPlatform());
    V8::Initialize();

    Isolate::CreateParams isoParams;
    isoParams.constraints.ConfigureDefaults(1024*1024*64, 1024*1024*256, 1);
    Isolate* iso = Isolate::New(isoParams);
    iso->Enter();
    gIsolate = iso;

    HandleScope handle_scope(iso);

    Local<Context> context = Context::New(iso);
    Context::Scope context_scope(context);
    gContext.Reset(iso, context);

    return JNI_VERSION_1_6;
}

////////////////////////////////////////////////////////////////////////////////



//#include "JavaLangString.h"
//#include "JavaTest.h"
#include "_java.h"

void test_string() {

    JLocalRef<JavaLangString> str = JString::create("Hello World");

    LOG("str=%s", str->toString()->c_str());

    // constructors...??? must be static function...
    // 
    LOG("str.length()=%d", str->length());
    LOG("str.charAt(0)=%c", str->charAt(0));

    auto bytes = str->getBytes();
    LOG("bytes.length()=%d", bytes->length());
    LOG("bytes[0]=%d", bytes->operator[](0) );
    jni::Ref<jni::Array<jbyte>> bytes2 = bytes;
    LOG("bytes[0]=%d", (*bytes)[0] );
    // LOG("bytes[0]=%d", bytes[0] ); // fails as expected

    auto str2 = str->concat(jni::String::create(" !!"));
    LOG("str2=%s", str2->toString()->c_str());

    //auto str3 = str->concat("sugar string");
    //LOG("str3=%s", str3->toString()->c_str());

    auto parts = str->split(jni::String::create(" "));
    LOG("parts.length()=%d", parts->length());
    LOG("parts[0]=%s", (*parts)[0]->toString()->c_str());

    LOG("String.valueOf(3.141f)=%s", JavaLangString::valueOf(3.141f)->toString()->c_str());


    jni::StaticField<jni::String> CASE_INSENSITIVE_ORDER("java/lang/String", "CASE_INSENSITIVE_ORDER", "Ljava/util/Comparator;");
    LOG("CASE_INSENSITIVE_ORDER jfieldid %d", (jfieldID)CASE_INSENSITIVE_ORDER);
    LOG("CASE_INSENSITIVE_ORDER toString %s", CASE_INSENSITIVE_ORDER.get()->toString()->c_str());

    LOG("String.CASE_INSENSITIVE_ORDER %s", JavaLangString::CASE_INSENSITIVE_ORDER.get()->toString()->c_str());
    LOG("String.CASE_INSENSITIVE_ORDER %s", JavaLangString::CASE_INSENSITIVE_ORDER->toString()->c_str());

    // JavaLangString::CASE_INSENSITIVE_ORDER.set(JString::create("test")); // fails with read only

    JavaTest::staticObject.set( JString::create("test"));
    LOG("JavaTest::staticObject %s", JavaTest::staticObject->toString()->c_str());
    JavaTest::staticObject = (jni::Ref<jni::Object>) JString::create("test");
    LOG("JavaTest::staticObject %s", JavaTest::staticObject->toString()->c_str());

    LOG("JavaTest::staticInt %d", (jint)JavaTest::staticInt);
    JavaTest::staticInt = 1234;
    LOG("JavaTest::staticInt %d", (jint)JavaTest::staticInt);


    // throw an exception
    {
        auto ecls = jni::Class::forName("java/lang/Exception");
        jni::Constructor<jni::Object,jni::String> method(ecls, "(Ljava/lang/String;)V");
        auto ex = method.construct(jni::String::create("hello world!"));
        jni::Env::throwException(ex);
    }
    // catch exception
    if (jni::Env::hasException()) {
        LOG("got an exception");
        auto ex = jni::Env::getException();
        LOG("ex toString: %s", ex->toString()->c_str());
    }

};

////////////////////////////////////////////////////////////////////////////////


class JavaLangReflectMethod : public jni::Object
{
public:
    using parent = jni::Object;
    using parent::parent;
    static jni::GlobalRef<jni::Class>& getClass() {
        static jni::GlobalRef<jni::Class> cls;
        if (!cls) cls.set(jni::Class::forName("java/lang/reflect/Method"));
        return cls;
    }









    jni::LocalRef<jni::Object> invoke(const jni::Ref<jni::Object>& a0, const jni::Ref<jni::Array<jni::Object>>& a1) const {
        static jni::Method<jni::Object,jni::Object,jni::Array<jni::Object>> method(getClass(), "invoke", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
        return method.call(*this, a0, a1);
    }
/*
    jboolean equals(const jni::Ref<jni::Object>& a0) const {
        static jni::Method<jboolean,jni::Ref<jni::Object>> method(getClass(), "equals", "(Ljava/lang/Object;)B");
        return method.call(*this, a0);
    }
    jni::LocalRef<jni::String> toString() const {
        static jni::Method<jni::String> method(getClass(), "toString", "()Ljava/lang/String;");
        return method.call(*this);
    }
    jint hashCode() const {
        static jni::Method<jint> method(getClass(), "hashCode", "()I");
        return method.call(*this);
    }
    jint getModifiers() const {
        static jni::Method<jint> method(getClass(), "getModifiers", "()I");
        return method.call(*this);
    }
    jni::LocalRef<jni::String> getName() const {
        static jni::Method<jni::String> method(getClass(), "getName", "()Ljava/lang/String;");
        return method.call(*this);
    }
    jboolean isSynthetic() const {
        static jni::Method<jboolean> method(getClass(), "isSynthetic", "()B");
        return method.call(*this);
    }
    jni::LocalRef<jni::Array<jni::Object>> getTypeParameters() const {
        static jni::Method<jni::Array<jni::Object>> method(getClass(), "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Class> getDeclaringClass() const {
        static jni::Method<jni::Class> method(getClass(), "getDeclaringClass", "()Ljava/lang/Class;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Object> getAnnotation(const jni::Ref<jni::Class>& a0) const {
        static jni::Method<jni::Object,jni::Ref<jni::Class>> method(getClass(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
        return method.call(*this, a0);
    }
    jni::LocalRef<jni::Array<jni::Object>> getDeclaredAnnotations() const {
        static jni::Method<jni::Array<jni::Object>> method(getClass(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Class> getReturnType() const {
        static jni::Method<jni::Class> method(getClass(), "getReturnType", "()Ljava/lang/Class;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Array<jni::Class>> getParameterTypes() const {
        static jni::Method<jni::Array<jni::Class>> method(getClass(), "getParameterTypes", "()[Ljava/lang/Class;");
        return method.call(*this);
    }
    jni::LocalRef<jni::String> toGenericString() const {
        static jni::Method<jni::String> method(getClass(), "toGenericString", "()Ljava/lang/String;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Object> getGenericReturnType() const {
        static jni::Method<jni::Object> method(getClass(), "getGenericReturnType", "()Ljava/lang/reflect/Type;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Array<jni::Object>> getGenericParameterTypes() const {
        static jni::Method<jni::Array<jni::Object>> method(getClass(), "getGenericParameterTypes", "()[Ljava/lang/reflect/Type;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Array<jni::Class>> getExceptionTypes() const {
        static jni::Method<jni::Array<jni::Class>> method(getClass(), "getExceptionTypes", "()[Ljava/lang/Class;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Array<jni::Object>> getGenericExceptionTypes() const {
        static jni::Method<jni::Array<jni::Object>> method(getClass(), "getGenericExceptionTypes", "()[Ljava/lang/reflect/Type;");
        return method.call(*this);
    }
    jboolean isBridge() const {
        static jni::Method<jboolean> method(getClass(), "isBridge", "()B");
        return method.call(*this);
    }
    jboolean isVarArgs() const {
        static jni::Method<jboolean> method(getClass(), "isVarArgs", "()B");
        return method.call(*this);
    }
    jni::LocalRef<jni::Object> getDefaultValue() const {
        static jni::Method<jni::Object> method(getClass(), "getDefaultValue", "()Ljava/lang/Object;");
        return method.call(*this);
    }
    jni::LocalRef<jni::Array<jni::Array<jni::Object>>> getParameterAnnotations() const {
        static jni::Method<jni::Array<jni::Array<jni::Object>>> method(getClass(), "getParameterAnnotations", "()[[Ljava/lang/annotation/Annotation;");
        return method.call(*this);
    }

*/








};

class JavaLangClass : public jni::Class
{
public:
    using parent = jni::Class;
    using parent::parent;

    static jni::GlobalRef<jni::Class>& getClass() {
        static jni::GlobalRef<jni::Class> cls;
        if (!cls) cls.set( jni::Class::forName("java/lang/Class") );
        return cls;
    }

    jni::LocalRef<jni::String> getName() const {
        static jni::Method<jni::String> method(getClass(), "getName", "()Ljava/lang/String;");
        return method.call(*this);
    }

    jboolean isPrimitive() const {
        static jni::Method<jboolean> method(getClass(), "isPrimitive", "()Z");
        return method.call(*this);
    }

    jboolean isArray() const {
        static jni::Method<jboolean> method(getClass(), "isArray", "()Z");
        return method.call(*this);
    }

    jni::LocalRef<JavaLangClass> getComponentType() const {
        static jni::Method<JavaLangClass> method(getClass(), "getComponentType", "()Ljava/lang/Class;");
        return method.call(*this);
    }

    jni::LocalRef<JavaLangClass> getSuperclass() const {
        static jni::Method<JavaLangClass> method(getClass(), "getSuperclass", "()Ljava/lang/Class;");
        return method.call(*this);
    }

    jni::LocalRef<jni::Array<JavaLangReflectMethod>> getDeclaredMethods() const {
        static jni::Method<jni::Array<JavaLangReflectMethod>> method("java/lang/Class", "getDeclaredMethods", "()[Ljava/lang/reflect/Method;");
        return method.call(*this);
    }

};


void test()
{
    jni::LocalRef<JavaLangClass> cls = jni::LocalRef<JavaLangClass>( jni::Class::forName("java/lang/String") );
    LOG("%s", cls->getName()->c_str());

    jni::GlobalRef<JavaLangClass> cls2;
    cls2.set(cls);

/*

    auto methods = cls->getDeclaredMethods();
    for (auto method : *methods) {
        LOG("xx %s", method->toString()->c_str());
    }




    LOG("A");
    auto x = jni::Class::find("java/lang/String");
    LOG("sizeof(x)=%d / %d", sizeof(x), sizeof(jobject));
    auto y = x->getName();
    LOG("name=%s", y->c_str());
    auto methods = x->getDeclaredMethods();
    LOG("methods=%d", methods->length());
    
    for (int i=0; i<methods->size(); i++) {
        LOG("i=%d", i);
        auto method = methods[i];
    }
    */
    /*
    *//*

    jni::Method<jboolean,jobject> javaLangObject_equals("java/lang/Object", "equals", "(Ljava/lang/Object;)Z");
    LOG("D");
    jboolean res = javaLangObject_equals.call(methods, (jobject)x);
    LOG("a %d", res);

    jni::StaticMethod<jni::String,jboolean> javaLangString_valueOf("java/lang/String", "valueOf", "(Z)Ljava/lang/String;");
    jni::LocalRef<jni::String> res2 = javaLangString_valueOf.call(JNI_FALSE);
    LOG("res2 %s", res2->c_str());

    // next step: cached jclass retrieval and cached methodID retrieval.
    // next step: own custom subclass
*/
//    x->testFunc();
}

////////////////////////////////////////////////////////////////////////////////

//#include "bridge.h"

void api_print(const FunctionCallbackInfo<Value>& info)
{
    Isolate* iso = Isolate::GetCurrent();
    HandleScope handle_scope(iso);
    for (int i=0; i<info.Length(); i++) {
        Local<String> asd = info[i]->ToString();
        LOG("%s", cast(info[i]).c_str());
    }
    //info.GetReturnValue().Set( String::NewFromUtf8(iso, "result") );
}

const char* scriptcode = R"raw(

print('hello world from js');

)raw";


extern "C" JNIEXPORT void JNICALL Java_Test_native1(JNIEnv* env, jobject thiz)
{
    jni::Env::Scope scope(env);
    Isolate* iso = Isolate::GetCurrent();
    HandleScope handle_scope(iso);

    Local<Context> context = Local<Context>::New(iso, gContext);
    Context::Scope context_scope(context);
    Local<Object> global = context->Global();

    Local<FunctionTemplate> tpl = FunctionTemplate::New(iso);
    tpl->SetCallHandler(api_print);
    global->Set(String::NewFromUtf8(iso, "print"), tpl->GetFunction());

    test_string();
    //test();
    //test_reflect();
/*
    TryCatch tryCatch;
    ScriptOrigin origin(String::NewFromUtf8(iso, "<eval>"));
    Handle<Script> script = Script::Compile(String::NewFromUtf8(iso, scriptcode), &origin);
    Handle<Value> result = script->Run();
    LOG("result: %s", cast(result).c_str());
    if (tryCatch.HasCaught()) {
        Local<String> errorMessage = tryCatch.Exception()->ToString();
        Local<String> errorOrigin = tryCatch.Message()->GetScriptOrigin().ResourceName()->ToString();
        LOG("error: %s %s", cast(errorMessage).c_str(), cast(errorOrigin).c_str());
    }
*/

}

////////////////////////////////////////////////////////////////////////////////
