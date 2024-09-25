package be.labruyere.arqanore;

import be.labruyere.arqanore.enums.PointerType;
import be.labruyere.arqanore.exceptions.ArqanoreException;

import java.util.ArrayList;

/**
 * Represents a polygon, a shape created from triangles where each triangle is defined by 3 vertices.
 */
public class Polygon extends Pointer {
    static {
        Arqanore.init();
    }

    /**
     * Public constructor.
     * @param vertices An array of vertices
     * @param texcoords An array of texcoords
     */
    public Polygon(Vector2[] vertices, Vector2[] texcoords) throws ArqanoreException {
        super();

        var listVertices = new ArrayList<Float>();
        var listTexcoords = new ArrayList<Float>();

        for (var vertex : vertices) {
            listVertices.add(vertex.x);
            listVertices.add(vertex.y);
        }

        for (var vertex : texcoords) {
            listTexcoords.add(vertex.x);
            listTexcoords.add(vertex.y);
        }

        var arrVertices = new float[listVertices.size()];
        var arrTexcoords = new float[listTexcoords.size()];

        for (var i = 0; i < arrVertices.length; i++) {
            arrVertices[i] = listVertices.get(i);
        }

        for (var i = 0; i < arrTexcoords.length; i++) {
            arrTexcoords[i] = listTexcoords.get(i);
        }

        this.address = _create(arrVertices, arrTexcoords);
    }

    /**
     * Public constructor.
     * @param vertices An float array of vertex values
     * @param texcoords An float array of texcoord values
     */
    public Polygon(float[] vertices, float[] texcoords) throws ArqanoreException {
        this.address = _create(vertices, texcoords);
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

    private static native long _create(float[] vertices, float[] texcoords);

    private static native void _destroy(long polygon);
}
