#include <arqanore/mouse.h>
#include "be_labruyere_arqanore_Mouse.h"

jfloat Java_be_labruyere_arqanore_Mouse__1getX(JNIEnv *env, jclass cls) {
    return arqanore::Mouse::get_x();
}

jfloat Java_be_labruyere_arqanore_Mouse__1getY(JNIEnv *env, jclass cls) {
    return arqanore::Mouse::get_y();
}

jfloat Java_be_labruyere_arqanore_Mouse__1getMoveX(JNIEnv *env, jclass cls) {
    return arqanore::Mouse::get_move_x();
}

jfloat Java_be_labruyere_arqanore_Mouse__1getMoveY(JNIEnv *env, jclass cls) {
    return arqanore::Mouse::get_move_y();
}

jint Java_be_labruyere_arqanore_Mouse__1getScrollX(JNIEnv *env, jclass cls) {
    return arqanore::Mouse::get_scroll_x();
}

jint Java_be_labruyere_arqanore_Mouse__1getScrollY(JNIEnv *env, jclass cls) {
    return arqanore::Mouse::get_scroll_y();
}

jboolean Java_be_labruyere_arqanore_Mouse__1buttonDown(JNIEnv *env, jclass cls, jint button) {
    return arqanore::Mouse::button_down(button);
}

jboolean Java_be_labruyere_arqanore_Mouse__1buttonUp(JNIEnv *env, jclass cls, jint button) {
    return arqanore::Mouse::button_up(button);
}

jboolean Java_be_labruyere_arqanore_Mouse__1buttonPressed(JNIEnv *env, jclass cls, jint button) {
    return arqanore::Mouse::button_pressed(button);
}

void Java_be_labruyere_arqanore_Mouse__1hide(JNIEnv *env, jclass cls, jlong ptr) {
    arqanore::Mouse::hide((arqanore::Window *) ptr);
}

void Java_be_labruyere_arqanore_Mouse__1disable(JNIEnv *env, jclass cls, jlong ptr) {
    arqanore::Mouse::disable((arqanore::Window *) ptr);
}

void Java_be_labruyere_arqanore_Mouse__1show(JNIEnv *env, jclass cls, jlong ptr) {
    arqanore::Mouse::show((arqanore::Window *) ptr);
}
