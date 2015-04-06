#include <string>
#include <stdio.h>
#include <iostream>
#include <assert.h>

void LOG(const char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
    printf("\n");
    va_end(va);
}


#include <jnipp.h>
namespace jni = jnipp;
template <typename T> using JLocalRef = jnipp::LocalRef<T>;
using JString = jnipp::String;

#define EXPORT __attribute__((visibility("default"))) extern "C"

////////////////////////////////////////////////////////////////////////////////

EXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    return JNI_VERSION_1_6;
}

////////////////////////////////////////////////////////////////////////////////

JNIEXPORT

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

EXPORT JNIEXPORT void JNICALL Java_Test_native1(JNIEnv* env, jobject thiz)
{
    jni::Env::Scope scope(env);

    test_string();
}

////////////////////////////////////////////////////////////////////////////////
