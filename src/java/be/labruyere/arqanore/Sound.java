package be.labruyere.arqanore;

/**
 * Represents a sound
 */
public class Sound extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * Checks if the sound is paused
     * @return True if it is paused or false if it was not
     */
    public boolean isPaused() {
        return _isPaused(address);
    }

    /**
     * Checks if the sound is being looped
     * @return True if it is being looped or false if it is not
     */
    public boolean isLooping() {
        return _isLooping(address);
    }

    /**
     * Checks if the sound is playing
     * @return True if the sound is playing or false if it is not
     */
    public boolean isPlaying() {
        return _isPlaying(address);
    }

    /**
     * Gets the sound's volume. A value of 0 means completely silent and a value of 1 is max volume.
     * @return A double in range from 0 to 1 representing the sound's volume.
     */
    public double getVolume() {
        return _getVolume(address);
    }

    /**
     * Gets the sound's pan. A value of 0 means the pan is to the left and a value of 2 means the pan is to the right. If the value is 1 it means it is centered.
     * @return A double in range from 0 to 2 representing the sound's pan.
     */
    public double getPan() {
        return _getPan(address);
    }

    /**
     * Sets the sound's looping state
     * @param value The value
     */
    public void setLooping(boolean value) {
        _setLooping(address, value);
    }

    /**
     * Sets the sound's paused state
     * @param value The value
     */
    public void setPaused(boolean value) {
        _setPaused(address, value);
    }

    /**
     * Sets the sound's volume
     * @param value A double in range of 0 to 1.
     * @see Sound#getVolume()
     */
    public void setVolume(double value) {
        _setVolume(address, value);
    }

    /**
     * Sets the sound's pan
     * @param value A double in range from 0 to 2
     * @see Sound#getPan()
     */
    public void setPan(double value) {
        _setPan(address, value);
    }

    /**
     * Public default constructor
     * @param path The path to the sound
     */
    public Sound(String path) {
        super();

        address = _create(path);
    }

    /**
     * Deletes the nativep ointer
     */
    @Override
    public void delete() {
        _destroy(address);
        super.delete();
    }

    /**
     * Plays the sound if it is not playing
     */
    public void play() {
        _play(address);
    }

    /**
     * Stops the sound if it is playing
     */
    public void stop() {
        _stop(address);
    }

    private native boolean _isPaused(long sound);
    private native boolean _isLooping(long sound);
    private native boolean _isPlaying(long sound);
    private native double _getVolume(long sound);
    private native double _getPan(long sound);
    private native void _setLooping(long sound, boolean value);
    private native void _setPaused(long sound, boolean value);
    private native void _setVolume(long sound, double value);
    private native void _setPan(long sound, double value);
    private native long _create(String path);
    private native void _destroy(long sound);
    private native void _play(long sound);
    private native void _stop(long sound);
}
