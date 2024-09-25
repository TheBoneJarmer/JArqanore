package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class Mesh extends Pointer {
    static {
        Arqanore.init();
    }

    public float[] getVertices() {
        return _getVertices(address);
    }

    public float[] getNormals() {
        return _getNormals(address);
    }

    public float[] getTexCoords() {
        return _getTexCoords(address);
    }

    public String getName() {
        return _getName(address);
    }

    public MeshAnimation getAnimation() {
        var ptr = _getAnimation(address);
        var animation = new MeshAnimation(ptr, PointerType.MANAGED);

        return animation;
    }

    public Material getMaterial() {
        var ptr = _getMaterial(address);
        var material = new Material(ptr, PointerType.MANAGED);

        return material;
    }

    /**
     * Internal constructor
     * @param pointer The native pointer address
     * @param pointerType The native pointer type
     */
    Mesh(long pointer, PointerType pointerType) {
        super();

        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public Mesh() {
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

    private native float[] _getVertices(long pointer);

    private native float[] _getNormals(long pointer);

    private native float[] _getTexCoords(long pointer);

    private native String _getName(long pointer);

    private native long _getAnimation(long pointer);

    private native long _getMaterial(long pointer);
}
