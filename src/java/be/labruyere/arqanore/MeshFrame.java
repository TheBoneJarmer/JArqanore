package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class MeshFrame extends Pointer {
    static {
        Arqanore.init();
    }

    public Vector3 getPosition() {
        return _getPosition(address);
    }

    public Quaternion getRotation() {
        return _getRotation(address);
    }

    public Vector3 getScale() {
        return _getScale(address);
    }

    public void setPosition(Vector3 position) {
        _setPosition(address, position);
    }

    public void setRotation(Quaternion rotation) {
        _setRotation(address, rotation);
    }

    public void setScale(Vector3 scale) {
        _setScale(address, scale);
    }

    /**
     * Internal constructor
     * @param pointer The native pointer address
     * @param pointerType The native pointer type
     */
    MeshFrame(long pointer, PointerType pointerType) {
        super();

        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public MeshFrame() {
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

    private native Vector3 _getScale(long pointer);

    private native void _setPosition(long pointer, Vector3 value);

    private native void _setRotation(long pointer, Quaternion value);

    private native void _setScale(long pointer, Vector3 value);
}
