package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class Material extends Pointer {
    static {
        Arqanore.init();
    }

    public String getName() {
        return _getName(address);
    }

    public Color getColor() {
        return _getColor(address);
    }

    public Color getDiffuse() {
        return _getDiffuse(address);
    }

    public Color getAmbient() {
        return _getAmbient(address);
    }

    public Color getSpecular() {
        return _getSpecular(address);
    }

    public float getShininess() {
        return _getShininess(address);
    }

    public Texture getDiffuseMap() {
        var ptr = _getDiffuseMap(address);

        if (ptr > 0) {
            return new Texture(ptr, PointerType.MANAGED);
        }

        return null;
    }

    public Texture getAmbientMap() {
        var ptr = _getAmbientMap(address);

        if (ptr > 0) {
            return new Texture(ptr, PointerType.MANAGED);
        }

        return null;
    }

    public Texture getSpecularMap() {
        var ptr = _getSpecularMap(address);

        if (ptr > 0) {
            return new Texture(ptr, PointerType.MANAGED);
        }

        return null;
    }

    public void setName(String value) {
        _setName(address, value);
    }

    public void setColor(Color value) {
        _setColor(address, value);
    }

    public void setDiffuse(Color value) {
        _setDiffuse(address, value);
    }

    public void setDiffuse(int r, int g, int b) {
        var color = new Color(r, g, b);
        _setDiffuse(address, color);
    }

    public void setAmbient(Color value) {
        _setAmbient(address, value);
    }

    public void setAmbient(int r, int g, int b) {
        var color = new Color(r, g, b);
        _setAmbient(address, color);
    }

    public void setSpecular(Color value) {
        _setSpecular(address, value);
    }

    public void setSpecular(int r, int g, int b) {
        var color = new Color(r, g, b);
        _setSpecular(address, color);
    }

    public void setShininess(float value) {
        _setShininess(address, value);
    }

    public void setDiffuseMap(Texture value) {
        if (value == null) {
            _setDiffuseMap(address, 0);
        } else {
            _setDiffuseMap(address, value.address);
        }
    }

    public void setAmbientMap(Texture value) {
        if (value == null) {
            _setAmbientMap(address, 0);
        } else {
            _setAmbientMap(address, value.address);
        }
    }

    public void setSpecularMap(Texture value) {
        if (value == null) {
            _setSpecularMap(address, 0);
        } else {
            _setSpecularMap(address, value.address);
        }
    }

    Material(long pointer, PointerType type) {
        super();

        this.address = pointer;
        this.type = type;
    }

    /**
     * Public default constructor.
     */
    public Material() {
        super();

        this.address = _create();
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

    private native String _getName(long pointer);

    private native Color _getColor(long pointer);

    private native Color _getDiffuse(long pointer);

    private native Color _getAmbient(long pointer);

    private native Color _getSpecular(long pointer);

    private native float _getShininess(long pointer);

    private native long _getDiffuseMap(long pointer);

    private native long _getAmbientMap(long pointer);

    private native long _getSpecularMap(long pointer);

    private native void _setName(long pointer, String value);

    private native void _setColor(long pointer, Color value);

    private native void _setDiffuse(long pointer, Color value);

    private native void _setAmbient(long pointer, Color value);

    private native void _setSpecular(long pointer, Color value);

    private native void _setShininess(long pointer, float value);

    private native void _setDiffuseMap(long pointer, long value);

    private native void _setAmbientMap(long pointer, long value);

    private native void _setSpecularMap(long pointer, long value);
}
