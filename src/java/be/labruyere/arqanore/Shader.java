package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.enums.ShaderSourceType;
import be.labruyere.arqanore.enums.ShaderType;
import be.labruyere.arqanore.exceptions.ArqanoreException;
import be.labruyere.arqanore.utils.EnumUtils;

/**
 * Represents an OpenGL shader object. Shaders can be used to modify the graphical representation of a polygon, font or sprite.
 */
public class Shader extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * Internal constructor
     *
     * @param pointer     The native pointer address
     * @param pointerType The native pointer type
     */
    Shader(long pointer, PointerType pointerType) {
        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public Shader() {
        super();

        address = _create();
    }

    /**
     * Deletes the native pointer.
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
     * Adds a shader source from a shader file (.glsl)
     *
     * @param source The path to the shader file
     * @param type   The shader type
     */
    public void addSource(String source, ShaderType type) throws ArqanoreException {
        addSource(source, type, ShaderSourceType.FILE);
    }

    /**
     * Adds a shader from a source. This can be either a raw string or a path to a shader file (.glsl).
     *
     * @param source     The shader source
     * @param type       The shader type
     * @param sourceType The shader source type
     */
    public void addSource(String source, ShaderType type, ShaderSourceType sourceType) throws ArqanoreException {
        if (type == ShaderType.VERTEX) {
            _addVertexSource(address, source, EnumUtils.convertShaderSourceType(sourceType));
        }

        if (type == ShaderType.FRAGMENT) {
            _addFragmentSource(address, source, EnumUtils.convertShaderSourceType(sourceType));
        }
    }

    /**
     * Compiles the shader using the sources that were added.
     *
     * @throws ArqanoreException If the compilation fails. The message contains the error message from the OpenGL shader compilation result.
     */
    public void compile() throws ArqanoreException {
        _compile(address);
    }

    public void setUniform1i(String name, int i) throws ArqanoreException {
        _setUniform1i(address, name, i);
    }

    public void setUniform2i(String name, int i1, int i2) throws ArqanoreException {
        _setUniform2i(address, name, i1, i2);
    }

    public void setUniform3i(String name, int i1, int i2, int i3) throws ArqanoreException {
        _setUniform3i(address, name, i1, i2, i3);
    }

    public void setUniform4i(String name, int i1, int i2, int i3, int i4) throws ArqanoreException {
        _setUniform4i(address, name, i1, i2, i3, i4);
    }

    public void setUniform1f(String name, float f) throws ArqanoreException {
        _setUniform1f(address, name, f);
    }

    public void setUniform2f(String name, float f1, float f2) throws ArqanoreException {
        _setUniform2f(address, name, f1, f2);
    }

    public void setUniform3f(String name, float f1, float f2, float f3) throws ArqanoreException {
        _setUniform3f(address, name, f1, f2, f3);
    }

    public void setUniform4f(String name, float f1, float f2, float f3, float f4) throws ArqanoreException {
        _setUniform4f(address, name, f1, f2, f3, f4);
    }

    public void setUniform1d(String name, double d) throws ArqanoreException {
        _setUniform1d(address, name, d);
    }

    public void setUniform2d(String name, double d1, double d2) throws ArqanoreException {
        _setUniform2d(address, name, d1, d2);
    }

    public void setUniform3d(String name, double d1, double d2, double d3) throws ArqanoreException {
        _setUniform3d(address, name, d1, d2, d3);
    }

    public void setUniform4d(String name, double d1, double d2, double d3, double d4) throws ArqanoreException {
        _setUniform4d(address, name, d1, d2, d3, d4);
    }

    public void setUniformVec2(String name, Vector2 value) throws ArqanoreException {
        _setUniformVec2(address, name, value);
    }

    public void setUniformVec3(String name, Vector3 value) throws ArqanoreException {
        _setUniformVec3(address, name, value);
    }

    public void setUniformMat3(String name, Matrix3 value) throws ArqanoreException {
        _setUniformMat3(address, name, value);
    }

    public void setUniformMat4(String name, Matrix4 value) throws ArqanoreException {
        _setUniformMat4(address, name, value);
    }

    public void setUniformRgba(String name, Color value) throws ArqanoreException {
        _setUniformRgba(address, name, value);
    }

    public void setUniformRgb(String name, Color value) throws ArqanoreException {
        _setUniformRgb(address, name, value);
    }

    public void setTexture(int index, Texture tex) {
        _setTexture(address, index, tex.address);
    }

    public void setSprite(int index, Sprite spr) {
        _setSprite(address, index, spr.address);
    }

    private native long _create();

    private native void _destroy(long shader);

    private native void _addVertexSource(long shader, String source, int sourceType);

    private native void _addFragmentSource(long shader, String source, int sourceType);

    private native void _compile(long shader);

    private native void _setUniform1i(long shader, String name, int i);

    private native void _setUniform2i(long shader, String name, int i1, int i2);

    private native void _setUniform3i(long shader, String name, int i1, int i2, int i3);

    private native void _setUniform4i(long shader, String name, int i1, int i2, int i3, int i4);

    private native void _setUniform1f(long shader, String name, float f);

    private native void _setUniform2f(long shader, String name, float f1, float f2);

    private native void _setUniform3f(long shader, String name, float f1, float f2, float f3);

    private native void _setUniform4f(long shader, String name, float f1, float f2, float f3, float f4);

    private native void _setUniform1d(long shader, String name, double d);

    private native void _setUniform2d(long shader, String name, double d1, double d2);

    private native void _setUniform3d(long shader, String name, double d1, double d2, double d3);

    private native void _setUniform4d(long shader, String name, double d1, double d2, double d3, double d4);

    private native void _setUniformVec2(long shader, String name, Vector2 value);

    private native void _setUniformVec3(long shader, String name, Vector3 value);

    private native void _setUniformMat3(long shader, String name, Matrix3 value);

    private native void _setUniformMat4(long shader, String name, Matrix4 value);

    private native void _setUniformRgba(long shader, String name, Color value);

    private native void _setUniformRgb(long shader, String name, Color value);

    private native void _setTexture(long shader, int index, long texture);

    private native void _setSprite(long shader, int index, long sprite);
}
