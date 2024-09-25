package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

/**
 * Contains additional math functionality
 */
public class MathHelper {
    static {
        Arqanore.init();
    }

    /**
     * Converts the given degrees to radians
     *
     * @param degrees The degree value
     * @return The value in radians
     */
    public static float radians(float degrees) {
        return _radians(degrees);
    }

    /**
     * Converts the given radians to degrees
     *
     * @param radians The radians value
     * @return The value in degrees
     */
    public static float degrees(float radians) {
        return _degrees(radians);
    }

    public static float lerp(float d1, float d2, float by) {
        return _lerp(d1, d2, by);
    }

    public static float clamp(float value, float min, float max) {
        return _clamp(value, min ,max);
    }

    private static native float _radians(float degrees);

    private static native float _degrees(float radians);

    private static native float _lerp(float d1, float d2, float by);

    private static native float _clamp(float value, float min, float max);
}
