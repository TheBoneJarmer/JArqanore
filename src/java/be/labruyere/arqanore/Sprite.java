package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

/**
 * Represents a sprite object
 */
public class Sprite extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * Gets the sprite's width
     * @return The width in pixels
     */
    public int getWidth() {
        return _getWidth(address);
    }

    /**
     * Gets the sprite's height
     * @return The height in pixels
     */
    public int getHeight() {
        return _getHeight(address);
    }

    /**
     * Gets the sprite's frame width
     * @return The width in pixels
     */
    public int getFrameWidth() {
        return _getFrameWidth(address);
    }

    /**
     * Gets the sprite's frame height
     * @return The height in pixels
     */
    public int getFrameHeight() {
        return _getFrameHeight(address);
    }

    /**
     * Gets the total frames horizontally
     * @return The amount of horizontal frames
     */
    public int getFramesHor() {
        return _getFramesHor(address);
    }

    /**
     * Gets the total frames vertically
     * @return The amount of vertical frames
     */
    public int getFramesVert() {
        return _getFramesVert(address);
    }

    /**
     * Internal constructor
     * @param pointer The pointer address
     * @param pointerType The pointer type
     */
    Sprite(long pointer, PointerType pointerType) {
        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public constructor
     * @param path The path to the sprite's image file
     * @param frameWidth The sprite's frame width if the sprite is a spritesheet. If 0 the sprite's width is used.
     * @param frameHeight The sprite's frame height if the sprite is a spritesheet. If 0 the sprite's height is used.
     */
    public Sprite(String path, int frameWidth, int frameHeight) throws ArqanoreException {
        super();

        address = _create(path, frameWidth, frameHeight);
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

    private native long _create(String path, int frameWidth, int frameHeight);
    private native void _destroy(long pointer);

    private native int _getWidth(long pointer);
    private native int _getHeight(long pointer);
    private native int _getFrameWidth(long pointer);
    private native int _getFrameHeight(long pointer);
    private native int _getFramesHor(long pointer);
    private native int _getFramesVert(long pointer);
}
