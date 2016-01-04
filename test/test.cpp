#include <string>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <stdarg.h>

void LOG(const char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
    printf("\n");
    va_end(va);
}


#include <jnipp.h>
using namespace jnipp;

//#define EXPORT __attribute__((visibility("default"))) extern "C"
#define EXPORT extern "C"

////////////////////////////////////////////////////////////////////////////////

EXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    return JNI_VERSION_1_6;
}

////////////////////////////////////////////////////////////////////////////////

#include "_java.h"

void test_string() {
    LocalRef<JavaLangString> str = String::create("Hello World");

    LOG("str=%s", str->std_str().c_str());
    LOG("str.length()=%d", str->length());
    LOG("str.charAt(0)=%c", str->charAt(0));

    auto bytes = str->getBytes();
    LOG("bytes.length()=%d", bytes->length());
    LOG("bytes[0]=%d", bytes[0] );

    auto str2 = str->concat(String::create(" !!"));
    LOG("str2=%s", str2->toString()->std_str().c_str());

    auto str3 = str->concat(" with const char*");
    LOG("str3=%s", str3->std_str().c_str());

    auto parts = str->split(" ");
    LOG("parts.length()=%d", parts->length());
    LOG("parts[0]=%s", parts[0]->std_str().c_str());

    LOG("String.valueOf(3.141f)=%s", JavaLangString::valueOf(3.141f)->toString()->std_str().c_str());

    LOG("String.CASE_INSENSITIVE_ORDER %s", JavaLangString::CASE_INSENSITIVE_ORDER.get()->toString()->std_str().c_str());
    LOG("String.CASE_INSENSITIVE_ORDER %s", JavaLangString::CASE_INSENSITIVE_ORDER->toString()->std_str().c_str());

    // JavaLangString::CASE_INSENSITIVE_ORDER.set(String::create("test")); // fails with read only

    JavaTest::staticObject.set( String::create("test") );
    LOG("JavaTest::staticObject %s", JavaTest::staticObject->toString()->std_str().c_str());
    JavaTest::staticObject = (Ref<Object>) String::create("test");
    LOG("JavaTest::staticObject %s", JavaTest::staticObject->toString()->std_str().c_str());

    LOG("JavaTest::staticInt %d", (jint)JavaTest::staticInt);
    JavaTest::staticInt = 1234;
    LOG("JavaTest::staticInt %d", (jint)JavaTest::staticInt);

    // throw an exception
    {
        auto ecls = GlobalRef<Class>(Class::forName("java/lang/Exception"));
        Constructor<Object,String> method(ecls, "(Ljava/lang/String;)V");
        auto ex = method.construct(String::create("hello world!"));
        Env::throwException(ex);
        if (Env::hasException()) {
            LOG("got an exception");
            auto ex = Env::getException();
            LOG("ex toString: %s", ex->toString()->std_str().c_str());
        }
    }

    {
        // throw an exception
        Env::throwException("java/lang/RuntimeException", "message");
        if (Env::hasException()) {
            LOG("got an exception");
            auto ex = Env::getException();
            LOG("ex toString: %s", ex->toString()->std_str().c_str());
        }
    }

    {
        // create byte array
        LocalRef<Array<jbyte>> byteArray = Array<jbyte>::create(1024);
        LOG("byteArray.length()=%d", byteArray->length());
        for (int i=0; i<1024; i++) {
            byteArray->set(i, i & 0xFF);
        }
        LOG("byteArray[3]=%d", (*byteArray)[3]);
        LOG("byteArray[0]=%d", (*byteArray)[0]);
        LOG("byteArray[0]=%d", byteArray[0]);
        byteArray[0] = 123;
        LOG("byteArray[0]=%d", (*byteArray)[0]);
    }

    {
        // create char array
        LOG("charArray");
        auto charArray = Array<jchar>::create(10);
        for (int i=0; i<charArray->length(); i++) (*charArray)[i] = '0' + i;
        auto charString = JavaLangString::construct(charArray);
        LOG("charString=%s", charString->std_str().c_str());
    }
};

EXPORT JNIEXPORT void JNICALL Java_Test_native1(JNIEnv* env, jobject thiz)
{
    Env::Scope scope(env);

    test_string();
}

////////////////////////////////////////////////////////////////////////////////
