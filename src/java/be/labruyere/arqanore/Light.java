package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.LightType;
import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.utils.EnumUtils;

public class Light extends Pointer {
    static {
        Arqanore.init();
    }

    public LightType getLightType() {
        var value = _getLightType(address);
        return EnumUtils.convertLightType(value);
    }

    public Vector3 getSource() {
        return _getSource(address);
    }

    public Color getColor() {
        return _getColor(address);
    }

    public boolean isEnabled() {
        return _isEnabled(address);
    }

    public float getStrength() {
        return _getStrength(address);
    }

    public float getRange() {
        return _getRange(address);
    }

    public void setLightType(LightType value) {
        _setLightType(address, EnumUtils.convertLightType(value));
    }

    public void setSource(Vector3 value) {
        _setSource(address, value);
    }

    public void setSource(float x, float y, float z) {
        var vec = new Vector3(x, y, z);
        _setSource(address, vec);
    }

    public void setColor(Color value) {
        _setColor(address, value);
    }

    public void setColor(int r, int g, int b) {
        var color = new Color(r, g, b);
        _setColor(address, color);
    }

    public void setEnabled(boolean value) {
        _setEnabled(address, value);
    }

    public void setStrength(float value) {
        _setStrength(address, value);
    }

    public void setRange(float value) {
        _setRange(address, value);
    }

    /**
     * Internal constructor
     *
     * @param pointer     The native pointer address
     * @param pointerType The native pointer type
     */
    Light(long pointer, PointerType pointerType) {
        super();

        this.address = pointer;
        this.type = pointerType;
    }

    /**
     * Public default constructor.
     */
    public Light() {
        super();

        address = _create();
    }

    public Light(LightType type) {
        super();

        address = _create(EnumUtils.convertLightType(type));
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

    private native long _create(int type);

    private native void _destroy(long pointer);

    private native int _getLightType(long pointer);

    private native Vector3 _getSource(long pointer);

    private native Color _getColor(long pointer);

    private native boolean _isEnabled(long pointer);

    private native float _getStrength(long pointer);
    private native float _getRange(long pointer);

    private native void _setLightType(long pointer, int value);

    private native void _setSource(long pointer, Vector3 value);

    private native void _setColor(long pointer, Color color);

    private native void _setEnabled(long pointer, boolean value);

    private native void _setStrength(long pointer, float value);
    private native void _setRange(long pointer, float value);
}
