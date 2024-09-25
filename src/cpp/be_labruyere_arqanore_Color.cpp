#include <cinttypes>
#include "be_labruyere_arqanore_Color.h"
#include "arqanore/color.h"
#include "arq_utils.h"

jobject Java_be_labruyere_arqanore_Color__1getConstRed(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::RED);
}

jobject Java_be_labruyere_arqanore_Color__1getConstGreen(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::GREEN);
}

jobject Java_be_labruyere_arqanore_Color__1getConstBlue(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::BLUE);
}

jobject Java_be_labruyere_arqanore_Color__1getConstCyan(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::CYAN);
}

jobject Java_be_labruyere_arqanore_Color__1getConstYellow(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::YELLOW);
}

jobject Java_be_labruyere_arqanore_Color__1getConstPurple(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::PURPLE);
}

jobject Java_be_labruyere_arqanore_Color__1getConstWhite(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::WHITE);
}

jobject Java_be_labruyere_arqanore_Color__1getConstBlack(JNIEnv *env, jclass cls) {
    return convert_color(env, arqanore::Color::BLACK);
}
