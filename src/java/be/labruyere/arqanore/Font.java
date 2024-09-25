package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

/**
 * Represents a font, used for drawing text
 */
public class Font extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * Public constructor
     * @param path The relative or absolute path to the TrueTypeFont file (.ttf)
     * @param glyphWidth The default width of each glyph
     * @param glyphHeight The default height of each glyph
     */
    public Font(String path, int glyphWidth, int glyphHeight) throws ArqanoreException {
        super();
        address = _create(path, glyphWidth, glyphHeight);
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
     * Measures the width of the text in pixels
     * @param text The text
     * @return The width of the text in pixels
     */
    public float measure(String text, float scale) {
        return _measure(address, text, scale);
    }

    private native long _create(String path, int width, int height);

    private native void _destroy(long font);

    private native float _measure(long font, String text, float scale);
}
