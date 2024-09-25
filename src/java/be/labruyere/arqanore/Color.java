package be.labruyere.arqanore;

/**
 * Represents a color using the components red, green, blue and alpha
 */
public class Color {
    static {
        Arqanore.init();

        RED = _getConstRed();
        GREEN = _getConstGreen();
        BLUE = _getConstBlue();
        CYAN = _getConstCyan();
        YELLOW = _getConstYellow();
        PURPLE = _getConstPurple();
        WHITE = _getConstWhite();
        BLACK = _getConstBlack();
    }

    /**
     * The color constant RED
     */
    public static final Color RED;

    /**
     * The color constant GREEN
     */
    public static final Color GREEN;

    /**
     * The color constant BLUE
     */
    public static final Color BLUE;

    /**
     * The color constant CYAN
     */
    public static final Color CYAN;

    /**
     * The color constant YELLOW
     */
    public static final Color YELLOW;

    /**
     * The color constant PURPLE
     */
    public static final Color PURPLE;

    /**
     * The color constant WHITE
     */
    public static final Color WHITE;

    /**
     * The color constant BLACK
     */
    public static final Color BLACK;

    public int r;
    public int g;
    public int b;
    public int a;

    public Color() {
        this.r = 0;
        this.g = 0;
        this.b = 0;
        this.a = 255;
    }

    public Color(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
        this.a = 255;
    }

    public Color(int r, int g, int b, int a) {
        this.r = r;
        this.g = g;
        this.b = b;
        this.a = a;
    }

    private static native Color _getConstRed();

    private static native Color _getConstGreen();

    private static native Color _getConstBlue();

    private static native Color _getConstCyan();

    private static native Color _getConstYellow();

    private static native Color _getConstPurple();

    private static native Color _getConstWhite();

    private static native Color _getConstBlack();
}
