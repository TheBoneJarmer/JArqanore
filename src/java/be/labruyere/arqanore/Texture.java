package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

/**
 * Represents a single image which can be used by polygons
 */
public class Texture extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * The texture's width
     * @return The width in pixels
     */
    public int getWidth() {
        return _getWidth(address);
    }

    /**
     * The texture's height
     * @return The height in pixels
     */
    public int getHeight() {
        return _getHeight(address);
    }

    /**
     * Internal constructor
     * @param pointer The pointer address
     * @param pointerType The pointer type
     */
    Texture(long pointer, PointerType pointerType) {
        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public constructor
     * @param filename The absolure or relative path to the image file
     */
    public Texture(String filename) throws ArqanoreException {
        super();

        address = _create(filename);
    }

    /**
     * Deletes the native pointer object
     */
    @Override
    public void delete() {
        if (type != PointerType.DYNAMIC) {
            return;
        }

        _destroy(address);
        super.delete();
    }

    private native long _create(String filename);
    private native void _destroy(long pointer);
    private native int _getWidth(long pointer);
    private native int _getHeight(long pointer);
}
