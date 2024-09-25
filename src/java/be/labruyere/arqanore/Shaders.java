package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

/**
 * Represents all default shaders
 */
public class Shaders {
    static {
        Arqanore.init();
    }

    /**
     * The default sprite shader
     * @return A shader object
     */
    public static Shader getSprite() {
        return new Shader(_getSprite(), PointerType.MANAGED);
    }

    /**
     * The default polygon shader
     * @return A shader object
     */
    public static Shader getPolygon() {
        return new Shader(_getPolygon(), PointerType.MANAGED);
    }

    /**
     * The default font shader
     * @return A shader object
     */
    public static Shader getFont() {
        return new Shader(_getFont(), PointerType.MANAGED);
    }

    /**
     * Sets the default sprite shader.
     * @param shader The shader object
     * @throws ArqanoreException When the shader is null
     */
    public static void setSprite(Shader shader) throws ArqanoreException {
        if (shader == null) {
            throw new ArqanoreException("Shader cannot be null");
        }

        _setSprite(shader.getAddress());
    }

    /**
     * Sets the default polygon shader.
     * @param shader The shader object
     * @throws ArqanoreException When the shader is null
     */
    public static void setPolygon(Shader shader) throws ArqanoreException {
        if (shader == null) {
            throw new ArqanoreException("Shader cannot be null");
        }

        _setPolygon(shader.getAddress());
    }

    /**
     * Sets the default font shader.
     * @param shader The shader object
     * @throws ArqanoreException When the shader is null
     */
    public static void setFont(Shader shader) throws ArqanoreException {
        if (shader == null) {
            throw new ArqanoreException("Shader cannot be null");
        }

        _setFont(shader.getAddress());
    }

    private static native long _getSprite();

    private static native void _setSprite(long shader);

    private static native long _getPolygon();

    private static native void _setPolygon(long shader);

    private static native long _getFont();

    private static native void _setFont(long shader);
}
