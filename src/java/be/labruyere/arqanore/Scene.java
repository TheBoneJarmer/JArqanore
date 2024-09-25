package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;

public class Scene {
    static {
        Arqanore.init();
    }

    public static Light[] getLights() {
        var pointers = _getLights();
        var lights = new Light[pointers.length];

        for (int i = 0; i < lights.length; i++) {
            lights[i] = new Light(pointers[i], PointerType.MANAGED);
        }

        return lights;
    }

    public static Camera[] getCameras() {
        var pointers = _getCameras();
        var cameras = new Camera[pointers.length];

        for (int i=0; i<cameras.length; i++) {
            cameras[i] = new Camera(pointers[i], PointerType.MANAGED);
        }

        return cameras;
    }

    public static int getActiveCamera() {
        return _getActiveCamera();
    }

    public static void reset() {
        _reset();
    }

    public static void add(Camera camera) {
        _addCamera(camera.address);
    }

    public static void add(Light light) {
        _addLight(light.address);
    }

    private static native long[] _getCameras();
    private static native long[] _getLights();
    private static native int _getActiveCamera();
    private static native void _reset();
    private static native void _addCamera(long pointer);
    private static native void _addLight(long pointer);
}
