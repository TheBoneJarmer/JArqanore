package be.labruyere.arqanore;

/**
 * Manages the bridge between the JRE and native library
 */
public class Arqanore {
    /**
     * Gets the version number from Arqanore
    */
    public static int[] getVersion() {
        return _getVersion();    
    }
    
    /**
     * Gets the OpenGL version number from your device
    */
    public static String getOpenGLVersion() {
        return _getOpenGLVersion();    
    }

    /**
     * Initializes the Arqanore library.
     */
    static void init() {
        var os = System.getProperty("os.name");

        if (os.contains("Linux")) {
            System.loadLibrary("jarqanore");
            return;
        }

        if (os.contains("Windows")) {
            System.loadLibrary("libjarqanore");
            return;
        }

        throw new RuntimeException("Operating system " + os + " not supported");
    }
    
    private static native int[] _getVersion();
    
    private static native String _getOpenGLVersion();
}
