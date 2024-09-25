package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.Keys;
import be.labruyere.arqanore.exceptions.ArqanoreException;
import be.labruyere.arqanore.utils.EnumUtils;

/**
 * Represents a global keyboard manager object that allows you to get keyboard input.
 */
public class Keyboard {
    static {
        Arqanore.init();
    }

    /**
     * Checks whether the given key is held down.
     *
     * @param key The key.
     * @return True if the given key is held down or false if the given key is not held down.
     * @see Keys
     */
    public static boolean keyDown(Keys key) throws ArqanoreException {
        return _keyDown(EnumUtils.convertKey(key));
    }

    /**
     * Checks whether the given key was held down but not anymore.
     *
     * @param key The key.
     * @return True if the given key was held down or false if the given key is not held down anymore.
     */
    public static boolean keyUp(Keys key) throws ArqanoreException {
        return _keyUp(EnumUtils.convertKey(key));
    }

    /**
     * Checks whether the given key was pressed.
     *
     * @param key The key.
     * @return True if the given key was pressed or false if the given key was not.
     */
    public static boolean keyPressed(Keys key) throws ArqanoreException {
        return _keyPressed(EnumUtils.convertKey(key));
    }

    private static native boolean _keyUp(int key);

    private static native boolean _keyDown(int key);

    private static native boolean _keyPressed(int key);
}
