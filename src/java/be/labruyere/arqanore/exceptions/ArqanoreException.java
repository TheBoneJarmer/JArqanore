package be.labruyere.arqanore.exceptions;

public class ArqanoreException extends Exception {
    public ArqanoreException(String message) {
        super(message);
    }

    public ArqanoreException(Exception e) {
        super(e);
    }

    public ArqanoreException(String message, Exception e) {
        super(message, e);
    }
}
