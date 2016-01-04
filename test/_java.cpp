#include "_java.h"

jnipp::GlobalRef<jnipp::Class>& JavaLangObject::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Object"));
    return cls;
}

// public java.lang.Object()
jnipp::LocalRef<JavaLangObject> JavaLangObject::construct() {
    static jnipp::Constructor<JavaLangObject> constructor(clazz(), "()V");
    return constructor.construct();
}

// public final void java.lang.Object.wait(long,int) throws java.lang.InterruptedException
void JavaLangObject::wait(jlong a0, jint a1) const {
    static jnipp::Method<void,jlong,jint> method(clazz(), "wait", "(JI)V");
    method.call(*this, a0, a1);
}

// public final native void java.lang.Object.wait(long) throws java.lang.InterruptedException
void JavaLangObject::wait(jlong a0) const {
    static jnipp::Method<void,jlong> method(clazz(), "wait", "(J)V");
    method.call(*this, a0);
}

// public final void java.lang.Object.wait() throws java.lang.InterruptedException
void JavaLangObject::wait() const {
    static jnipp::Method<void> method(clazz(), "wait", "()V");
    method.call(*this);
}

// public boolean java.lang.Object.equals(java.lang.Object)
jboolean JavaLangObject::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public native int java.lang.Object.hashCode()
jint JavaLangObject::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public final native void java.lang.Object.notify()
void JavaLangObject::notify() const {
    static jnipp::Method<void> method(clazz(), "notify", "()V");
    method.call(*this);
}

// public final native void java.lang.Object.notifyAll()
void JavaLangObject::notifyAll() const {
    static jnipp::Method<void> method(clazz(), "notifyAll", "()V");
    method.call(*this);
}
jnipp::GlobalRef<jnipp::Class>& JavaLangString::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/String"));
    return cls;
}

// public java.lang.String(byte[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,jint,jint> constructor(clazz(), "([BII)V");
    return constructor.construct(a0, a1, a2);
}

// public java.lang.String(byte[],java.nio.charset.Charset)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, const jnipp::Ref<JavaNioCharsetCharset>& a1) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,JavaNioCharsetCharset> constructor(clazz(), "([BLjava/nio/charset/Charset;)V");
    return constructor.construct(a0, a1);
}

// public java.lang.String(byte[],java.lang.String) throws java.io.UnsupportedEncodingException
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,JavaLangString> constructor(clazz(), "([BLjava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public java.lang.String(byte[],int,int,java.nio.charset.Charset)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2, const jnipp::Ref<JavaNioCharsetCharset>& a3) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,jint,jint,JavaNioCharsetCharset> constructor(clazz(), "([BIILjava/nio/charset/Charset;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public java.lang.String(byte[],int,int,java.lang.String) throws java.io.UnsupportedEncodingException
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2, const jnipp::Ref<JavaLangString>& a3) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,jint,jint,JavaLangString> constructor(clazz(), "([BIILjava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// java.lang.String(char[],boolean)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jchar>>& a0, jboolean a1) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jchar>,jboolean> constructor(clazz(), "([CZ)V");
    return constructor.construct(a0, a1);
}

// public java.lang.String(java.lang.StringBuilder)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<JavaLangStringBuilder>& a0) {
    static jnipp::Constructor<JavaLangString,JavaLangStringBuilder> constructor(clazz(), "(Ljava/lang/StringBuilder;)V");
    return constructor.construct(a0);
}

// public java.lang.String(java.lang.StringBuffer)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<JavaLangStringBuffer>& a0) {
    static jnipp::Constructor<JavaLangString,JavaLangStringBuffer> constructor(clazz(), "(Ljava/lang/StringBuffer;)V");
    return constructor.construct(a0);
}

// public java.lang.String(byte[])
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>> constructor(clazz(), "([B)V");
    return constructor.construct(a0);
}

// public java.lang.String(int[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jint>>& a0, jint a1, jint a2) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jint>,jint,jint> constructor(clazz(), "([III)V");
    return constructor.construct(a0, a1, a2);
}

// public java.lang.String()
jnipp::LocalRef<JavaLangString> JavaLangString::construct() {
    static jnipp::Constructor<JavaLangString> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.lang.String(char[])
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jchar>>& a0) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jchar>> constructor(clazz(), "([C)V");
    return constructor.construct(a0);
}

// public java.lang.String(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.lang.String(char[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jchar>,jint,jint> constructor(clazz(), "([CII)V");
    return constructor.construct(a0, a1, a2);
}

// public java.lang.String(byte[],int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,jint> constructor(clazz(), "([BI)V");
    return constructor.construct(a0, a1);
}

// public java.lang.String(byte[],int,int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2, jint a3) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,jint,jint,jint> constructor(clazz(), "([BIII)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public boolean java.lang.String.equals(java.lang.Object)
jboolean JavaLangString::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.lang.String.hashCode()
jint JavaLangString::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.lang.String.compareTo(java.lang.String)
jint JavaLangString::compareTo(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "compareTo", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public int java.lang.String.indexOf(java.lang.String,int)
jint JavaLangString::indexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "indexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.String.indexOf(int)
jint JavaLangString::indexOf(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "indexOf", "(I)I");
    return method.call(*this, a0);
}

// public int java.lang.String.indexOf(java.lang.String)
jint JavaLangString::indexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "indexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public int java.lang.String.indexOf(int,int)
jint JavaLangString::indexOf(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "indexOf", "(II)I");
    return method.call(*this, a0, a1);
}

// public static java.lang.String java.lang.String.valueOf(char)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jchar a0) {
    static jnipp::StaticMethod<JavaLangString,jchar> method(clazz(), "valueOf", "(C)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(java.lang.Object)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(const jnipp::Ref<JavaLangObject>& a0) {
    static jnipp::StaticMethod<JavaLangString,JavaLangObject> method(clazz(), "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(boolean)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jboolean a0) {
    static jnipp::StaticMethod<JavaLangString,jboolean> method(clazz(), "valueOf", "(Z)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(char[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<JavaLangString,jnipp::Array<jchar>,jint,jint> method(clazz(), "valueOf", "([CII)Ljava/lang/String;");
    return method.call(a0, a1, a2);
}

// public static java.lang.String java.lang.String.valueOf(char[])
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(const jnipp::Ref<jnipp::Array<jchar>>& a0) {
    static jnipp::StaticMethod<JavaLangString,jnipp::Array<jchar>> method(clazz(), "valueOf", "([C)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(double)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jdouble a0) {
    static jnipp::StaticMethod<JavaLangString,jdouble> method(clazz(), "valueOf", "(D)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(float)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jfloat a0) {
    static jnipp::StaticMethod<JavaLangString,jfloat> method(clazz(), "valueOf", "(F)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(long)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jlong a0) {
    static jnipp::StaticMethod<JavaLangString,jlong> method(clazz(), "valueOf", "(J)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(int)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jint a0) {
    static jnipp::StaticMethod<JavaLangString,jint> method(clazz(), "valueOf", "(I)Ljava/lang/String;");
    return method.call(a0);
}

// public int java.lang.String.length()
jint JavaLangString::length() const {
    static jnipp::Method<jint> method(clazz(), "length", "()I");
    return method.call(*this);
}

// public boolean java.lang.String.isEmpty()
jboolean JavaLangString::isEmpty() const {
    static jnipp::Method<jboolean> method(clazz(), "isEmpty", "()Z");
    return method.call(*this);
}

// public char java.lang.String.charAt(int)
jchar JavaLangString::charAt(jint a0) const {
    static jnipp::Method<jchar,jint> method(clazz(), "charAt", "(I)C");
    return method.call(*this, a0);
}

// public int java.lang.String.codePointAt(int)
jint JavaLangString::codePointAt(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "codePointAt", "(I)I");
    return method.call(*this, a0);
}

// public int java.lang.String.codePointBefore(int)
jint JavaLangString::codePointBefore(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "codePointBefore", "(I)I");
    return method.call(*this, a0);
}

// public int java.lang.String.codePointCount(int,int)
jint JavaLangString::codePointCount(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "codePointCount", "(II)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.String.offsetByCodePoints(int,int)
jint JavaLangString::offsetByCodePoints(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "offsetByCodePoints", "(II)I");
    return method.call(*this, a0, a1);
}

// public void java.lang.String.getChars(int,int,char[],int)
void JavaLangString::getChars(jint a0, jint a1, const jnipp::Ref<jnipp::Array<jchar>>& a2, jint a3) const {
    static jnipp::Method<void,jint,jint,jnipp::Array<jchar>,jint> method(clazz(), "getChars", "(II[CI)V");
    method.call(*this, a0, a1, a2, a3);
}

// public byte[] java.lang.String.getBytes()
jnipp::LocalRef<jnipp::Array<jbyte>> JavaLangString::getBytes() const {
    static jnipp::Method<jnipp::Array<jbyte>> method(clazz(), "getBytes", "()[B");
    return method.call(*this);
}

// public byte[] java.lang.String.getBytes(java.lang.String) throws java.io.UnsupportedEncodingException
jnipp::LocalRef<jnipp::Array<jbyte>> JavaLangString::getBytes(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jnipp::Array<jbyte>,JavaLangString> method(clazz(), "getBytes", "(Ljava/lang/String;)[B");
    return method.call(*this, a0);
}

// public void java.lang.String.getBytes(int,int,byte[],int)
void JavaLangString::getBytes(jint a0, jint a1, const jnipp::Ref<jnipp::Array<jbyte>>& a2, jint a3) const {
    static jnipp::Method<void,jint,jint,jnipp::Array<jbyte>,jint> method(clazz(), "getBytes", "(II[BI)V");
    method.call(*this, a0, a1, a2, a3);
}

// public byte[] java.lang.String.getBytes(java.nio.charset.Charset)
jnipp::LocalRef<jnipp::Array<jbyte>> JavaLangString::getBytes(const jnipp::Ref<JavaNioCharsetCharset>& a0) const {
    static jnipp::Method<jnipp::Array<jbyte>,JavaNioCharsetCharset> method(clazz(), "getBytes", "(Ljava/nio/charset/Charset;)[B");
    return method.call(*this, a0);
}

// public boolean java.lang.String.contentEquals(java.lang.StringBuffer)
jboolean JavaLangString::contentEquals(const jnipp::Ref<JavaLangStringBuffer>& a0) const {
    static jnipp::Method<jboolean,JavaLangStringBuffer> method(clazz(), "contentEquals", "(Ljava/lang/StringBuffer;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.String.contentEquals(java.lang.CharSequence)
jboolean JavaLangString::contentEquals(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<jboolean,JavaLangCharSequence> method(clazz(), "contentEquals", "(Ljava/lang/CharSequence;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.String.equalsIgnoreCase(java.lang.String)
jboolean JavaLangString::equalsIgnoreCase(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "equalsIgnoreCase", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public int java.lang.String.compareToIgnoreCase(java.lang.String)
jint JavaLangString::compareToIgnoreCase(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "compareToIgnoreCase", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public boolean java.lang.String.regionMatches(int,java.lang.String,int,int)
jboolean JavaLangString::regionMatches(jint a0, const jnipp::Ref<JavaLangString>& a1, jint a2, jint a3) const {
    static jnipp::Method<jboolean,jint,JavaLangString,jint,jint> method(clazz(), "regionMatches", "(ILjava/lang/String;II)Z");
    return method.call(*this, a0, a1, a2, a3);
}

// public boolean java.lang.String.regionMatches(boolean,int,java.lang.String,int,int)
jboolean JavaLangString::regionMatches(jboolean a0, jint a1, const jnipp::Ref<JavaLangString>& a2, jint a3, jint a4) const {
    static jnipp::Method<jboolean,jboolean,jint,JavaLangString,jint,jint> method(clazz(), "regionMatches", "(ZILjava/lang/String;II)Z");
    return method.call(*this, a0, a1, a2, a3, a4);
}

// public boolean java.lang.String.startsWith(java.lang.String)
jboolean JavaLangString::startsWith(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "startsWith", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.String.startsWith(java.lang.String,int)
jboolean JavaLangString::startsWith(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jboolean,JavaLangString,jint> method(clazz(), "startsWith", "(Ljava/lang/String;I)Z");
    return method.call(*this, a0, a1);
}

// public boolean java.lang.String.endsWith(java.lang.String)
jboolean JavaLangString::endsWith(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "endsWith", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public int java.lang.String.lastIndexOf(int,int)
jint JavaLangString::lastIndexOf(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "lastIndexOf", "(II)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.String.lastIndexOf(java.lang.String,int)
jint JavaLangString::lastIndexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.String.lastIndexOf(int)
jint JavaLangString::lastIndexOf(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "lastIndexOf", "(I)I");
    return method.call(*this, a0);
}

// public int java.lang.String.lastIndexOf(java.lang.String)
jint JavaLangString::lastIndexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "lastIndexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.substring(int)
jnipp::LocalRef<JavaLangString> JavaLangString::substring(jint a0) const {
    static jnipp::Method<JavaLangString,jint> method(clazz(), "substring", "(I)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.substring(int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::substring(jint a0, jint a1) const {
    static jnipp::Method<JavaLangString,jint,jint> method(clazz(), "substring", "(II)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.CharSequence java.lang.String.subSequence(int,int)
jnipp::LocalRef<JavaLangCharSequence> JavaLangString::subSequence(jint a0, jint a1) const {
    static jnipp::Method<JavaLangCharSequence,jint,jint> method(clazz(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return method.call(*this, a0, a1);
}

// public java.lang.String java.lang.String.concat(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaLangString::concat(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangString> method(clazz(), "concat", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.replace(char,char)
jnipp::LocalRef<JavaLangString> JavaLangString::replace(jchar a0, jchar a1) const {
    static jnipp::Method<JavaLangString,jchar,jchar> method(clazz(), "replace", "(CC)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.String java.lang.String.replace(java.lang.CharSequence,java.lang.CharSequence)
jnipp::LocalRef<JavaLangString> JavaLangString::replace(const jnipp::Ref<JavaLangCharSequence>& a0, const jnipp::Ref<JavaLangCharSequence>& a1) const {
    static jnipp::Method<JavaLangString,JavaLangCharSequence,JavaLangCharSequence> method(clazz(), "replace", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public boolean java.lang.String.matches(java.lang.String)
jboolean JavaLangString::matches(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "matches", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.String.contains(java.lang.CharSequence)
jboolean JavaLangString::contains(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<jboolean,JavaLangCharSequence> method(clazz(), "contains", "(Ljava/lang/CharSequence;)Z");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.replaceFirst(java.lang.String,java.lang.String)
jnipp::LocalRef<JavaLangString> JavaLangString::replaceFirst(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<JavaLangString,JavaLangString,JavaLangString> method(clazz(), "replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.String java.lang.String.replaceAll(java.lang.String,java.lang.String)
jnipp::LocalRef<JavaLangString> JavaLangString::replaceAll(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<JavaLangString,JavaLangString,JavaLangString> method(clazz(), "replaceAll", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.String[] java.lang.String.split(java.lang.String,int)
jnipp::LocalRef<jnipp::Array<JavaLangString>> JavaLangString::split(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jnipp::Array<JavaLangString>,JavaLangString,jint> method(clazz(), "split", "(Ljava/lang/String;I)[Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.String[] java.lang.String.split(java.lang.String)
jnipp::LocalRef<jnipp::Array<JavaLangString>> JavaLangString::split(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jnipp::Array<JavaLangString>,JavaLangString> method(clazz(), "split", "(Ljava/lang/String;)[Ljava/lang/String;");
    return method.call(*this, a0);
}

// public static java.lang.String java.lang.String.join(java.lang.CharSequence,java.lang.CharSequence[])
jnipp::LocalRef<JavaLangString> JavaLangString::join(const jnipp::Ref<JavaLangCharSequence>& a0, const jnipp::Ref<jnipp::Array<JavaLangCharSequence>>& a1) {
    static jnipp::StaticMethod<JavaLangString,JavaLangCharSequence,jnipp::Array<JavaLangCharSequence>> method(clazz(), "join", "(Ljava/lang/CharSequence;[Ljava/lang/CharSequence;)Ljava/lang/String;");
    return method.call(a0, a1);
}

// public static java.lang.String java.lang.String.join(java.lang.CharSequence,java.lang.Iterable)
jnipp::LocalRef<JavaLangString> JavaLangString::join(const jnipp::Ref<JavaLangCharSequence>& a0, const jnipp::Ref<JavaLangIterable>& a1) {
    static jnipp::StaticMethod<JavaLangString,JavaLangCharSequence,JavaLangIterable> method(clazz(), "join", "(Ljava/lang/CharSequence;Ljava/lang/Iterable;)Ljava/lang/String;");
    return method.call(a0, a1);
}

// public java.lang.String java.lang.String.toLowerCase(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaLangString::toLowerCase(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "toLowerCase", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.toLowerCase()
jnipp::LocalRef<JavaLangString> JavaLangString::toLowerCase() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toLowerCase", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.String.toUpperCase()
jnipp::LocalRef<JavaLangString> JavaLangString::toUpperCase() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toUpperCase", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.String.toUpperCase(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaLangString::toUpperCase(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "toUpperCase", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.trim()
jnipp::LocalRef<JavaLangString> JavaLangString::trim() const {
    static jnipp::Method<JavaLangString> method(clazz(), "trim", "()Ljava/lang/String;");
    return method.call(*this);
}

// public char[] java.lang.String.toCharArray()
jnipp::LocalRef<jnipp::Array<jchar>> JavaLangString::toCharArray() const {
    static jnipp::Method<jnipp::Array<jchar>> method(clazz(), "toCharArray", "()[C");
    return method.call(*this);
}

// public static java.lang.String java.lang.String.format(java.util.Locale,java.lang.String,java.lang.Object[])
jnipp::LocalRef<JavaLangString> JavaLangString::format(const jnipp::Ref<JavaUtilLocale>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<jnipp::Array<JavaLangObject>>& a2) {
    static jnipp::StaticMethod<JavaLangString,JavaUtilLocale,JavaLangString,jnipp::Array<JavaLangObject>> method(clazz(), "format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
    return method.call(a0, a1, a2);
}

// public static java.lang.String java.lang.String.format(java.lang.String,java.lang.Object[])
jnipp::LocalRef<JavaLangString> JavaLangString::format(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<jnipp::Array<JavaLangObject>>& a1) {
    static jnipp::StaticMethod<JavaLangString,JavaLangString,jnipp::Array<JavaLangObject>> method(clazz(), "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
    return method.call(a0, a1);
}

// public static java.lang.String java.lang.String.copyValueOf(char[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::copyValueOf(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<JavaLangString,jnipp::Array<jchar>,jint,jint> method(clazz(), "copyValueOf", "([CII)Ljava/lang/String;");
    return method.call(a0, a1, a2);
}

// public static java.lang.String java.lang.String.copyValueOf(char[])
jnipp::LocalRef<JavaLangString> JavaLangString::copyValueOf(const jnipp::Ref<jnipp::Array<jchar>>& a0) {
    static jnipp::StaticMethod<JavaLangString,jnipp::Array<jchar>> method(clazz(), "copyValueOf", "([C)Ljava/lang/String;");
    return method.call(a0);
}

// public native java.lang.String java.lang.String.intern()
jnipp::LocalRef<JavaLangString> JavaLangString::intern() const {
    static jnipp::Method<JavaLangString> method(clazz(), "intern", "()Ljava/lang/String;");
    return method.call(*this);
}
#undef CASE_INSENSITIVE_ORDER
const jnipp::StaticField<JavaUtilComparator> JavaLangString::CASE_INSENSITIVE_ORDER ("java/lang/String", "CASE_INSENSITIVE_ORDER", "Ljava/util/Comparator;");
jnipp::GlobalRef<jnipp::Class>& JavaTest::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("JavaTest"));
    return cls;
}

// public JavaTest()
jnipp::LocalRef<JavaTest> JavaTest::construct() {
    static jnipp::Constructor<JavaTest> constructor(clazz(), "()V");
    return constructor.construct();
}
#undef staticObject
jnipp::StaticField<JavaLangObject> JavaTest::staticObject ("JavaTest", "staticObject", "Ljava/lang/Object;");
#undef staticInt
jnipp::StaticField<jint> JavaTest::staticInt ("JavaTest", "staticInt", "I");
jnipp::GlobalRef<jnipp::Class>& JavaLangAbstractStringBuilder::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/AbstractStringBuilder"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaLangStringBuffer::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/StringBuffer"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaLangCharSequence::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/CharSequence"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaLangStringBuilder::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/StringBuilder"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaUtilComparator::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Comparator"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaUtilLocale::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Locale"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaNioCharsetCharset::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/nio/charset/Charset"));
    return cls;
}
jnipp::GlobalRef<jnipp::Class>& JavaLangIterable::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Iterable"));
    return cls;
}

