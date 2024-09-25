package be.labruyere.arqanore;

/**
 * Represents a 2D vector
 */
public class Vector3 {
    static {
        Arqanore.init();

        ZERO = _getConstZero();
        ONE = _getConstOne();
        UP = _getConstUp();
        DOWN = _getConstDown();
        LEFT = _getConstLeft();
        RIGHT = _getConstRight();
        FORWARD = _getConstForward();
        BACKWARD = _getConstBackward();
    }

    public static final Vector3 ZERO;
    public static final Vector3 ONE;
    public static final Vector3 UP;
    public static final Vector3 DOWN;
    public static final Vector3 LEFT;
    public static final Vector3 RIGHT;
    public static final Vector3 FORWARD;
    public static final Vector3 BACKWARD;

    public float x;
    public float y;
    public float z;

    public Vector3() {

    }

    public Vector3(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public static float distance(Vector3 v1, Vector3 v2) {
        return _distance(v1, v2);
    }

    public static float angle(Vector3 v1, Vector3 v2) {
        return _angle(v1, v2);
    }

    public static float dot(Vector3 v1, Vector3 v2) {
        return _dot(v1, v2);
    }

    public static Vector3 cross(Vector3 v1, Vector3 v2) {
        return _cross(v1, v2);
    }

    public static Vector3 normalized(Vector3 v) {
        return _normalized(v);
    }

    public static Vector3 lerp(Vector3 v1, Vector3 v2, float by) {
        return _lerp(v1, v2, by);
    }

    private static native float _distance(Vector3 v1, Vector3 v2);

    private static native float _angle(Vector3 v1, Vector3 v2);

    private static native float _dot(Vector3 v1, Vector3 v2);

    private static native Vector3 _cross(Vector3 v1, Vector3 v2);

    private static native Vector3 _normalized(Vector3 v);

    private static native Vector3 _lerp(Vector3 v1, Vector3 v2, float by);

    private static native Vector3 _getConstZero();

    private static native Vector3 _getConstOne();

    private static native Vector3 _getConstUp();

    private static native Vector3 _getConstDown();

    private static native Vector3 _getConstLeft();

    private static native Vector3 _getConstRight();

    private static native Vector3 _getConstForward();

    private static native Vector3 _getConstBackward();
}
