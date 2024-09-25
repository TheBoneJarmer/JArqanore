package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class MeshAnimation extends Pointer {
    static {
        Arqanore.init();
    }

    public MeshFrame[] getFrames() {
        var pointers = _getFrames(address);
        var frames = new MeshFrame[pointers.length];

        for (int i=0; i<frames.length; i++) {
            frames[i] = new MeshFrame(pointers[i], PointerType.MANAGED);
        }

        return frames;
    }

    /**
     * Internal constructor
     * @param pointer The native pointer address
     * @param pointerType The native pointer type
     */
    MeshAnimation(long pointer, PointerType pointerType) {
        super();

        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public MeshAnimation() {
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
    private native long[] _getFrames(long pointer);
}
