#include <arqanore/keyboard.h>
#include "be_labruyere_arqanore_Keyboard.h"
#include "arqanore/exceptions.h"
#include "jni_utils.h"

/* WRAPPER METHODS */
jboolean Java_be_labruyere_arqanore_Keyboard__1keyDown(JNIEnv *env, jclass cls, jint key) {
    try {
        return arqanore::Keyboard::key_down(key);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return false;
}

jboolean Java_be_labruyere_arqanore_Keyboard__1keyUp(JNIEnv *env, jclass cls, jint key) {
    try {
        return arqanore::Keyboard::key_up(key);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return false;
}

jboolean Java_be_labruyere_arqanore_Keyboard__1keyPressed(JNIEnv *env, jclass cls, jint key) {
    try {
        return arqanore::Keyboard::key_pressed(key);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return false;
}
