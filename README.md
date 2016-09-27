What is this?
=============

jnipp is a C++11 Java Native Interface wrapper supposed to make life easier.


Requirements
============

- you need c++11 support: `-std=c++11`
- compile with `-DJNIPP_USE_TYPE_TRAITS` to use type traits if available; some versions of libstdc++ do not support `type_traits`: compile with `-DJNIPP_USE_BOOST` and put boost in your include path.
- some platforms (Android for example) do not completely support thread local storage. use `-DJNIPP_THREAD_LOCAL_PTHREAD` to fallback to pthread.


Quick Test:
===========
    cd test
    make -f Makefile.osx
    make -f Makefile.linux

It does not work?
- recompile the generate script: cd generate; javac generate.java
- install clang
- fix include path in Makefile


Usage without generated classes
===============================

    #include <jnipp.h>
    using namespace jnipp;

    JNIEnv* jni_env_pointer = /* ... */;
    Env::Scope scope(jni_env_pointer);

    LocalRef<String> str = String::create("Some String!");
    Method<String> String_toUpperCase("java/lang/String", "toUpperCase", "()Ljava/lang/String;");
    LocalRef<String> str_upper = String_toUpperCase(str);

compile with:

    clang -std=c++11 -lc++ -fvisibility=hidden -fvisibility-inlines-hidden -Wl,-dead_strip test.cpp -o test


Usage with generated classes
============================

use `./generate/generate java.lang.String` to generate the java class header file

    #include <jnipp.h>
    #include "_java.h" // contains the JavaLangString definition
    using namespace jnipp;

    JNIEnv* jni_env_pointer = /* ... */;
    Env::Scope scope(jni_env_pointer);

    LocalRef<JavaLangString> str = String::create("Some String!");
    LocalRef<JavaLangString> str_upper = str->toUpperCase();

Please note that due to the fact that some names are reserved in C++ and C++ also does not allow fields and methods with the same name, some method or member names are made unique by appending underscores (i.e. someField_ instead of someField)


Runtime size and speed
======================

This library is designed to generate as close to manually written code as possible.
- All functions are inlined
- No additional reference counters
- No allocations
- the "test" sample produces a .dylib of 30kb

When using java class headers you need to use dead code stripping, for clang:

    clang source.cpp -fvisibility=hidden -fvisibility-inlines-hidden
    clang source.o -Wl,-dead_strip


TODO
====
- clean up generate tool (own dir, .jar, output file name option etc.)
- option to limit scope of generate tool.


Reference
=========

Env
---
* stores the current `JNIEnv*` as a thread local variable
* use `Env::get()` to get the current `JNIEnv*`
* use `Env::peek()` to get the current `JNIEnv*` without throwing an exception if it is null
* use `Env::Scope myScope(my_jni_env)` to set the `JNIEnv*`. The scope setter will restore the previous value on destruction.
* use `Env::Scope myScope(my_jni_vm)` to attach the current thread to the VM.

* use `Env::hasException()` to check if an exception has occured, Env::getException() to get the exception object.
* use `Env::throwException(exceptionObject)` or `Env::throwException(exceptionClass, stringArgument)` to throw an exception.

Refs
----
* `Ref` is an unmanaged reference (`jobject`). Use these for method arguments.
* `Ref`s are not larger than a `jobject` and do not need to be passed by reference.
* all `Ref`s support `operator ==` (`IsSameObject`) and `operator bool` checking (for not null)
* a `LocalRef` keeps a jni local reference and call `DeleteLocalRef` on destruction. Use these for returning objects. The copy constructor will call `NewLocalRef`.
* use `LocalRef.steal()` to get the jobject from a LocalRef and zeroing the LocalRef (i.e. preventing the call to DeleteLocalRef on destruction).
* use `LocalRef::use(jobject)` to use an existing local reference jobject.
* a `GlobalRef` is a java global reference (`NewGlobalRef`). on destruction, calls `DeleteGlobalRef`.
* a `WeakRef` is a java weak global reference (`NewWeakGlobalRef`). on destruction, calls `DeleteWeakGlobalRef`. These are not a subclass of `Ref` and can only be used to initialize a `LocalRef` (to make sure that the weak reference is not garbage collected during usage).

Ref sugar
---------
* for arguments of type `Ref<String>` you can directly pass a `const char*` instead of passing `String::create(...)`
* for a `Ref<Array>` you can directly use the array subscript operator, i.e. `myArrayRef[0]` instead of `(*myArrayRef)[0]`
* `Ref<String>` can be cast to `const char*` and `std::string`
* `Ref<String>` has a `operator ==(const char*)` (and !=)

Methods and Fields
------------------
* `Method<returnType, argType1, argType2, argType3> method(const char* / Ref<Class> class, const char* methodName, const char* signature);` defines a method.
* Same for `StaticMethod` and `NonvirtualMethod`
* use `method.call([thisref, ]arg1, arg2, arg3);` to call
* `Field<type> field(const char* / Ref<Class> class, const char* fieldName, const char* signature);` defines a field
* Same for `StaticField`
* use `field.get([thisref])` and `field.set([thisref, ]value)`
* there is also a cast and assignment operator
* `Constructor<classType, argType1, ...> constructor(const char* / Ref<Class> class, const char* signature);` defines a constructor.
* use `constructor.construct(arg1, arg2, ..)` to call

Arrays
------
* `Array<Object>` is an object array. You can use `length()`, `get(index)` and `set(index, newValue)`. An `[]` operator exist, but only for reading.
* `Array<Object>::construct(size, elementClass)` creates a new array.
* object arrays support iterators, so you can use `for (auto something in myObjectArray)`
* `Array<jbyte>` (or any other primitive) is a primitive array. It also supports `length()`, `get(index)` and `set(index, newValue)`, but works by locking the buffer into memory on first usage (`GetByteArrayElements`). The subscript operators work for getting and setting, and the primitive array can also be cast to a pointer.
* upon next usage as a `jobject` the buffer is unlocked (`ReleaseByteArrayElements`) automatically.
* you can use `lock()` and `unlock()` to do this manually.

Generate Tool
-------------
* The `generate` tool will create a header file containing all method and field definitions.
* Referenced classes are included.
* Pass all java classes you need to access as parameters (i.e. `./generate java.lang.String java.util.Map java.util.Set`)
* Output filename is always `_java.h`
* The generated classes are named `JavaLangString` for `java.lang.String` and so on.
* dont forget to turn on dead code stripping (see above), otherwise that will make your executable really large.



