#include "_java.h"

inline jnipp::GlobalRef<jnipp::Class>& JavaLangObject::clazz() {
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
inline jnipp::GlobalRef<jnipp::Class>& JavaLangString::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/String"));
    return cls;
}

// public java.lang.String(byte[])
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>> constructor(clazz(), "([B)V");
    return constructor.construct(a0);
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

// java.lang.String(int,int,char[])
jnipp::LocalRef<JavaLangString> JavaLangString::construct(jint a0, jint a1, const jnipp::Ref<jnipp::Array<jchar>>& a2) {
    static jnipp::Constructor<JavaLangString,jint,jint,jnipp::Array<jchar>> constructor(clazz(), "(II[C)V");
    return constructor.construct(a0, a1, a2);
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

// public java.lang.String(int[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jint>>& a0, jint a1, jint a2) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jint>,jint,jint> constructor(clazz(), "([III)V");
    return constructor.construct(a0, a1, a2);
}

// public java.lang.String(char[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jchar>,jint,jint> constructor(clazz(), "([CII)V");
    return constructor.construct(a0, a1, a2);
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

// public java.lang.String()
jnipp::LocalRef<JavaLangString> JavaLangString::construct() {
    static jnipp::Constructor<JavaLangString> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.lang.String(byte[],int,int,java.lang.String) throws java.io.UnsupportedEncodingException
jnipp::LocalRef<JavaLangString> JavaLangString::construct(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2, const jnipp::Ref<JavaLangString>& a3) {
    static jnipp::Constructor<JavaLangString,jnipp::Array<jbyte>,jint,jint,JavaLangString> constructor(clazz(), "([BIILjava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3);
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

// public int java.lang.String.indexOf(java.lang.String)
jint JavaLangString::indexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "indexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public int java.lang.String.indexOf(int)
jint JavaLangString::indexOf(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "indexOf", "(I)I");
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

// public static java.lang.String java.lang.String.valueOf(long)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jlong a0) {
    static jnipp::StaticMethod<JavaLangString,jlong> method(clazz(), "valueOf", "(J)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(float)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jfloat a0) {
    static jnipp::StaticMethod<JavaLangString,jfloat> method(clazz(), "valueOf", "(F)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(int)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jint a0) {
    static jnipp::StaticMethod<JavaLangString,jint> method(clazz(), "valueOf", "(I)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.valueOf(double)
jnipp::LocalRef<JavaLangString> JavaLangString::valueOf(jdouble a0) {
    static jnipp::StaticMethod<JavaLangString,jdouble> method(clazz(), "valueOf", "(D)Ljava/lang/String;");
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

// public byte[] java.lang.String.getBytes()
jnipp::LocalRef<jnipp::Array<jbyte>> JavaLangString::getBytes() const {
    static jnipp::Method<jnipp::Array<jbyte>> method(clazz(), "getBytes", "()[B");
    return method.call(*this);
}

// public boolean java.lang.String.contentEquals(java.lang.CharSequence)
jboolean JavaLangString::contentEquals(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<jboolean,JavaLangCharSequence> method(clazz(), "contentEquals", "(Ljava/lang/CharSequence;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.String.contentEquals(java.lang.StringBuffer)
jboolean JavaLangString::contentEquals(const jnipp::Ref<JavaLangStringBuffer>& a0) const {
    static jnipp::Method<jboolean,JavaLangStringBuffer> method(clazz(), "contentEquals", "(Ljava/lang/StringBuffer;)Z");
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

// public boolean java.lang.String.regionMatches(boolean,int,java.lang.String,int,int)
jboolean JavaLangString::regionMatches(jboolean a0, jint a1, const jnipp::Ref<JavaLangString>& a2, jint a3, jint a4) const {
    static jnipp::Method<jboolean,jboolean,jint,JavaLangString,jint,jint> method(clazz(), "regionMatches", "(ZILjava/lang/String;II)Z");
    return method.call(*this, a0, a1, a2, a3, a4);
}

// public boolean java.lang.String.regionMatches(int,java.lang.String,int,int)
jboolean JavaLangString::regionMatches(jint a0, const jnipp::Ref<JavaLangString>& a1, jint a2, jint a3) const {
    static jnipp::Method<jboolean,jint,JavaLangString,jint,jint> method(clazz(), "regionMatches", "(ILjava/lang/String;II)Z");
    return method.call(*this, a0, a1, a2, a3);
}

// public boolean java.lang.String.startsWith(java.lang.String,int)
jboolean JavaLangString::startsWith(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jboolean,JavaLangString,jint> method(clazz(), "startsWith", "(Ljava/lang/String;I)Z");
    return method.call(*this, a0, a1);
}

// public boolean java.lang.String.startsWith(java.lang.String)
jboolean JavaLangString::startsWith(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "startsWith", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.String.endsWith(java.lang.String)
jboolean JavaLangString::endsWith(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "endsWith", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public int java.lang.String.lastIndexOf(java.lang.String)
jint JavaLangString::lastIndexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "lastIndexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
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

// public int java.lang.String.lastIndexOf(int,int)
jint JavaLangString::lastIndexOf(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "lastIndexOf", "(II)I");
    return method.call(*this, a0, a1);
}

// public java.lang.String java.lang.String.substring(int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::substring(jint a0, jint a1) const {
    static jnipp::Method<JavaLangString,jint,jint> method(clazz(), "substring", "(II)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.String java.lang.String.substring(int)
jnipp::LocalRef<JavaLangString> JavaLangString::substring(jint a0) const {
    static jnipp::Method<JavaLangString,jint> method(clazz(), "substring", "(I)Ljava/lang/String;");
    return method.call(*this, a0);
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

// public java.lang.String[] java.lang.String.split(java.lang.String)
jnipp::LocalRef<jnipp::Array<JavaLangString>> JavaLangString::split(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jnipp::Array<JavaLangString>,JavaLangString> method(clazz(), "split", "(Ljava/lang/String;)[Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String[] java.lang.String.split(java.lang.String,int)
jnipp::LocalRef<jnipp::Array<JavaLangString>> JavaLangString::split(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jnipp::Array<JavaLangString>,JavaLangString,jint> method(clazz(), "split", "(Ljava/lang/String;I)[Ljava/lang/String;");
    return method.call(*this, a0, a1);
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

// public java.lang.String java.lang.String.toUpperCase(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaLangString::toUpperCase(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "toUpperCase", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.String.toUpperCase()
jnipp::LocalRef<JavaLangString> JavaLangString::toUpperCase() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toUpperCase", "()Ljava/lang/String;");
    return method.call(*this);
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

// public static java.lang.String java.lang.String.format(java.lang.String,java.lang.Object[])
jnipp::LocalRef<JavaLangString> JavaLangString::format(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<jnipp::Array<JavaLangObject>>& a1) {
    static jnipp::StaticMethod<JavaLangString,JavaLangString,jnipp::Array<JavaLangObject>> method(clazz(), "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
    return method.call(a0, a1);
}

// public static java.lang.String java.lang.String.format(java.util.Locale,java.lang.String,java.lang.Object[])
jnipp::LocalRef<JavaLangString> JavaLangString::format(const jnipp::Ref<JavaUtilLocale>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<jnipp::Array<JavaLangObject>>& a2) {
    static jnipp::StaticMethod<JavaLangString,JavaUtilLocale,JavaLangString,jnipp::Array<JavaLangObject>> method(clazz(), "format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
    return method.call(a0, a1, a2);
}

// public static java.lang.String java.lang.String.copyValueOf(char[])
jnipp::LocalRef<JavaLangString> JavaLangString::copyValueOf(const jnipp::Ref<jnipp::Array<jchar>>& a0) {
    static jnipp::StaticMethod<JavaLangString,jnipp::Array<jchar>> method(clazz(), "copyValueOf", "([C)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.lang.String.copyValueOf(char[],int,int)
jnipp::LocalRef<JavaLangString> JavaLangString::copyValueOf(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<JavaLangString,jnipp::Array<jchar>,jint,jint> method(clazz(), "copyValueOf", "([CII)Ljava/lang/String;");
    return method.call(a0, a1, a2);
}

// public native java.lang.String java.lang.String.intern()
jnipp::LocalRef<JavaLangString> JavaLangString::intern() const {
    static jnipp::Method<JavaLangString> method(clazz(), "intern", "()Ljava/lang/String;");
    return method.call(*this);
}
const jnipp::StaticField<JavaUtilComparator> JavaLangString::CASE_INSENSITIVE_ORDER ("java/lang/String", "CASE_INSENSITIVE_ORDER", "Ljava/util/Comparator;");
inline jnipp::GlobalRef<jnipp::Class>& JavaLangAbstractStringBuilder::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/AbstractStringBuilder"));
    return cls;
}

// java.lang.AbstractStringBuilder()
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::construct() {
    static jnipp::Constructor<JavaLangAbstractStringBuilder> constructor(clazz(), "()V");
    return constructor.construct();
}

// java.lang.AbstractStringBuilder(int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::construct(jint a0) {
    static jnipp::Constructor<JavaLangAbstractStringBuilder,jint> constructor(clazz(), "(I)V");
    return constructor.construct(a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(char[],int,int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jnipp::Array<jchar>,jint,jint> method(clazz(), "append", "([CII)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1, a2);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(char[])
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<jnipp::Array<jchar>>& a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jnipp::Array<jchar>> method(clazz(), "append", "([C)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(boolean)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(jboolean a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jboolean> method(clazz(), "append", "(Z)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(char)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(jchar a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jchar> method(clazz(), "append", "(C)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(java.lang.String)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,JavaLangString> method(clazz(), "append", "(Ljava/lang/String;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(java.lang.StringBuffer)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<JavaLangStringBuffer>& a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,JavaLangStringBuffer> method(clazz(), "append", "(Ljava/lang/StringBuffer;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(java.lang.CharSequence)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,JavaLangCharSequence> method(clazz(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,JavaLangCharSequence,jint,jint> method(clazz(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1, a2);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(double)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(jdouble a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jdouble> method(clazz(), "append", "(D)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(float)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(jfloat a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jfloat> method(clazz(), "append", "(F)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(long)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(jlong a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jlong> method(clazz(), "append", "(J)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(jint a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint> method(clazz(), "append", "(I)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.append(java.lang.Object)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::append(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,JavaLangObject> method(clazz(), "append", "(Ljava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public int java.lang.AbstractStringBuilder.indexOf(java.lang.String,int)
jint JavaLangAbstractStringBuilder::indexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "indexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.AbstractStringBuilder.indexOf(java.lang.String)
jint JavaLangAbstractStringBuilder::indexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "indexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public int java.lang.AbstractStringBuilder.length()
jint JavaLangAbstractStringBuilder::length() const {
    static jnipp::Method<jint> method(clazz(), "length", "()I");
    return method.call(*this);
}

// public char java.lang.AbstractStringBuilder.charAt(int)
jchar JavaLangAbstractStringBuilder::charAt(jint a0) const {
    static jnipp::Method<jchar,jint> method(clazz(), "charAt", "(I)C");
    return method.call(*this, a0);
}

// public int java.lang.AbstractStringBuilder.codePointAt(int)
jint JavaLangAbstractStringBuilder::codePointAt(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "codePointAt", "(I)I");
    return method.call(*this, a0);
}

// public int java.lang.AbstractStringBuilder.codePointBefore(int)
jint JavaLangAbstractStringBuilder::codePointBefore(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "codePointBefore", "(I)I");
    return method.call(*this, a0);
}

// public int java.lang.AbstractStringBuilder.codePointCount(int,int)
jint JavaLangAbstractStringBuilder::codePointCount(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "codePointCount", "(II)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.AbstractStringBuilder.offsetByCodePoints(int,int)
jint JavaLangAbstractStringBuilder::offsetByCodePoints(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "offsetByCodePoints", "(II)I");
    return method.call(*this, a0, a1);
}

// public void java.lang.AbstractStringBuilder.getChars(int,int,char[],int)
void JavaLangAbstractStringBuilder::getChars(jint a0, jint a1, const jnipp::Ref<jnipp::Array<jchar>>& a2, jint a3) const {
    static jnipp::Method<void,jint,jint,jnipp::Array<jchar>,jint> method(clazz(), "getChars", "(II[CI)V");
    method.call(*this, a0, a1, a2, a3);
}

// public int java.lang.AbstractStringBuilder.lastIndexOf(java.lang.String,int)
jint JavaLangAbstractStringBuilder::lastIndexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.AbstractStringBuilder.lastIndexOf(java.lang.String)
jint JavaLangAbstractStringBuilder::lastIndexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "lastIndexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.AbstractStringBuilder.substring(int)
jnipp::LocalRef<JavaLangString> JavaLangAbstractStringBuilder::substring(jint a0) const {
    static jnipp::Method<JavaLangString,jint> method(clazz(), "substring", "(I)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.AbstractStringBuilder.substring(int,int)
jnipp::LocalRef<JavaLangString> JavaLangAbstractStringBuilder::substring(jint a0, jint a1) const {
    static jnipp::Method<JavaLangString,jint,jint> method(clazz(), "substring", "(II)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public java.lang.CharSequence java.lang.AbstractStringBuilder.subSequence(int,int)
jnipp::LocalRef<JavaLangCharSequence> JavaLangAbstractStringBuilder::subSequence(jint a0, jint a1) const {
    static jnipp::Method<JavaLangCharSequence,jint,jint> method(clazz(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.replace(int,int,java.lang.String)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::replace(jint a0, jint a1, const jnipp::Ref<JavaLangString>& a2) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jint,JavaLangString> method(clazz(), "replace", "(IILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1, a2);
}

// public int java.lang.AbstractStringBuilder.capacity()
jint JavaLangAbstractStringBuilder::capacity() const {
    static jnipp::Method<jint> method(clazz(), "capacity", "()I");
    return method.call(*this);
}

// public void java.lang.AbstractStringBuilder.ensureCapacity(int)
void JavaLangAbstractStringBuilder::ensureCapacity(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "ensureCapacity", "(I)V");
    method.call(*this, a0);
}

// public void java.lang.AbstractStringBuilder.trimToSize()
void JavaLangAbstractStringBuilder::trimToSize() const {
    static jnipp::Method<void> method(clazz(), "trimToSize", "()V");
    method.call(*this);
}

// public void java.lang.AbstractStringBuilder.setLength(int)
void JavaLangAbstractStringBuilder::setLength(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setLength", "(I)V");
    method.call(*this, a0);
}

// public void java.lang.AbstractStringBuilder.setCharAt(int,char)
void JavaLangAbstractStringBuilder::setCharAt(jint a0, jchar a1) const {
    static jnipp::Method<void,jint,jchar> method(clazz(), "setCharAt", "(IC)V");
    method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.appendCodePoint(int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::appendCodePoint(jint a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint> method(clazz(), "appendCodePoint", "(I)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.delete(int,int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::delete_(jint a0, jint a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jint> method(clazz(), "delete", "(II)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.deleteCharAt(int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::deleteCharAt(jint a0) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint> method(clazz(), "deleteCharAt", "(I)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,java.lang.CharSequence)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangCharSequence>& a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,JavaLangCharSequence> method(clazz(), "insert", "(ILjava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,char[])
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jnipp::Array<jchar>> method(clazz(), "insert", "(I[C)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,java.lang.Object)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangObject>& a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,JavaLangObject> method(clazz(), "insert", "(ILjava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,char[],int,int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1, jint a2, jint a3) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jnipp::Array<jchar>,jint,jint> method(clazz(), "insert", "(I[CII)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1, a2, a3);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,java.lang.String)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,JavaLangString> method(clazz(), "insert", "(ILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, jint a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jint> method(clazz(), "insert", "(II)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,char)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, jchar a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jchar> method(clazz(), "insert", "(IC)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,boolean)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, jboolean a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jboolean> method(clazz(), "insert", "(IZ)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangCharSequence>& a1, jint a2, jint a3) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,JavaLangCharSequence,jint,jint> method(clazz(), "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1, a2, a3);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,float)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, jfloat a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jfloat> method(clazz(), "insert", "(IF)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,long)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, jlong a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jlong> method(clazz(), "insert", "(IJ)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.insert(int,double)
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::insert(jint a0, jdouble a1) const {
    static jnipp::Method<JavaLangAbstractStringBuilder,jint,jdouble> method(clazz(), "insert", "(ID)Ljava/lang/AbstractStringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.AbstractStringBuilder java.lang.AbstractStringBuilder.reverse()
jnipp::LocalRef<JavaLangAbstractStringBuilder> JavaLangAbstractStringBuilder::reverse() const {
    static jnipp::Method<JavaLangAbstractStringBuilder> method(clazz(), "reverse", "()Ljava/lang/AbstractStringBuilder;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangStringBuilder::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/StringBuilder"));
    return cls;
}

// public java.lang.StringBuilder(java.lang.CharSequence)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::construct(const jnipp::Ref<JavaLangCharSequence>& a0) {
    static jnipp::Constructor<JavaLangStringBuilder,JavaLangCharSequence> constructor(clazz(), "(Ljava/lang/CharSequence;)V");
    return constructor.construct(a0);
}

// public java.lang.StringBuilder(java.lang.String)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaLangStringBuilder,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.lang.StringBuilder(int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::construct(jint a0) {
    static jnipp::Constructor<JavaLangStringBuilder,jint> constructor(clazz(), "(I)V");
    return constructor.construct(a0);
}

// public java.lang.StringBuilder()
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::construct() {
    static jnipp::Constructor<JavaLangStringBuilder> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(char[])
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<jnipp::Array<jchar>>& a0) const {
    static jnipp::Method<JavaLangStringBuilder,jnipp::Array<jchar>> method(clazz(), "append", "([C)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(char[],int,int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaLangStringBuilder,jnipp::Array<jchar>,jint,jint> method(clazz(), "append", "([CII)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1, a2);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(boolean)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(jboolean a0) const {
    static jnipp::Method<JavaLangStringBuilder,jboolean> method(clazz(), "append", "(Z)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(java.lang.StringBuffer)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<JavaLangStringBuffer>& a0) const {
    static jnipp::Method<JavaLangStringBuilder,JavaLangStringBuffer> method(clazz(), "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(java.lang.CharSequence)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<JavaLangStringBuilder,JavaLangCharSequence> method(clazz(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaLangStringBuilder,JavaLangCharSequence,jint,jint> method(clazz(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1, a2);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(float)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(jfloat a0) const {
    static jnipp::Method<JavaLangStringBuilder,jfloat> method(clazz(), "append", "(F)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(java.lang.String)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangStringBuilder,JavaLangString> method(clazz(), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(java.lang.Object)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangStringBuilder,JavaLangObject> method(clazz(), "append", "(Ljava/lang/Object;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(double)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(jdouble a0) const {
    static jnipp::Method<JavaLangStringBuilder,jdouble> method(clazz(), "append", "(D)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(char)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(jchar a0) const {
    static jnipp::Method<JavaLangStringBuilder,jchar> method(clazz(), "append", "(C)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(jint a0) const {
    static jnipp::Method<JavaLangStringBuilder,jint> method(clazz(), "append", "(I)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.append(long)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::append(jlong a0) const {
    static jnipp::Method<JavaLangStringBuilder,jlong> method(clazz(), "append", "(J)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public int java.lang.StringBuilder.indexOf(java.lang.String,int)
jint JavaLangStringBuilder::indexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "indexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.StringBuilder.indexOf(java.lang.String)
jint JavaLangStringBuilder::indexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "indexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public int java.lang.StringBuilder.lastIndexOf(java.lang.String)
jint JavaLangStringBuilder::lastIndexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "lastIndexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public int java.lang.StringBuilder.lastIndexOf(java.lang.String,int)
jint JavaLangStringBuilder::lastIndexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.replace(int,int,java.lang.String)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::replace(jint a0, jint a1, const jnipp::Ref<JavaLangString>& a2) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jint,JavaLangString> method(clazz(), "replace", "(IILjava/lang/String;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1, a2);
}

// public java.lang.StringBuilder java.lang.StringBuilder.appendCodePoint(int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::appendCodePoint(jint a0) const {
    static jnipp::Method<JavaLangStringBuilder,jint> method(clazz(), "appendCodePoint", "(I)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.delete(int,int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::delete_(jint a0, jint a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jint> method(clazz(), "delete", "(II)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.deleteCharAt(int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::deleteCharAt(jint a0) const {
    static jnipp::Method<JavaLangStringBuilder,jint> method(clazz(), "deleteCharAt", "(I)Ljava/lang/StringBuilder;");
    return method.call(*this, a0);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,char)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, jchar a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jchar> method(clazz(), "insert", "(IC)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,boolean)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, jboolean a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jboolean> method(clazz(), "insert", "(IZ)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,char[],int,int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1, jint a2, jint a3) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jnipp::Array<jchar>,jint,jint> method(clazz(), "insert", "(I[CII)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1, a2, a3);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, jint a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jint> method(clazz(), "insert", "(II)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,long)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, jlong a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jlong> method(clazz(), "insert", "(IJ)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,java.lang.String)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,JavaLangString> method(clazz(), "insert", "(ILjava/lang/String;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,char[])
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jnipp::Array<jchar>> method(clazz(), "insert", "(I[C)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,java.lang.CharSequence)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangCharSequence>& a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,JavaLangCharSequence> method(clazz(), "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangCharSequence>& a1, jint a2, jint a3) const {
    static jnipp::Method<JavaLangStringBuilder,jint,JavaLangCharSequence,jint,jint> method(clazz(), "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1, a2, a3);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,java.lang.Object)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, const jnipp::Ref<JavaLangObject>& a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,JavaLangObject> method(clazz(), "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,float)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, jfloat a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jfloat> method(clazz(), "insert", "(IF)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.insert(int,double)
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::insert(jint a0, jdouble a1) const {
    static jnipp::Method<JavaLangStringBuilder,jint,jdouble> method(clazz(), "insert", "(ID)Ljava/lang/StringBuilder;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuilder java.lang.StringBuilder.reverse()
jnipp::LocalRef<JavaLangStringBuilder> JavaLangStringBuilder::reverse() const {
    static jnipp::Method<JavaLangStringBuilder> method(clazz(), "reverse", "()Ljava/lang/StringBuilder;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangStringBuffer::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/StringBuffer"));
    return cls;
}

// public java.lang.StringBuffer(java.lang.CharSequence)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::construct(const jnipp::Ref<JavaLangCharSequence>& a0) {
    static jnipp::Constructor<JavaLangStringBuffer,JavaLangCharSequence> constructor(clazz(), "(Ljava/lang/CharSequence;)V");
    return constructor.construct(a0);
}

// public java.lang.StringBuffer(java.lang.String)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaLangStringBuffer,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.lang.StringBuffer(int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::construct(jint a0) {
    static jnipp::Constructor<JavaLangStringBuffer,jint> constructor(clazz(), "(I)V");
    return constructor.construct(a0);
}

// public java.lang.StringBuffer()
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::construct() {
    static jnipp::Constructor<JavaLangStringBuffer> constructor(clazz(), "()V");
    return constructor.construct();
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(float)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(jfloat a0) const {
    static jnipp::Method<JavaLangStringBuffer,jfloat> method(clazz(), "append", "(F)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(boolean)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(jboolean a0) const {
    static jnipp::Method<JavaLangStringBuffer,jboolean> method(clazz(), "append", "(Z)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(char)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(jchar a0) const {
    static jnipp::Method<JavaLangStringBuffer,jchar> method(clazz(), "append", "(C)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(jint a0) const {
    static jnipp::Method<JavaLangStringBuffer,jint> method(clazz(), "append", "(I)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(long)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(jlong a0) const {
    static jnipp::Method<JavaLangStringBuffer,jlong> method(clazz(), "append", "(J)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(java.lang.String)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangStringBuffer,JavaLangString> method(clazz(), "append", "(Ljava/lang/String;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(java.lang.Object)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangStringBuffer,JavaLangObject> method(clazz(), "append", "(Ljava/lang/Object;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(double)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(jdouble a0) const {
    static jnipp::Method<JavaLangStringBuffer,jdouble> method(clazz(), "append", "(D)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public java.lang.StringBuffer java.lang.StringBuffer.append(java.lang.CharSequence)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<JavaLangStringBuffer,JavaLangCharSequence> method(clazz(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaLangStringBuffer,JavaLangCharSequence,jint,jint> method(clazz(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(char[])
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<jnipp::Array<jchar>>& a0) const {
    static jnipp::Method<JavaLangStringBuffer,jnipp::Array<jchar>> method(clazz(), "append", "([C)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(char[],int,int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaLangStringBuffer,jnipp::Array<jchar>,jint,jint> method(clazz(), "append", "([CII)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.append(java.lang.StringBuffer)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::append(const jnipp::Ref<JavaLangStringBuffer>& a0) const {
    static jnipp::Method<JavaLangStringBuffer,JavaLangStringBuffer> method(clazz(), "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public int java.lang.StringBuffer.indexOf(java.lang.String)
jint JavaLangStringBuffer::indexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "indexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public synchronized int java.lang.StringBuffer.indexOf(java.lang.String,int)
jint JavaLangStringBuffer::indexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "indexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public synchronized int java.lang.StringBuffer.length()
jint JavaLangStringBuffer::length() const {
    static jnipp::Method<jint> method(clazz(), "length", "()I");
    return method.call(*this);
}

// public synchronized char java.lang.StringBuffer.charAt(int)
jchar JavaLangStringBuffer::charAt(jint a0) const {
    static jnipp::Method<jchar,jint> method(clazz(), "charAt", "(I)C");
    return method.call(*this, a0);
}

// public synchronized int java.lang.StringBuffer.codePointAt(int)
jint JavaLangStringBuffer::codePointAt(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "codePointAt", "(I)I");
    return method.call(*this, a0);
}

// public synchronized int java.lang.StringBuffer.codePointBefore(int)
jint JavaLangStringBuffer::codePointBefore(jint a0) const {
    static jnipp::Method<jint,jint> method(clazz(), "codePointBefore", "(I)I");
    return method.call(*this, a0);
}

// public synchronized int java.lang.StringBuffer.codePointCount(int,int)
jint JavaLangStringBuffer::codePointCount(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "codePointCount", "(II)I");
    return method.call(*this, a0, a1);
}

// public synchronized int java.lang.StringBuffer.offsetByCodePoints(int,int)
jint JavaLangStringBuffer::offsetByCodePoints(jint a0, jint a1) const {
    static jnipp::Method<jint,jint,jint> method(clazz(), "offsetByCodePoints", "(II)I");
    return method.call(*this, a0, a1);
}

// public synchronized void java.lang.StringBuffer.getChars(int,int,char[],int)
void JavaLangStringBuffer::getChars(jint a0, jint a1, const jnipp::Ref<jnipp::Array<jchar>>& a2, jint a3) const {
    static jnipp::Method<void,jint,jint,jnipp::Array<jchar>,jint> method(clazz(), "getChars", "(II[CI)V");
    method.call(*this, a0, a1, a2, a3);
}

// public synchronized int java.lang.StringBuffer.lastIndexOf(java.lang.String,int)
jint JavaLangStringBuffer::lastIndexOf(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public int java.lang.StringBuffer.lastIndexOf(java.lang.String)
jint JavaLangStringBuffer::lastIndexOf(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jint,JavaLangString> method(clazz(), "lastIndexOf", "(Ljava/lang/String;)I");
    return method.call(*this, a0);
}

// public synchronized java.lang.String java.lang.StringBuffer.substring(int,int)
jnipp::LocalRef<JavaLangString> JavaLangStringBuffer::substring(jint a0, jint a1) const {
    static jnipp::Method<JavaLangString,jint,jint> method(clazz(), "substring", "(II)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.String java.lang.StringBuffer.substring(int)
jnipp::LocalRef<JavaLangString> JavaLangStringBuffer::substring(jint a0) const {
    static jnipp::Method<JavaLangString,jint> method(clazz(), "substring", "(I)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public synchronized java.lang.CharSequence java.lang.StringBuffer.subSequence(int,int)
jnipp::LocalRef<JavaLangCharSequence> JavaLangStringBuffer::subSequence(jint a0, jint a1) const {
    static jnipp::Method<JavaLangCharSequence,jint,jint> method(clazz(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.replace(int,int,java.lang.String)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::replace(jint a0, jint a1, const jnipp::Ref<JavaLangString>& a2) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jint,JavaLangString> method(clazz(), "replace", "(IILjava/lang/String;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public synchronized int java.lang.StringBuffer.capacity()
jint JavaLangStringBuffer::capacity() const {
    static jnipp::Method<jint> method(clazz(), "capacity", "()I");
    return method.call(*this);
}

// public synchronized void java.lang.StringBuffer.ensureCapacity(int)
void JavaLangStringBuffer::ensureCapacity(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "ensureCapacity", "(I)V");
    method.call(*this, a0);
}

// public synchronized void java.lang.StringBuffer.trimToSize()
void JavaLangStringBuffer::trimToSize() const {
    static jnipp::Method<void> method(clazz(), "trimToSize", "()V");
    method.call(*this);
}

// public synchronized void java.lang.StringBuffer.setLength(int)
void JavaLangStringBuffer::setLength(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setLength", "(I)V");
    method.call(*this, a0);
}

// public synchronized void java.lang.StringBuffer.setCharAt(int,char)
void JavaLangStringBuffer::setCharAt(jint a0, jchar a1) const {
    static jnipp::Method<void,jint,jchar> method(clazz(), "setCharAt", "(IC)V");
    method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.appendCodePoint(int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::appendCodePoint(jint a0) const {
    static jnipp::Method<JavaLangStringBuffer,jint> method(clazz(), "appendCodePoint", "(I)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.delete(int,int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::delete_(jint a0, jint a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jint> method(clazz(), "delete", "(II)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.deleteCharAt(int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::deleteCharAt(jint a0) const {
    static jnipp::Method<JavaLangStringBuffer,jint> method(clazz(), "deleteCharAt", "(I)Ljava/lang/StringBuffer;");
    return method.call(*this, a0);
}

// public java.lang.StringBuffer java.lang.StringBuffer.insert(int,long)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, jlong a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jlong> method(clazz(), "insert", "(IJ)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuffer java.lang.StringBuffer.insert(int,boolean)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, jboolean a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jboolean> method(clazz(), "insert", "(IZ)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.insert(int,char)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, jchar a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jchar> method(clazz(), "insert", "(IC)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuffer java.lang.StringBuffer.insert(int,int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, jint a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jint> method(clazz(), "insert", "(II)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuffer java.lang.StringBuffer.insert(int,float)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, jfloat a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jfloat> method(clazz(), "insert", "(IF)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuffer java.lang.StringBuffer.insert(int,double)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, jdouble a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jdouble> method(clazz(), "insert", "(ID)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.insert(int,char[],int,int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1, jint a2, jint a3) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jnipp::Array<jchar>,jint,jint> method(clazz(), "insert", "(I[CII)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1, a2, a3);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.insert(int,java.lang.Object)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, const jnipp::Ref<JavaLangObject>& a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,JavaLangObject> method(clazz(), "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.insert(int,java.lang.String)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,JavaLangString> method(clazz(), "insert", "(ILjava/lang/String;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.insert(int,char[])
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,jnipp::Array<jchar>> method(clazz(), "insert", "(I[C)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public java.lang.StringBuffer java.lang.StringBuffer.insert(int,java.lang.CharSequence)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, const jnipp::Ref<JavaLangCharSequence>& a1) const {
    static jnipp::Method<JavaLangStringBuffer,jint,JavaLangCharSequence> method(clazz(), "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.insert(int,java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::insert(jint a0, const jnipp::Ref<JavaLangCharSequence>& a1, jint a2, jint a3) const {
    static jnipp::Method<JavaLangStringBuffer,jint,JavaLangCharSequence,jint,jint> method(clazz(), "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
    return method.call(*this, a0, a1, a2, a3);
}

// public synchronized java.lang.StringBuffer java.lang.StringBuffer.reverse()
jnipp::LocalRef<JavaLangStringBuffer> JavaLangStringBuffer::reverse() const {
    static jnipp::Method<JavaLangStringBuffer> method(clazz(), "reverse", "()Ljava/lang/StringBuffer;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNioCharsetCharset::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/nio/charset/Charset"));
    return cls;
}

// protected java.nio.charset.Charset(java.lang.String,java.lang.String[])
jnipp::LocalRef<JavaNioCharsetCharset> JavaNioCharsetCharset::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<jnipp::Array<JavaLangString>>& a1) {
    static jnipp::Constructor<JavaNioCharsetCharset,JavaLangString,jnipp::Array<JavaLangString>> constructor(clazz(), "(Ljava/lang/String;[Ljava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public final java.lang.String java.nio.charset.Charset.name()
jnipp::LocalRef<JavaLangString> JavaNioCharsetCharset::name() const {
    static jnipp::Method<JavaLangString> method(clazz(), "name", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static java.nio.charset.Charset java.nio.charset.Charset.forName(java.lang.String)
jnipp::LocalRef<JavaNioCharsetCharset> JavaNioCharsetCharset::forName(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaNioCharsetCharset,JavaLangString> method(clazz(), "forName", "(Ljava/lang/String;)Ljava/nio/charset/Charset;");
    return method.call(a0);
}

// public final boolean java.nio.charset.Charset.equals(java.lang.Object)
jboolean JavaNioCharsetCharset::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public final int java.nio.charset.Charset.hashCode()
jint JavaNioCharsetCharset::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public final int java.nio.charset.Charset.compareTo(java.nio.charset.Charset)
jint JavaNioCharsetCharset::compareTo(const jnipp::Ref<JavaNioCharsetCharset>& a0) const {
    static jnipp::Method<jint,JavaNioCharsetCharset> method(clazz(), "compareTo", "(Ljava/nio/charset/Charset;)I");
    return method.call(*this, a0);
}

// public final java.nio.CharBuffer java.nio.charset.Charset.decode(java.nio.ByteBuffer)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharsetCharset::decode(const jnipp::Ref<JavaNioByteBuffer>& a0) const {
    static jnipp::Method<JavaNioCharBuffer,JavaNioByteBuffer> method(clazz(), "decode", "(Ljava/nio/ByteBuffer;)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public final java.nio.ByteBuffer java.nio.charset.Charset.encode(java.nio.CharBuffer)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioCharsetCharset::encode(const jnipp::Ref<JavaNioCharBuffer>& a0) const {
    static jnipp::Method<JavaNioByteBuffer,JavaNioCharBuffer> method(clazz(), "encode", "(Ljava/nio/CharBuffer;)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0);
}

// public final java.nio.ByteBuffer java.nio.charset.Charset.encode(java.lang.String)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioCharsetCharset::encode(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaNioByteBuffer,JavaLangString> method(clazz(), "encode", "(Ljava/lang/String;)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0);
}

// public final boolean java.nio.charset.Charset.isRegistered()
jboolean JavaNioCharsetCharset::isRegistered() const {
    static jnipp::Method<jboolean> method(clazz(), "isRegistered", "()Z");
    return method.call(*this);
}

// public static java.nio.charset.Charset java.nio.charset.Charset.defaultCharset()
jnipp::LocalRef<JavaNioCharsetCharset> JavaNioCharsetCharset::defaultCharset() {
    static jnipp::StaticMethod<JavaNioCharsetCharset> method(clazz(), "defaultCharset", "()Ljava/nio/charset/Charset;");
    return method.call();
}

// public final java.util.Set java.nio.charset.Charset.aliases()
jnipp::LocalRef<JavaUtilSet> JavaNioCharsetCharset::aliases() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "aliases", "()Ljava/util/Set;");
    return method.call(*this);
}

// public static boolean java.nio.charset.Charset.isSupported(java.lang.String)
jboolean JavaNioCharsetCharset::isSupported(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<jboolean,JavaLangString> method(clazz(), "isSupported", "(Ljava/lang/String;)Z");
    return method.call(a0);
}

// public static java.util.SortedMap java.nio.charset.Charset.availableCharsets()
jnipp::LocalRef<JavaUtilSortedMap> JavaNioCharsetCharset::availableCharsets() {
    static jnipp::StaticMethod<JavaUtilSortedMap> method(clazz(), "availableCharsets", "()Ljava/util/SortedMap;");
    return method.call();
}

// public java.lang.String java.nio.charset.Charset.displayName(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaNioCharsetCharset::displayName(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "displayName", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.nio.charset.Charset.displayName()
jnipp::LocalRef<JavaLangString> JavaNioCharsetCharset::displayName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "displayName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public boolean java.nio.charset.Charset.canEncode()
jboolean JavaNioCharsetCharset::canEncode() const {
    static jnipp::Method<jboolean> method(clazz(), "canEncode", "()Z");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilComparator::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Comparator"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangCharSequence::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/CharSequence"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilLocale::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Locale"));
    return cls;
}

// java.util.Locale(sun.util.locale.BaseLocale,sun.util.locale.LocaleExtensions,java.util.Locale$1)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::construct(const jnipp::Ref<SunUtilLocaleBaseLocale>& a0, const jnipp::Ref<SunUtilLocaleLocaleExtensions>& a1, const jnipp::Ref<JavaUtilLocale_1>& a2) {
    static jnipp::Constructor<JavaUtilLocale,SunUtilLocaleBaseLocale,SunUtilLocaleLocaleExtensions,JavaUtilLocale_1> constructor(clazz(), "(Lsun/util/locale/BaseLocale;Lsun/util/locale/LocaleExtensions;Ljava/util/Locale$1;)V");
    return constructor.construct(a0, a1, a2);
}

// public java.util.Locale(java.lang.String)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaUtilLocale,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.util.Locale(java.lang.String,java.lang.String)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::Constructor<JavaUtilLocale,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public java.util.Locale(java.lang.String,java.lang.String,java.lang.String)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2) {
    static jnipp::Constructor<JavaUtilLocale,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2);
}

// private java.util.Locale(sun.util.locale.BaseLocale,sun.util.locale.LocaleExtensions)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::construct(const jnipp::Ref<SunUtilLocaleBaseLocale>& a0, const jnipp::Ref<SunUtilLocaleLocaleExtensions>& a1) {
    static jnipp::Constructor<JavaUtilLocale,SunUtilLocaleBaseLocale,SunUtilLocaleLocaleExtensions> constructor(clazz(), "(Lsun/util/locale/BaseLocale;Lsun/util/locale/LocaleExtensions;)V");
    return constructor.construct(a0, a1);
}

// public boolean java.util.Locale.equals(java.lang.Object)
jboolean JavaUtilLocale::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.util.Locale.hashCode()
jint JavaUtilLocale::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.Object java.util.Locale.clone()
jnipp::LocalRef<JavaLangObject> JavaUtilLocale::clone() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "clone", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getLanguage()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getLanguage() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getLanguage", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static java.util.Locale java.util.Locale.getDefault(java.util.Locale$Category)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::getDefault(const jnipp::Ref<JavaUtilLocale_Category>& a0) {
    static jnipp::StaticMethod<JavaUtilLocale,JavaUtilLocale_Category> method(clazz(), "getDefault", "(Ljava/util/Locale$Category;)Ljava/util/Locale;");
    return method.call(a0);
}

// public static java.util.Locale java.util.Locale.getDefault()
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::getDefault() {
    static jnipp::StaticMethod<JavaUtilLocale> method(clazz(), "getDefault", "()Ljava/util/Locale;");
    return method.call();
}

// public static synchronized void java.util.Locale.setDefault(java.util.Locale$Category,java.util.Locale)
void JavaUtilLocale::setDefault(const jnipp::Ref<JavaUtilLocale_Category>& a0, const jnipp::Ref<JavaUtilLocale>& a1) {
    static jnipp::StaticMethod<void,JavaUtilLocale_Category,JavaUtilLocale> method(clazz(), "setDefault", "(Ljava/util/Locale$Category;Ljava/util/Locale;)V");
    method.call(a0, a1);
}

// public static synchronized void java.util.Locale.setDefault(java.util.Locale)
void JavaUtilLocale::setDefault(const jnipp::Ref<JavaUtilLocale>& a0) {
    static jnipp::StaticMethod<void,JavaUtilLocale> method(clazz(), "setDefault", "(Ljava/util/Locale;)V");
    method.call(a0);
}

// public static java.util.Locale[] java.util.Locale.getAvailableLocales()
jnipp::LocalRef<jnipp::Array<JavaUtilLocale>> JavaUtilLocale::getAvailableLocales() {
    static jnipp::StaticMethod<jnipp::Array<JavaUtilLocale>> method(clazz(), "getAvailableLocales", "()[Ljava/util/Locale;");
    return method.call();
}

// public static java.lang.String[] java.util.Locale.getISOCountries()
jnipp::LocalRef<jnipp::Array<JavaLangString>> JavaUtilLocale::getISOCountries() {
    static jnipp::StaticMethod<jnipp::Array<JavaLangString>> method(clazz(), "getISOCountries", "()[Ljava/lang/String;");
    return method.call();
}

// public static java.lang.String[] java.util.Locale.getISOLanguages()
jnipp::LocalRef<jnipp::Array<JavaLangString>> JavaUtilLocale::getISOLanguages() {
    static jnipp::StaticMethod<jnipp::Array<JavaLangString>> method(clazz(), "getISOLanguages", "()[Ljava/lang/String;");
    return method.call();
}

// public java.lang.String java.util.Locale.getScript()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getScript() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getScript", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getCountry()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getCountry() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getCountry", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getVariant()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getVariant() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getVariant", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getExtension(char)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getExtension(jchar a0) const {
    static jnipp::Method<JavaLangString,jchar> method(clazz(), "getExtension", "(C)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.util.Set java.util.Locale.getExtensionKeys()
jnipp::LocalRef<JavaUtilSet> JavaUtilLocale::getExtensionKeys() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "getExtensionKeys", "()Ljava/util/Set;");
    return method.call(*this);
}

// public java.util.Set java.util.Locale.getUnicodeLocaleAttributes()
jnipp::LocalRef<JavaUtilSet> JavaUtilLocale::getUnicodeLocaleAttributes() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "getUnicodeLocaleAttributes", "()Ljava/util/Set;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getUnicodeLocaleType(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getUnicodeLocaleType(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangString> method(clazz(), "getUnicodeLocaleType", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.util.Set java.util.Locale.getUnicodeLocaleKeys()
jnipp::LocalRef<JavaUtilSet> JavaUtilLocale::getUnicodeLocaleKeys() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "getUnicodeLocaleKeys", "()Ljava/util/Set;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.toLanguageTag()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::toLanguageTag() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toLanguageTag", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static java.util.Locale java.util.Locale.forLanguageTag(java.lang.String)
jnipp::LocalRef<JavaUtilLocale> JavaUtilLocale::forLanguageTag(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaUtilLocale,JavaLangString> method(clazz(), "forLanguageTag", "(Ljava/lang/String;)Ljava/util/Locale;");
    return method.call(a0);
}

// public java.lang.String java.util.Locale.getISO3Language() throws java.util.MissingResourceException
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getISO3Language() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getISO3Language", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getISO3Country() throws java.util.MissingResourceException
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getISO3Country() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getISO3Country", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getDisplayLanguage(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayLanguage(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "getDisplayLanguage", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public final java.lang.String java.util.Locale.getDisplayLanguage()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayLanguage() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getDisplayLanguage", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getDisplayScript()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayScript() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getDisplayScript", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getDisplayScript(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayScript(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "getDisplayScript", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.util.Locale.getDisplayCountry(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayCountry(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "getDisplayCountry", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public final java.lang.String java.util.Locale.getDisplayCountry()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayCountry() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getDisplayCountry", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getDisplayVariant(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayVariant(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "getDisplayVariant", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public final java.lang.String java.util.Locale.getDisplayVariant()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayVariant() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getDisplayVariant", "()Ljava/lang/String;");
    return method.call(*this);
}

// public final java.lang.String java.util.Locale.getDisplayName()
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getDisplayName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Locale.getDisplayName(java.util.Locale)
jnipp::LocalRef<JavaLangString> JavaUtilLocale::getDisplayName(const jnipp::Ref<JavaUtilLocale>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilLocale> method(clazz(), "getDisplayName", "(Ljava/util/Locale;)Ljava/lang/String;");
    return method.call(*this, a0);
}
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::ENGLISH ("java/util/Locale", "ENGLISH", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::FRENCH ("java/util/Locale", "FRENCH", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::GERMAN ("java/util/Locale", "GERMAN", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::ITALIAN ("java/util/Locale", "ITALIAN", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::JAPANESE ("java/util/Locale", "JAPANESE", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::KOREAN ("java/util/Locale", "KOREAN", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::CHINESE ("java/util/Locale", "CHINESE", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::SIMPLIFIED_CHINESE ("java/util/Locale", "SIMPLIFIED_CHINESE", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::TRADITIONAL_CHINESE ("java/util/Locale", "TRADITIONAL_CHINESE", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::FRANCE ("java/util/Locale", "FRANCE", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::GERMANY ("java/util/Locale", "GERMANY", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::ITALY ("java/util/Locale", "ITALY", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::JAPAN ("java/util/Locale", "JAPAN", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::KOREA ("java/util/Locale", "KOREA", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::CHINA ("java/util/Locale", "CHINA", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::PRC ("java/util/Locale", "PRC", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::TAIWAN ("java/util/Locale", "TAIWAN", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::UK ("java/util/Locale", "UK", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::US ("java/util/Locale", "US", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::CANADA ("java/util/Locale", "CANADA", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::CANADA_FRENCH ("java/util/Locale", "CANADA_FRENCH", "Ljava/util/Locale;");
const jnipp::StaticField<JavaUtilLocale> JavaUtilLocale::ROOT ("java/util/Locale", "ROOT", "Ljava/util/Locale;");
const jnipp::StaticField<jchar> JavaUtilLocale::PRIVATE_USE_EXTENSION ("java/util/Locale", "PRIVATE_USE_EXTENSION", "C");
const jnipp::StaticField<jchar> JavaUtilLocale::UNICODE_LOCALE_EXTENSION ("java/util/Locale", "UNICODE_LOCALE_EXTENSION", "C");
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilSet::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Set"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNioBuffer::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/nio/Buffer"));
    return cls;
}

// java.nio.Buffer(int,int,int,int)
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::construct(jint a0, jint a1, jint a2, jint a3) {
    static jnipp::Constructor<JavaNioBuffer,jint,jint,jint,jint> constructor(clazz(), "(IIII)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public final java.nio.Buffer java.nio.Buffer.limit(int)
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::limit(jint a0) const {
    static jnipp::Method<JavaNioBuffer,jint> method(clazz(), "limit", "(I)Ljava/nio/Buffer;");
    return method.call(*this, a0);
}

// public final int java.nio.Buffer.limit()
jint JavaNioBuffer::limit() const {
    static jnipp::Method<jint> method(clazz(), "limit", "()I");
    return method.call(*this);
}

// public final java.nio.Buffer java.nio.Buffer.clear()
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::clear() const {
    static jnipp::Method<JavaNioBuffer> method(clazz(), "clear", "()Ljava/nio/Buffer;");
    return method.call(*this);
}

// public final int java.nio.Buffer.remaining()
jint JavaNioBuffer::remaining() const {
    static jnipp::Method<jint> method(clazz(), "remaining", "()I");
    return method.call(*this);
}

// public final java.nio.Buffer java.nio.Buffer.position(int)
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::position(jint a0) const {
    static jnipp::Method<JavaNioBuffer,jint> method(clazz(), "position", "(I)Ljava/nio/Buffer;");
    return method.call(*this, a0);
}

// public final int java.nio.Buffer.position()
jint JavaNioBuffer::position() const {
    static jnipp::Method<jint> method(clazz(), "position", "()I");
    return method.call(*this);
}

// public final int java.nio.Buffer.capacity()
jint JavaNioBuffer::capacity() const {
    static jnipp::Method<jint> method(clazz(), "capacity", "()I");
    return method.call(*this);
}

// public final java.nio.Buffer java.nio.Buffer.mark()
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::mark() const {
    static jnipp::Method<JavaNioBuffer> method(clazz(), "mark", "()Ljava/nio/Buffer;");
    return method.call(*this);
}

// public final java.nio.Buffer java.nio.Buffer.reset()
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::reset() const {
    static jnipp::Method<JavaNioBuffer> method(clazz(), "reset", "()Ljava/nio/Buffer;");
    return method.call(*this);
}

// public final java.nio.Buffer java.nio.Buffer.flip()
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::flip() const {
    static jnipp::Method<JavaNioBuffer> method(clazz(), "flip", "()Ljava/nio/Buffer;");
    return method.call(*this);
}

// public final java.nio.Buffer java.nio.Buffer.rewind()
jnipp::LocalRef<JavaNioBuffer> JavaNioBuffer::rewind() const {
    static jnipp::Method<JavaNioBuffer> method(clazz(), "rewind", "()Ljava/nio/Buffer;");
    return method.call(*this);
}

// public final boolean java.nio.Buffer.hasRemaining()
jboolean JavaNioBuffer::hasRemaining() const {
    static jnipp::Method<jboolean> method(clazz(), "hasRemaining", "()Z");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNioCharBuffer::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/nio/CharBuffer"));
    return cls;
}

// java.nio.CharBuffer(int,int,int,int,char[],int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::construct(jint a0, jint a1, jint a2, jint a3, const jnipp::Ref<jnipp::Array<jchar>>& a4, jint a5) {
    static jnipp::Constructor<JavaNioCharBuffer,jint,jint,jint,jint,jnipp::Array<jchar>,jint> constructor(clazz(), "(IIII[CI)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5);
}

// java.nio.CharBuffer(int,int,int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::construct(jint a0, jint a1, jint a2, jint a3) {
    static jnipp::Constructor<JavaNioCharBuffer,jint,jint,jint,jint> constructor(clazz(), "(IIII)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public java.nio.CharBuffer java.nio.CharBuffer.get(char[],int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::get(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaNioCharBuffer,jnipp::Array<jchar>,jint,jint> method(clazz(), "get", "([CII)Ljava/nio/CharBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public java.nio.CharBuffer java.nio.CharBuffer.get(char[])
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::get(const jnipp::Ref<jnipp::Array<jchar>>& a0) const {
    static jnipp::Method<JavaNioCharBuffer,jnipp::Array<jchar>> method(clazz(), "get", "([C)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public final java.nio.CharBuffer java.nio.CharBuffer.put(java.lang.String)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::put(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaNioCharBuffer,JavaLangString> method(clazz(), "put", "(Ljava/lang/String;)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public java.nio.CharBuffer java.nio.CharBuffer.put(java.lang.String,int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::put(const jnipp::Ref<JavaLangString>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaNioCharBuffer,JavaLangString,jint,jint> method(clazz(), "put", "(Ljava/lang/String;II)Ljava/nio/CharBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public final java.nio.CharBuffer java.nio.CharBuffer.put(char[])
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::put(const jnipp::Ref<jnipp::Array<jchar>>& a0) const {
    static jnipp::Method<JavaNioCharBuffer,jnipp::Array<jchar>> method(clazz(), "put", "([C)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public java.nio.CharBuffer java.nio.CharBuffer.put(char[],int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::put(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaNioCharBuffer,jnipp::Array<jchar>,jint,jint> method(clazz(), "put", "([CII)Ljava/nio/CharBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public java.nio.CharBuffer java.nio.CharBuffer.put(java.nio.CharBuffer)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::put(const jnipp::Ref<JavaNioCharBuffer>& a0) const {
    static jnipp::Method<JavaNioCharBuffer,JavaNioCharBuffer> method(clazz(), "put", "(Ljava/nio/CharBuffer;)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public boolean java.nio.CharBuffer.equals(java.lang.Object)
jboolean JavaNioCharBuffer::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public java.nio.CharBuffer java.nio.CharBuffer.append(java.lang.CharSequence)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::append(const jnipp::Ref<JavaLangCharSequence>& a0) const {
    static jnipp::Method<JavaNioCharBuffer,JavaLangCharSequence> method(clazz(), "append", "(Ljava/lang/CharSequence;)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public java.nio.CharBuffer java.nio.CharBuffer.append(char)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::append(jchar a0) const {
    static jnipp::Method<JavaNioCharBuffer,jchar> method(clazz(), "append", "(C)Ljava/nio/CharBuffer;");
    return method.call(*this, a0);
}

// public java.nio.CharBuffer java.nio.CharBuffer.append(java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::append(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaNioCharBuffer,JavaLangCharSequence,jint,jint> method(clazz(), "append", "(Ljava/lang/CharSequence;II)Ljava/nio/CharBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public int java.nio.CharBuffer.hashCode()
jint JavaNioCharBuffer::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.nio.CharBuffer.compareTo(java.nio.CharBuffer)
jint JavaNioCharBuffer::compareTo(const jnipp::Ref<JavaNioCharBuffer>& a0) const {
    static jnipp::Method<jint,JavaNioCharBuffer> method(clazz(), "compareTo", "(Ljava/nio/CharBuffer;)I");
    return method.call(*this, a0);
}

// public final int java.nio.CharBuffer.length()
jint JavaNioCharBuffer::length() const {
    static jnipp::Method<jint> method(clazz(), "length", "()I");
    return method.call(*this);
}

// public final char java.nio.CharBuffer.charAt(int)
jchar JavaNioCharBuffer::charAt(jint a0) const {
    static jnipp::Method<jchar,jint> method(clazz(), "charAt", "(I)C");
    return method.call(*this, a0);
}

// public final boolean java.nio.CharBuffer.hasArray()
jboolean JavaNioCharBuffer::hasArray() const {
    static jnipp::Method<jboolean> method(clazz(), "hasArray", "()Z");
    return method.call(*this);
}

// public final char[] java.nio.CharBuffer.array()
jnipp::LocalRef<jnipp::Array<jchar>> JavaNioCharBuffer::array() const {
    static jnipp::Method<jnipp::Array<jchar>> method(clazz(), "array", "()[C");
    return method.call(*this);
}

// public final int java.nio.CharBuffer.arrayOffset()
jint JavaNioCharBuffer::arrayOffset() const {
    static jnipp::Method<jint> method(clazz(), "arrayOffset", "()I");
    return method.call(*this);
}

// public static java.nio.CharBuffer java.nio.CharBuffer.wrap(char[])
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::wrap(const jnipp::Ref<jnipp::Array<jchar>>& a0) {
    static jnipp::StaticMethod<JavaNioCharBuffer,jnipp::Array<jchar>> method(clazz(), "wrap", "([C)Ljava/nio/CharBuffer;");
    return method.call(a0);
}

// public static java.nio.CharBuffer java.nio.CharBuffer.wrap(java.lang.CharSequence,int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::wrap(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<JavaNioCharBuffer,JavaLangCharSequence,jint,jint> method(clazz(), "wrap", "(Ljava/lang/CharSequence;II)Ljava/nio/CharBuffer;");
    return method.call(a0, a1, a2);
}

// public static java.nio.CharBuffer java.nio.CharBuffer.wrap(char[],int,int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::wrap(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<JavaNioCharBuffer,jnipp::Array<jchar>,jint,jint> method(clazz(), "wrap", "([CII)Ljava/nio/CharBuffer;");
    return method.call(a0, a1, a2);
}

// public static java.nio.CharBuffer java.nio.CharBuffer.wrap(java.lang.CharSequence)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::wrap(const jnipp::Ref<JavaLangCharSequence>& a0) {
    static jnipp::StaticMethod<JavaNioCharBuffer,JavaLangCharSequence> method(clazz(), "wrap", "(Ljava/lang/CharSequence;)Ljava/nio/CharBuffer;");
    return method.call(a0);
}

// public static java.nio.CharBuffer java.nio.CharBuffer.allocate(int)
jnipp::LocalRef<JavaNioCharBuffer> JavaNioCharBuffer::allocate(jint a0) {
    static jnipp::StaticMethod<JavaNioCharBuffer,jint> method(clazz(), "allocate", "(I)Ljava/nio/CharBuffer;");
    return method.call(a0);
}

// public int java.nio.CharBuffer.read(java.nio.CharBuffer) throws java.io.IOException
jint JavaNioCharBuffer::read(const jnipp::Ref<JavaNioCharBuffer>& a0) const {
    static jnipp::Method<jint,JavaNioCharBuffer> method(clazz(), "read", "(Ljava/nio/CharBuffer;)I");
    return method.call(*this, a0);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNioByteBuffer::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/nio/ByteBuffer"));
    return cls;
}

// java.nio.ByteBuffer(int,int,int,int,byte[],int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::construct(jint a0, jint a1, jint a2, jint a3, const jnipp::Ref<jnipp::Array<jbyte>>& a4, jint a5) {
    static jnipp::Constructor<JavaNioByteBuffer,jint,jint,jint,jint,jnipp::Array<jbyte>,jint> constructor(clazz(), "(IIII[BI)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5);
}

// java.nio.ByteBuffer(int,int,int,int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::construct(jint a0, jint a1, jint a2, jint a3) {
    static jnipp::Constructor<JavaNioByteBuffer,jint,jint,jint,jint> constructor(clazz(), "(IIII)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public java.nio.ByteBuffer java.nio.ByteBuffer.get(byte[],int,int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::get(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaNioByteBuffer,jnipp::Array<jbyte>,jint,jint> method(clazz(), "get", "([BII)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public java.nio.ByteBuffer java.nio.ByteBuffer.get(byte[])
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::get(const jnipp::Ref<jnipp::Array<jbyte>>& a0) const {
    static jnipp::Method<JavaNioByteBuffer,jnipp::Array<jbyte>> method(clazz(), "get", "([B)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0);
}

// public java.nio.ByteBuffer java.nio.ByteBuffer.put(byte[],int,int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::put(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2) const {
    static jnipp::Method<JavaNioByteBuffer,jnipp::Array<jbyte>,jint,jint> method(clazz(), "put", "([BII)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0, a1, a2);
}

// public java.nio.ByteBuffer java.nio.ByteBuffer.put(java.nio.ByteBuffer)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::put(const jnipp::Ref<JavaNioByteBuffer>& a0) const {
    static jnipp::Method<JavaNioByteBuffer,JavaNioByteBuffer> method(clazz(), "put", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0);
}

// public final java.nio.ByteBuffer java.nio.ByteBuffer.put(byte[])
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::put(const jnipp::Ref<jnipp::Array<jbyte>>& a0) const {
    static jnipp::Method<JavaNioByteBuffer,jnipp::Array<jbyte>> method(clazz(), "put", "([B)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0);
}

// public boolean java.nio.ByteBuffer.equals(java.lang.Object)
jboolean JavaNioByteBuffer::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.nio.ByteBuffer.hashCode()
jint JavaNioByteBuffer::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.nio.ByteBuffer.compareTo(java.nio.ByteBuffer)
jint JavaNioByteBuffer::compareTo(const jnipp::Ref<JavaNioByteBuffer>& a0) const {
    static jnipp::Method<jint,JavaNioByteBuffer> method(clazz(), "compareTo", "(Ljava/nio/ByteBuffer;)I");
    return method.call(*this, a0);
}

// public final boolean java.nio.ByteBuffer.hasArray()
jboolean JavaNioByteBuffer::hasArray() const {
    static jnipp::Method<jboolean> method(clazz(), "hasArray", "()Z");
    return method.call(*this);
}

// public final byte[] java.nio.ByteBuffer.array()
jnipp::LocalRef<jnipp::Array<jbyte>> JavaNioByteBuffer::array() const {
    static jnipp::Method<jnipp::Array<jbyte>> method(clazz(), "array", "()[B");
    return method.call(*this);
}

// public final int java.nio.ByteBuffer.arrayOffset()
jint JavaNioByteBuffer::arrayOffset() const {
    static jnipp::Method<jint> method(clazz(), "arrayOffset", "()I");
    return method.call(*this);
}

// public static java.nio.ByteBuffer java.nio.ByteBuffer.wrap(byte[])
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::wrap(const jnipp::Ref<jnipp::Array<jbyte>>& a0) {
    static jnipp::StaticMethod<JavaNioByteBuffer,jnipp::Array<jbyte>> method(clazz(), "wrap", "([B)Ljava/nio/ByteBuffer;");
    return method.call(a0);
}

// public static java.nio.ByteBuffer java.nio.ByteBuffer.wrap(byte[],int,int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::wrap(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<JavaNioByteBuffer,jnipp::Array<jbyte>,jint,jint> method(clazz(), "wrap", "([BII)Ljava/nio/ByteBuffer;");
    return method.call(a0, a1, a2);
}

// public static java.nio.ByteBuffer java.nio.ByteBuffer.allocate(int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::allocate(jint a0) {
    static jnipp::StaticMethod<JavaNioByteBuffer,jint> method(clazz(), "allocate", "(I)Ljava/nio/ByteBuffer;");
    return method.call(a0);
}

// public static java.nio.ByteBuffer java.nio.ByteBuffer.allocateDirect(int)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::allocateDirect(jint a0) {
    static jnipp::StaticMethod<JavaNioByteBuffer,jint> method(clazz(), "allocateDirect", "(I)Ljava/nio/ByteBuffer;");
    return method.call(a0);
}

// public final java.nio.ByteBuffer java.nio.ByteBuffer.order(java.nio.ByteOrder)
jnipp::LocalRef<JavaNioByteBuffer> JavaNioByteBuffer::order(const jnipp::Ref<JavaNioByteOrder>& a0) const {
    static jnipp::Method<JavaNioByteBuffer,JavaNioByteOrder> method(clazz(), "order", "(Ljava/nio/ByteOrder;)Ljava/nio/ByteBuffer;");
    return method.call(*this, a0);
}

// public final java.nio.ByteOrder java.nio.ByteBuffer.order()
jnipp::LocalRef<JavaNioByteOrder> JavaNioByteBuffer::order() const {
    static jnipp::Method<JavaNioByteOrder> method(clazz(), "order", "()Ljava/nio/ByteOrder;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilSortedMap::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/SortedMap"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangEnum::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Enum"));
    return cls;
}

// protected java.lang.Enum(java.lang.String,int)
jnipp::LocalRef<JavaLangEnum> JavaLangEnum::construct(const jnipp::Ref<JavaLangString>& a0, jint a1) {
    static jnipp::Constructor<JavaLangEnum,JavaLangString,jint> constructor(clazz(), "(Ljava/lang/String;I)V");
    return constructor.construct(a0, a1);
}

// public final java.lang.String java.lang.Enum.name()
jnipp::LocalRef<JavaLangString> JavaLangEnum::name() const {
    static jnipp::Method<JavaLangString> method(clazz(), "name", "()Ljava/lang/String;");
    return method.call(*this);
}

// public final boolean java.lang.Enum.equals(java.lang.Object)
jboolean JavaLangEnum::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public final int java.lang.Enum.hashCode()
jint JavaLangEnum::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public final int java.lang.Enum.compareTo(java.lang.Enum)
jint JavaLangEnum::compareTo(const jnipp::Ref<JavaLangEnum>& a0) const {
    static jnipp::Method<jint,JavaLangEnum> method(clazz(), "compareTo", "(Ljava/lang/Enum;)I");
    return method.call(*this, a0);
}

// public static java.lang.Enum java.lang.Enum.valueOf(java.lang.Class,java.lang.String)
jnipp::LocalRef<JavaLangEnum> JavaLangEnum::valueOf(const jnipp::Ref<JavaLangClass>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::StaticMethod<JavaLangEnum,JavaLangClass,JavaLangString> method(clazz(), "valueOf", "(Ljava/lang/Class;Ljava/lang/String;)Ljava/lang/Enum;");
    return method.call(a0, a1);
}

// public final java.lang.Class java.lang.Enum.getDeclaringClass()
jnipp::LocalRef<JavaLangClass> JavaLangEnum::getDeclaringClass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getDeclaringClass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public final int java.lang.Enum.ordinal()
jint JavaLangEnum::ordinal() const {
    static jnipp::Method<jint> method(clazz(), "ordinal", "()I");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilLocale_Category::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Locale$Category"));
    return cls;
}

// private java.util.Locale$Category(java.lang.String,int,java.lang.String,java.lang.String,java.lang.String,java.lang.String)
jnipp::LocalRef<JavaUtilLocale_Category> JavaUtilLocale_Category::construct(const jnipp::Ref<JavaLangString>& a0, jint a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3, const jnipp::Ref<JavaLangString>& a4, const jnipp::Ref<JavaLangString>& a5) {
    static jnipp::Constructor<JavaUtilLocale_Category,JavaLangString,jint,JavaLangString,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5);
}

// public static java.util.Locale$Category[] java.util.Locale$Category.values()
jnipp::LocalRef<jnipp::Array<JavaUtilLocale_Category>> JavaUtilLocale_Category::values() {
    static jnipp::StaticMethod<jnipp::Array<JavaUtilLocale_Category>> method(clazz(), "values", "()[Ljava/util/Locale$Category;");
    return method.call();
}

// public static java.util.Locale$Category java.util.Locale$Category.valueOf(java.lang.String)
jnipp::LocalRef<JavaUtilLocale_Category> JavaUtilLocale_Category::valueOf(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaUtilLocale_Category,JavaLangString> method(clazz(), "valueOf", "(Ljava/lang/String;)Ljava/util/Locale$Category;");
    return method.call(a0);
}
const jnipp::StaticField<JavaUtilLocale_Category> JavaUtilLocale_Category::DISPLAY ("java/util/Locale$Category", "DISPLAY", "Ljava/util/Locale$Category;");
const jnipp::StaticField<JavaUtilLocale_Category> JavaUtilLocale_Category::FORMAT ("java/util/Locale$Category", "FORMAT", "Ljava/util/Locale$Category;");
inline jnipp::GlobalRef<jnipp::Class>& SunUtilLocaleLocaleExtensions::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("sun/util/locale/LocaleExtensions"));
    return cls;
}

// private sun.util.locale.LocaleExtensions(java.lang.String,java.lang.Character,sun.util.locale.Extension)
jnipp::LocalRef<SunUtilLocaleLocaleExtensions> SunUtilLocaleLocaleExtensions::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangCharacter>& a1, const jnipp::Ref<SunUtilLocaleExtension>& a2) {
    static jnipp::Constructor<SunUtilLocaleLocaleExtensions,JavaLangString,JavaLangCharacter,SunUtilLocaleExtension> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/Character;Lsun/util/locale/Extension;)V");
    return constructor.construct(a0, a1, a2);
}

// sun.util.locale.LocaleExtensions(java.util.Map,java.util.Set,java.util.Map)
jnipp::LocalRef<SunUtilLocaleLocaleExtensions> SunUtilLocaleLocaleExtensions::construct(const jnipp::Ref<JavaUtilMap>& a0, const jnipp::Ref<JavaUtilSet>& a1, const jnipp::Ref<JavaUtilMap>& a2) {
    static jnipp::Constructor<SunUtilLocaleLocaleExtensions,JavaUtilMap,JavaUtilSet,JavaUtilMap> constructor(clazz(), "(Ljava/util/Map;Ljava/util/Set;Ljava/util/Map;)V");
    return constructor.construct(a0, a1, a2);
}

// public boolean sun.util.locale.LocaleExtensions.equals(java.lang.Object)
jboolean SunUtilLocaleLocaleExtensions::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int sun.util.locale.LocaleExtensions.hashCode()
jint SunUtilLocaleLocaleExtensions::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public boolean sun.util.locale.LocaleExtensions.isEmpty()
jboolean SunUtilLocaleLocaleExtensions::isEmpty() const {
    static jnipp::Method<jboolean> method(clazz(), "isEmpty", "()Z");
    return method.call(*this);
}

// public sun.util.locale.Extension sun.util.locale.LocaleExtensions.getExtension(java.lang.Character)
jnipp::LocalRef<SunUtilLocaleExtension> SunUtilLocaleLocaleExtensions::getExtension(const jnipp::Ref<JavaLangCharacter>& a0) const {
    static jnipp::Method<SunUtilLocaleExtension,JavaLangCharacter> method(clazz(), "getExtension", "(Ljava/lang/Character;)Lsun/util/locale/Extension;");
    return method.call(*this, a0);
}

// public java.util.Set sun.util.locale.LocaleExtensions.getUnicodeLocaleAttributes()
jnipp::LocalRef<JavaUtilSet> SunUtilLocaleLocaleExtensions::getUnicodeLocaleAttributes() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "getUnicodeLocaleAttributes", "()Ljava/util/Set;");
    return method.call(*this);
}

// public java.lang.String sun.util.locale.LocaleExtensions.getUnicodeLocaleType(java.lang.String)
jnipp::LocalRef<JavaLangString> SunUtilLocaleLocaleExtensions::getUnicodeLocaleType(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangString> method(clazz(), "getUnicodeLocaleType", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.util.Set sun.util.locale.LocaleExtensions.getUnicodeLocaleKeys()
jnipp::LocalRef<JavaUtilSet> SunUtilLocaleLocaleExtensions::getUnicodeLocaleKeys() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "getUnicodeLocaleKeys", "()Ljava/util/Set;");
    return method.call(*this);
}

// public static boolean sun.util.locale.LocaleExtensions.isValidKey(char)
jboolean SunUtilLocaleLocaleExtensions::isValidKey(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isValidKey", "(C)Z");
    return method.call(a0);
}

// public java.lang.String sun.util.locale.LocaleExtensions.getExtensionValue(java.lang.Character)
jnipp::LocalRef<JavaLangString> SunUtilLocaleLocaleExtensions::getExtensionValue(const jnipp::Ref<JavaLangCharacter>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangCharacter> method(clazz(), "getExtensionValue", "(Ljava/lang/Character;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.util.Set sun.util.locale.LocaleExtensions.getKeys()
jnipp::LocalRef<JavaUtilSet> SunUtilLocaleLocaleExtensions::getKeys() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "getKeys", "()Ljava/util/Set;");
    return method.call(*this);
}

// public java.lang.String sun.util.locale.LocaleExtensions.getID()
jnipp::LocalRef<JavaLangString> SunUtilLocaleLocaleExtensions::getID() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getID", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static boolean sun.util.locale.LocaleExtensions.isValidUnicodeLocaleKey(java.lang.String)
jboolean SunUtilLocaleLocaleExtensions::isValidUnicodeLocaleKey(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<jboolean,JavaLangString> method(clazz(), "isValidUnicodeLocaleKey", "(Ljava/lang/String;)Z");
    return method.call(a0);
}
const jnipp::StaticField<SunUtilLocaleLocaleExtensions> SunUtilLocaleLocaleExtensions::CALENDAR_JAPANESE ("sun/util/locale/LocaleExtensions", "CALENDAR_JAPANESE", "Lsun/util/locale/LocaleExtensions;");
const jnipp::StaticField<SunUtilLocaleLocaleExtensions> SunUtilLocaleLocaleExtensions::NUMBER_THAI ("sun/util/locale/LocaleExtensions", "NUMBER_THAI", "Lsun/util/locale/LocaleExtensions;");
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilLocale_1::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Locale$1"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& SunUtilLocaleBaseLocale::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("sun/util/locale/BaseLocale"));
    return cls;
}

// sun.util.locale.BaseLocale(java.lang.String,java.lang.String,java.lang.String,java.lang.String,sun.util.locale.BaseLocale$1)
jnipp::LocalRef<SunUtilLocaleBaseLocale> SunUtilLocaleBaseLocale::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3, const jnipp::Ref<SunUtilLocaleBaseLocale_1>& a4) {
    static jnipp::Constructor<SunUtilLocaleBaseLocale,JavaLangString,JavaLangString,JavaLangString,JavaLangString,SunUtilLocaleBaseLocale_1> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/util/locale/BaseLocale$1;)V");
    return constructor.construct(a0, a1, a2, a3, a4);
}

// private sun.util.locale.BaseLocale(java.lang.String,java.lang.String,java.lang.String,java.lang.String)
jnipp::LocalRef<SunUtilLocaleBaseLocale> SunUtilLocaleBaseLocale::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3) {
    static jnipp::Constructor<SunUtilLocaleBaseLocale,JavaLangString,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// private sun.util.locale.BaseLocale(java.lang.String,java.lang.String)
jnipp::LocalRef<SunUtilLocaleBaseLocale> SunUtilLocaleBaseLocale::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::Constructor<SunUtilLocaleBaseLocale,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public boolean sun.util.locale.BaseLocale.equals(java.lang.Object)
jboolean SunUtilLocaleBaseLocale::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int sun.util.locale.BaseLocale.hashCode()
jint SunUtilLocaleBaseLocale::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.String sun.util.locale.BaseLocale.getLanguage()
jnipp::LocalRef<JavaLangString> SunUtilLocaleBaseLocale::getLanguage() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getLanguage", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static sun.util.locale.BaseLocale sun.util.locale.BaseLocale.getInstance(java.lang.String,java.lang.String,java.lang.String,java.lang.String)
jnipp::LocalRef<SunUtilLocaleBaseLocale> SunUtilLocaleBaseLocale::getInstance(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3) {
    static jnipp::StaticMethod<SunUtilLocaleBaseLocale,JavaLangString,JavaLangString,JavaLangString,JavaLangString> method(clazz(), "getInstance", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lsun/util/locale/BaseLocale;");
    return method.call(a0, a1, a2, a3);
}

// public java.lang.String sun.util.locale.BaseLocale.getScript()
jnipp::LocalRef<JavaLangString> SunUtilLocaleBaseLocale::getScript() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getScript", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String sun.util.locale.BaseLocale.getVariant()
jnipp::LocalRef<JavaLangString> SunUtilLocaleBaseLocale::getVariant() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getVariant", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static sun.util.locale.BaseLocale sun.util.locale.BaseLocale.createInstance(java.lang.String,java.lang.String)
jnipp::LocalRef<SunUtilLocaleBaseLocale> SunUtilLocaleBaseLocale::createInstance(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::StaticMethod<SunUtilLocaleBaseLocale,JavaLangString,JavaLangString> method(clazz(), "createInstance", "(Ljava/lang/String;Ljava/lang/String;)Lsun/util/locale/BaseLocale;");
    return method.call(a0, a1);
}

// public java.lang.String sun.util.locale.BaseLocale.getRegion()
jnipp::LocalRef<JavaLangString> SunUtilLocaleBaseLocale::getRegion() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRegion", "()Ljava/lang/String;");
    return method.call(*this);
}
const jnipp::StaticField<JavaLangString> SunUtilLocaleBaseLocale::SEP ("sun/util/locale/BaseLocale", "SEP", "Ljava/lang/String;");
inline jnipp::GlobalRef<jnipp::Class>& JavaNioByteOrder::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/nio/ByteOrder"));
    return cls;
}

// private java.nio.ByteOrder(java.lang.String)
jnipp::LocalRef<JavaNioByteOrder> JavaNioByteOrder::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaNioByteOrder,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public static java.nio.ByteOrder java.nio.ByteOrder.nativeOrder()
jnipp::LocalRef<JavaNioByteOrder> JavaNioByteOrder::nativeOrder() {
    static jnipp::StaticMethod<JavaNioByteOrder> method(clazz(), "nativeOrder", "()Ljava/nio/ByteOrder;");
    return method.call();
}
const jnipp::StaticField<JavaNioByteOrder> JavaNioByteOrder::BIG_ENDIAN ("java/nio/ByteOrder", "BIG_ENDIAN", "Ljava/nio/ByteOrder;");
const jnipp::StaticField<JavaNioByteOrder> JavaNioByteOrder::LITTLE_ENDIAN ("java/nio/ByteOrder", "LITTLE_ENDIAN", "Ljava/nio/ByteOrder;");
inline jnipp::GlobalRef<jnipp::Class>& JavaLangClass::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Class"));
    return cls;
}

// private java.lang.Class()
jnipp::LocalRef<JavaLangClass> JavaLangClass::construct() {
    static jnipp::Constructor<JavaLangClass> constructor(clazz(), "()V");
    return constructor.construct();
}

// public static java.lang.Class java.lang.Class.forName(java.lang.String,boolean,java.lang.ClassLoader) throws java.lang.ClassNotFoundException
jnipp::LocalRef<JavaLangClass> JavaLangClass::forName(const jnipp::Ref<JavaLangString>& a0, jboolean a1, const jnipp::Ref<JavaLangClassLoader>& a2) {
    static jnipp::StaticMethod<JavaLangClass,JavaLangString,jboolean,JavaLangClassLoader> method(clazz(), "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");
    return method.call(a0, a1, a2);
}

// public static java.lang.Class java.lang.Class.forName(java.lang.String) throws java.lang.ClassNotFoundException
jnipp::LocalRef<JavaLangClass> JavaLangClass::forName(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaLangClass,JavaLangString> method(clazz(), "forName", "(Ljava/lang/String;)Ljava/lang/Class;");
    return method.call(a0);
}

// public native boolean java.lang.Class.isAssignableFrom(java.lang.Class)
jboolean JavaLangClass::isAssignableFrom(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<jboolean,JavaLangClass> method(clazz(), "isAssignableFrom", "(Ljava/lang/Class;)Z");
    return method.call(*this, a0);
}

// public native boolean java.lang.Class.isInstance(java.lang.Object)
jboolean JavaLangClass::isInstance(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "isInstance", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public native int java.lang.Class.getModifiers()
jint JavaLangClass::getModifiers() const {
    static jnipp::Method<jint> method(clazz(), "getModifiers", "()I");
    return method.call(*this);
}

// public native boolean java.lang.Class.isInterface()
jboolean JavaLangClass::isInterface() const {
    static jnipp::Method<jboolean> method(clazz(), "isInterface", "()Z");
    return method.call(*this);
}

// public native boolean java.lang.Class.isArray()
jboolean JavaLangClass::isArray() const {
    static jnipp::Method<jboolean> method(clazz(), "isArray", "()Z");
    return method.call(*this);
}

// public native boolean java.lang.Class.isPrimitive()
jboolean JavaLangClass::isPrimitive() const {
    static jnipp::Method<jboolean> method(clazz(), "isPrimitive", "()Z");
    return method.call(*this);
}

// public native java.lang.Class java.lang.Class.getSuperclass()
jnipp::LocalRef<JavaLangClass> JavaLangClass::getSuperclass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getSuperclass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public native java.lang.Class java.lang.Class.getComponentType()
jnipp::LocalRef<JavaLangClass> JavaLangClass::getComponentType() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getComponentType", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.String java.lang.Class.getName()
jnipp::LocalRef<JavaLangString> JavaLangClass::getName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.Object java.lang.Class.newInstance() throws java.lang.InstantiationException,java.lang.IllegalAccessException
jnipp::LocalRef<JavaLangObject> JavaLangClass::newInstance() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "newInstance", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public boolean java.lang.Class.isAnnotation()
jboolean JavaLangClass::isAnnotation() const {
    static jnipp::Method<jboolean> method(clazz(), "isAnnotation", "()Z");
    return method.call(*this);
}

// public boolean java.lang.Class.isSynthetic()
jboolean JavaLangClass::isSynthetic() const {
    static jnipp::Method<jboolean> method(clazz(), "isSynthetic", "()Z");
    return method.call(*this);
}

// public java.lang.ClassLoader java.lang.Class.getClassLoader()
jnipp::LocalRef<JavaLangClassLoader> JavaLangClass::getClassLoader() const {
    static jnipp::Method<JavaLangClassLoader> method(clazz(), "getClassLoader", "()Ljava/lang/ClassLoader;");
    return method.call(*this);
}

// public java.lang.reflect.TypeVariable[] java.lang.Class.getTypeParameters()
jnipp::LocalRef<jnipp::Array<JavaLangReflectTypeVariable>> JavaLangClass::getTypeParameters() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectTypeVariable>> method(clazz(), "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return method.call(*this);
}

// public java.lang.reflect.Type java.lang.Class.getGenericSuperclass()
jnipp::LocalRef<JavaLangReflectType> JavaLangClass::getGenericSuperclass() const {
    static jnipp::Method<JavaLangReflectType> method(clazz(), "getGenericSuperclass", "()Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public java.lang.Package java.lang.Class.getPackage()
jnipp::LocalRef<JavaLangPackage> JavaLangClass::getPackage() const {
    static jnipp::Method<JavaLangPackage> method(clazz(), "getPackage", "()Ljava/lang/Package;");
    return method.call(*this);
}

// public native java.lang.Class[] java.lang.Class.getInterfaces()
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangClass::getInterfaces() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getInterfaces", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.reflect.Type[] java.lang.Class.getGenericInterfaces()
jnipp::LocalRef<jnipp::Array<JavaLangReflectType>> JavaLangClass::getGenericInterfaces() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectType>> method(clazz(), "getGenericInterfaces", "()[Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public native java.lang.Object[] java.lang.Class.getSigners()
jnipp::LocalRef<jnipp::Array<JavaLangObject>> JavaLangClass::getSigners() const {
    static jnipp::Method<jnipp::Array<JavaLangObject>> method(clazz(), "getSigners", "()[Ljava/lang/Object;");
    return method.call(*this);
}

// public java.lang.reflect.Method java.lang.Class.getEnclosingMethod()
jnipp::LocalRef<JavaLangReflectMethod> JavaLangClass::getEnclosingMethod() const {
    static jnipp::Method<JavaLangReflectMethod> method(clazz(), "getEnclosingMethod", "()Ljava/lang/reflect/Method;");
    return method.call(*this);
}

// public java.lang.reflect.Constructor java.lang.Class.getEnclosingConstructor()
jnipp::LocalRef<JavaLangReflectConstructor> JavaLangClass::getEnclosingConstructor() const {
    static jnipp::Method<JavaLangReflectConstructor> method(clazz(), "getEnclosingConstructor", "()Ljava/lang/reflect/Constructor;");
    return method.call(*this);
}

// public java.lang.Class java.lang.Class.getDeclaringClass()
jnipp::LocalRef<JavaLangClass> JavaLangClass::getDeclaringClass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getDeclaringClass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.Class java.lang.Class.getEnclosingClass()
jnipp::LocalRef<JavaLangClass> JavaLangClass::getEnclosingClass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getEnclosingClass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.String java.lang.Class.getSimpleName()
jnipp::LocalRef<JavaLangString> JavaLangClass::getSimpleName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getSimpleName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.Class.getCanonicalName()
jnipp::LocalRef<JavaLangString> JavaLangClass::getCanonicalName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getCanonicalName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public boolean java.lang.Class.isAnonymousClass()
jboolean JavaLangClass::isAnonymousClass() const {
    static jnipp::Method<jboolean> method(clazz(), "isAnonymousClass", "()Z");
    return method.call(*this);
}

// public boolean java.lang.Class.isLocalClass()
jboolean JavaLangClass::isLocalClass() const {
    static jnipp::Method<jboolean> method(clazz(), "isLocalClass", "()Z");
    return method.call(*this);
}

// public boolean java.lang.Class.isMemberClass()
jboolean JavaLangClass::isMemberClass() const {
    static jnipp::Method<jboolean> method(clazz(), "isMemberClass", "()Z");
    return method.call(*this);
}

// public java.lang.Class[] java.lang.Class.getClasses()
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangClass::getClasses() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getClasses", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.reflect.Field[] java.lang.Class.getFields() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangReflectField>> JavaLangClass::getFields() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectField>> method(clazz(), "getFields", "()[Ljava/lang/reflect/Field;");
    return method.call(*this);
}

// public java.lang.reflect.Method[] java.lang.Class.getMethods() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangReflectMethod>> JavaLangClass::getMethods() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectMethod>> method(clazz(), "getMethods", "()[Ljava/lang/reflect/Method;");
    return method.call(*this);
}

// public java.lang.reflect.Constructor[] java.lang.Class.getConstructors() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangReflectConstructor>> JavaLangClass::getConstructors() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectConstructor>> method(clazz(), "getConstructors", "()[Ljava/lang/reflect/Constructor;");
    return method.call(*this);
}

// public java.lang.reflect.Field java.lang.Class.getField(java.lang.String) throws java.lang.NoSuchFieldException,java.lang.SecurityException
jnipp::LocalRef<JavaLangReflectField> JavaLangClass::getField(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangReflectField,JavaLangString> method(clazz(), "getField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return method.call(*this, a0);
}

// public java.lang.reflect.Method java.lang.Class.getMethod(java.lang.String,java.lang.Class[]) throws java.lang.NoSuchMethodException,java.lang.SecurityException
jnipp::LocalRef<JavaLangReflectMethod> JavaLangClass::getMethod(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<jnipp::Array<JavaLangClass>>& a1) const {
    static jnipp::Method<JavaLangReflectMethod,JavaLangString,jnipp::Array<JavaLangClass>> method(clazz(), "getMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return method.call(*this, a0, a1);
}

// public java.lang.reflect.Constructor java.lang.Class.getConstructor(java.lang.Class[]) throws java.lang.NoSuchMethodException,java.lang.SecurityException
jnipp::LocalRef<JavaLangReflectConstructor> JavaLangClass::getConstructor(const jnipp::Ref<jnipp::Array<JavaLangClass>>& a0) const {
    static jnipp::Method<JavaLangReflectConstructor,jnipp::Array<JavaLangClass>> method(clazz(), "getConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return method.call(*this, a0);
}

// public java.lang.Class[] java.lang.Class.getDeclaredClasses() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangClass::getDeclaredClasses() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getDeclaredClasses", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.reflect.Field[] java.lang.Class.getDeclaredFields() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangReflectField>> JavaLangClass::getDeclaredFields() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectField>> method(clazz(), "getDeclaredFields", "()[Ljava/lang/reflect/Field;");
    return method.call(*this);
}

// public java.lang.reflect.Method[] java.lang.Class.getDeclaredMethods() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangReflectMethod>> JavaLangClass::getDeclaredMethods() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectMethod>> method(clazz(), "getDeclaredMethods", "()[Ljava/lang/reflect/Method;");
    return method.call(*this);
}

// public java.lang.reflect.Constructor[] java.lang.Class.getDeclaredConstructors() throws java.lang.SecurityException
jnipp::LocalRef<jnipp::Array<JavaLangReflectConstructor>> JavaLangClass::getDeclaredConstructors() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectConstructor>> method(clazz(), "getDeclaredConstructors", "()[Ljava/lang/reflect/Constructor;");
    return method.call(*this);
}

// public java.lang.reflect.Field java.lang.Class.getDeclaredField(java.lang.String) throws java.lang.NoSuchFieldException,java.lang.SecurityException
jnipp::LocalRef<JavaLangReflectField> JavaLangClass::getDeclaredField(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangReflectField,JavaLangString> method(clazz(), "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return method.call(*this, a0);
}

// public java.lang.reflect.Method java.lang.Class.getDeclaredMethod(java.lang.String,java.lang.Class[]) throws java.lang.NoSuchMethodException,java.lang.SecurityException
jnipp::LocalRef<JavaLangReflectMethod> JavaLangClass::getDeclaredMethod(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<jnipp::Array<JavaLangClass>>& a1) const {
    static jnipp::Method<JavaLangReflectMethod,JavaLangString,jnipp::Array<JavaLangClass>> method(clazz(), "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return method.call(*this, a0, a1);
}

// public java.lang.reflect.Constructor java.lang.Class.getDeclaredConstructor(java.lang.Class[]) throws java.lang.NoSuchMethodException,java.lang.SecurityException
jnipp::LocalRef<JavaLangReflectConstructor> JavaLangClass::getDeclaredConstructor(const jnipp::Ref<jnipp::Array<JavaLangClass>>& a0) const {
    static jnipp::Method<JavaLangReflectConstructor,jnipp::Array<JavaLangClass>> method(clazz(), "getDeclaredConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return method.call(*this, a0);
}

// public java.io.InputStream java.lang.Class.getResourceAsStream(java.lang.String)
jnipp::LocalRef<JavaIoInputStream> JavaLangClass::getResourceAsStream(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaIoInputStream,JavaLangString> method(clazz(), "getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return method.call(*this, a0);
}

// public java.net.URL java.lang.Class.getResource(java.lang.String)
jnipp::LocalRef<JavaNetURL> JavaLangClass::getResource(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaNetURL,JavaLangString> method(clazz(), "getResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return method.call(*this, a0);
}

// public java.security.ProtectionDomain java.lang.Class.getProtectionDomain()
jnipp::LocalRef<JavaSecurityProtectionDomain> JavaLangClass::getProtectionDomain() const {
    static jnipp::Method<JavaSecurityProtectionDomain> method(clazz(), "getProtectionDomain", "()Ljava/security/ProtectionDomain;");
    return method.call(*this);
}

// public boolean java.lang.Class.desiredAssertionStatus()
jboolean JavaLangClass::desiredAssertionStatus() const {
    static jnipp::Method<jboolean> method(clazz(), "desiredAssertionStatus", "()Z");
    return method.call(*this);
}

// public boolean java.lang.Class.isEnum()
jboolean JavaLangClass::isEnum() const {
    static jnipp::Method<jboolean> method(clazz(), "isEnum", "()Z");
    return method.call(*this);
}

// public java.lang.Object[] java.lang.Class.getEnumConstants()
jnipp::LocalRef<jnipp::Array<JavaLangObject>> JavaLangClass::getEnumConstants() const {
    static jnipp::Method<jnipp::Array<JavaLangObject>> method(clazz(), "getEnumConstants", "()[Ljava/lang/Object;");
    return method.call(*this);
}

// public java.lang.Object java.lang.Class.cast(java.lang.Object)
jnipp::LocalRef<JavaLangObject> JavaLangClass::cast(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangObject,JavaLangObject> method(clazz(), "cast", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public java.lang.Class java.lang.Class.asSubclass(java.lang.Class)
jnipp::LocalRef<JavaLangClass> JavaLangClass::asSubclass(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangClass,JavaLangClass> method(clazz(), "asSubclass", "(Ljava/lang/Class;)Ljava/lang/Class;");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation java.lang.Class.getAnnotation(java.lang.Class)
jnipp::LocalRef<JavaLangAnnotationAnnotation> JavaLangClass::getAnnotation(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangAnnotationAnnotation,JavaLangClass> method(clazz(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return method.call(*this, a0);
}

// public boolean java.lang.Class.isAnnotationPresent(java.lang.Class)
jboolean JavaLangClass::isAnnotationPresent(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<jboolean,JavaLangClass> method(clazz(), "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation[] java.lang.Class.getAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangClass::getAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation[] java.lang.Class.getDeclaredAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangClass::getDeclaredAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangCharacter::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Character"));
    return cls;
}

// public java.lang.Character(char)
jnipp::LocalRef<JavaLangCharacter> JavaLangCharacter::construct(jchar a0) {
    static jnipp::Constructor<JavaLangCharacter,jchar> constructor(clazz(), "(C)V");
    return constructor.construct(a0);
}

// public static boolean java.lang.Character.isJavaIdentifierStart(char)
jboolean JavaLangCharacter::isJavaIdentifierStart(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isJavaIdentifierStart", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isJavaIdentifierStart(int)
jboolean JavaLangCharacter::isJavaIdentifierStart(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isJavaIdentifierStart", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isJavaIdentifierPart(char)
jboolean JavaLangCharacter::isJavaIdentifierPart(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isJavaIdentifierPart", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isJavaIdentifierPart(int)
jboolean JavaLangCharacter::isJavaIdentifierPart(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isJavaIdentifierPart", "(I)Z");
    return method.call(a0);
}

// public boolean java.lang.Character.equals(java.lang.Object)
jboolean JavaLangCharacter::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.lang.Character.hashCode()
jint JavaLangCharacter::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public static char java.lang.Character.reverseBytes(char)
jchar JavaLangCharacter::reverseBytes(jchar a0) {
    static jnipp::StaticMethod<jchar,jchar> method(clazz(), "reverseBytes", "(C)C");
    return method.call(a0);
}

// public int java.lang.Character.compareTo(java.lang.Character)
jint JavaLangCharacter::compareTo(const jnipp::Ref<JavaLangCharacter>& a0) const {
    static jnipp::Method<jint,JavaLangCharacter> method(clazz(), "compareTo", "(Ljava/lang/Character;)I");
    return method.call(*this, a0);
}

// public char java.lang.Character.charValue()
jchar JavaLangCharacter::charValue() const {
    static jnipp::Method<jchar> method(clazz(), "charValue", "()C");
    return method.call(*this);
}

// public static java.lang.Character java.lang.Character.valueOf(char)
jnipp::LocalRef<JavaLangCharacter> JavaLangCharacter::valueOf(jchar a0) {
    static jnipp::StaticMethod<JavaLangCharacter,jchar> method(clazz(), "valueOf", "(C)Ljava/lang/Character;");
    return method.call(a0);
}

// public static java.lang.String java.lang.Character.getName(int)
jnipp::LocalRef<JavaLangString> JavaLangCharacter::getName(jint a0) {
    static jnipp::StaticMethod<JavaLangString,jint> method(clazz(), "getName", "(I)Ljava/lang/String;");
    return method.call(a0);
}

// public static int java.lang.Character.codePointAt(char[],int,int)
jint JavaLangCharacter::codePointAt(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<jint,jnipp::Array<jchar>,jint,jint> method(clazz(), "codePointAt", "([CII)I");
    return method.call(a0, a1, a2);
}

// public static int java.lang.Character.codePointAt(char[],int)
jint JavaLangCharacter::codePointAt(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1) {
    static jnipp::StaticMethod<jint,jnipp::Array<jchar>,jint> method(clazz(), "codePointAt", "([CI)I");
    return method.call(a0, a1);
}

// public static int java.lang.Character.codePointAt(java.lang.CharSequence,int)
jint JavaLangCharacter::codePointAt(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1) {
    static jnipp::StaticMethod<jint,JavaLangCharSequence,jint> method(clazz(), "codePointAt", "(Ljava/lang/CharSequence;I)I");
    return method.call(a0, a1);
}

// public static int java.lang.Character.codePointBefore(char[],int,int)
jint JavaLangCharacter::codePointBefore(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<jint,jnipp::Array<jchar>,jint,jint> method(clazz(), "codePointBefore", "([CII)I");
    return method.call(a0, a1, a2);
}

// public static int java.lang.Character.codePointBefore(char[],int)
jint JavaLangCharacter::codePointBefore(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1) {
    static jnipp::StaticMethod<jint,jnipp::Array<jchar>,jint> method(clazz(), "codePointBefore", "([CI)I");
    return method.call(a0, a1);
}

// public static int java.lang.Character.codePointBefore(java.lang.CharSequence,int)
jint JavaLangCharacter::codePointBefore(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1) {
    static jnipp::StaticMethod<jint,JavaLangCharSequence,jint> method(clazz(), "codePointBefore", "(Ljava/lang/CharSequence;I)I");
    return method.call(a0, a1);
}

// public static int java.lang.Character.codePointCount(char[],int,int)
jint JavaLangCharacter::codePointCount(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<jint,jnipp::Array<jchar>,jint,jint> method(clazz(), "codePointCount", "([CII)I");
    return method.call(a0, a1, a2);
}

// public static int java.lang.Character.codePointCount(java.lang.CharSequence,int,int)
jint JavaLangCharacter::codePointCount(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<jint,JavaLangCharSequence,jint,jint> method(clazz(), "codePointCount", "(Ljava/lang/CharSequence;II)I");
    return method.call(a0, a1, a2);
}

// public static int java.lang.Character.offsetByCodePoints(char[],int,int,int,int)
jint JavaLangCharacter::offsetByCodePoints(const jnipp::Ref<jnipp::Array<jchar>>& a0, jint a1, jint a2, jint a3, jint a4) {
    static jnipp::StaticMethod<jint,jnipp::Array<jchar>,jint,jint,jint,jint> method(clazz(), "offsetByCodePoints", "([CIIII)I");
    return method.call(a0, a1, a2, a3, a4);
}

// public static int java.lang.Character.offsetByCodePoints(java.lang.CharSequence,int,int)
jint JavaLangCharacter::offsetByCodePoints(const jnipp::Ref<JavaLangCharSequence>& a0, jint a1, jint a2) {
    static jnipp::StaticMethod<jint,JavaLangCharSequence,jint,jint> method(clazz(), "offsetByCodePoints", "(Ljava/lang/CharSequence;II)I");
    return method.call(a0, a1, a2);
}

// public static int java.lang.Character.toLowerCase(int)
jint JavaLangCharacter::toLowerCase(jint a0) {
    static jnipp::StaticMethod<jint,jint> method(clazz(), "toLowerCase", "(I)I");
    return method.call(a0);
}

// public static char java.lang.Character.toLowerCase(char)
jchar JavaLangCharacter::toLowerCase(jchar a0) {
    static jnipp::StaticMethod<jchar,jchar> method(clazz(), "toLowerCase", "(C)C");
    return method.call(a0);
}

// public static int java.lang.Character.toUpperCase(int)
jint JavaLangCharacter::toUpperCase(jint a0) {
    static jnipp::StaticMethod<jint,jint> method(clazz(), "toUpperCase", "(I)I");
    return method.call(a0);
}

// public static char java.lang.Character.toUpperCase(char)
jchar JavaLangCharacter::toUpperCase(jchar a0) {
    static jnipp::StaticMethod<jchar,jchar> method(clazz(), "toUpperCase", "(C)C");
    return method.call(a0);
}

// public static boolean java.lang.Character.isBmpCodePoint(int)
jboolean JavaLangCharacter::isBmpCodePoint(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isBmpCodePoint", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isValidCodePoint(int)
jboolean JavaLangCharacter::isValidCodePoint(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isValidCodePoint", "(I)Z");
    return method.call(a0);
}

// public static int java.lang.Character.compare(char,char)
jint JavaLangCharacter::compare(jchar a0, jchar a1) {
    static jnipp::StaticMethod<jint,jchar,jchar> method(clazz(), "compare", "(CC)I");
    return method.call(a0, a1);
}

// public static char java.lang.Character.highSurrogate(int)
jchar JavaLangCharacter::highSurrogate(jint a0) {
    static jnipp::StaticMethod<jchar,jint> method(clazz(), "highSurrogate", "(I)C");
    return method.call(a0);
}

// public static char java.lang.Character.lowSurrogate(int)
jchar JavaLangCharacter::lowSurrogate(jint a0) {
    static jnipp::StaticMethod<jchar,jint> method(clazz(), "lowSurrogate", "(I)C");
    return method.call(a0);
}

// public static int java.lang.Character.charCount(int)
jint JavaLangCharacter::charCount(jint a0) {
    static jnipp::StaticMethod<jint,jint> method(clazz(), "charCount", "(I)I");
    return method.call(a0);
}

// public static int java.lang.Character.toChars(int,char[],int)
jint JavaLangCharacter::toChars(jint a0, const jnipp::Ref<jnipp::Array<jchar>>& a1, jint a2) {
    static jnipp::StaticMethod<jint,jint,jnipp::Array<jchar>,jint> method(clazz(), "toChars", "(I[CI)I");
    return method.call(a0, a1, a2);
}

// public static char[] java.lang.Character.toChars(int)
jnipp::LocalRef<jnipp::Array<jchar>> JavaLangCharacter::toChars(jint a0) {
    static jnipp::StaticMethod<jnipp::Array<jchar>,jint> method(clazz(), "toChars", "(I)[C");
    return method.call(a0);
}

// public static int java.lang.Character.getType(char)
jint JavaLangCharacter::getType(jchar a0) {
    static jnipp::StaticMethod<jint,jchar> method(clazz(), "getType", "(C)I");
    return method.call(a0);
}

// public static int java.lang.Character.getType(int)
jint JavaLangCharacter::getType(jint a0) {
    static jnipp::StaticMethod<jint,jint> method(clazz(), "getType", "(I)I");
    return method.call(a0);
}

// public static boolean java.lang.Character.isLowSurrogate(char)
jboolean JavaLangCharacter::isLowSurrogate(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isLowSurrogate", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isHighSurrogate(char)
jboolean JavaLangCharacter::isHighSurrogate(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isHighSurrogate", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isSupplementaryCodePoint(int)
jboolean JavaLangCharacter::isSupplementaryCodePoint(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isSupplementaryCodePoint", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isSurrogate(char)
jboolean JavaLangCharacter::isSurrogate(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isSurrogate", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isSurrogatePair(char,char)
jboolean JavaLangCharacter::isSurrogatePair(jchar a0, jchar a1) {
    static jnipp::StaticMethod<jboolean,jchar,jchar> method(clazz(), "isSurrogatePair", "(CC)Z");
    return method.call(a0, a1);
}

// public static int java.lang.Character.toCodePoint(char,char)
jint JavaLangCharacter::toCodePoint(jchar a0, jchar a1) {
    static jnipp::StaticMethod<jint,jchar,jchar> method(clazz(), "toCodePoint", "(CC)I");
    return method.call(a0, a1);
}

// public static boolean java.lang.Character.isLowerCase(int)
jboolean JavaLangCharacter::isLowerCase(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isLowerCase", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isLowerCase(char)
jboolean JavaLangCharacter::isLowerCase(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isLowerCase", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isUpperCase(char)
jboolean JavaLangCharacter::isUpperCase(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isUpperCase", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isUpperCase(int)
jboolean JavaLangCharacter::isUpperCase(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isUpperCase", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isTitleCase(int)
jboolean JavaLangCharacter::isTitleCase(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isTitleCase", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isTitleCase(char)
jboolean JavaLangCharacter::isTitleCase(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isTitleCase", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isDigit(char)
jboolean JavaLangCharacter::isDigit(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isDigit", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isDigit(int)
jboolean JavaLangCharacter::isDigit(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isDigit", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isDefined(char)
jboolean JavaLangCharacter::isDefined(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isDefined", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isDefined(int)
jboolean JavaLangCharacter::isDefined(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isDefined", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isLetter(int)
jboolean JavaLangCharacter::isLetter(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isLetter", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isLetter(char)
jboolean JavaLangCharacter::isLetter(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isLetter", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isLetterOrDigit(char)
jboolean JavaLangCharacter::isLetterOrDigit(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isLetterOrDigit", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isLetterOrDigit(int)
jboolean JavaLangCharacter::isLetterOrDigit(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isLetterOrDigit", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isJavaLetter(char)
jboolean JavaLangCharacter::isJavaLetter(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isJavaLetter", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isJavaLetterOrDigit(char)
jboolean JavaLangCharacter::isJavaLetterOrDigit(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isJavaLetterOrDigit", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isAlphabetic(int)
jboolean JavaLangCharacter::isAlphabetic(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isAlphabetic", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isIdeographic(int)
jboolean JavaLangCharacter::isIdeographic(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isIdeographic", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isUnicodeIdentifierStart(int)
jboolean JavaLangCharacter::isUnicodeIdentifierStart(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isUnicodeIdentifierStart", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isUnicodeIdentifierStart(char)
jboolean JavaLangCharacter::isUnicodeIdentifierStart(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isUnicodeIdentifierStart", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isUnicodeIdentifierPart(int)
jboolean JavaLangCharacter::isUnicodeIdentifierPart(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isUnicodeIdentifierPart", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isUnicodeIdentifierPart(char)
jboolean JavaLangCharacter::isUnicodeIdentifierPart(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isUnicodeIdentifierPart", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isIdentifierIgnorable(char)
jboolean JavaLangCharacter::isIdentifierIgnorable(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isIdentifierIgnorable", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isIdentifierIgnorable(int)
jboolean JavaLangCharacter::isIdentifierIgnorable(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isIdentifierIgnorable", "(I)Z");
    return method.call(a0);
}

// public static char java.lang.Character.toTitleCase(char)
jchar JavaLangCharacter::toTitleCase(jchar a0) {
    static jnipp::StaticMethod<jchar,jchar> method(clazz(), "toTitleCase", "(C)C");
    return method.call(a0);
}

// public static int java.lang.Character.toTitleCase(int)
jint JavaLangCharacter::toTitleCase(jint a0) {
    static jnipp::StaticMethod<jint,jint> method(clazz(), "toTitleCase", "(I)I");
    return method.call(a0);
}

// public static int java.lang.Character.digit(int,int)
jint JavaLangCharacter::digit(jint a0, jint a1) {
    static jnipp::StaticMethod<jint,jint,jint> method(clazz(), "digit", "(II)I");
    return method.call(a0, a1);
}

// public static int java.lang.Character.digit(char,int)
jint JavaLangCharacter::digit(jchar a0, jint a1) {
    static jnipp::StaticMethod<jint,jchar,jint> method(clazz(), "digit", "(CI)I");
    return method.call(a0, a1);
}

// public static int java.lang.Character.getNumericValue(int)
jint JavaLangCharacter::getNumericValue(jint a0) {
    static jnipp::StaticMethod<jint,jint> method(clazz(), "getNumericValue", "(I)I");
    return method.call(a0);
}

// public static int java.lang.Character.getNumericValue(char)
jint JavaLangCharacter::getNumericValue(jchar a0) {
    static jnipp::StaticMethod<jint,jchar> method(clazz(), "getNumericValue", "(C)I");
    return method.call(a0);
}

// public static boolean java.lang.Character.isSpace(char)
jboolean JavaLangCharacter::isSpace(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isSpace", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isSpaceChar(char)
jboolean JavaLangCharacter::isSpaceChar(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isSpaceChar", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isSpaceChar(int)
jboolean JavaLangCharacter::isSpaceChar(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isSpaceChar", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isWhitespace(int)
jboolean JavaLangCharacter::isWhitespace(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isWhitespace", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isWhitespace(char)
jboolean JavaLangCharacter::isWhitespace(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isWhitespace", "(C)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isISOControl(int)
jboolean JavaLangCharacter::isISOControl(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isISOControl", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isISOControl(char)
jboolean JavaLangCharacter::isISOControl(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isISOControl", "(C)Z");
    return method.call(a0);
}

// public static char java.lang.Character.forDigit(int,int)
jchar JavaLangCharacter::forDigit(jint a0, jint a1) {
    static jnipp::StaticMethod<jchar,jint,jint> method(clazz(), "forDigit", "(II)C");
    return method.call(a0, a1);
}

// public static byte java.lang.Character.getDirectionality(char)
jbyte JavaLangCharacter::getDirectionality(jchar a0) {
    static jnipp::StaticMethod<jbyte,jchar> method(clazz(), "getDirectionality", "(C)B");
    return method.call(a0);
}

// public static byte java.lang.Character.getDirectionality(int)
jbyte JavaLangCharacter::getDirectionality(jint a0) {
    static jnipp::StaticMethod<jbyte,jint> method(clazz(), "getDirectionality", "(I)B");
    return method.call(a0);
}

// public static boolean java.lang.Character.isMirrored(int)
jboolean JavaLangCharacter::isMirrored(jint a0) {
    static jnipp::StaticMethod<jboolean,jint> method(clazz(), "isMirrored", "(I)Z");
    return method.call(a0);
}

// public static boolean java.lang.Character.isMirrored(char)
jboolean JavaLangCharacter::isMirrored(jchar a0) {
    static jnipp::StaticMethod<jboolean,jchar> method(clazz(), "isMirrored", "(C)Z");
    return method.call(a0);
}
const jnipp::StaticField<jint> JavaLangCharacter::MIN_RADIX ("java/lang/Character", "MIN_RADIX", "I");
const jnipp::StaticField<jint> JavaLangCharacter::MAX_RADIX ("java/lang/Character", "MAX_RADIX", "I");
const jnipp::StaticField<jchar> JavaLangCharacter::MIN_VALUE ("java/lang/Character", "MIN_VALUE", "C");
const jnipp::StaticField<jchar> JavaLangCharacter::MAX_VALUE ("java/lang/Character", "MAX_VALUE", "C");
const jnipp::StaticField<JavaLangClass> JavaLangCharacter::TYPE ("java/lang/Character", "TYPE", "Ljava/lang/Class;");
const jnipp::StaticField<jbyte> JavaLangCharacter::UNASSIGNED ("java/lang/Character", "UNASSIGNED", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::UPPERCASE_LETTER ("java/lang/Character", "UPPERCASE_LETTER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::LOWERCASE_LETTER ("java/lang/Character", "LOWERCASE_LETTER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::TITLECASE_LETTER ("java/lang/Character", "TITLECASE_LETTER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::MODIFIER_LETTER ("java/lang/Character", "MODIFIER_LETTER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::OTHER_LETTER ("java/lang/Character", "OTHER_LETTER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::NON_SPACING_MARK ("java/lang/Character", "NON_SPACING_MARK", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::ENCLOSING_MARK ("java/lang/Character", "ENCLOSING_MARK", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::COMBINING_SPACING_MARK ("java/lang/Character", "COMBINING_SPACING_MARK", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DECIMAL_DIGIT_NUMBER ("java/lang/Character", "DECIMAL_DIGIT_NUMBER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::LETTER_NUMBER ("java/lang/Character", "LETTER_NUMBER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::OTHER_NUMBER ("java/lang/Character", "OTHER_NUMBER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::SPACE_SEPARATOR ("java/lang/Character", "SPACE_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::LINE_SEPARATOR ("java/lang/Character", "LINE_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::PARAGRAPH_SEPARATOR ("java/lang/Character", "PARAGRAPH_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::CONTROL ("java/lang/Character", "CONTROL", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::FORMAT ("java/lang/Character", "FORMAT", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::PRIVATE_USE ("java/lang/Character", "PRIVATE_USE", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::SURROGATE ("java/lang/Character", "SURROGATE", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DASH_PUNCTUATION ("java/lang/Character", "DASH_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::START_PUNCTUATION ("java/lang/Character", "START_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::END_PUNCTUATION ("java/lang/Character", "END_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::CONNECTOR_PUNCTUATION ("java/lang/Character", "CONNECTOR_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::OTHER_PUNCTUATION ("java/lang/Character", "OTHER_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::MATH_SYMBOL ("java/lang/Character", "MATH_SYMBOL", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::CURRENCY_SYMBOL ("java/lang/Character", "CURRENCY_SYMBOL", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::MODIFIER_SYMBOL ("java/lang/Character", "MODIFIER_SYMBOL", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::OTHER_SYMBOL ("java/lang/Character", "OTHER_SYMBOL", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::INITIAL_QUOTE_PUNCTUATION ("java/lang/Character", "INITIAL_QUOTE_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::FINAL_QUOTE_PUNCTUATION ("java/lang/Character", "FINAL_QUOTE_PUNCTUATION", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_UNDEFINED ("java/lang/Character", "DIRECTIONALITY_UNDEFINED", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_LEFT_TO_RIGHT ("java/lang/Character", "DIRECTIONALITY_LEFT_TO_RIGHT", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_RIGHT_TO_LEFT ("java/lang/Character", "DIRECTIONALITY_RIGHT_TO_LEFT", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC ("java/lang/Character", "DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_EUROPEAN_NUMBER ("java/lang/Character", "DIRECTIONALITY_EUROPEAN_NUMBER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR ("java/lang/Character", "DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR ("java/lang/Character", "DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_ARABIC_NUMBER ("java/lang/Character", "DIRECTIONALITY_ARABIC_NUMBER", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_COMMON_NUMBER_SEPARATOR ("java/lang/Character", "DIRECTIONALITY_COMMON_NUMBER_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_NONSPACING_MARK ("java/lang/Character", "DIRECTIONALITY_NONSPACING_MARK", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_BOUNDARY_NEUTRAL ("java/lang/Character", "DIRECTIONALITY_BOUNDARY_NEUTRAL", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_PARAGRAPH_SEPARATOR ("java/lang/Character", "DIRECTIONALITY_PARAGRAPH_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_SEGMENT_SEPARATOR ("java/lang/Character", "DIRECTIONALITY_SEGMENT_SEPARATOR", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_WHITESPACE ("java/lang/Character", "DIRECTIONALITY_WHITESPACE", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_OTHER_NEUTRALS ("java/lang/Character", "DIRECTIONALITY_OTHER_NEUTRALS", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING ("java/lang/Character", "DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE ("java/lang/Character", "DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING ("java/lang/Character", "DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE ("java/lang/Character", "DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE", "B");
const jnipp::StaticField<jbyte> JavaLangCharacter::DIRECTIONALITY_POP_DIRECTIONAL_FORMAT ("java/lang/Character", "DIRECTIONALITY_POP_DIRECTIONAL_FORMAT", "B");
const jnipp::StaticField<jchar> JavaLangCharacter::MIN_HIGH_SURROGATE ("java/lang/Character", "MIN_HIGH_SURROGATE", "C");
const jnipp::StaticField<jchar> JavaLangCharacter::MAX_HIGH_SURROGATE ("java/lang/Character", "MAX_HIGH_SURROGATE", "C");
const jnipp::StaticField<jchar> JavaLangCharacter::MIN_LOW_SURROGATE ("java/lang/Character", "MIN_LOW_SURROGATE", "C");
const jnipp::StaticField<jchar> JavaLangCharacter::MAX_LOW_SURROGATE ("java/lang/Character", "MAX_LOW_SURROGATE", "C");
const jnipp::StaticField<jchar> JavaLangCharacter::MIN_SURROGATE ("java/lang/Character", "MIN_SURROGATE", "C");
const jnipp::StaticField<jchar> JavaLangCharacter::MAX_SURROGATE ("java/lang/Character", "MAX_SURROGATE", "C");
const jnipp::StaticField<jint> JavaLangCharacter::MIN_SUPPLEMENTARY_CODE_POINT ("java/lang/Character", "MIN_SUPPLEMENTARY_CODE_POINT", "I");
const jnipp::StaticField<jint> JavaLangCharacter::MIN_CODE_POINT ("java/lang/Character", "MIN_CODE_POINT", "I");
const jnipp::StaticField<jint> JavaLangCharacter::MAX_CODE_POINT ("java/lang/Character", "MAX_CODE_POINT", "I");
const jnipp::StaticField<jint> JavaLangCharacter::SIZE ("java/lang/Character", "SIZE", "I");
inline jnipp::GlobalRef<jnipp::Class>& SunUtilLocaleExtension::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("sun/util/locale/Extension"));
    return cls;
}

// protected sun.util.locale.Extension(char)
jnipp::LocalRef<SunUtilLocaleExtension> SunUtilLocaleExtension::construct(jchar a0) {
    static jnipp::Constructor<SunUtilLocaleExtension,jchar> constructor(clazz(), "(C)V");
    return constructor.construct(a0);
}

// sun.util.locale.Extension(char,java.lang.String)
jnipp::LocalRef<SunUtilLocaleExtension> SunUtilLocaleExtension::construct(jchar a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::Constructor<SunUtilLocaleExtension,jchar,JavaLangString> constructor(clazz(), "(CLjava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public java.lang.String sun.util.locale.Extension.getValue()
jnipp::LocalRef<JavaLangString> SunUtilLocaleExtension::getValue() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getValue", "()Ljava/lang/String;");
    return method.call(*this);
}

// public char sun.util.locale.Extension.getKey()
jchar SunUtilLocaleExtension::getKey() const {
    static jnipp::Method<jchar> method(clazz(), "getKey", "()C");
    return method.call(*this);
}

// public java.lang.String sun.util.locale.Extension.getID()
jnipp::LocalRef<JavaLangString> SunUtilLocaleExtension::getID() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getID", "()Ljava/lang/String;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilMap::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Map"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& SunUtilLocaleBaseLocale_1::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("sun/util/locale/BaseLocale$1"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangReflectAccessibleObject::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/reflect/AccessibleObject"));
    return cls;
}

// protected java.lang.reflect.AccessibleObject()
jnipp::LocalRef<JavaLangReflectAccessibleObject> JavaLangReflectAccessibleObject::construct() {
    static jnipp::Constructor<JavaLangReflectAccessibleObject> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.lang.annotation.Annotation java.lang.reflect.AccessibleObject.getAnnotation(java.lang.Class)
jnipp::LocalRef<JavaLangAnnotationAnnotation> JavaLangReflectAccessibleObject::getAnnotation(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangAnnotationAnnotation,JavaLangClass> method(clazz(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return method.call(*this, a0);
}

// public boolean java.lang.reflect.AccessibleObject.isAnnotationPresent(java.lang.Class)
jboolean JavaLangReflectAccessibleObject::isAnnotationPresent(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<jboolean,JavaLangClass> method(clazz(), "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation[] java.lang.reflect.AccessibleObject.getAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangReflectAccessibleObject::getAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation[] java.lang.reflect.AccessibleObject.getDeclaredAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangReflectAccessibleObject::getDeclaredAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public static void java.lang.reflect.AccessibleObject.setAccessible(java.lang.reflect.AccessibleObject[],boolean) throws java.lang.SecurityException
void JavaLangReflectAccessibleObject::setAccessible(const jnipp::Ref<jnipp::Array<JavaLangReflectAccessibleObject>>& a0, jboolean a1) {
    static jnipp::StaticMethod<void,jnipp::Array<JavaLangReflectAccessibleObject>,jboolean> method(clazz(), "setAccessible", "([Ljava/lang/reflect/AccessibleObject;Z)V");
    method.call(a0, a1);
}

// public void java.lang.reflect.AccessibleObject.setAccessible(boolean) throws java.lang.SecurityException
void JavaLangReflectAccessibleObject::setAccessible(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setAccessible", "(Z)V");
    method.call(*this, a0);
}

// public boolean java.lang.reflect.AccessibleObject.isAccessible()
jboolean JavaLangReflectAccessibleObject::isAccessible() const {
    static jnipp::Method<jboolean> method(clazz(), "isAccessible", "()Z");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangReflectMethod::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/reflect/Method"));
    return cls;
}

// java.lang.reflect.Method(java.lang.Class,java.lang.String,java.lang.Class[],java.lang.Class,java.lang.Class[],int,int,java.lang.String,byte[],byte[],byte[])
jnipp::LocalRef<JavaLangReflectMethod> JavaLangReflectMethod::construct(const jnipp::Ref<JavaLangClass>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<jnipp::Array<JavaLangClass>>& a2, const jnipp::Ref<JavaLangClass>& a3, const jnipp::Ref<jnipp::Array<JavaLangClass>>& a4, jint a5, jint a6, const jnipp::Ref<JavaLangString>& a7, const jnipp::Ref<jnipp::Array<jbyte>>& a8, const jnipp::Ref<jnipp::Array<jbyte>>& a9, const jnipp::Ref<jnipp::Array<jbyte>>& a10) {
    static jnipp::Constructor<JavaLangReflectMethod,JavaLangClass,JavaLangString,jnipp::Array<JavaLangClass>,JavaLangClass,jnipp::Array<JavaLangClass>,jint,jint,JavaLangString,jnipp::Array<jbyte>,jnipp::Array<jbyte>,jnipp::Array<jbyte>> constructor(clazz(), "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/Class;[Ljava/lang/Class;IILjava/lang/String;[B[B[B)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

// public java.lang.Object java.lang.reflect.Method.invoke(java.lang.Object,java.lang.Object[]) throws java.lang.IllegalAccessException,java.lang.IllegalArgumentException,java.lang.reflect.InvocationTargetException
jnipp::LocalRef<JavaLangObject> JavaLangReflectMethod::invoke(const jnipp::Ref<JavaLangObject>& a0, const jnipp::Ref<jnipp::Array<JavaLangObject>>& a1) const {
    static jnipp::Method<JavaLangObject,JavaLangObject,jnipp::Array<JavaLangObject>> method(clazz(), "invoke", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0, a1);
}

// public boolean java.lang.reflect.Method.equals(java.lang.Object)
jboolean JavaLangReflectMethod::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.lang.reflect.Method.hashCode()
jint JavaLangReflectMethod::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.lang.reflect.Method.getModifiers()
jint JavaLangReflectMethod::getModifiers() const {
    static jnipp::Method<jint> method(clazz(), "getModifiers", "()I");
    return method.call(*this);
}

// public java.lang.String java.lang.reflect.Method.getName()
jnipp::LocalRef<JavaLangString> JavaLangReflectMethod::getName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public boolean java.lang.reflect.Method.isSynthetic()
jboolean JavaLangReflectMethod::isSynthetic() const {
    static jnipp::Method<jboolean> method(clazz(), "isSynthetic", "()Z");
    return method.call(*this);
}

// public java.lang.reflect.TypeVariable[] java.lang.reflect.Method.getTypeParameters()
jnipp::LocalRef<jnipp::Array<JavaLangReflectTypeVariable>> JavaLangReflectMethod::getTypeParameters() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectTypeVariable>> method(clazz(), "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return method.call(*this);
}

// public java.lang.Class java.lang.reflect.Method.getDeclaringClass()
jnipp::LocalRef<JavaLangClass> JavaLangReflectMethod::getDeclaringClass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getDeclaringClass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation java.lang.reflect.Method.getAnnotation(java.lang.Class)
jnipp::LocalRef<JavaLangAnnotationAnnotation> JavaLangReflectMethod::getAnnotation(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangAnnotationAnnotation,JavaLangClass> method(clazz(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation[] java.lang.reflect.Method.getDeclaredAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangReflectMethod::getDeclaredAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public java.lang.Class java.lang.reflect.Method.getReturnType()
jnipp::LocalRef<JavaLangClass> JavaLangReflectMethod::getReturnType() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getReturnType", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.Class[] java.lang.reflect.Method.getParameterTypes()
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangReflectMethod::getParameterTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getParameterTypes", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.String java.lang.reflect.Method.toGenericString()
jnipp::LocalRef<JavaLangString> JavaLangReflectMethod::toGenericString() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toGenericString", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.reflect.Type java.lang.reflect.Method.getGenericReturnType()
jnipp::LocalRef<JavaLangReflectType> JavaLangReflectMethod::getGenericReturnType() const {
    static jnipp::Method<JavaLangReflectType> method(clazz(), "getGenericReturnType", "()Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public java.lang.reflect.Type[] java.lang.reflect.Method.getGenericParameterTypes()
jnipp::LocalRef<jnipp::Array<JavaLangReflectType>> JavaLangReflectMethod::getGenericParameterTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectType>> method(clazz(), "getGenericParameterTypes", "()[Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public java.lang.Class[] java.lang.reflect.Method.getExceptionTypes()
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangReflectMethod::getExceptionTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getExceptionTypes", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.reflect.Type[] java.lang.reflect.Method.getGenericExceptionTypes()
jnipp::LocalRef<jnipp::Array<JavaLangReflectType>> JavaLangReflectMethod::getGenericExceptionTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectType>> method(clazz(), "getGenericExceptionTypes", "()[Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public boolean java.lang.reflect.Method.isBridge()
jboolean JavaLangReflectMethod::isBridge() const {
    static jnipp::Method<jboolean> method(clazz(), "isBridge", "()Z");
    return method.call(*this);
}

// public boolean java.lang.reflect.Method.isVarArgs()
jboolean JavaLangReflectMethod::isVarArgs() const {
    static jnipp::Method<jboolean> method(clazz(), "isVarArgs", "()Z");
    return method.call(*this);
}

// public java.lang.Object java.lang.reflect.Method.getDefaultValue()
jnipp::LocalRef<JavaLangObject> JavaLangReflectMethod::getDefaultValue() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "getDefaultValue", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation[][] java.lang.reflect.Method.getParameterAnnotations()
jnipp::LocalRef<jnipp::Array<jnipp::Array<JavaLangAnnotationAnnotation>>> JavaLangReflectMethod::getParameterAnnotations() const {
    static jnipp::Method<jnipp::Array<jnipp::Array<JavaLangAnnotationAnnotation>>> method(clazz(), "getParameterAnnotations", "()[[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityProtectionDomain::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/ProtectionDomain"));
    return cls;
}

// public java.security.ProtectionDomain(java.security.CodeSource,java.security.PermissionCollection)
jnipp::LocalRef<JavaSecurityProtectionDomain> JavaSecurityProtectionDomain::construct(const jnipp::Ref<JavaSecurityCodeSource>& a0, const jnipp::Ref<JavaSecurityPermissionCollection>& a1) {
    static jnipp::Constructor<JavaSecurityProtectionDomain,JavaSecurityCodeSource,JavaSecurityPermissionCollection> constructor(clazz(), "(Ljava/security/CodeSource;Ljava/security/PermissionCollection;)V");
    return constructor.construct(a0, a1);
}

// public java.security.ProtectionDomain(java.security.CodeSource,java.security.PermissionCollection,java.lang.ClassLoader,java.security.Principal[])
jnipp::LocalRef<JavaSecurityProtectionDomain> JavaSecurityProtectionDomain::construct(const jnipp::Ref<JavaSecurityCodeSource>& a0, const jnipp::Ref<JavaSecurityPermissionCollection>& a1, const jnipp::Ref<JavaLangClassLoader>& a2, const jnipp::Ref<jnipp::Array<JavaSecurityPrincipal>>& a3) {
    static jnipp::Constructor<JavaSecurityProtectionDomain,JavaSecurityCodeSource,JavaSecurityPermissionCollection,JavaLangClassLoader,jnipp::Array<JavaSecurityPrincipal>> constructor(clazz(), "(Ljava/security/CodeSource;Ljava/security/PermissionCollection;Ljava/lang/ClassLoader;[Ljava/security/Principal;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public final java.lang.ClassLoader java.security.ProtectionDomain.getClassLoader()
jnipp::LocalRef<JavaLangClassLoader> JavaSecurityProtectionDomain::getClassLoader() const {
    static jnipp::Method<JavaLangClassLoader> method(clazz(), "getClassLoader", "()Ljava/lang/ClassLoader;");
    return method.call(*this);
}

// public final java.security.CodeSource java.security.ProtectionDomain.getCodeSource()
jnipp::LocalRef<JavaSecurityCodeSource> JavaSecurityProtectionDomain::getCodeSource() const {
    static jnipp::Method<JavaSecurityCodeSource> method(clazz(), "getCodeSource", "()Ljava/security/CodeSource;");
    return method.call(*this);
}

// public final java.security.Principal[] java.security.ProtectionDomain.getPrincipals()
jnipp::LocalRef<jnipp::Array<JavaSecurityPrincipal>> JavaSecurityProtectionDomain::getPrincipals() const {
    static jnipp::Method<jnipp::Array<JavaSecurityPrincipal>> method(clazz(), "getPrincipals", "()[Ljava/security/Principal;");
    return method.call(*this);
}

// public final java.security.PermissionCollection java.security.ProtectionDomain.getPermissions()
jnipp::LocalRef<JavaSecurityPermissionCollection> JavaSecurityProtectionDomain::getPermissions() const {
    static jnipp::Method<JavaSecurityPermissionCollection> method(clazz(), "getPermissions", "()Ljava/security/PermissionCollection;");
    return method.call(*this);
}

// public boolean java.security.ProtectionDomain.implies(java.security.Permission)
jboolean JavaSecurityProtectionDomain::implies(const jnipp::Ref<JavaSecurityPermission>& a0) const {
    static jnipp::Method<jboolean,JavaSecurityPermission> method(clazz(), "implies", "(Ljava/security/Permission;)Z");
    return method.call(*this, a0);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangReflectField::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/reflect/Field"));
    return cls;
}

// java.lang.reflect.Field(java.lang.Class,java.lang.String,java.lang.Class,int,int,java.lang.String,byte[])
jnipp::LocalRef<JavaLangReflectField> JavaLangReflectField::construct(const jnipp::Ref<JavaLangClass>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangClass>& a2, jint a3, jint a4, const jnipp::Ref<JavaLangString>& a5, const jnipp::Ref<jnipp::Array<jbyte>>& a6) {
    static jnipp::Constructor<JavaLangReflectField,JavaLangClass,JavaLangString,JavaLangClass,jint,jint,JavaLangString,jnipp::Array<jbyte>> constructor(clazz(), "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;IILjava/lang/String;[B)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5, a6);
}

// public java.lang.Object java.lang.reflect.Field.get(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jnipp::LocalRef<JavaLangObject> JavaLangReflectField::get(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangObject,JavaLangObject> method(clazz(), "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public boolean java.lang.reflect.Field.equals(java.lang.Object)
jboolean JavaLangReflectField::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.lang.reflect.Field.hashCode()
jint JavaLangReflectField::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.lang.reflect.Field.getModifiers()
jint JavaLangReflectField::getModifiers() const {
    static jnipp::Method<jint> method(clazz(), "getModifiers", "()I");
    return method.call(*this);
}

// public boolean java.lang.reflect.Field.getBoolean(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jboolean JavaLangReflectField::getBoolean(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "getBoolean", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public byte java.lang.reflect.Field.getByte(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jbyte JavaLangReflectField::getByte(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jbyte,JavaLangObject> method(clazz(), "getByte", "(Ljava/lang/Object;)B");
    return method.call(*this, a0);
}

// public short java.lang.reflect.Field.getShort(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jshort JavaLangReflectField::getShort(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jshort,JavaLangObject> method(clazz(), "getShort", "(Ljava/lang/Object;)S");
    return method.call(*this, a0);
}

// public char java.lang.reflect.Field.getChar(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jchar JavaLangReflectField::getChar(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jchar,JavaLangObject> method(clazz(), "getChar", "(Ljava/lang/Object;)C");
    return method.call(*this, a0);
}

// public int java.lang.reflect.Field.getInt(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jint JavaLangReflectField::getInt(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jint,JavaLangObject> method(clazz(), "getInt", "(Ljava/lang/Object;)I");
    return method.call(*this, a0);
}

// public long java.lang.reflect.Field.getLong(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jlong JavaLangReflectField::getLong(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jlong,JavaLangObject> method(clazz(), "getLong", "(Ljava/lang/Object;)J");
    return method.call(*this, a0);
}

// public float java.lang.reflect.Field.getFloat(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jfloat JavaLangReflectField::getFloat(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jfloat,JavaLangObject> method(clazz(), "getFloat", "(Ljava/lang/Object;)F");
    return method.call(*this, a0);
}

// public double java.lang.reflect.Field.getDouble(java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
jdouble JavaLangReflectField::getDouble(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jdouble,JavaLangObject> method(clazz(), "getDouble", "(Ljava/lang/Object;)D");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.reflect.Field.getName()
jnipp::LocalRef<JavaLangString> JavaLangReflectField::getName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public boolean java.lang.reflect.Field.isSynthetic()
jboolean JavaLangReflectField::isSynthetic() const {
    static jnipp::Method<jboolean> method(clazz(), "isSynthetic", "()Z");
    return method.call(*this);
}

// public java.lang.Class java.lang.reflect.Field.getDeclaringClass()
jnipp::LocalRef<JavaLangClass> JavaLangReflectField::getDeclaringClass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getDeclaringClass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation java.lang.reflect.Field.getAnnotation(java.lang.Class)
jnipp::LocalRef<JavaLangAnnotationAnnotation> JavaLangReflectField::getAnnotation(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangAnnotationAnnotation,JavaLangClass> method(clazz(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation[] java.lang.reflect.Field.getDeclaredAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangReflectField::getDeclaredAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public boolean java.lang.reflect.Field.isEnumConstant()
jboolean JavaLangReflectField::isEnumConstant() const {
    static jnipp::Method<jboolean> method(clazz(), "isEnumConstant", "()Z");
    return method.call(*this);
}

// public java.lang.Class java.lang.reflect.Field.getType()
jnipp::LocalRef<JavaLangClass> JavaLangReflectField::getType() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getType", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.reflect.Type java.lang.reflect.Field.getGenericType()
jnipp::LocalRef<JavaLangReflectType> JavaLangReflectField::getGenericType() const {
    static jnipp::Method<JavaLangReflectType> method(clazz(), "getGenericType", "()Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public java.lang.String java.lang.reflect.Field.toGenericString()
jnipp::LocalRef<JavaLangString> JavaLangReflectField::toGenericString() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toGenericString", "()Ljava/lang/String;");
    return method.call(*this);
}

// public void java.lang.reflect.Field.set(java.lang.Object,java.lang.Object) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::set(const jnipp::Ref<JavaLangObject>& a0, const jnipp::Ref<JavaLangObject>& a1) const {
    static jnipp::Method<void,JavaLangObject,JavaLangObject> method(clazz(), "set", "(Ljava/lang/Object;Ljava/lang/Object;)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setBoolean(java.lang.Object,boolean) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setBoolean(const jnipp::Ref<JavaLangObject>& a0, jboolean a1) const {
    static jnipp::Method<void,JavaLangObject,jboolean> method(clazz(), "setBoolean", "(Ljava/lang/Object;Z)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setByte(java.lang.Object,byte) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setByte(const jnipp::Ref<JavaLangObject>& a0, jbyte a1) const {
    static jnipp::Method<void,JavaLangObject,jbyte> method(clazz(), "setByte", "(Ljava/lang/Object;B)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setChar(java.lang.Object,char) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setChar(const jnipp::Ref<JavaLangObject>& a0, jchar a1) const {
    static jnipp::Method<void,JavaLangObject,jchar> method(clazz(), "setChar", "(Ljava/lang/Object;C)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setShort(java.lang.Object,short) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setShort(const jnipp::Ref<JavaLangObject>& a0, jshort a1) const {
    static jnipp::Method<void,JavaLangObject,jshort> method(clazz(), "setShort", "(Ljava/lang/Object;S)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setInt(java.lang.Object,int) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setInt(const jnipp::Ref<JavaLangObject>& a0, jint a1) const {
    static jnipp::Method<void,JavaLangObject,jint> method(clazz(), "setInt", "(Ljava/lang/Object;I)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setLong(java.lang.Object,long) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setLong(const jnipp::Ref<JavaLangObject>& a0, jlong a1) const {
    static jnipp::Method<void,JavaLangObject,jlong> method(clazz(), "setLong", "(Ljava/lang/Object;J)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setFloat(java.lang.Object,float) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setFloat(const jnipp::Ref<JavaLangObject>& a0, jfloat a1) const {
    static jnipp::Method<void,JavaLangObject,jfloat> method(clazz(), "setFloat", "(Ljava/lang/Object;F)V");
    method.call(*this, a0, a1);
}

// public void java.lang.reflect.Field.setDouble(java.lang.Object,double) throws java.lang.IllegalArgumentException,java.lang.IllegalAccessException
void JavaLangReflectField::setDouble(const jnipp::Ref<JavaLangObject>& a0, jdouble a1) const {
    static jnipp::Method<void,JavaLangObject,jdouble> method(clazz(), "setDouble", "(Ljava/lang/Object;D)V");
    method.call(*this, a0, a1);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangReflectTypeVariable::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/reflect/TypeVariable"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangPackage::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Package"));
    return cls;
}

// private java.lang.Package(java.lang.String,java.util.jar.Manifest,java.net.URL,java.lang.ClassLoader)
jnipp::LocalRef<JavaLangPackage> JavaLangPackage::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaUtilJarManifest>& a1, const jnipp::Ref<JavaNetURL>& a2, const jnipp::Ref<JavaLangClassLoader>& a3) {
    static jnipp::Constructor<JavaLangPackage,JavaLangString,JavaUtilJarManifest,JavaNetURL,JavaLangClassLoader> constructor(clazz(), "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;Ljava/lang/ClassLoader;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// java.lang.Package(java.lang.String,java.util.jar.Manifest,java.net.URL,java.lang.ClassLoader,java.lang.Package$1)
jnipp::LocalRef<JavaLangPackage> JavaLangPackage::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaUtilJarManifest>& a1, const jnipp::Ref<JavaNetURL>& a2, const jnipp::Ref<JavaLangClassLoader>& a3, const jnipp::Ref<JavaLangPackage_1>& a4) {
    static jnipp::Constructor<JavaLangPackage,JavaLangString,JavaUtilJarManifest,JavaNetURL,JavaLangClassLoader,JavaLangPackage_1> constructor(clazz(), "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;Ljava/lang/ClassLoader;Ljava/lang/Package$1;)V");
    return constructor.construct(a0, a1, a2, a3, a4);
}

// java.lang.Package(java.lang.String,java.lang.String,java.lang.String,java.lang.String,java.lang.String,java.lang.String,java.lang.String,java.net.URL,java.lang.ClassLoader)
jnipp::LocalRef<JavaLangPackage> JavaLangPackage::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3, const jnipp::Ref<JavaLangString>& a4, const jnipp::Ref<JavaLangString>& a5, const jnipp::Ref<JavaLangString>& a6, const jnipp::Ref<JavaNetURL>& a7, const jnipp::Ref<JavaLangClassLoader>& a8) {
    static jnipp::Constructor<JavaLangPackage,JavaLangString,JavaLangString,JavaLangString,JavaLangString,JavaLangString,JavaLangString,JavaLangString,JavaNetURL,JavaLangClassLoader> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/net/URL;Ljava/lang/ClassLoader;)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

// public int java.lang.Package.hashCode()
jint JavaLangPackage::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.String java.lang.Package.getName()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static java.lang.Package java.lang.Package.getPackage(java.lang.String)
jnipp::LocalRef<JavaLangPackage> JavaLangPackage::getPackage(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaLangPackage,JavaLangString> method(clazz(), "getPackage", "(Ljava/lang/String;)Ljava/lang/Package;");
    return method.call(a0);
}

// public java.lang.annotation.Annotation java.lang.Package.getAnnotation(java.lang.Class)
jnipp::LocalRef<JavaLangAnnotationAnnotation> JavaLangPackage::getAnnotation(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangAnnotationAnnotation,JavaLangClass> method(clazz(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return method.call(*this, a0);
}

// public boolean java.lang.Package.isAnnotationPresent(java.lang.Class)
jboolean JavaLangPackage::isAnnotationPresent(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<jboolean,JavaLangClass> method(clazz(), "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation[] java.lang.Package.getAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangPackage::getAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation[] java.lang.Package.getDeclaredAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangPackage::getDeclaredAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public static java.lang.Package[] java.lang.Package.getPackages()
jnipp::LocalRef<jnipp::Array<JavaLangPackage>> JavaLangPackage::getPackages() {
    static jnipp::StaticMethod<jnipp::Array<JavaLangPackage>> method(clazz(), "getPackages", "()[Ljava/lang/Package;");
    return method.call();
}

// public boolean java.lang.Package.isSealed()
jboolean JavaLangPackage::isSealed() const {
    static jnipp::Method<jboolean> method(clazz(), "isSealed", "()Z");
    return method.call(*this);
}

// public boolean java.lang.Package.isSealed(java.net.URL)
jboolean JavaLangPackage::isSealed(const jnipp::Ref<JavaNetURL>& a0) const {
    static jnipp::Method<jboolean,JavaNetURL> method(clazz(), "isSealed", "(Ljava/net/URL;)Z");
    return method.call(*this, a0);
}

// public boolean java.lang.Package.isCompatibleWith(java.lang.String) throws java.lang.NumberFormatException
jboolean JavaLangPackage::isCompatibleWith(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<jboolean,JavaLangString> method(clazz(), "isCompatibleWith", "(Ljava/lang/String;)Z");
    return method.call(*this, a0);
}

// public java.lang.String java.lang.Package.getSpecificationTitle()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getSpecificationTitle() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getSpecificationTitle", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.Package.getSpecificationVersion()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getSpecificationVersion() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getSpecificationVersion", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.Package.getSpecificationVendor()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getSpecificationVendor() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getSpecificationVendor", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.Package.getImplementationTitle()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getImplementationTitle() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getImplementationTitle", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.Package.getImplementationVersion()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getImplementationVersion() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getImplementationVersion", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.lang.Package.getImplementationVendor()
jnipp::LocalRef<JavaLangString> JavaLangPackage::getImplementationVendor() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getImplementationVendor", "()Ljava/lang/String;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangReflectConstructor::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/reflect/Constructor"));
    return cls;
}

// java.lang.reflect.Constructor(java.lang.Class,java.lang.Class[],java.lang.Class[],int,int,java.lang.String,byte[],byte[])
jnipp::LocalRef<JavaLangReflectConstructor> JavaLangReflectConstructor::construct(const jnipp::Ref<JavaLangClass>& a0, const jnipp::Ref<jnipp::Array<JavaLangClass>>& a1, const jnipp::Ref<jnipp::Array<JavaLangClass>>& a2, jint a3, jint a4, const jnipp::Ref<JavaLangString>& a5, const jnipp::Ref<jnipp::Array<jbyte>>& a6, const jnipp::Ref<jnipp::Array<jbyte>>& a7) {
    static jnipp::Constructor<JavaLangReflectConstructor,JavaLangClass,jnipp::Array<JavaLangClass>,jnipp::Array<JavaLangClass>,jint,jint,JavaLangString,jnipp::Array<jbyte>,jnipp::Array<jbyte>> constructor(clazz(), "(Ljava/lang/Class;[Ljava/lang/Class;[Ljava/lang/Class;IILjava/lang/String;[B[B)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5, a6, a7);
}

// public boolean java.lang.reflect.Constructor.equals(java.lang.Object)
jboolean JavaLangReflectConstructor::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.lang.reflect.Constructor.hashCode()
jint JavaLangReflectConstructor::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.lang.reflect.Constructor.getModifiers()
jint JavaLangReflectConstructor::getModifiers() const {
    static jnipp::Method<jint> method(clazz(), "getModifiers", "()I");
    return method.call(*this);
}

// public java.lang.String java.lang.reflect.Constructor.getName()
jnipp::LocalRef<JavaLangString> JavaLangReflectConstructor::getName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.Object java.lang.reflect.Constructor.newInstance(java.lang.Object[]) throws java.lang.InstantiationException,java.lang.IllegalAccessException,java.lang.IllegalArgumentException,java.lang.reflect.InvocationTargetException
jnipp::LocalRef<JavaLangObject> JavaLangReflectConstructor::newInstance(const jnipp::Ref<jnipp::Array<JavaLangObject>>& a0) const {
    static jnipp::Method<JavaLangObject,jnipp::Array<JavaLangObject>> method(clazz(), "newInstance", "([Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public boolean java.lang.reflect.Constructor.isSynthetic()
jboolean JavaLangReflectConstructor::isSynthetic() const {
    static jnipp::Method<jboolean> method(clazz(), "isSynthetic", "()Z");
    return method.call(*this);
}

// public java.lang.reflect.TypeVariable[] java.lang.reflect.Constructor.getTypeParameters()
jnipp::LocalRef<jnipp::Array<JavaLangReflectTypeVariable>> JavaLangReflectConstructor::getTypeParameters() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectTypeVariable>> method(clazz(), "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return method.call(*this);
}

// public java.lang.Class java.lang.reflect.Constructor.getDeclaringClass()
jnipp::LocalRef<JavaLangClass> JavaLangReflectConstructor::getDeclaringClass() const {
    static jnipp::Method<JavaLangClass> method(clazz(), "getDeclaringClass", "()Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.annotation.Annotation java.lang.reflect.Constructor.getAnnotation(java.lang.Class)
jnipp::LocalRef<JavaLangAnnotationAnnotation> JavaLangReflectConstructor::getAnnotation(const jnipp::Ref<JavaLangClass>& a0) const {
    static jnipp::Method<JavaLangAnnotationAnnotation,JavaLangClass> method(clazz(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return method.call(*this, a0);
}

// public java.lang.annotation.Annotation[] java.lang.reflect.Constructor.getDeclaredAnnotations()
jnipp::LocalRef<jnipp::Array<JavaLangAnnotationAnnotation>> JavaLangReflectConstructor::getDeclaredAnnotations() const {
    static jnipp::Method<jnipp::Array<JavaLangAnnotationAnnotation>> method(clazz(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}

// public java.lang.Class[] java.lang.reflect.Constructor.getParameterTypes()
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangReflectConstructor::getParameterTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getParameterTypes", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.String java.lang.reflect.Constructor.toGenericString()
jnipp::LocalRef<JavaLangString> JavaLangReflectConstructor::toGenericString() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toGenericString", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.reflect.Type[] java.lang.reflect.Constructor.getGenericParameterTypes()
jnipp::LocalRef<jnipp::Array<JavaLangReflectType>> JavaLangReflectConstructor::getGenericParameterTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectType>> method(clazz(), "getGenericParameterTypes", "()[Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public java.lang.Class[] java.lang.reflect.Constructor.getExceptionTypes()
jnipp::LocalRef<jnipp::Array<JavaLangClass>> JavaLangReflectConstructor::getExceptionTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangClass>> method(clazz(), "getExceptionTypes", "()[Ljava/lang/Class;");
    return method.call(*this);
}

// public java.lang.reflect.Type[] java.lang.reflect.Constructor.getGenericExceptionTypes()
jnipp::LocalRef<jnipp::Array<JavaLangReflectType>> JavaLangReflectConstructor::getGenericExceptionTypes() const {
    static jnipp::Method<jnipp::Array<JavaLangReflectType>> method(clazz(), "getGenericExceptionTypes", "()[Ljava/lang/reflect/Type;");
    return method.call(*this);
}

// public boolean java.lang.reflect.Constructor.isVarArgs()
jboolean JavaLangReflectConstructor::isVarArgs() const {
    static jnipp::Method<jboolean> method(clazz(), "isVarArgs", "()Z");
    return method.call(*this);
}

// public java.lang.annotation.Annotation[][] java.lang.reflect.Constructor.getParameterAnnotations()
jnipp::LocalRef<jnipp::Array<jnipp::Array<JavaLangAnnotationAnnotation>>> JavaLangReflectConstructor::getParameterAnnotations() const {
    static jnipp::Method<jnipp::Array<jnipp::Array<JavaLangAnnotationAnnotation>>> method(clazz(), "getParameterAnnotations", "()[[Ljava/lang/annotation/Annotation;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaIoInputStream::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/io/InputStream"));
    return cls;
}

// public java.io.InputStream()
jnipp::LocalRef<JavaIoInputStream> JavaIoInputStream::construct() {
    static jnipp::Constructor<JavaIoInputStream> constructor(clazz(), "()V");
    return constructor.construct();
}

// public void java.io.InputStream.close() throws java.io.IOException
void JavaIoInputStream::close() const {
    static jnipp::Method<void> method(clazz(), "close", "()V");
    method.call(*this);
}

// public synchronized void java.io.InputStream.mark(int)
void JavaIoInputStream::mark(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "mark", "(I)V");
    method.call(*this, a0);
}

// public synchronized void java.io.InputStream.reset() throws java.io.IOException
void JavaIoInputStream::reset() const {
    static jnipp::Method<void> method(clazz(), "reset", "()V");
    method.call(*this);
}

// public int java.io.InputStream.read(byte[],int,int) throws java.io.IOException
jint JavaIoInputStream::read(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2) const {
    static jnipp::Method<jint,jnipp::Array<jbyte>,jint,jint> method(clazz(), "read", "([BII)I");
    return method.call(*this, a0, a1, a2);
}

// public int java.io.InputStream.read(byte[]) throws java.io.IOException
jint JavaIoInputStream::read(const jnipp::Ref<jnipp::Array<jbyte>>& a0) const {
    static jnipp::Method<jint,jnipp::Array<jbyte>> method(clazz(), "read", "([B)I");
    return method.call(*this, a0);
}

// public long java.io.InputStream.skip(long) throws java.io.IOException
jlong JavaIoInputStream::skip(jlong a0) const {
    static jnipp::Method<jlong,jlong> method(clazz(), "skip", "(J)J");
    return method.call(*this, a0);
}

// public int java.io.InputStream.available() throws java.io.IOException
jint JavaIoInputStream::available() const {
    static jnipp::Method<jint> method(clazz(), "available", "()I");
    return method.call(*this);
}

// public boolean java.io.InputStream.markSupported()
jboolean JavaIoInputStream::markSupported() const {
    static jnipp::Method<jboolean> method(clazz(), "markSupported", "()Z");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetURL::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/URL"));
    return cls;
}

// public java.net.URL(java.net.URL,java.lang.String,java.net.URLStreamHandler) throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURL::construct(const jnipp::Ref<JavaNetURL>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaNetURLStreamHandler>& a2) {
    static jnipp::Constructor<JavaNetURL,JavaNetURL,JavaLangString,JavaNetURLStreamHandler> constructor(clazz(), "(Ljava/net/URL;Ljava/lang/String;Ljava/net/URLStreamHandler;)V");
    return constructor.construct(a0, a1, a2);
}

// public java.net.URL(java.net.URL,java.lang.String) throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURL::construct(const jnipp::Ref<JavaNetURL>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::Constructor<JavaNetURL,JavaNetURL,JavaLangString> constructor(clazz(), "(Ljava/net/URL;Ljava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public java.net.URL(java.lang.String) throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURL::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaNetURL,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.net.URL(java.lang.String,java.lang.String,int,java.lang.String) throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURL::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, jint a2, const jnipp::Ref<JavaLangString>& a3) {
    static jnipp::Constructor<JavaNetURL,JavaLangString,JavaLangString,jint,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public java.net.URL(java.lang.String,java.lang.String,java.lang.String) throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURL::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2) {
    static jnipp::Constructor<JavaNetURL,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2);
}

// public java.net.URL(java.lang.String,java.lang.String,int,java.lang.String,java.net.URLStreamHandler) throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURL::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, jint a2, const jnipp::Ref<JavaLangString>& a3, const jnipp::Ref<JavaNetURLStreamHandler>& a4) {
    static jnipp::Constructor<JavaNetURL,JavaLangString,JavaLangString,jint,JavaLangString,JavaNetURLStreamHandler> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/net/URLStreamHandler;)V");
    return constructor.construct(a0, a1, a2, a3, a4);
}

// public boolean java.net.URL.equals(java.lang.Object)
jboolean JavaNetURL::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public synchronized int java.net.URL.hashCode()
jint JavaNetURL::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public final java.io.InputStream java.net.URL.openStream() throws java.io.IOException
jnipp::LocalRef<JavaIoInputStream> JavaNetURL::openStream() const {
    static jnipp::Method<JavaIoInputStream> method(clazz(), "openStream", "()Ljava/io/InputStream;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getPath()
jnipp::LocalRef<JavaLangString> JavaNetURL::getPath() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getPath", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.net.URI java.net.URL.toURI() throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURL::toURI() const {
    static jnipp::Method<JavaNetURI> method(clazz(), "toURI", "()Ljava/net/URI;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getAuthority()
jnipp::LocalRef<JavaLangString> JavaNetURL::getAuthority() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getAuthority", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getQuery()
jnipp::LocalRef<JavaLangString> JavaNetURL::getQuery() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getQuery", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.net.URLConnection java.net.URL.openConnection() throws java.io.IOException
jnipp::LocalRef<JavaNetURLConnection> JavaNetURL::openConnection() const {
    static jnipp::Method<JavaNetURLConnection> method(clazz(), "openConnection", "()Ljava/net/URLConnection;");
    return method.call(*this);
}

// public java.net.URLConnection java.net.URL.openConnection(java.net.Proxy) throws java.io.IOException
jnipp::LocalRef<JavaNetURLConnection> JavaNetURL::openConnection(const jnipp::Ref<JavaNetProxy>& a0) const {
    static jnipp::Method<JavaNetURLConnection,JavaNetProxy> method(clazz(), "openConnection", "(Ljava/net/Proxy;)Ljava/net/URLConnection;");
    return method.call(*this, a0);
}

// public java.lang.String java.net.URL.getProtocol()
jnipp::LocalRef<JavaLangString> JavaNetURL::getProtocol() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getProtocol", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getFile()
jnipp::LocalRef<JavaLangString> JavaNetURL::getFile() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getFile", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getHost()
jnipp::LocalRef<JavaLangString> JavaNetURL::getHost() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getHost", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getRef()
jnipp::LocalRef<JavaLangString> JavaNetURL::getRef() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRef", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URL.getUserInfo()
jnipp::LocalRef<JavaLangString> JavaNetURL::getUserInfo() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getUserInfo", "()Ljava/lang/String;");
    return method.call(*this);
}

// public int java.net.URL.getPort()
jint JavaNetURL::getPort() const {
    static jnipp::Method<jint> method(clazz(), "getPort", "()I");
    return method.call(*this);
}

// public int java.net.URL.getDefaultPort()
jint JavaNetURL::getDefaultPort() const {
    static jnipp::Method<jint> method(clazz(), "getDefaultPort", "()I");
    return method.call(*this);
}

// public boolean java.net.URL.sameFile(java.net.URL)
jboolean JavaNetURL::sameFile(const jnipp::Ref<JavaNetURL>& a0) const {
    static jnipp::Method<jboolean,JavaNetURL> method(clazz(), "sameFile", "(Ljava/net/URL;)Z");
    return method.call(*this, a0);
}

// public java.lang.String java.net.URL.toExternalForm()
jnipp::LocalRef<JavaLangString> JavaNetURL::toExternalForm() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toExternalForm", "()Ljava/lang/String;");
    return method.call(*this);
}

// public final java.lang.Object java.net.URL.getContent() throws java.io.IOException
jnipp::LocalRef<JavaLangObject> JavaNetURL::getContent() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "getContent", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public final java.lang.Object java.net.URL.getContent(java.lang.Class[]) throws java.io.IOException
jnipp::LocalRef<JavaLangObject> JavaNetURL::getContent(const jnipp::Ref<jnipp::Array<JavaLangClass>>& a0) const {
    static jnipp::Method<JavaLangObject,jnipp::Array<JavaLangClass>> method(clazz(), "getContent", "([Ljava/lang/Class;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public static void java.net.URL.setURLStreamHandlerFactory(java.net.URLStreamHandlerFactory)
void JavaNetURL::setURLStreamHandlerFactory(const jnipp::Ref<JavaNetURLStreamHandlerFactory>& a0) {
    static jnipp::StaticMethod<void,JavaNetURLStreamHandlerFactory> method(clazz(), "setURLStreamHandlerFactory", "(Ljava/net/URLStreamHandlerFactory;)V");
    method.call(a0);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangClassLoader::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/ClassLoader"));
    return cls;
}

// protected java.lang.ClassLoader(java.lang.ClassLoader)
jnipp::LocalRef<JavaLangClassLoader> JavaLangClassLoader::construct(const jnipp::Ref<JavaLangClassLoader>& a0) {
    static jnipp::Constructor<JavaLangClassLoader,JavaLangClassLoader> constructor(clazz(), "(Ljava/lang/ClassLoader;)V");
    return constructor.construct(a0);
}

// protected java.lang.ClassLoader()
jnipp::LocalRef<JavaLangClassLoader> JavaLangClassLoader::construct() {
    static jnipp::Constructor<JavaLangClassLoader> constructor(clazz(), "()V");
    return constructor.construct();
}

// private java.lang.ClassLoader(java.lang.Void,java.lang.ClassLoader)
jnipp::LocalRef<JavaLangClassLoader> JavaLangClassLoader::construct(const jnipp::Ref<JavaLangVoid>& a0, const jnipp::Ref<JavaLangClassLoader>& a1) {
    static jnipp::Constructor<JavaLangClassLoader,JavaLangVoid,JavaLangClassLoader> constructor(clazz(), "(Ljava/lang/Void;Ljava/lang/ClassLoader;)V");
    return constructor.construct(a0, a1);
}

// public java.lang.Class java.lang.ClassLoader.loadClass(java.lang.String) throws java.lang.ClassNotFoundException
jnipp::LocalRef<JavaLangClass> JavaLangClassLoader::loadClass(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangClass,JavaLangString> method(clazz(), "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    return method.call(*this, a0);
}

// public static java.lang.ClassLoader java.lang.ClassLoader.getSystemClassLoader()
jnipp::LocalRef<JavaLangClassLoader> JavaLangClassLoader::getSystemClassLoader() {
    static jnipp::StaticMethod<JavaLangClassLoader> method(clazz(), "getSystemClassLoader", "()Ljava/lang/ClassLoader;");
    return method.call();
}

// public java.io.InputStream java.lang.ClassLoader.getResourceAsStream(java.lang.String)
jnipp::LocalRef<JavaIoInputStream> JavaLangClassLoader::getResourceAsStream(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaIoInputStream,JavaLangString> method(clazz(), "getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return method.call(*this, a0);
}

// public java.net.URL java.lang.ClassLoader.getResource(java.lang.String)
jnipp::LocalRef<JavaNetURL> JavaLangClassLoader::getResource(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaNetURL,JavaLangString> method(clazz(), "getResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return method.call(*this, a0);
}

// public static java.io.InputStream java.lang.ClassLoader.getSystemResourceAsStream(java.lang.String)
jnipp::LocalRef<JavaIoInputStream> JavaLangClassLoader::getSystemResourceAsStream(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaIoInputStream,JavaLangString> method(clazz(), "getSystemResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return method.call(a0);
}

// public static java.net.URL java.lang.ClassLoader.getSystemResource(java.lang.String)
jnipp::LocalRef<JavaNetURL> JavaLangClassLoader::getSystemResource(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaNetURL,JavaLangString> method(clazz(), "getSystemResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return method.call(a0);
}

// public java.util.Enumeration java.lang.ClassLoader.getResources(java.lang.String) throws java.io.IOException
jnipp::LocalRef<JavaUtilEnumeration> JavaLangClassLoader::getResources(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaUtilEnumeration,JavaLangString> method(clazz(), "getResources", "(Ljava/lang/String;)Ljava/util/Enumeration;");
    return method.call(*this, a0);
}

// public static java.util.Enumeration java.lang.ClassLoader.getSystemResources(java.lang.String) throws java.io.IOException
jnipp::LocalRef<JavaUtilEnumeration> JavaLangClassLoader::getSystemResources(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaUtilEnumeration,JavaLangString> method(clazz(), "getSystemResources", "(Ljava/lang/String;)Ljava/util/Enumeration;");
    return method.call(a0);
}

// public final java.lang.ClassLoader java.lang.ClassLoader.getParent()
jnipp::LocalRef<JavaLangClassLoader> JavaLangClassLoader::getParent() const {
    static jnipp::Method<JavaLangClassLoader> method(clazz(), "getParent", "()Ljava/lang/ClassLoader;");
    return method.call(*this);
}

// public void java.lang.ClassLoader.setDefaultAssertionStatus(boolean)
void JavaLangClassLoader::setDefaultAssertionStatus(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setDefaultAssertionStatus", "(Z)V");
    method.call(*this, a0);
}

// public void java.lang.ClassLoader.setPackageAssertionStatus(java.lang.String,boolean)
void JavaLangClassLoader::setPackageAssertionStatus(const jnipp::Ref<JavaLangString>& a0, jboolean a1) const {
    static jnipp::Method<void,JavaLangString,jboolean> method(clazz(), "setPackageAssertionStatus", "(Ljava/lang/String;Z)V");
    method.call(*this, a0, a1);
}

// public void java.lang.ClassLoader.setClassAssertionStatus(java.lang.String,boolean)
void JavaLangClassLoader::setClassAssertionStatus(const jnipp::Ref<JavaLangString>& a0, jboolean a1) const {
    static jnipp::Method<void,JavaLangString,jboolean> method(clazz(), "setClassAssertionStatus", "(Ljava/lang/String;Z)V");
    method.call(*this, a0, a1);
}

// public void java.lang.ClassLoader.clearAssertionStatus()
void JavaLangClassLoader::clearAssertionStatus() const {
    static jnipp::Method<void> method(clazz(), "clearAssertionStatus", "()V");
    method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangReflectType::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/reflect/Type"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangAnnotationAnnotation::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/annotation/Annotation"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityPermissionCollection::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/PermissionCollection"));
    return cls;
}

// public java.security.PermissionCollection()
jnipp::LocalRef<JavaSecurityPermissionCollection> JavaSecurityPermissionCollection::construct() {
    static jnipp::Constructor<JavaSecurityPermissionCollection> constructor(clazz(), "()V");
    return constructor.construct();
}

// public void java.security.PermissionCollection.setReadOnly()
void JavaSecurityPermissionCollection::setReadOnly() const {
    static jnipp::Method<void> method(clazz(), "setReadOnly", "()V");
    method.call(*this);
}

// public boolean java.security.PermissionCollection.isReadOnly()
jboolean JavaSecurityPermissionCollection::isReadOnly() const {
    static jnipp::Method<jboolean> method(clazz(), "isReadOnly", "()Z");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityPrincipal::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/Principal"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityCodeSource::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/CodeSource"));
    return cls;
}

// public java.security.CodeSource(java.net.URL,java.security.cert.Certificate[])
jnipp::LocalRef<JavaSecurityCodeSource> JavaSecurityCodeSource::construct(const jnipp::Ref<JavaNetURL>& a0, const jnipp::Ref<jnipp::Array<JavaSecurityCertCertificate>>& a1) {
    static jnipp::Constructor<JavaSecurityCodeSource,JavaNetURL,jnipp::Array<JavaSecurityCertCertificate>> constructor(clazz(), "(Ljava/net/URL;[Ljava/security/cert/Certificate;)V");
    return constructor.construct(a0, a1);
}

// public java.security.CodeSource(java.net.URL,java.security.CodeSigner[])
jnipp::LocalRef<JavaSecurityCodeSource> JavaSecurityCodeSource::construct(const jnipp::Ref<JavaNetURL>& a0, const jnipp::Ref<jnipp::Array<JavaSecurityCodeSigner>>& a1) {
    static jnipp::Constructor<JavaSecurityCodeSource,JavaNetURL,jnipp::Array<JavaSecurityCodeSigner>> constructor(clazz(), "(Ljava/net/URL;[Ljava/security/CodeSigner;)V");
    return constructor.construct(a0, a1);
}

// public boolean java.security.CodeSource.equals(java.lang.Object)
jboolean JavaSecurityCodeSource::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.security.CodeSource.hashCode()
jint JavaSecurityCodeSource::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public final java.net.URL java.security.CodeSource.getLocation()
jnipp::LocalRef<JavaNetURL> JavaSecurityCodeSource::getLocation() const {
    static jnipp::Method<JavaNetURL> method(clazz(), "getLocation", "()Ljava/net/URL;");
    return method.call(*this);
}

// public final java.security.cert.Certificate[] java.security.CodeSource.getCertificates()
jnipp::LocalRef<jnipp::Array<JavaSecurityCertCertificate>> JavaSecurityCodeSource::getCertificates() const {
    static jnipp::Method<jnipp::Array<JavaSecurityCertCertificate>> method(clazz(), "getCertificates", "()[Ljava/security/cert/Certificate;");
    return method.call(*this);
}

// public boolean java.security.CodeSource.implies(java.security.CodeSource)
jboolean JavaSecurityCodeSource::implies(const jnipp::Ref<JavaSecurityCodeSource>& a0) const {
    static jnipp::Method<jboolean,JavaSecurityCodeSource> method(clazz(), "implies", "(Ljava/security/CodeSource;)Z");
    return method.call(*this, a0);
}

// public final java.security.CodeSigner[] java.security.CodeSource.getCodeSigners()
jnipp::LocalRef<jnipp::Array<JavaSecurityCodeSigner>> JavaSecurityCodeSource::getCodeSigners() const {
    static jnipp::Method<jnipp::Array<JavaSecurityCodeSigner>> method(clazz(), "getCodeSigners", "()[Ljava/security/CodeSigner;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityPermission::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/Permission"));
    return cls;
}

// public java.security.Permission(java.lang.String)
jnipp::LocalRef<JavaSecurityPermission> JavaSecurityPermission::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaSecurityPermission,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public final java.lang.String java.security.Permission.getName()
jnipp::LocalRef<JavaLangString> JavaSecurityPermission::getName() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getName", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.security.PermissionCollection java.security.Permission.newPermissionCollection()
jnipp::LocalRef<JavaSecurityPermissionCollection> JavaSecurityPermission::newPermissionCollection() const {
    static jnipp::Method<JavaSecurityPermissionCollection> method(clazz(), "newPermissionCollection", "()Ljava/security/PermissionCollection;");
    return method.call(*this);
}

// public void java.security.Permission.checkGuard(java.lang.Object) throws java.lang.SecurityException
void JavaSecurityPermission::checkGuard(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<void,JavaLangObject> method(clazz(), "checkGuard", "(Ljava/lang/Object;)V");
    method.call(*this, a0);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilJarManifest::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/jar/Manifest"));
    return cls;
}

// public java.util.jar.Manifest(java.util.jar.Manifest)
jnipp::LocalRef<JavaUtilJarManifest> JavaUtilJarManifest::construct(const jnipp::Ref<JavaUtilJarManifest>& a0) {
    static jnipp::Constructor<JavaUtilJarManifest,JavaUtilJarManifest> constructor(clazz(), "(Ljava/util/jar/Manifest;)V");
    return constructor.construct(a0);
}

// public java.util.jar.Manifest(java.io.InputStream) throws java.io.IOException
jnipp::LocalRef<JavaUtilJarManifest> JavaUtilJarManifest::construct(const jnipp::Ref<JavaIoInputStream>& a0) {
    static jnipp::Constructor<JavaUtilJarManifest,JavaIoInputStream> constructor(clazz(), "(Ljava/io/InputStream;)V");
    return constructor.construct(a0);
}

// public java.util.jar.Manifest()
jnipp::LocalRef<JavaUtilJarManifest> JavaUtilJarManifest::construct() {
    static jnipp::Constructor<JavaUtilJarManifest> constructor(clazz(), "()V");
    return constructor.construct();
}

// public boolean java.util.jar.Manifest.equals(java.lang.Object)
jboolean JavaUtilJarManifest::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.util.jar.Manifest.hashCode()
jint JavaUtilJarManifest::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.Object java.util.jar.Manifest.clone()
jnipp::LocalRef<JavaLangObject> JavaUtilJarManifest::clone() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "clone", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public void java.util.jar.Manifest.clear()
void JavaUtilJarManifest::clear() const {
    static jnipp::Method<void> method(clazz(), "clear", "()V");
    method.call(*this);
}

// public void java.util.jar.Manifest.write(java.io.OutputStream) throws java.io.IOException
void JavaUtilJarManifest::write(const jnipp::Ref<JavaIoOutputStream>& a0) const {
    static jnipp::Method<void,JavaIoOutputStream> method(clazz(), "write", "(Ljava/io/OutputStream;)V");
    method.call(*this, a0);
}

// public void java.util.jar.Manifest.read(java.io.InputStream) throws java.io.IOException
void JavaUtilJarManifest::read(const jnipp::Ref<JavaIoInputStream>& a0) const {
    static jnipp::Method<void,JavaIoInputStream> method(clazz(), "read", "(Ljava/io/InputStream;)V");
    method.call(*this, a0);
}

// public java.util.jar.Attributes java.util.jar.Manifest.getAttributes(java.lang.String)
jnipp::LocalRef<JavaUtilJarAttributes> JavaUtilJarManifest::getAttributes(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaUtilJarAttributes,JavaLangString> method(clazz(), "getAttributes", "(Ljava/lang/String;)Ljava/util/jar/Attributes;");
    return method.call(*this, a0);
}

// public java.util.jar.Attributes java.util.jar.Manifest.getMainAttributes()
jnipp::LocalRef<JavaUtilJarAttributes> JavaUtilJarManifest::getMainAttributes() const {
    static jnipp::Method<JavaUtilJarAttributes> method(clazz(), "getMainAttributes", "()Ljava/util/jar/Attributes;");
    return method.call(*this);
}

// public java.util.Map java.util.jar.Manifest.getEntries()
jnipp::LocalRef<JavaUtilMap> JavaUtilJarManifest::getEntries() const {
    static jnipp::Method<JavaUtilMap> method(clazz(), "getEntries", "()Ljava/util/Map;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangPackage_1::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Package$1"));
    return cls;
}

// java.lang.Package$1(java.lang.String,java.lang.String)
jnipp::LocalRef<JavaLangPackage_1> JavaLangPackage_1::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::Constructor<JavaLangPackage_1,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1);
}

// public java.lang.Package java.lang.Package$1.run()
jnipp::LocalRef<JavaLangPackage> JavaLangPackage_1::run() const {
    static jnipp::Method<JavaLangPackage> method(clazz(), "run", "()Ljava/lang/Package;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetURLConnection::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/URLConnection"));
    return cls;
}

// protected java.net.URLConnection(java.net.URL)
jnipp::LocalRef<JavaNetURLConnection> JavaNetURLConnection::construct(const jnipp::Ref<JavaNetURL>& a0) {
    static jnipp::Constructor<JavaNetURLConnection,JavaNetURL> constructor(clazz(), "(Ljava/net/URL;)V");
    return constructor.construct(a0);
}

// public java.net.URL java.net.URLConnection.getURL()
jnipp::LocalRef<JavaNetURL> JavaNetURLConnection::getURL() const {
    static jnipp::Method<JavaNetURL> method(clazz(), "getURL", "()Ljava/net/URL;");
    return method.call(*this);
}

// public java.io.InputStream java.net.URLConnection.getInputStream() throws java.io.IOException
jnipp::LocalRef<JavaIoInputStream> JavaNetURLConnection::getInputStream() const {
    static jnipp::Method<JavaIoInputStream> method(clazz(), "getInputStream", "()Ljava/io/InputStream;");
    return method.call(*this);
}

// public java.security.Permission java.net.URLConnection.getPermission() throws java.io.IOException
jnipp::LocalRef<JavaSecurityPermission> JavaNetURLConnection::getPermission() const {
    static jnipp::Method<JavaSecurityPermission> method(clazz(), "getPermission", "()Ljava/security/Permission;");
    return method.call(*this);
}

// public java.lang.Object java.net.URLConnection.getContent(java.lang.Class[]) throws java.io.IOException
jnipp::LocalRef<JavaLangObject> JavaNetURLConnection::getContent(const jnipp::Ref<jnipp::Array<JavaLangClass>>& a0) const {
    static jnipp::Method<JavaLangObject,jnipp::Array<JavaLangClass>> method(clazz(), "getContent", "([Ljava/lang/Class;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public java.lang.Object java.net.URLConnection.getContent() throws java.io.IOException
jnipp::LocalRef<JavaLangObject> JavaNetURLConnection::getContent() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "getContent", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public void java.net.URLConnection.setRequestProperty(java.lang.String,java.lang.String)
void JavaNetURLConnection::setRequestProperty(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<void,JavaLangString,JavaLangString> method(clazz(), "setRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
    method.call(*this, a0, a1);
}

// public long java.net.URLConnection.getDate()
jlong JavaNetURLConnection::getDate() const {
    static jnipp::Method<jlong> method(clazz(), "getDate", "()J");
    return method.call(*this);
}

// public int java.net.URLConnection.getContentLength()
jint JavaNetURLConnection::getContentLength() const {
    static jnipp::Method<jint> method(clazz(), "getContentLength", "()I");
    return method.call(*this);
}

// public java.lang.String java.net.URLConnection.getHeaderField(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getHeaderField(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangString> method(clazz(), "getHeaderField", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.net.URLConnection.getHeaderField(int)
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getHeaderField(jint a0) const {
    static jnipp::Method<JavaLangString,jint> method(clazz(), "getHeaderField", "(I)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public long java.net.URLConnection.getContentLengthLong()
jlong JavaNetURLConnection::getContentLengthLong() const {
    static jnipp::Method<jlong> method(clazz(), "getContentLengthLong", "()J");
    return method.call(*this);
}

// public java.lang.String java.net.URLConnection.getHeaderFieldKey(int)
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getHeaderFieldKey(jint a0) const {
    static jnipp::Method<JavaLangString,jint> method(clazz(), "getHeaderFieldKey", "(I)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public long java.net.URLConnection.getLastModified()
jlong JavaNetURLConnection::getLastModified() const {
    static jnipp::Method<jlong> method(clazz(), "getLastModified", "()J");
    return method.call(*this);
}

// public static synchronized java.net.FileNameMap java.net.URLConnection.getFileNameMap()
jnipp::LocalRef<JavaNetFileNameMap> JavaNetURLConnection::getFileNameMap() {
    static jnipp::StaticMethod<JavaNetFileNameMap> method(clazz(), "getFileNameMap", "()Ljava/net/FileNameMap;");
    return method.call();
}

// public void java.net.URLConnection.addRequestProperty(java.lang.String,java.lang.String)
void JavaNetURLConnection::addRequestProperty(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<void,JavaLangString,JavaLangString> method(clazz(), "addRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
    method.call(*this, a0, a1);
}

// public java.lang.String java.net.URLConnection.getRequestProperty(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getRequestProperty(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangString> method(clazz(), "getRequestProperty", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.util.Map java.net.URLConnection.getRequestProperties()
jnipp::LocalRef<JavaUtilMap> JavaNetURLConnection::getRequestProperties() const {
    static jnipp::Method<JavaUtilMap> method(clazz(), "getRequestProperties", "()Ljava/util/Map;");
    return method.call(*this);
}

// public java.lang.String java.net.URLConnection.getContentType()
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getContentType() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getContentType", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static java.lang.String java.net.URLConnection.guessContentTypeFromStream(java.io.InputStream) throws java.io.IOException
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::guessContentTypeFromStream(const jnipp::Ref<JavaIoInputStream>& a0) {
    static jnipp::StaticMethod<JavaLangString,JavaIoInputStream> method(clazz(), "guessContentTypeFromStream", "(Ljava/io/InputStream;)Ljava/lang/String;");
    return method.call(a0);
}

// public static java.lang.String java.net.URLConnection.guessContentTypeFromName(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::guessContentTypeFromName(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaLangString,JavaLangString> method(clazz(), "guessContentTypeFromName", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(a0);
}

// public static void java.net.URLConnection.setFileNameMap(java.net.FileNameMap)
void JavaNetURLConnection::setFileNameMap(const jnipp::Ref<JavaNetFileNameMap>& a0) {
    static jnipp::StaticMethod<void,JavaNetFileNameMap> method(clazz(), "setFileNameMap", "(Ljava/net/FileNameMap;)V");
    method.call(a0);
}

// public void java.net.URLConnection.setConnectTimeout(int)
void JavaNetURLConnection::setConnectTimeout(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setConnectTimeout", "(I)V");
    method.call(*this, a0);
}

// public int java.net.URLConnection.getConnectTimeout()
jint JavaNetURLConnection::getConnectTimeout() const {
    static jnipp::Method<jint> method(clazz(), "getConnectTimeout", "()I");
    return method.call(*this);
}

// public void java.net.URLConnection.setReadTimeout(int)
void JavaNetURLConnection::setReadTimeout(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setReadTimeout", "(I)V");
    method.call(*this, a0);
}

// public int java.net.URLConnection.getReadTimeout()
jint JavaNetURLConnection::getReadTimeout() const {
    static jnipp::Method<jint> method(clazz(), "getReadTimeout", "()I");
    return method.call(*this);
}

// public java.lang.String java.net.URLConnection.getContentEncoding()
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getContentEncoding() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getContentEncoding", "()Ljava/lang/String;");
    return method.call(*this);
}

// public long java.net.URLConnection.getExpiration()
jlong JavaNetURLConnection::getExpiration() const {
    static jnipp::Method<jlong> method(clazz(), "getExpiration", "()J");
    return method.call(*this);
}

// public java.util.Map java.net.URLConnection.getHeaderFields()
jnipp::LocalRef<JavaUtilMap> JavaNetURLConnection::getHeaderFields() const {
    static jnipp::Method<JavaUtilMap> method(clazz(), "getHeaderFields", "()Ljava/util/Map;");
    return method.call(*this);
}

// public int java.net.URLConnection.getHeaderFieldInt(java.lang.String,int)
jint JavaNetURLConnection::getHeaderFieldInt(const jnipp::Ref<JavaLangString>& a0, jint a1) const {
    static jnipp::Method<jint,JavaLangString,jint> method(clazz(), "getHeaderFieldInt", "(Ljava/lang/String;I)I");
    return method.call(*this, a0, a1);
}

// public long java.net.URLConnection.getHeaderFieldLong(java.lang.String,long)
jlong JavaNetURLConnection::getHeaderFieldLong(const jnipp::Ref<JavaLangString>& a0, jlong a1) const {
    static jnipp::Method<jlong,JavaLangString,jlong> method(clazz(), "getHeaderFieldLong", "(Ljava/lang/String;J)J");
    return method.call(*this, a0, a1);
}

// public long java.net.URLConnection.getHeaderFieldDate(java.lang.String,long)
jlong JavaNetURLConnection::getHeaderFieldDate(const jnipp::Ref<JavaLangString>& a0, jlong a1) const {
    static jnipp::Method<jlong,JavaLangString,jlong> method(clazz(), "getHeaderFieldDate", "(Ljava/lang/String;J)J");
    return method.call(*this, a0, a1);
}

// public java.io.OutputStream java.net.URLConnection.getOutputStream() throws java.io.IOException
jnipp::LocalRef<JavaIoOutputStream> JavaNetURLConnection::getOutputStream() const {
    static jnipp::Method<JavaIoOutputStream> method(clazz(), "getOutputStream", "()Ljava/io/OutputStream;");
    return method.call(*this);
}

// public void java.net.URLConnection.setDoInput(boolean)
void JavaNetURLConnection::setDoInput(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setDoInput", "(Z)V");
    method.call(*this, a0);
}

// public boolean java.net.URLConnection.getDoInput()
jboolean JavaNetURLConnection::getDoInput() const {
    static jnipp::Method<jboolean> method(clazz(), "getDoInput", "()Z");
    return method.call(*this);
}

// public void java.net.URLConnection.setDoOutput(boolean)
void JavaNetURLConnection::setDoOutput(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setDoOutput", "(Z)V");
    method.call(*this, a0);
}

// public boolean java.net.URLConnection.getDoOutput()
jboolean JavaNetURLConnection::getDoOutput() const {
    static jnipp::Method<jboolean> method(clazz(), "getDoOutput", "()Z");
    return method.call(*this);
}

// public void java.net.URLConnection.setAllowUserInteraction(boolean)
void JavaNetURLConnection::setAllowUserInteraction(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setAllowUserInteraction", "(Z)V");
    method.call(*this, a0);
}

// public boolean java.net.URLConnection.getAllowUserInteraction()
jboolean JavaNetURLConnection::getAllowUserInteraction() const {
    static jnipp::Method<jboolean> method(clazz(), "getAllowUserInteraction", "()Z");
    return method.call(*this);
}

// public static void java.net.URLConnection.setDefaultAllowUserInteraction(boolean)
void JavaNetURLConnection::setDefaultAllowUserInteraction(jboolean a0) {
    static jnipp::StaticMethod<void,jboolean> method(clazz(), "setDefaultAllowUserInteraction", "(Z)V");
    method.call(a0);
}

// public static boolean java.net.URLConnection.getDefaultAllowUserInteraction()
jboolean JavaNetURLConnection::getDefaultAllowUserInteraction() {
    static jnipp::StaticMethod<jboolean> method(clazz(), "getDefaultAllowUserInteraction", "()Z");
    return method.call();
}

// public void java.net.URLConnection.setUseCaches(boolean)
void JavaNetURLConnection::setUseCaches(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setUseCaches", "(Z)V");
    method.call(*this, a0);
}

// public boolean java.net.URLConnection.getUseCaches()
jboolean JavaNetURLConnection::getUseCaches() const {
    static jnipp::Method<jboolean> method(clazz(), "getUseCaches", "()Z");
    return method.call(*this);
}

// public void java.net.URLConnection.setIfModifiedSince(long)
void JavaNetURLConnection::setIfModifiedSince(jlong a0) const {
    static jnipp::Method<void,jlong> method(clazz(), "setIfModifiedSince", "(J)V");
    method.call(*this, a0);
}

// public long java.net.URLConnection.getIfModifiedSince()
jlong JavaNetURLConnection::getIfModifiedSince() const {
    static jnipp::Method<jlong> method(clazz(), "getIfModifiedSince", "()J");
    return method.call(*this);
}

// public boolean java.net.URLConnection.getDefaultUseCaches()
jboolean JavaNetURLConnection::getDefaultUseCaches() const {
    static jnipp::Method<jboolean> method(clazz(), "getDefaultUseCaches", "()Z");
    return method.call(*this);
}

// public void java.net.URLConnection.setDefaultUseCaches(boolean)
void JavaNetURLConnection::setDefaultUseCaches(jboolean a0) const {
    static jnipp::Method<void,jboolean> method(clazz(), "setDefaultUseCaches", "(Z)V");
    method.call(*this, a0);
}

// public static void java.net.URLConnection.setDefaultRequestProperty(java.lang.String,java.lang.String)
void JavaNetURLConnection::setDefaultRequestProperty(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) {
    static jnipp::StaticMethod<void,JavaLangString,JavaLangString> method(clazz(), "setDefaultRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
    method.call(a0, a1);
}

// public static java.lang.String java.net.URLConnection.getDefaultRequestProperty(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaNetURLConnection::getDefaultRequestProperty(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaLangString,JavaLangString> method(clazz(), "getDefaultRequestProperty", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(a0);
}

// public static synchronized void java.net.URLConnection.setContentHandlerFactory(java.net.ContentHandlerFactory)
void JavaNetURLConnection::setContentHandlerFactory(const jnipp::Ref<JavaNetContentHandlerFactory>& a0) {
    static jnipp::StaticMethod<void,JavaNetContentHandlerFactory> method(clazz(), "setContentHandlerFactory", "(Ljava/net/ContentHandlerFactory;)V");
    method.call(a0);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetURLStreamHandlerFactory::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/URLStreamHandlerFactory"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetProxy::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/Proxy"));
    return cls;
}

// private java.net.Proxy()
jnipp::LocalRef<JavaNetProxy> JavaNetProxy::construct() {
    static jnipp::Constructor<JavaNetProxy> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.net.Proxy(java.net.Proxy$Type,java.net.SocketAddress)
jnipp::LocalRef<JavaNetProxy> JavaNetProxy::construct(const jnipp::Ref<JavaNetProxy_Type>& a0, const jnipp::Ref<JavaNetSocketAddress>& a1) {
    static jnipp::Constructor<JavaNetProxy,JavaNetProxy_Type,JavaNetSocketAddress> constructor(clazz(), "(Ljava/net/Proxy$Type;Ljava/net/SocketAddress;)V");
    return constructor.construct(a0, a1);
}

// public java.net.Proxy$Type java.net.Proxy.type()
jnipp::LocalRef<JavaNetProxy_Type> JavaNetProxy::type() const {
    static jnipp::Method<JavaNetProxy_Type> method(clazz(), "type", "()Ljava/net/Proxy$Type;");
    return method.call(*this);
}

// public final boolean java.net.Proxy.equals(java.lang.Object)
jboolean JavaNetProxy::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public final int java.net.Proxy.hashCode()
jint JavaNetProxy::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.net.SocketAddress java.net.Proxy.address()
jnipp::LocalRef<JavaNetSocketAddress> JavaNetProxy::address() const {
    static jnipp::Method<JavaNetSocketAddress> method(clazz(), "address", "()Ljava/net/SocketAddress;");
    return method.call(*this);
}
const jnipp::StaticField<JavaNetProxy> JavaNetProxy::NO_PROXY ("java/net/Proxy", "NO_PROXY", "Ljava/net/Proxy;");
inline jnipp::GlobalRef<jnipp::Class>& JavaNetURI::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/URI"));
    return cls;
}

// public java.net.URI(java.lang.String,java.lang.String,java.lang.String) throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURI::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2) {
    static jnipp::Constructor<JavaNetURI,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2);
}

// public java.net.URI(java.lang.String,java.lang.String,java.lang.String,java.lang.String) throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURI::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3) {
    static jnipp::Constructor<JavaNetURI,JavaLangString,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3);
}

// public java.net.URI(java.lang.String,java.lang.String,java.lang.String,java.lang.String,java.lang.String) throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURI::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, const jnipp::Ref<JavaLangString>& a3, const jnipp::Ref<JavaLangString>& a4) {
    static jnipp::Constructor<JavaNetURI,JavaLangString,JavaLangString,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3, a4);
}

// private java.net.URI()
jnipp::LocalRef<JavaNetURI> JavaNetURI::construct() {
    static jnipp::Constructor<JavaNetURI> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.net.URI(java.lang.String) throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURI::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaNetURI,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.net.URI(java.lang.String,java.lang.String,java.lang.String,int,java.lang.String,java.lang.String,java.lang.String) throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURI::construct(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1, const jnipp::Ref<JavaLangString>& a2, jint a3, const jnipp::Ref<JavaLangString>& a4, const jnipp::Ref<JavaLangString>& a5, const jnipp::Ref<JavaLangString>& a6) {
    static jnipp::Constructor<JavaNetURI,JavaLangString,JavaLangString,JavaLangString,jint,JavaLangString,JavaLangString,JavaLangString> constructor(clazz(), "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5, a6);
}

// public boolean java.net.URI.equals(java.lang.Object)
jboolean JavaNetURI::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.net.URI.hashCode()
jint JavaNetURI::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public int java.net.URI.compareTo(java.net.URI)
jint JavaNetURI::compareTo(const jnipp::Ref<JavaNetURI>& a0) const {
    static jnipp::Method<jint,JavaNetURI> method(clazz(), "compareTo", "(Ljava/net/URI;)I");
    return method.call(*this, a0);
}

// public boolean java.net.URI.isAbsolute()
jboolean JavaNetURI::isAbsolute() const {
    static jnipp::Method<jboolean> method(clazz(), "isAbsolute", "()Z");
    return method.call(*this);
}

// public java.net.URI java.net.URI.resolve(java.lang.String)
jnipp::LocalRef<JavaNetURI> JavaNetURI::resolve(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaNetURI,JavaLangString> method(clazz(), "resolve", "(Ljava/lang/String;)Ljava/net/URI;");
    return method.call(*this, a0);
}

// public java.net.URI java.net.URI.resolve(java.net.URI)
jnipp::LocalRef<JavaNetURI> JavaNetURI::resolve(const jnipp::Ref<JavaNetURI>& a0) const {
    static jnipp::Method<JavaNetURI,JavaNetURI> method(clazz(), "resolve", "(Ljava/net/URI;)Ljava/net/URI;");
    return method.call(*this, a0);
}

// public java.net.URI java.net.URI.normalize()
jnipp::LocalRef<JavaNetURI> JavaNetURI::normalize() const {
    static jnipp::Method<JavaNetURI> method(clazz(), "normalize", "()Ljava/net/URI;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getPath()
jnipp::LocalRef<JavaLangString> JavaNetURI::getPath() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getPath", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.net.URL java.net.URI.toURL() throws java.net.MalformedURLException
jnipp::LocalRef<JavaNetURL> JavaNetURI::toURL() const {
    static jnipp::Method<JavaNetURL> method(clazz(), "toURL", "()Ljava/net/URL;");
    return method.call(*this);
}

// public boolean java.net.URI.isOpaque()
jboolean JavaNetURI::isOpaque() const {
    static jnipp::Method<jboolean> method(clazz(), "isOpaque", "()Z");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getScheme()
jnipp::LocalRef<JavaLangString> JavaNetURI::getScheme() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getScheme", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getAuthority()
jnipp::LocalRef<JavaLangString> JavaNetURI::getAuthority() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getAuthority", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getFragment()
jnipp::LocalRef<JavaLangString> JavaNetURI::getFragment() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getFragment", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getQuery()
jnipp::LocalRef<JavaLangString> JavaNetURI::getQuery() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getQuery", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getHost()
jnipp::LocalRef<JavaLangString> JavaNetURI::getHost() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getHost", "()Ljava/lang/String;");
    return method.call(*this);
}

// public static java.net.URI java.net.URI.create(java.lang.String)
jnipp::LocalRef<JavaNetURI> JavaNetURI::create(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaNetURI,JavaLangString> method(clazz(), "create", "(Ljava/lang/String;)Ljava/net/URI;");
    return method.call(a0);
}

// public java.lang.String java.net.URI.getUserInfo()
jnipp::LocalRef<JavaLangString> JavaNetURI::getUserInfo() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getUserInfo", "()Ljava/lang/String;");
    return method.call(*this);
}

// public int java.net.URI.getPort()
jint JavaNetURI::getPort() const {
    static jnipp::Method<jint> method(clazz(), "getPort", "()I");
    return method.call(*this);
}

// public java.net.URI java.net.URI.parseServerAuthority() throws java.net.URISyntaxException
jnipp::LocalRef<JavaNetURI> JavaNetURI::parseServerAuthority() const {
    static jnipp::Method<JavaNetURI> method(clazz(), "parseServerAuthority", "()Ljava/net/URI;");
    return method.call(*this);
}

// public java.net.URI java.net.URI.relativize(java.net.URI)
jnipp::LocalRef<JavaNetURI> JavaNetURI::relativize(const jnipp::Ref<JavaNetURI>& a0) const {
    static jnipp::Method<JavaNetURI,JavaNetURI> method(clazz(), "relativize", "(Ljava/net/URI;)Ljava/net/URI;");
    return method.call(*this, a0);
}

// public java.lang.String java.net.URI.getRawSchemeSpecificPart()
jnipp::LocalRef<JavaLangString> JavaNetURI::getRawSchemeSpecificPart() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRawSchemeSpecificPart", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getSchemeSpecificPart()
jnipp::LocalRef<JavaLangString> JavaNetURI::getSchemeSpecificPart() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getSchemeSpecificPart", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getRawAuthority()
jnipp::LocalRef<JavaLangString> JavaNetURI::getRawAuthority() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRawAuthority", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getRawUserInfo()
jnipp::LocalRef<JavaLangString> JavaNetURI::getRawUserInfo() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRawUserInfo", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getRawPath()
jnipp::LocalRef<JavaLangString> JavaNetURI::getRawPath() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRawPath", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getRawQuery()
jnipp::LocalRef<JavaLangString> JavaNetURI::getRawQuery() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRawQuery", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.getRawFragment()
jnipp::LocalRef<JavaLangString> JavaNetURI::getRawFragment() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getRawFragment", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.net.URI.toASCIIString()
jnipp::LocalRef<JavaLangString> JavaNetURI::toASCIIString() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toASCIIString", "()Ljava/lang/String;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetURLStreamHandler::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/URLStreamHandler"));
    return cls;
}

// public java.net.URLStreamHandler()
jnipp::LocalRef<JavaNetURLStreamHandler> JavaNetURLStreamHandler::construct() {
    static jnipp::Constructor<JavaNetURLStreamHandler> constructor(clazz(), "()V");
    return constructor.construct();
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilEnumeration::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Enumeration"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaLangVoid::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/lang/Void"));
    return cls;
}

// private java.lang.Void()
jnipp::LocalRef<JavaLangVoid> JavaLangVoid::construct() {
    static jnipp::Constructor<JavaLangVoid> constructor(clazz(), "()V");
    return constructor.construct();
}
const jnipp::StaticField<JavaLangClass> JavaLangVoid::TYPE ("java/lang/Void", "TYPE", "Ljava/lang/Class;");
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityCodeSigner::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/CodeSigner"));
    return cls;
}

// public java.security.CodeSigner(java.security.cert.CertPath,java.security.Timestamp)
jnipp::LocalRef<JavaSecurityCodeSigner> JavaSecurityCodeSigner::construct(const jnipp::Ref<JavaSecurityCertCertPath>& a0, const jnipp::Ref<JavaSecurityTimestamp>& a1) {
    static jnipp::Constructor<JavaSecurityCodeSigner,JavaSecurityCertCertPath,JavaSecurityTimestamp> constructor(clazz(), "(Ljava/security/cert/CertPath;Ljava/security/Timestamp;)V");
    return constructor.construct(a0, a1);
}

// public boolean java.security.CodeSigner.equals(java.lang.Object)
jboolean JavaSecurityCodeSigner::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.security.CodeSigner.hashCode()
jint JavaSecurityCodeSigner::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.security.cert.CertPath java.security.CodeSigner.getSignerCertPath()
jnipp::LocalRef<JavaSecurityCertCertPath> JavaSecurityCodeSigner::getSignerCertPath() const {
    static jnipp::Method<JavaSecurityCertCertPath> method(clazz(), "getSignerCertPath", "()Ljava/security/cert/CertPath;");
    return method.call(*this);
}

// public java.security.Timestamp java.security.CodeSigner.getTimestamp()
jnipp::LocalRef<JavaSecurityTimestamp> JavaSecurityCodeSigner::getTimestamp() const {
    static jnipp::Method<JavaSecurityTimestamp> method(clazz(), "getTimestamp", "()Ljava/security/Timestamp;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityCertCertificate::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/cert/Certificate"));
    return cls;
}

// protected java.security.cert.Certificate(java.lang.String)
jnipp::LocalRef<JavaSecurityCertCertificate> JavaSecurityCertCertificate::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaSecurityCertCertificate,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public boolean java.security.cert.Certificate.equals(java.lang.Object)
jboolean JavaSecurityCertCertificate::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.security.cert.Certificate.hashCode()
jint JavaSecurityCertCertificate::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public final java.lang.String java.security.cert.Certificate.getType()
jnipp::LocalRef<JavaLangString> JavaSecurityCertCertificate::getType() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getType", "()Ljava/lang/String;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilJarAttributes::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/jar/Attributes"));
    return cls;
}

// public java.util.jar.Attributes(java.util.jar.Attributes)
jnipp::LocalRef<JavaUtilJarAttributes> JavaUtilJarAttributes::construct(const jnipp::Ref<JavaUtilJarAttributes>& a0) {
    static jnipp::Constructor<JavaUtilJarAttributes,JavaUtilJarAttributes> constructor(clazz(), "(Ljava/util/jar/Attributes;)V");
    return constructor.construct(a0);
}

// public java.util.jar.Attributes(int)
jnipp::LocalRef<JavaUtilJarAttributes> JavaUtilJarAttributes::construct(jint a0) {
    static jnipp::Constructor<JavaUtilJarAttributes,jint> constructor(clazz(), "(I)V");
    return constructor.construct(a0);
}

// public java.util.jar.Attributes()
jnipp::LocalRef<JavaUtilJarAttributes> JavaUtilJarAttributes::construct() {
    static jnipp::Constructor<JavaUtilJarAttributes> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.lang.Object java.util.jar.Attributes.remove(java.lang.Object)
jnipp::LocalRef<JavaLangObject> JavaUtilJarAttributes::remove(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangObject,JavaLangObject> method(clazz(), "remove", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public java.lang.Object java.util.jar.Attributes.get(java.lang.Object)
jnipp::LocalRef<JavaLangObject> JavaUtilJarAttributes::get(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<JavaLangObject,JavaLangObject> method(clazz(), "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0);
}

// public java.lang.Object java.util.jar.Attributes.put(java.lang.Object,java.lang.Object)
jnipp::LocalRef<JavaLangObject> JavaUtilJarAttributes::put(const jnipp::Ref<JavaLangObject>& a0, const jnipp::Ref<JavaLangObject>& a1) const {
    static jnipp::Method<JavaLangObject,JavaLangObject,JavaLangObject> method(clazz(), "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    return method.call(*this, a0, a1);
}

// public boolean java.util.jar.Attributes.equals(java.lang.Object)
jboolean JavaUtilJarAttributes::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public java.util.Collection java.util.jar.Attributes.values()
jnipp::LocalRef<JavaUtilCollection> JavaUtilJarAttributes::values() const {
    static jnipp::Method<JavaUtilCollection> method(clazz(), "values", "()Ljava/util/Collection;");
    return method.call(*this);
}

// public int java.util.jar.Attributes.hashCode()
jint JavaUtilJarAttributes::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.Object java.util.jar.Attributes.clone()
jnipp::LocalRef<JavaLangObject> JavaUtilJarAttributes::clone() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "clone", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public void java.util.jar.Attributes.clear()
void JavaUtilJarAttributes::clear() const {
    static jnipp::Method<void> method(clazz(), "clear", "()V");
    method.call(*this);
}

// public boolean java.util.jar.Attributes.isEmpty()
jboolean JavaUtilJarAttributes::isEmpty() const {
    static jnipp::Method<jboolean> method(clazz(), "isEmpty", "()Z");
    return method.call(*this);
}

// public java.lang.String java.util.jar.Attributes.getValue(java.util.jar.Attributes$Name)
jnipp::LocalRef<JavaLangString> JavaUtilJarAttributes::getValue(const jnipp::Ref<JavaUtilJarAttributes_Name>& a0) const {
    static jnipp::Method<JavaLangString,JavaUtilJarAttributes_Name> method(clazz(), "getValue", "(Ljava/util/jar/Attributes$Name;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public java.lang.String java.util.jar.Attributes.getValue(java.lang.String)
jnipp::LocalRef<JavaLangString> JavaUtilJarAttributes::getValue(const jnipp::Ref<JavaLangString>& a0) const {
    static jnipp::Method<JavaLangString,JavaLangString> method(clazz(), "getValue", "(Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0);
}

// public int java.util.jar.Attributes.size()
jint JavaUtilJarAttributes::size() const {
    static jnipp::Method<jint> method(clazz(), "size", "()I");
    return method.call(*this);
}

// public java.util.Set java.util.jar.Attributes.entrySet()
jnipp::LocalRef<JavaUtilSet> JavaUtilJarAttributes::entrySet() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "entrySet", "()Ljava/util/Set;");
    return method.call(*this);
}

// public void java.util.jar.Attributes.putAll(java.util.Map)
void JavaUtilJarAttributes::putAll(const jnipp::Ref<JavaUtilMap>& a0) const {
    static jnipp::Method<void,JavaUtilMap> method(clazz(), "putAll", "(Ljava/util/Map;)V");
    method.call(*this, a0);
}

// public java.util.Set java.util.jar.Attributes.keySet()
jnipp::LocalRef<JavaUtilSet> JavaUtilJarAttributes::keySet() const {
    static jnipp::Method<JavaUtilSet> method(clazz(), "keySet", "()Ljava/util/Set;");
    return method.call(*this);
}

// public boolean java.util.jar.Attributes.containsValue(java.lang.Object)
jboolean JavaUtilJarAttributes::containsValue(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "containsValue", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public boolean java.util.jar.Attributes.containsKey(java.lang.Object)
jboolean JavaUtilJarAttributes::containsKey(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "containsKey", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public java.lang.String java.util.jar.Attributes.putValue(java.lang.String,java.lang.String)
jnipp::LocalRef<JavaLangString> JavaUtilJarAttributes::putValue(const jnipp::Ref<JavaLangString>& a0, const jnipp::Ref<JavaLangString>& a1) const {
    static jnipp::Method<JavaLangString,JavaLangString,JavaLangString> method(clazz(), "putValue", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    return method.call(*this, a0, a1);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaIoOutputStream::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/io/OutputStream"));
    return cls;
}

// public java.io.OutputStream()
jnipp::LocalRef<JavaIoOutputStream> JavaIoOutputStream::construct() {
    static jnipp::Constructor<JavaIoOutputStream> constructor(clazz(), "()V");
    return constructor.construct();
}

// public void java.io.OutputStream.write(byte[],int,int) throws java.io.IOException
void JavaIoOutputStream::write(const jnipp::Ref<jnipp::Array<jbyte>>& a0, jint a1, jint a2) const {
    static jnipp::Method<void,jnipp::Array<jbyte>,jint,jint> method(clazz(), "write", "([BII)V");
    method.call(*this, a0, a1, a2);
}

// public void java.io.OutputStream.write(byte[]) throws java.io.IOException
void JavaIoOutputStream::write(const jnipp::Ref<jnipp::Array<jbyte>>& a0) const {
    static jnipp::Method<void,jnipp::Array<jbyte>> method(clazz(), "write", "([B)V");
    method.call(*this, a0);
}

// public void java.io.OutputStream.flush() throws java.io.IOException
void JavaIoOutputStream::flush() const {
    static jnipp::Method<void> method(clazz(), "flush", "()V");
    method.call(*this);
}

// public void java.io.OutputStream.close() throws java.io.IOException
void JavaIoOutputStream::close() const {
    static jnipp::Method<void> method(clazz(), "close", "()V");
    method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetFileNameMap::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/FileNameMap"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetContentHandlerFactory::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/ContentHandlerFactory"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaNetProxy_Type::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/Proxy$Type"));
    return cls;
}

// private java.net.Proxy$Type(java.lang.String,int)
jnipp::LocalRef<JavaNetProxy_Type> JavaNetProxy_Type::construct(const jnipp::Ref<JavaLangString>& a0, jint a1) {
    static jnipp::Constructor<JavaNetProxy_Type,JavaLangString,jint> constructor(clazz(), "(Ljava/lang/String;I)V");
    return constructor.construct(a0, a1);
}

// public static java.net.Proxy$Type[] java.net.Proxy$Type.values()
jnipp::LocalRef<jnipp::Array<JavaNetProxy_Type>> JavaNetProxy_Type::values() {
    static jnipp::StaticMethod<jnipp::Array<JavaNetProxy_Type>> method(clazz(), "values", "()[Ljava/net/Proxy$Type;");
    return method.call();
}

// public static java.net.Proxy$Type java.net.Proxy$Type.valueOf(java.lang.String)
jnipp::LocalRef<JavaNetProxy_Type> JavaNetProxy_Type::valueOf(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<JavaNetProxy_Type,JavaLangString> method(clazz(), "valueOf", "(Ljava/lang/String;)Ljava/net/Proxy$Type;");
    return method.call(a0);
}
const jnipp::StaticField<JavaNetProxy_Type> JavaNetProxy_Type::DIRECT ("java/net/Proxy$Type", "DIRECT", "Ljava/net/Proxy$Type;");
const jnipp::StaticField<JavaNetProxy_Type> JavaNetProxy_Type::HTTP ("java/net/Proxy$Type", "HTTP", "Ljava/net/Proxy$Type;");
const jnipp::StaticField<JavaNetProxy_Type> JavaNetProxy_Type::SOCKS ("java/net/Proxy$Type", "SOCKS", "Ljava/net/Proxy$Type;");
inline jnipp::GlobalRef<jnipp::Class>& JavaNetSocketAddress::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/net/SocketAddress"));
    return cls;
}

// public java.net.SocketAddress()
jnipp::LocalRef<JavaNetSocketAddress> JavaNetSocketAddress::construct() {
    static jnipp::Constructor<JavaNetSocketAddress> constructor(clazz(), "()V");
    return constructor.construct();
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityTimestamp::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/Timestamp"));
    return cls;
}

// public java.security.Timestamp(java.util.Date,java.security.cert.CertPath)
jnipp::LocalRef<JavaSecurityTimestamp> JavaSecurityTimestamp::construct(const jnipp::Ref<JavaUtilDate>& a0, const jnipp::Ref<JavaSecurityCertCertPath>& a1) {
    static jnipp::Constructor<JavaSecurityTimestamp,JavaUtilDate,JavaSecurityCertCertPath> constructor(clazz(), "(Ljava/util/Date;Ljava/security/cert/CertPath;)V");
    return constructor.construct(a0, a1);
}

// public boolean java.security.Timestamp.equals(java.lang.Object)
jboolean JavaSecurityTimestamp::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.security.Timestamp.hashCode()
jint JavaSecurityTimestamp::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.security.cert.CertPath java.security.Timestamp.getSignerCertPath()
jnipp::LocalRef<JavaSecurityCertCertPath> JavaSecurityTimestamp::getSignerCertPath() const {
    static jnipp::Method<JavaSecurityCertCertPath> method(clazz(), "getSignerCertPath", "()Ljava/security/cert/CertPath;");
    return method.call(*this);
}

// public java.util.Date java.security.Timestamp.getTimestamp()
jnipp::LocalRef<JavaUtilDate> JavaSecurityTimestamp::getTimestamp() const {
    static jnipp::Method<JavaUtilDate> method(clazz(), "getTimestamp", "()Ljava/util/Date;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaSecurityCertCertPath::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/security/cert/CertPath"));
    return cls;
}

// protected java.security.cert.CertPath(java.lang.String)
jnipp::LocalRef<JavaSecurityCertCertPath> JavaSecurityCertCertPath::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaSecurityCertCertPath,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public boolean java.security.cert.CertPath.equals(java.lang.Object)
jboolean JavaSecurityCertCertPath::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.security.cert.CertPath.hashCode()
jint JavaSecurityCertCertPath::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.String java.security.cert.CertPath.getType()
jnipp::LocalRef<JavaLangString> JavaSecurityCertCertPath::getType() const {
    static jnipp::Method<JavaLangString> method(clazz(), "getType", "()Ljava/lang/String;");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilJarAttributes_Name::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/jar/Attributes$Name"));
    return cls;
}

// public java.util.jar.Attributes$Name(java.lang.String)
jnipp::LocalRef<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaUtilJarAttributes_Name,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public boolean java.util.jar.Attributes$Name.equals(java.lang.Object)
jboolean JavaUtilJarAttributes_Name::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.util.jar.Attributes$Name.hashCode()
jint JavaUtilJarAttributes_Name::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::MANIFEST_VERSION ("java/util/jar/Attributes$Name", "MANIFEST_VERSION", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::SIGNATURE_VERSION ("java/util/jar/Attributes$Name", "SIGNATURE_VERSION", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::CONTENT_TYPE ("java/util/jar/Attributes$Name", "CONTENT_TYPE", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::CLASS_PATH ("java/util/jar/Attributes$Name", "CLASS_PATH", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::MAIN_CLASS ("java/util/jar/Attributes$Name", "MAIN_CLASS", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::SEALED ("java/util/jar/Attributes$Name", "SEALED", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::EXTENSION_LIST ("java/util/jar/Attributes$Name", "EXTENSION_LIST", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::EXTENSION_NAME ("java/util/jar/Attributes$Name", "EXTENSION_NAME", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::EXTENSION_INSTALLATION ("java/util/jar/Attributes$Name", "EXTENSION_INSTALLATION", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::IMPLEMENTATION_TITLE ("java/util/jar/Attributes$Name", "IMPLEMENTATION_TITLE", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::IMPLEMENTATION_VERSION ("java/util/jar/Attributes$Name", "IMPLEMENTATION_VERSION", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::IMPLEMENTATION_VENDOR ("java/util/jar/Attributes$Name", "IMPLEMENTATION_VENDOR", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::IMPLEMENTATION_VENDOR_ID ("java/util/jar/Attributes$Name", "IMPLEMENTATION_VENDOR_ID", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::IMPLEMENTATION_URL ("java/util/jar/Attributes$Name", "IMPLEMENTATION_URL", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::SPECIFICATION_TITLE ("java/util/jar/Attributes$Name", "SPECIFICATION_TITLE", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::SPECIFICATION_VERSION ("java/util/jar/Attributes$Name", "SPECIFICATION_VERSION", "Ljava/util/jar/Attributes$Name;");
const jnipp::StaticField<JavaUtilJarAttributes_Name> JavaUtilJarAttributes_Name::SPECIFICATION_VENDOR ("java/util/jar/Attributes$Name", "SPECIFICATION_VENDOR", "Ljava/util/jar/Attributes$Name;");
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilCollection::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Collection"));
    return cls;
}
inline jnipp::GlobalRef<jnipp::Class>& JavaUtilDate::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("java/util/Date"));
    return cls;
}

// public java.util.Date(java.lang.String)
jnipp::LocalRef<JavaUtilDate> JavaUtilDate::construct(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::Constructor<JavaUtilDate,JavaLangString> constructor(clazz(), "(Ljava/lang/String;)V");
    return constructor.construct(a0);
}

// public java.util.Date(int,int,int,int,int,int)
jnipp::LocalRef<JavaUtilDate> JavaUtilDate::construct(jint a0, jint a1, jint a2, jint a3, jint a4, jint a5) {
    static jnipp::Constructor<JavaUtilDate,jint,jint,jint,jint,jint,jint> constructor(clazz(), "(IIIIII)V");
    return constructor.construct(a0, a1, a2, a3, a4, a5);
}

// public java.util.Date(int,int,int,int,int)
jnipp::LocalRef<JavaUtilDate> JavaUtilDate::construct(jint a0, jint a1, jint a2, jint a3, jint a4) {
    static jnipp::Constructor<JavaUtilDate,jint,jint,jint,jint,jint> constructor(clazz(), "(IIIII)V");
    return constructor.construct(a0, a1, a2, a3, a4);
}

// public java.util.Date()
jnipp::LocalRef<JavaUtilDate> JavaUtilDate::construct() {
    static jnipp::Constructor<JavaUtilDate> constructor(clazz(), "()V");
    return constructor.construct();
}

// public java.util.Date(long)
jnipp::LocalRef<JavaUtilDate> JavaUtilDate::construct(jlong a0) {
    static jnipp::Constructor<JavaUtilDate,jlong> constructor(clazz(), "(J)V");
    return constructor.construct(a0);
}

// public java.util.Date(int,int,int)
jnipp::LocalRef<JavaUtilDate> JavaUtilDate::construct(jint a0, jint a1, jint a2) {
    static jnipp::Constructor<JavaUtilDate,jint,jint,jint> constructor(clazz(), "(III)V");
    return constructor.construct(a0, a1, a2);
}

// public boolean java.util.Date.equals(java.lang.Object)
jboolean JavaUtilDate::equals(const jnipp::Ref<JavaLangObject>& a0) const {
    static jnipp::Method<jboolean,JavaLangObject> method(clazz(), "equals", "(Ljava/lang/Object;)Z");
    return method.call(*this, a0);
}

// public int java.util.Date.hashCode()
jint JavaUtilDate::hashCode() const {
    static jnipp::Method<jint> method(clazz(), "hashCode", "()I");
    return method.call(*this);
}

// public java.lang.Object java.util.Date.clone()
jnipp::LocalRef<JavaLangObject> JavaUtilDate::clone() const {
    static jnipp::Method<JavaLangObject> method(clazz(), "clone", "()Ljava/lang/Object;");
    return method.call(*this);
}

// public int java.util.Date.compareTo(java.util.Date)
jint JavaUtilDate::compareTo(const jnipp::Ref<JavaUtilDate>& a0) const {
    static jnipp::Method<jint,JavaUtilDate> method(clazz(), "compareTo", "(Ljava/util/Date;)I");
    return method.call(*this, a0);
}

// public static long java.util.Date.parse(java.lang.String)
jlong JavaUtilDate::parse(const jnipp::Ref<JavaLangString>& a0) {
    static jnipp::StaticMethod<jlong,JavaLangString> method(clazz(), "parse", "(Ljava/lang/String;)J");
    return method.call(a0);
}

// public boolean java.util.Date.after(java.util.Date)
jboolean JavaUtilDate::after(const jnipp::Ref<JavaUtilDate>& a0) const {
    static jnipp::Method<jboolean,JavaUtilDate> method(clazz(), "after", "(Ljava/util/Date;)Z");
    return method.call(*this, a0);
}

// public boolean java.util.Date.before(java.util.Date)
jboolean JavaUtilDate::before(const jnipp::Ref<JavaUtilDate>& a0) const {
    static jnipp::Method<jboolean,JavaUtilDate> method(clazz(), "before", "(Ljava/util/Date;)Z");
    return method.call(*this, a0);
}

// public void java.util.Date.setTime(long)
void JavaUtilDate::setTime(jlong a0) const {
    static jnipp::Method<void,jlong> method(clazz(), "setTime", "(J)V");
    method.call(*this, a0);
}

// public long java.util.Date.getTime()
jlong JavaUtilDate::getTime() const {
    static jnipp::Method<jlong> method(clazz(), "getTime", "()J");
    return method.call(*this);
}

// public int java.util.Date.getYear()
jint JavaUtilDate::getYear() const {
    static jnipp::Method<jint> method(clazz(), "getYear", "()I");
    return method.call(*this);
}

// public int java.util.Date.getMonth()
jint JavaUtilDate::getMonth() const {
    static jnipp::Method<jint> method(clazz(), "getMonth", "()I");
    return method.call(*this);
}

// public int java.util.Date.getDate()
jint JavaUtilDate::getDate() const {
    static jnipp::Method<jint> method(clazz(), "getDate", "()I");
    return method.call(*this);
}

// public int java.util.Date.getHours()
jint JavaUtilDate::getHours() const {
    static jnipp::Method<jint> method(clazz(), "getHours", "()I");
    return method.call(*this);
}

// public int java.util.Date.getMinutes()
jint JavaUtilDate::getMinutes() const {
    static jnipp::Method<jint> method(clazz(), "getMinutes", "()I");
    return method.call(*this);
}

// public int java.util.Date.getSeconds()
jint JavaUtilDate::getSeconds() const {
    static jnipp::Method<jint> method(clazz(), "getSeconds", "()I");
    return method.call(*this);
}

// public static long java.util.Date.UTC(int,int,int,int,int,int)
jlong JavaUtilDate::UTC(jint a0, jint a1, jint a2, jint a3, jint a4, jint a5) {
    static jnipp::StaticMethod<jlong,jint,jint,jint,jint,jint,jint> method(clazz(), "UTC", "(IIIIII)J");
    return method.call(a0, a1, a2, a3, a4, a5);
}

// public void java.util.Date.setYear(int)
void JavaUtilDate::setYear(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setYear", "(I)V");
    method.call(*this, a0);
}

// public void java.util.Date.setMonth(int)
void JavaUtilDate::setMonth(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setMonth", "(I)V");
    method.call(*this, a0);
}

// public void java.util.Date.setDate(int)
void JavaUtilDate::setDate(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setDate", "(I)V");
    method.call(*this, a0);
}

// public int java.util.Date.getDay()
jint JavaUtilDate::getDay() const {
    static jnipp::Method<jint> method(clazz(), "getDay", "()I");
    return method.call(*this);
}

// public void java.util.Date.setHours(int)
void JavaUtilDate::setHours(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setHours", "(I)V");
    method.call(*this, a0);
}

// public void java.util.Date.setMinutes(int)
void JavaUtilDate::setMinutes(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setMinutes", "(I)V");
    method.call(*this, a0);
}

// public void java.util.Date.setSeconds(int)
void JavaUtilDate::setSeconds(jint a0) const {
    static jnipp::Method<void,jint> method(clazz(), "setSeconds", "(I)V");
    method.call(*this, a0);
}

// public java.lang.String java.util.Date.toLocaleString()
jnipp::LocalRef<JavaLangString> JavaUtilDate::toLocaleString() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toLocaleString", "()Ljava/lang/String;");
    return method.call(*this);
}

// public java.lang.String java.util.Date.toGMTString()
jnipp::LocalRef<JavaLangString> JavaUtilDate::toGMTString() const {
    static jnipp::Method<JavaLangString> method(clazz(), "toGMTString", "()Ljava/lang/String;");
    return method.call(*this);
}

// public int java.util.Date.getTimezoneOffset()
jint JavaUtilDate::getTimezoneOffset() const {
    static jnipp::Method<jint> method(clazz(), "getTimezoneOffset", "()I");
    return method.call(*this);
}
inline jnipp::GlobalRef<jnipp::Class>& JavaTest::clazz() {
    static jnipp::GlobalRef<jnipp::Class> cls;
    if (!cls) cls.set(jnipp::Class::forName("JavaTest"));
    return cls;
}

// public JavaTest()
jnipp::LocalRef<JavaTest> JavaTest::construct() {
    static jnipp::Constructor<JavaTest> constructor(clazz(), "()V");
    return constructor.construct();
}
jnipp::StaticField<JavaLangObject> JavaTest::staticObject ("JavaTest", "staticObject", "Ljava/lang/Object;");
jnipp::StaticField<jint> JavaTest::staticInt ("JavaTest", "staticInt", "I");

