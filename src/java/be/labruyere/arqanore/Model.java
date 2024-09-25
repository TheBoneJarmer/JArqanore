package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

public class Model extends Pointer {
    static {
        Arqanore.init();
    }

    public Mesh[] getMeshes() {
        var pointers = _getMeshes(address);
        var meshes = new Mesh[pointers.length];

        for (var i = 0; i < meshes.length; i++) {
            meshes[i] = new Mesh(pointers[i], PointerType.MANAGED);
        }

        return meshes;
    }

    /**
     * Internal constructor
     *
     * @param pointer     The native pointer address
     * @param pointerType The native pointer type
     */
    Model(long pointer, PointerType pointerType) {
        super();

        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public Model(String path) throws ArqanoreException {
        super();

        address = _create(path);
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

    public int totalVertices() {
        return _totalVertices(address);
    }

    public int totalTexcoords() {
        return _totalTexcoords(address);
    }

    public int totalNormals() {
        return _totalNormals(address);
    }

    public int totalFrames() {
        return _totalFrames(address);
    }

    public void calculateNormals(boolean flip) {
        _calculateNormals(address, flip);
    }

    private native long _create(String path);

    private native void _destroy(long pointer);

    private native long[] _getMeshes(long pointer);

    private native int _totalVertices(long pointer);

    private native int _totalTexcoords(long pointer);

    private native int _totalNormals(long pointer);

    private native int _totalFrames(long pointer);

    private native void _calculateNormals(long pointer, boolean flip);
}
