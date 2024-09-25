package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

public class Matrix4 {
    public float[] values;

    public Matrix4() {

    }

    public Matrix4(float[] values) throws ArqanoreException {
        if (values.length != 16) {
            throw new ArqanoreException("The float array provided in the constructor has an invalid array length. Expected 16 elements but got" + values.length + ".");
        }

        this.values = values;
    }

    public static Matrix4 identity() {
        return _identity();
    }

    public static Matrix4 scale(Matrix4 m, Vector3 v) {
        return _scale(m, v);
    }

    public static Matrix4 translate(Matrix4 m, Vector3 v) {
        return _translate(m, v);
    }

    public static Matrix4 rotate(Matrix4 m, Quaternion q) {
        return _rotate(m, q);
    }

    public static Matrix4 perspective(Matrix4 m, float fovy, float ratio, float near, float far) {
        return _perspective(m, fovy, ratio, near, far);
    }

    private static native Matrix4 _identity();

    private static native Matrix4 _scale(Matrix4 m, Vector3 v);

    private static native Matrix4 _translate(Matrix4 m, Vector3 v);

    private static native Matrix4 _rotate(Matrix4 m, Quaternion q);

    private static native Matrix4 _perspective(Matrix4 m, float fovy, float ratio, float near, float far);
}
