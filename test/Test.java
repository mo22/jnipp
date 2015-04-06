public class Test
{
    static {
        System.loadLibrary("Test");
    }

    public static native void native1();

    public static float add(float a, float b)
    {
        return a + b;
    }

    public static void main(String[] args) throws Exception
    {
        System.err.println("Hello World!");
        native1();
    }

}

