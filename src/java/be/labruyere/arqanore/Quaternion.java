package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class Quaternion {
    public float x;
    public float y;
    public float z;
    public float w;

    public Quaternion() {
        this.w = 1;
    }

    public Quaternion(float x, float y, float z, float w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    public static Vector3 eulerAngles(Quaternion q) {
        return _eulerAngles(q);
    }

    public static Vector3 eulerAngles(float x, float y, float z, float w) {
        var quat = new Quaternion(x, y, z, w);
        return _eulerAngles(quat);
    }

    public static Quaternion normalize(Quaternion q) {
        return _normalize(q);
    }

    public static Quaternion rotate(Quaternion q, float angle, Vector3 axis) {
        return _rotate(q, angle, axis);
    }

    public static Quaternion rotate(Quaternion q, float angle, float axisX, float axisY, float axisZ) {
        var axis = new Vector3(axisX, axisY, axisZ);
        return _rotate(q, angle, axis);
    }

    public static Quaternion rotate(float quatX, float quatY, float quatZ, float quatW, float angle, float axisX, float axisY, float axisZ) {
        var axis = new Vector3(axisX, axisY, axisZ);
        var quat = new Quaternion(quatX, quatY, quatZ, quatW);

        return rotate(quat, angle, axis);
    }

    public static Quaternion rotate(float quatX, float quatY, float quatZ, float quatW, float angle, Vector3 axis) {
        var quat = new Quaternion(quatX, quatY, quatZ, quatW);

        return rotate(quat, angle, axis);
    }

    public static Quaternion rotate(Quaternion q, Vector3 angles) {
        return _rotate(q, angles);
    }

    public static Quaternion rotate(Quaternion q, float angleX, float angleY, float angleZ) {
        var angles = new Vector3(angleX, angleY, angleZ);
        return rotate(q, angles);
    }

    public static Quaternion rotate(float quatX, float quatY, float quatZ, float quatW, float angleX, float angleY, float angleZ) {
        var angles = new Vector3(angleX, angleY, angleZ);
        var quat = new Quaternion(quatX, quatY, quatZ, quatW);

        return rotate(quat, angles);
    }

    private static native Vector3 _eulerAngles(Quaternion q);

    private static native Quaternion _normalize(Quaternion q);

    private static native Quaternion _rotate(Quaternion q, float angle, Vector3 axis);

    private static native Quaternion _rotate(Quaternion q, Vector3 axis);
}
