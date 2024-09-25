package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class Camera extends Pointer {
    static {
        Arqanore.init();
    }

    public Vector3 getPosition() {
        return _getPosition(address);
    }

    public Quaternion getRotation() {
        return _getRotation(address);
    }

    public float getFov() {
        return _getFov(address);
    }

    public float getNear() {
        return _getNear(address);
    }

    public float getFar() {
        return _getFar(address);
    }

    public void setPosition(Vector3 value) {
        _setPosition(address, value);
    }

    public void setPosition(float x, float y, float z) {
        var vec = new Vector3(x, y, z);
        _setPosition(address, vec);
    }

    public void setRotation(Quaternion value) {
        _setRotation(address, value);
    }

    public void setRotation(float x, float y, float z, float w) {
        var quat = new Quaternion(x, y, z, w);
        _setRotation(address, quat);
    }

    public void setFov(float value) {
        _setFov(address, value);
    }

    public void setNear(float value) {
        _setNear(address, value);
    }

    public void setFar(float value) {
        _setFar(address, value);
    }

    Camera(long pointer, PointerType pointerType) {
        super();

        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public Camera() {
        super();

        address = _create();
    }

    /**
     * Deletes the native pointer
     */
    @Override
    public void delete() {
        if (type != PointerType.DYNAMIC) {
            return;
        }

        _destroy(address);
        super.delete();
    }

    private native long _create();

    private native void _destroy(long pointer);

    private native Vector3 _getPosition(long pointer);

    private native Quaternion _getRotation(long pointer);

    private native float _getFov(long pointer);

    private native float _getNear(long pointer);

    private native float _getFar(long pointer);

    private native void _setPosition(long pointer, Vector3 value);

    private native void _setRotation(long pointer, Quaternion value);

    private native void _setFov(long pointer, float value);

    private native void _setNear(long pointer, float value);

    private native void _setFar(long pointer, float value);
}
