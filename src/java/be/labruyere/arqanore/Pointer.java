package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

/**
 * A container object for pointers from the native library.
 */
public abstract class Pointer {
    long address;
    PointerType type;

    /**
     * The address the pointer points at. This <b>cannot and may not be modified in any way</b> by any other Java code or 3rd party application or library.
     * Doing so will introduce memory corruption and crashes.
     */
    public long getAddress() {
        return address;
    }

    /**
     * <p>An enum representing the pointer type. By which I mean the way the pointer address is handled.
     * Most of the pointers in JArqanore are dynamic but some of them are managed by the native library.</p>
     * <p>The user however does not know which pointers are managed and which are not.
     * Therefore JArqanore takes care of that behind the scenes using this variable.</p>
     */
    public PointerType getType() {
        return type;
    }

    protected Pointer() {
        address = 0;
        type = PointerType.DYNAMIC;
    }

    public void delete() {
        address = 0;
    }
}
