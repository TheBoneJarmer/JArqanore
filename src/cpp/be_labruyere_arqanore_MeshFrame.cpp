#include <cinttypes>
#include "arqanore/mesh.h"
#include "be_labruyere_arqanore_MeshFrame.h"
#include "arq_utils.h"

jlong Java_be_labruyere_arqanore_MeshFrame__1create(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::MeshFrame();
}

void Java_be_labruyere_arqanore_MeshFrame__1destroy(JNIEnv *env, jobject cls, jlong frame) {
    delete (arqanore::MeshFrame *) frame;
}

jobject Java_be_labruyere_arqanore_MeshFrame__1getPosition(JNIEnv *env, jobject cls, jlong frame) {
    auto ptr = (arqanore::MeshFrame *) frame;
    return convert_vector3(env, ptr->position);
}

jobject Java_be_labruyere_arqanore_MeshFrame__1getRotation(JNIEnv *env, jobject cls, jlong frame) {
    auto ptr = (arqanore::MeshFrame *) frame;
    return convert_quaternion(env, ptr->rotation);
}

jobject Java_be_labruyere_arqanore_MeshFrame__1getScale(JNIEnv *env, jobject cls, jlong frame) {
    auto ptr = (arqanore::MeshFrame *) frame;
    return convert_vector3(env, ptr->scale);
}

void Java_be_labruyere_arqanore_MeshFrame__1setPosition(JNIEnv *env, jobject cls, jlong frame, jobject value) {
    auto ptr = (arqanore::MeshFrame *) frame;
    ptr->position = convert_vector3(env, value);
}

void Java_be_labruyere_arqanore_MeshFrame__1setRotation(JNIEnv *env, jobject cls, jlong frame, jobject value) {
    auto ptr = (arqanore::MeshFrame *) frame;
    ptr->rotation = convert_quaternion(env, value);
}

void Java_be_labruyere_arqanore_MeshFrame__1setScale(JNIEnv *env, jobject cls, jlong frame, jobject value) {
    auto ptr = (arqanore::MeshFrame *) frame;
    ptr->scale = convert_vector3(env, value);
}
