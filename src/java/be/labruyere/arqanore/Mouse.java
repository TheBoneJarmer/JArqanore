package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.MouseButtons;
import be.labruyere.arqanore.utils.EnumUtils;

/**
 * Represents a global mouse manager object that allows you to get mouse input.
 */
public class Mouse {
    static {
        Arqanore.init();
    }

    /**
     * @return The mouse's x position
     */
    public static float getX() {
        return _getX();
    }

    /**
     * @return The mouse's y position
     */
    public static float getY() {
        return _getY();
    }

    public static float getMoveX() {
        return _getMoveX();
    }

    public static float getMoveY() {
        return _getMoveY();
    }

    public static int getScrollX() {
        return _getScrollX();
    }

    public static int getScrollY() {
        return _getScrollY();
    }

    /**
     * Checks whether a mouse button is held down.
     *
     * @param button The mouse button.
     * @return True if the mouse button is held down or false if it is not
     */
    public static boolean buttonDown(MouseButtons button) {
        return _buttonDown(EnumUtils.convertMouseButton(button));
    }

    /**
     * Checks whether a mouse button used to be held down.
     *
     * @param button The mouse button.
     * @return True if the mouse button was held down or false if it was not
     */
    public static boolean buttonUp(MouseButtons button) {
        return _buttonUp(EnumUtils.convertMouseButton(button));
    }

    /**
     * Checks whether a mouse button was pressed
     *
     * @param button The mouse button.
     * @return True if the mouse button was pressed or false if it was not
     */
    public static boolean buttonPressed(MouseButtons button) {
        return _buttonPressed(EnumUtils.convertMouseButton(button));
    }

    /**
     * Hides the mouse in the window but still allows you to use it.
     */
    public static void hide(Window window) {
        _hide(window.address);
    }

    /**
     * Disables the mouse in the window. This means you cannot use it.
     */
    public static void disable(Window window) {
        _disable(window.address);
    }

    /**
     * Shows the mouse in the window if it was hidden or disabled.
     */
    public static void show(Window window) {
        _show(window.address);
    }

    private static native float _getX();

    private static native float _getY();

    private static native float _getMoveX();

    private static native float _getMoveY();

    private static native int _getScrollX();

    private static native int _getScrollY();

    private static native boolean _buttonDown(int button);

    private static native boolean _buttonUp(int button);

    private static native boolean _buttonPressed(int button);

    private static native void _hide(long window);

    private static native void _disable(long window);

    private static native void _show(long window);
}
