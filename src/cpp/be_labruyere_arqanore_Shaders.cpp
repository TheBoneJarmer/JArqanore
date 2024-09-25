#include "be_labruyere_arqanore_Shaders.h"
#include <arqanore/shaders.h>

jlong Java_be_labruyere_arqanore_Shaders__1getSprite(JNIEnv *env, jclass cls) {
    return (intptr_t) &arqanore::Shaders::sprite;
}

void Java_be_labruyere_arqanore_Shaders__1setSprite(JNIEnv *env, jclass cls, jlong shader) {
    auto ptr = (arqanore::Shader *) shader;
    arqanore::Shaders::sprite = *ptr;
}

jlong Java_be_labruyere_arqanore_Shaders__1getPolygon(JNIEnv *env, jclass cls) {
    return (intptr_t) &arqanore::Shaders::polygon;
}

void Java_be_labruyere_arqanore_Shaders__1setPolygon(JNIEnv *env, jclass cls, jlong shader) {
    auto ptr = (arqanore::Shader *) shader;
    arqanore::Shaders::polygon = *ptr;
}

jlong Java_be_labruyere_arqanore_Shaders__1getFont(JNIEnv *env, jclass cls) {
    return (intptr_t) &arqanore::Shaders::font;
}

void Java_be_labruyere_arqanore_Shaders__1setFont(JNIEnv *env, jclass cls, jlong shader) {
    auto ptr = (arqanore::Shader *) shader;
    arqanore::Shaders::font = *ptr;
}

jlong Java_be_labruyere_arqanore_Shaders__1getModel(JNIEnv *env, jclass cls) {
    return (intptr_t) &arqanore::Shaders::model;
}

void Java_be_labruyere_arqanore_Shaders__1setModel(JNIEnv *env, jclass cls, jlong shader) {
    auto ptr = (arqanore::Shader *) shader;
    arqanore::Shaders::model = *ptr;
}
