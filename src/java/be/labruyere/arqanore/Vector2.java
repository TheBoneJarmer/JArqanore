package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

/**
 * Represents a 2D vector
 */
public class Vector2 {
    static {
        Arqanore.init();

        ZERO = _getConstZero();
        ONE = _getConstOne();
    }

    /**
     * A global vector where x and y are 0
     */
    public static final Vector2 ZERO;

    /**
     * A global vector where x and y are 1
     */
    public static final Vector2 ONE;

    public float x;
    public float y;

    public Vector2() {

    }

    public Vector2(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public static float distance(Vector2 v1, Vector2 v2) {
        return _distance(v1, v2);
    }

    public static float angle(Vector2 v1, Vector2 v2) {
        return _angle(v1, v2);
    }

    public static float cross(Vector2 v1, Vector2 v2) {
        return _cross(v1, v2);
    }

    public static float dot(Vector2 v1, Vector2 v2) {
        return _dot(v1, v2);
    }

    public static Vector2 normalized(Vector2 v) {
        return _normalized(v);
    }


    private static native float _distance(Vector2 v1, Vector2 v2);

    private static native float _angle(Vector2 v1, Vector2 v2);

    private static native float _cross(Vector2 v1, Vector2 v2);

    private static native float _dot(Vector2 v1, Vector2 v2);

    private static native Vector2 _normalized(Vector2 v);

    private static native Vector2 _getConstZero();

    private static native Vector2 _getConstOne();
}
