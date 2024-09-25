package be.labruyere.arqanore;

/**
 * Manages all audio globally
 */
public class Audio {
    static {
        Arqanore.init();
    }

    /**
     * Stops every audio stream being played
     */
    public static void stop() {
        _stop();
    }

    private static native void _stop();
}
