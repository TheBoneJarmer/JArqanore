package be.labruyere.arqanore;

import be.labruyere.arqanore.exceptions.ArqanoreException;

public class Matrix3 {
    public float[] values;

    public Matrix3() {
        this.values = new float[9];
    }

    public Matrix3(float[] values) throws ArqanoreException {
        if (values.length != 9) {
            throw new ArqanoreException("The float array provided in the constructor has an invalid array length. Expected 9 elements but got" + values.length + ".");
        }

        this.values = values;
    }

    public static Matrix3 inverse(Matrix3 m) {
        return _inverse(m);
    }

    public static Matrix3 transpose(Matrix3 m) {
        return _transpose(m);
    }

    private static native Matrix3 _inverse(Matrix3 m);

    private static native Matrix3 _transpose(Matrix3 m);
}
