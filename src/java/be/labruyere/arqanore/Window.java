package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

/**
 * Represents a GLFW window object
 */
public class Window extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * The window's width in pixels
     *
     * @return The window width
     */
    public int getWidth() {
        return _getWidth(address);
    }

    /**
     * The window's height in pixels
     *
     * @return The window height
     */
    public int getHeight() {
        return _getHeight(address);
    }

    /**
     * The windows's x position on the screen
     *
     * @return The window's x position
     */
    public int getX() {
        return _getX(address);
    }

    /**
     * The windows's y position on the screen
     *
     * @return The window's y position
     */
    public int getY() {
        return _getY(address);
    }

    /**
     * The window's vertical sync state
     *
     * @return True if VSync is enabled or false if it is not
     */
    public boolean getVSync() {
        return _getVSync(address);
    }

    /**
     * Retrieves the window's title bar text
     *
     * @return The title
     */
    public String getTitle() {
        return _getTitle(address);
    }

    /**
     * A huge difference compared to other getters because the method arqanore::Window::get_clear_color() is used in the c++ part of JArqanore
     * And since c++ methods return copies instead of the reference itself, the copy would have been cleaned up once it leaves the scope.
     * Therefore, a new pointer is created based on the return value from the method.
     *
     * @return Color
     */
    public Color getClearColor() {
        return _getClearColor(address);
    }

    public double getFps() {
        return _getFps(address);
    }

    /**
     * Set the window's width
     *
     * @param value The value in pixels
     */
    public void setWidth(int value) {
        _setWidth(address, value);
    }

    /**
     * Sets the window's height
     *
     * @param value The value in pixels
     */
    public void setHeight(int value) {
        _setHeight(address, value);
    }

    /**
     * Sets the window's x position
     *
     * @param value The value in pixels
     */
    public void setX(int value) {
        _setX(address, value);
    }

    /**
     * Sets the window's y position
     *
     * @param value The value in pixels
     */
    public void setY(int value) {
        _setY(address, value);
    }

    /**
     * Enables or disables vertical sync
     *
     * @param value The value
     */
    public void setVSync(boolean value) {
        _setVSync(address, value);
    }

    /**
     * Sets the window's title bar text
     *
     * @param value The value
     */
    public void setTitle(String value) {
        _setTitle(address, value);
    }

    /**
     * Sets the window's clear color (aka background color)
     *
     * @param value The color
     */
    public void setClearColor(Color value) {
        _setClearColor(address, value);
    }

    public void setClearColor(int r, int g, int b) {
        var color = new Color(r, g, b);
        _setClearColor(address, color);
    }

    public boolean isClosed() {
        return _isClosed(address);
    }

    public void setClosed(boolean value) {
        _setClosed(address, value);
    }

    public boolean isMinimized() {
        return _isMinimized(address);
    }

    public boolean isMaximized() {
        return _isMaximized(address);
    }

    public boolean isVisible() {
        return _isVisible(address);
    }

    /**
     * Public constructor
     *
     * @param width  The window's initial width
     * @param height The window's initial height
     * @param title  The window's initial title
     */
    public Window(int width, int height, String title) {
        super();

        address = _create(width, height, title);
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

    /**
     * Opens the window
     *
     * @param fullscreen If true, the window will be fullscreen
     * @param resizable  If true, the user can resize the window and the maximize and minimize buttons are enabled
     */
    public void open(boolean fullscreen, boolean maximized, boolean resizable) throws ArqanoreException {
        _open(address, fullscreen, maximized, resizable);
    }

    /**
     * Closes the window
     */
    public void close() {
        _close(address);
    }

    public void minimize() {
        _minimize(address);
    }

    public void maximize() {
        _maximize(address);
    }

    public void show() {
        _show(address);
    }

    public void hide() {
        _hide(address);
    }

    public void restore() {
        _restore(address);
    }

    /**
     * Sets the onOpen callback
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onOpen(String className, String methodName) throws ArqanoreException {
        _setOpenCallback(address, className, methodName);
    }

    /**
     * Sets the onClose callback
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onClose(String className, String methodName) throws ArqanoreException {
        _setCloseCallback(address, className, methodName);
    }

    /**
     * Sets the onUpdate callback
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onUpdate(String className, String methodName) throws ArqanoreException {
        _setUpdateCallback(address, className, methodName);
    }

    /**
     * Sets the onRender callback for 2D
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onRender2D(String className, String methodName) throws ArqanoreException {
        _setRender2DCallback(address, className, methodName);
    }

    /**
     * Sets the onRender callback for 3D
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onRender3D(String className, String methodName) throws ArqanoreException {
        _setRender3DCallback(address, className, methodName);
    }

    /**
     * Sets the onResize callback
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onResize(String className, String methodName) throws ArqanoreException {
        _setResizeCallback(address, className, methodName);
    }

    /**
     * Sets the onPosition callback
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onPosition(String className, String methodName) throws ArqanoreException {
        _setPositionCallback(address, className, methodName);
    }

    /**
     * Sets the onChar callback
     *
     * @param className  The fully qualified name of the class
     * @param methodName The method name from the class
     * @throws ArqanoreException If callback did not register correctly
     */
    public void onChar(String className, String methodName) throws ArqanoreException {
        _setCharCallback(address, className, methodName);
    }

    private native int _getWidth(long window);

    private native int _getHeight(long window);

    private native int _getX(long window);

    private native int _getY(long window);

    private native boolean _getVSync(long window);

    private native String _getTitle(long window);

    private native Color _getClearColor(long window);

    private native double _getFps(long window);

    private native boolean _isClosed(long window);

    private native boolean _isMinimized(long window);

    private native boolean _isMaximized(long window);

    private native boolean _isVisible(long window);

    private native void _setWidth(long window, int value);

    private native void _setHeight(long window, int value);

    private native void _setX(long window, int value);

    private native void _setY(long window, int value);

    private native void _setVSync(long window, boolean value);

    private native void _setTitle(long window, String title);

    private native void _setClosed(long window, boolean value);

    private native void _setClearColor(long window, Color color);

    private native void _setOpenCallback(long window, String className, String methodName);

    private native void _setCloseCallback(long window, String className, String methodName);

    private native void _setUpdateCallback(long window, String className, String methodName);

    private native void _setRender2DCallback(long window, String className, String methodName);

    private native void _setRender3DCallback(long window, String className, String methodName);

    private native void _setResizeCallback(long window, String className, String methodName);

    private native void _setPositionCallback(long window, String className, String methodName);

    private native void _setCharCallback(long window, String className, String methodName);

    private native long _create(int width, int height, String title);

    private native void _destroy(long window);

    private native void _open(long window, boolean fullscreen, boolean maximized, boolean resizable);

    private native void _close(long window);

    private native void _minimize(long window);

    private native void _maximize(long window);

    private native void _restore(long window);

    private native void _show(long window);

    private native void _hide(long window);
}
