package be.labruyere.arqanore;

import be.labruyere.arqanore.exceptions.ArqanoreException;

/**
 * Represents a global joystick manager object that allows you to get joystick input and states.
 * Joysticks are presented with ids ranging from 1 to 16.
 */
public class Joystick {
    static {
        Arqanore.init();
    }

    /**
     * Checks if a joystick is connected
     * @param jid The joystick's id
     * @return True if the joystick is connected or false if it is not
     */
    public static boolean isConnected(int jid) throws ArqanoreException {
        return _isConnected(jid);
    }

    /**
     * Gets a joystick's name
     * @param jid The joystick's id
     * @return The name of the joystick
     */
    public static String getName(int jid) throws ArqanoreException {
        return _getName(jid);
    }

    /**
     * Gets a joystick's guid
     * @param jid The joystick's id
     * @return The guid of the joystick
     */
    public static String getGuid(int jid) throws ArqanoreException {
        return _getGuid(jid);
    }

    /**
     * Gets the axis states from a joystick.
     * @param jid The joystick's id
     * @return An array of floats where each element represents the state of the axis whose index matches the index of the element
     */
    public static float[] getAxes(int jid) throws ArqanoreException {
        return _getAxes(jid);
    }

    /**
     * Gets the button states from a joystick.
     * @param jid The joystick's id
     * @return An array of integers where each element represents the state of the button whose index matches the index of the element
     */
    public static int[] getButtons(int jid) throws ArqanoreException {
        return _getButtons(jid);
    }

    private static native boolean _isConnected(int jid);
    private static native String _getName(int jid);
    private static native String _getGuid(int jid);
    private static native float[] _getAxes(int jid);
    private static native int[] _getButtons(int jid);
}
