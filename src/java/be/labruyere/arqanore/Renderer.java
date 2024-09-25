package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.ShaderTarget;
import be.labruyere.arqanore.exceptions.ArqanoreException;
import be.labruyere.arqanore.utils.EnumUtils;

/**
 * A global object used for rendering sprites, polygons and fonts on the screen using the default shaders.
 * The user can also use different shaders for specific targets.
 */
public class Renderer {
    static {
        Arqanore.init();
    }

    public static Matrix4 generateModelMatrix(Vector3 pos, Quaternion rot, Vector3 scl) {
        return _generateModelMatrix(pos, rot, scl);
    }

    public static Matrix4 generateViewMatrix(Camera camera) {
        return _generateViewMatrix(camera.address);
    }

    public static Matrix4 generateProjectionMatrix(Camera camera, Window window) {
        return _generateProjectionMatrix(camera.address, window.address);
    }

    /**
     * Sets a custom shader for a specific target that remains active until the game loop ends or when the user sets another shader.
     *
     * @param shader The shader object
     * @param target The shader target.
     * @see Shaders
     */
    public static void setShader(Shader shader, ShaderTarget target) throws ArqanoreException {
        var targetValue = EnumUtils.convertShaderTarget(target);
        _setShader(shader.address, targetValue);
    }

    public static void switchShader(Shader shader) throws ArqanoreException {
        _switchShader(shader.address);
    }

    /**
     * Renders a sprite on the screen
     *
     * @param window    The window object
     * @param sprite    The sprite object
     * @param position  The sprite's position in pixels
     * @param scale     The sprite's scale
     * @param origin    The sprite's origin
     * @param angle     The sprite's angle in degrees
     * @param frameHor  The horizontal frame index of the sprite
     * @param frameVert The vertical frame index of the sprite
     * @param flipHor   If true, flips the sprite's texture horizontally
     * @param flipVert  If true, flips the sprite's texture vertically
     * @param color     The sprite's color
     */
    public static void renderSprite(Window window, Sprite sprite, Vector2 position, Vector2 scale, Vector2 origin, float angle, int frameHor, int frameVert, boolean flipHor, boolean flipVert, Color color) throws ArqanoreException {
        var winPtr = window.address;
        var sprPtr = sprite.address;

        _renderSprite(winPtr, sprPtr, position, scale, origin, angle, frameHor, frameVert, flipHor, flipVert, color);
    }

    public static void renderSprite(Window window, Sprite sprite, float x, float y, float scaleX, float scaleY, float originX, float originY, float angle, int frameHor, int frameVert, boolean flipHor, boolean flipVert, int r, int g, int b, int a) throws ArqanoreException {
        var position = new Vector2(x, y);
        var scale = new Vector2(scaleX, scaleY);
        var origin = new Vector2(originX, originY);
        var color = new Color(r, g, b, a);

        renderSprite(window, sprite, position, scale, origin, angle, frameHor, frameVert, flipHor, flipVert, color);
    }

    /**
     * Renders text on the screen using a specific font
     *
     * @param window   The window object
     * @param font     The font object
     * @param text     The text
     * @param position The position of the text in pixels
     * @param color    The text's color
     */
    public static void renderText(Window window, Font font, String text, Vector2 position, Vector2 scale, Color color) throws ArqanoreException {
        var winPtr = window.address;
        var fontPtr = font.address;

        _renderText(winPtr, fontPtr, text, position, scale, color);
    }

    public static void renderText(Window window, Font font, String text, float x, float y, float scaleX, float scaleY, int r, int g, int b, int a) throws ArqanoreException {
        var position = new Vector2(x, y);
        var color = new Color(r, g, b, a);
        var scale = new Vector2(scaleX, scaleY);

        renderText(window, font, text, position, scale, color);
    }

    /**
     * Renders a polygon on the screen
     *
     * @param window   The window object
     * @param polygon  The polygon object
     * @param texture  A texture object or null if you do not want to use a texture
     * @param position The polygon's position in pixels
     * @param scale    The polygon's scale
     * @param origin   The polygon's origin
     * @param offset   The polygon's texture offset. If no texture was set this value is ignored.
     * @param angle    The polygon's angle
     * @param flipHor  Flips the polygon's texture horizontally. If no texture was set this value is ignored.
     * @param flipVert Flips the polygon's texture vertically. If no texture was set this value is ignored.
     * @param color    The polygon's color.
     */
    public static void renderPolygon(Window window, Polygon polygon, Texture texture, Vector2 position, Vector2 scale, Vector2 origin, Vector2 offset, float angle, boolean flipHor, boolean flipVert, Color color) throws ArqanoreException {
        var winPtr = window.address;
        var polyPtr = polygon.address;
        var texPtr = 0L;

        if (texture != null) {
            texPtr = texture.address;
        }

        _renderPolygon(winPtr, polyPtr, texPtr, position, scale, origin, offset, angle, flipHor, flipVert, color);
    }

    public static void renderPolygon(Window window, Polygon polygon, Texture texture, float x, float y, float scaleX, float scaleY, float originX, float originY, float offsetX, float offsetY, float angle, boolean flipHor, boolean flipVert, int r, int g, int b, int a) throws ArqanoreException {
        var position = new Vector2(x, y);
        var scale = new Vector2(scaleX, scaleY);
        var origin = new Vector2(originX, originY);
        var offset = new Vector2(offsetX, offsetY);
        var color = new Color(r, g, b, a);

        renderPolygon(window, polygon, texture, position, scale, origin, offset, angle, flipHor, flipVert, color);
    }

    public static void renderModel(Window window, Model model, Vector3 position, Quaternion rotation, Vector3 scale, int frame) throws ArqanoreException {
        var winPtr = window.address;
        var modelPtr = model.address;

        _renderModel(winPtr, modelPtr, position, rotation, scale, frame);
    }

    public static void renderModel(Window window, Model model, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float rotW, float sclX, float sclY, float sclZ, int frame) throws ArqanoreException {
        var pos = new Vector3(posX, posY, posZ);
        var rot = new Quaternion(rotX, rotY, rotZ, rotW);
        var scl = new Vector3(sclX, sclY, sclZ);

        renderModel(window, model, pos, rot, scl, frame);
    }

    private static native Matrix4 _generateModelMatrix(Vector3 pos, Quaternion rot, Vector3 scl);

    private static native Matrix4 _generateViewMatrix(long camera);

    private static native Matrix4 _generateProjectionMatrix(long camera, long window);

    private static native void _setShader(long shader, int target);

    private static native void _switchShader(long shader);

    private static native void _renderText(long window, long font, String text, Vector2 position, Vector2 scale, Color color);

    private static native void _renderPolygon(long window, long polygon, long texture, Vector2 position, Vector2 scale, Vector2 origin, Vector2 offset, float angle, boolean flipHor, boolean flipVert, Color color);

    private static native void _renderSprite(long window, long sprite, Vector2 position, Vector2 scale, Vector2 origin, float angle, int frameHor, int frameVert, boolean flipHor, boolean flipVert, Color color);

    private static native void _renderModel(long window, long model, Vector3 position, Quaternion rotation, Vector3 scale, int frame);
}
