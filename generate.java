import java.lang.reflect.*;
import java.util.*;
import java.io.*;

public class generate
{
    private Class cls;
    private String defClsName;
    private Map<Class, String> usedClasses = new HashMap<Class, String>();
    private Set<Class> done = new HashSet<Class>();

    private StringBuffer header = new StringBuffer();
    private StringBuffer declaration = new StringBuffer();
    private StringBuffer implementation = new StringBuffer();

    private String convertClassName(Class cls)
    {
        StringBuffer res = new StringBuffer();
        for (String i : cls.getName().replace('$', '_').split("\\.")) {
            res.append( i.substring(0, 1).toUpperCase() + i.substring(1) );
        }
        usedClasses.put(cls, res.toString());
        return res.toString();
    }

    private static String getSignature(Class cls) throws Exception
    {
        if (cls.isPrimitive()) {
            if (cls == void.class) return "V";
            if (cls == byte.class) return "B";
            if (cls == short.class) return "S";
            if (cls == int.class) return "I";
            if (cls == long.class) return "J";
            if (cls == float.class) return "F";
            if (cls == double.class) return "D";
            if (cls == char.class) return "C";
            if (cls == boolean.class) return "B";
            throw new Exception("cannot convert: " + cls);
        } else if (cls.isArray()) {
            return "[" + getSignature(cls.getComponentType());
        } else {
            return "L" + cls.getName().replace(".", "/") + ";";
        }
    }

    private static String getSignature(Method member) throws Exception
    {
        StringBuffer res = new StringBuffer();
        res.append("(");
        for (Class i : member.getParameterTypes()) {
            res.append(getSignature(i));
        }
        res.append(")");
        res.append(getSignature(member.getReturnType()));
        return res.toString();
    }

    private static String getSignature(Constructor member) throws Exception
    {
        StringBuffer res = new StringBuffer();
        res.append("(");
        for (Class i : member.getParameterTypes()) {
            res.append(getSignature(i));
        }
        res.append(")V");
        return res.toString();
    }

    private String getNativeClassName(Class cls) throws Exception
    {
        if (cls.isPrimitive()) {
            if (cls == void.class) return "void";
            return "j" + cls.getName();
        } else if (cls.isArray()) {
            return "jnipp::Array<"+getNativeClassName(cls.getComponentType())+">";
        } else {
            if (cls == Object.class) return "jnipp::Object";
            if (cls == String.class) return "jnipp::String";
            if (cls == Class.class) return "jnipp::Class";
            //return "jnipp::Object";
            return convertClassName(cls);
        }
    }

    private String getNativeClassNameRef(Class cls) throws Exception
    {
        if (cls.isPrimitive()) {
            return getNativeClassName(cls);
        } else {
            return "const jnipp::Ref<"+getNativeClassName(cls) + ">&";
        }
    }

    private String getNativeClassNameLocalRef(Class cls) throws Exception
    {
        if (cls.isPrimitive()) {
            return getNativeClassName(cls);
        } else {
            return "jnipp::LocalRef<"+getNativeClassName(cls) + ">";
        }
    }

    private String castParameter(Class cls, String name) throws Exception
    {
        if (cls.isPrimitive()) return name;
        if (cls == String.class) return "(jstring)"+name;
        return "(jobject)"+name;
    }

    private void handleGetClass() throws Exception
    {
        declaration.append("\n");
        declaration.append("    static jnipp::GlobalRef<jnipp::Class>& getClass();\n");

        implementation.append("inline jnipp::GlobalRef<jnipp::Class>& "+defClsName+"::getClass() {\n");
        implementation.append("    static jnipp::GlobalRef<jnipp::Class> cls;\n");
        implementation.append("    if (!cls) cls.set(jnipp::Class::forName(\"" + cls.getName().replace(".", "/") + "\"));\n");
        implementation.append("    return cls;\n");
        implementation.append("}\n");
    }

    private void handleMethod(Method member) throws Exception
    {
        Class retType = member.getReturnType();
        Class[] paramTypes = member.getParameterTypes();
        String name = member.getName();
        String defName = name;
        if (defName.equals("delete")) defName = "delete_";

        declaration.append("\n");
        declaration.append("    // " + member + "\n");
        declaration.append("    " + getNativeClassNameLocalRef(retType) + " " + defName + "(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) declaration.append(", ");
            declaration.append(getNativeClassNameRef(paramTypes[i])+" a"+i);
        }
        declaration.append(") const;\n");

        implementation.append("\n");
        implementation.append("// " + member + "\n");
        implementation.append(getNativeClassNameLocalRef(retType) + " " + defClsName + "::" + defName + "(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) implementation.append(", ");
            implementation.append(getNativeClassNameRef(paramTypes[i])+" a"+i);
        }
        implementation.append(") const {\n");
        implementation.append("    static jnipp::Method<"+getNativeClassName(retType));
        for (int i=0; i<paramTypes.length; i++) {
            implementation.append(",");
            implementation.append(getNativeClassName(paramTypes[i]));
        }
        implementation.append("> method(getClass(), \""+member.getName()+"\", \""+getSignature(member)+"\");\n");
        implementation.append("    ");
        if (retType != void.class) implementation.append("return ");
        implementation.append("method.call(*this");
        for (int i=0; i<paramTypes.length; i++) {
            implementation.append(", a"+i);
        }
        implementation.append(");\n");
        implementation.append("}\n");
    }

    private void handleStaticMethod(Method member) throws Exception
    {
        Class retType = member.getReturnType();
        Class[] paramTypes = member.getParameterTypes();

        declaration.append("\n");
        declaration.append("    // " + member + "\n");
        declaration.append("    static " + getNativeClassNameLocalRef(retType) + " " + member.getName() + "(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) declaration.append(", ");
            declaration.append(getNativeClassNameRef(paramTypes[i])+" a"+i);
        }
        declaration.append(");\n");

        implementation.append("\n");
        implementation.append("// " + member + "\n");
        implementation.append(getNativeClassNameLocalRef(retType) + " " + defClsName + "::" + member.getName() + "(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) implementation.append(", ");
            implementation.append(getNativeClassNameRef(paramTypes[i])+" a"+i);
        }
        implementation.append(") {\n");
        implementation.append("    static jnipp::StaticMethod<"+getNativeClassName(retType));
        for (int i=0; i<paramTypes.length; i++) {
            implementation.append(",");
            implementation.append(getNativeClassName(paramTypes[i]));
        }
        implementation.append("> method(getClass(), \""+member.getName()+"\", \""+getSignature(member)+"\");\n");
        implementation.append("    ");
        if (retType != void.class) implementation.append("return ");
        implementation.append("method.call(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) implementation.append(", ");
            implementation.append("a"+i);
        }
        implementation.append(");\n");
        implementation.append("}\n");
    }

    private void handleConstructor(Constructor member) throws Exception
    {
        Class[] paramTypes = member.getParameterTypes();
        declaration.append("\n");
        declaration.append("    // " + member + "\n");
        declaration.append("    static " + getNativeClassNameLocalRef(cls) + " construct(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) declaration.append(", ");
            declaration.append(getNativeClassNameRef(paramTypes[i])+" a"+i);
        }
        declaration.append(");\n");

        implementation.append("\n");
        implementation.append("// " + member + "\n");
        implementation.append(getNativeClassNameLocalRef(cls) + " " + defClsName + "::construct(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) implementation.append(", ");
            implementation.append(getNativeClassNameRef(paramTypes[i])+" a"+i);
        }
        implementation.append(") {\n");
        implementation.append("    static jnipp::Constructor<"+getNativeClassName(cls));
        for (int i=0; i<paramTypes.length; i++) {
            implementation.append(",");
            implementation.append(getNativeClassName(paramTypes[i]));
        }
        implementation.append("> constructor(getClass(), \""+getSignature(member)+"\");\n");
        implementation.append("    return constructor.construct(");
        for (int i=0; i<paramTypes.length; i++) {
            if (i > 0) implementation.append(", ");
            implementation.append("a"+i);
        }
        implementation.append(");\n");
        implementation.append("}\n");
    }

    private void handleStaticField(Field member) throws Exception
    {
        Class type = member.getType();
        declaration.append("\n");
        declaration.append("#undef " + member.getName() + "\n");
        declaration.append("    // " + member + "\n");
        declaration.append("    static ");
        if ((member.getModifiers() & Modifier.FINAL) != 0) declaration.append("const ");
        declaration.append("jnipp::StaticField<" + getNativeClassName(type) + "> " + member.getName() + ";\n");

        if ((member.getModifiers() & Modifier.FINAL) != 0) implementation.append("const ");
        implementation.append("jnipp::StaticField<" + getNativeClassName(type) + "> ");
        implementation.append(convertClassName(cls) + "::" + member.getName());
        implementation.append(" (\"" + cls.getName().replace(".", "/") + "\", \"" + member.getName() + "\", \"" + getSignature(type) + "\");\n");
    }

    private void handleField(Field member) throws Exception
    {
        Class type = member.getType();
        declaration.append("\n");
        declaration.append("    // " + member + "\n");
        declaration.append("    ");
        if ((member.getModifiers() & Modifier.FINAL) != 0) declaration.append("const ");
        declaration.append("jnipp::Field<" + getNativeClassName(type) + "> " + member.getName() + " = ");
        declaration.append("jnipp::Field<" + getNativeClassName(type) + ">(\"" + cls.getName() + "\", \"" + member.getName() + "\", \"" + getSignature(type) + "\");\n");
        // @TODO...
    }

    private void handleClass(Class cls) throws Exception
    {
        if (done.contains(cls)) return;
        done.add(cls);
        this.cls = cls;
        defClsName = convertClassName(cls);

        declaration.append("\n");
        declaration.append("// " + cls + "\n");
        String parent = (cls.getSuperclass() == null) ? "jnipp::Object" : getNativeClassName(cls.getSuperclass());
        declaration.append("class " + defClsName + " : public " + parent + "\n");
        declaration.append("{\n");
        declaration.append("public:\n");
        declaration.append("    using parent = " + parent + ";\n");
        declaration.append("    using parent::parent;\n");

        handleGetClass();

        for (Constructor member : cls.getDeclaredConstructors()) {
            handleConstructor(member);
        }

        for (Method member : cls.getDeclaredMethods()) {

            if (member.getName().equals("toString")) continue;
            if (member.getName().equals("getClass")) continue;

            if ((member.getModifiers() & Modifier.PUBLIC) == 0) continue;
            if ((member.getModifiers() & Modifier.ABSTRACT) != 0) continue;

            if (member.isSynthetic()) continue;

            if ((member.getModifiers() & Modifier.STATIC) != 0) {
                handleStaticMethod(member);
            } else {
                handleMethod(member);
            }
        }

        for (Field member : cls.getDeclaredFields()) {
            if ((member.getModifiers() & Modifier.PUBLIC) == 0) continue;
            if ((member.getModifiers() & Modifier.STATIC) != 0) {
                handleStaticField(member);
            } else {
                handleField(member);
            }
        }

        // @TODO: nested classes

        // @TODO: gather all dependencies


        declaration.append("};\n");
    }

    public String getSingle() throws Exception
    {
        StringBuffer res = new StringBuffer();

        res.append("\n");
        for (String item : usedClasses.values()) {
            res.append("class " + item + ";\n");
        }

        res.append("\n");
        res.append(declaration);

        res.append("\n");
        res.append(implementation);

        res.append("\n");
        return res.toString();
    }

    public String getHeader() throws Exception
    {
        StringBuffer res = new StringBuffer();

        res.append("#ifndef _JNI_" + cls.getName().replace('.', '_').toUpperCase() + "\n");
        res.append("#define _JNI_" + cls.getName().replace('.', '_').toUpperCase() + "\n");

        res.append("\n");
        for (String item : usedClasses.values()) {
            res.append("class " + item + ";\n");
        }

        if (cls.getSuperclass() != null) {
            res.append("\n");
            res.append("#include \"" + convertClassName(cls.getSuperclass()) + ".h\"\n");
        }

        res.append("\n");
        res.append(declaration);

        res.append("\n");
        for (String item : usedClasses.values()) {
            if (item.equals(convertClassName(cls))) continue;
            res.append("#include \"" + item + ".h\"\n");
        }

        res.append("\n");
        res.append("#endif\n");
        return res.toString();
    }

    public String getBody() throws Exception
    {
        StringBuffer res = new StringBuffer();
        res.append("#include \"jnipp.h\"\n");
        res.append("#include \"" + convertClassName(cls) + ".h\"\n");
        res.append("\n");
        res.append(implementation);
        return res.toString();
    }

    public generate() throws Exception
    {
    }

    private void handleRecursive(Class startClass) throws Exception
    {
        List<Class> todo = new ArrayList<Class>();
        todo.add(startClass);
        while (todo.size() > 0) {
            Class cls = todo.remove(0);
            if (done.contains(cls)) continue;
            Class scls = cls.getSuperclass();
            if (scls != null && !done.contains(scls)) {
                todo.add(0, cls);
                todo.add(0, scls);
                continue;
            }
            System.err.println(cls);
            handleClass(cls);
            for (Class ref : usedClasses.keySet()) {
                if (done.contains(ref)) continue;
                todo.add(ref);
            }
        }
    }

    private static void convert(Class cls) throws Exception
    {
        System.err.println(cls);
        generate x = new generate();
        x.handleClass(cls);
        String name = x.convertClassName(cls);
        if (new File(name + ".h").exists()) return;
        FileWriter writer = new FileWriter(name + ".h");
        writer.write(x.getHeader());
        writer.flush();
        writer = new FileWriter(name + ".cpp");
        writer.write(x.getBody());
        writer.flush();
        for (Class item : x.usedClasses.keySet()) {
            convert(item);
        }
    }

    private static void convert(String[] args) throws Exception
    {
        for (String arg : args) {
            convert(Class.forName(arg));
        }
    }

    private static void convertSingle(String[] args) throws Exception
    {
        generate x = new generate();
        for (String arg : args) {
            x.handleRecursive(Class.forName(arg));
        }

        FileWriter writer = new FileWriter("_java.h");
        writer.write(x.getSingle());
        writer.flush();

    }

    public static void main(String[] args) throws Exception
    {
        convertSingle(args);
        //convert(args);
    }
}