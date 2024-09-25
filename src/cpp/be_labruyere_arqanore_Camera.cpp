#include <cinttypes>
#include "be_labruyere_arqanore_Camera.h"
#include "arqanore/camera.h"
#include "arq_utils.h"

jlong Java_be_labruyere_arqanore_Camera__1create(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::Camera();
}

void Java_be_labruyere_arqanore_Camera__1destroy(JNIEnv *env, jobject cls, jlong camera) {
    delete (arqanore::Camera *) camera;
}

jobject Java_be_labruyere_arqanore_Camera__1getPosition(JNIEnv *env, jobject cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    return convert_vector3(env, ptr->position);
}

jobject Java_be_labruyere_arqanore_Camera__1getRotation(JNIEnv *env, jobject cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    return convert_quaternion(env, ptr->rotation);
}

jfloat Java_be_labruyere_arqanore_Camera__1getFov(JNIEnv *env, jobject cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    return ptr->fov;
}

jfloat Java_be_labruyere_arqanore_Camera__1getNear(JNIEnv *env, jobject cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    return ptr->near;
}

jfloat Java_be_labruyere_arqanore_Camera__1getFar(JNIEnv *env, jobject cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    return ptr->far;
}

void Java_be_labruyere_arqanore_Camera__1setPosition(JNIEnv *env, jobject cls, jlong camera, jobject value) {
    auto ptr = (arqanore::Camera *) camera;
    ptr->position = convert_vector3(env, value);
}

void Java_be_labruyere_arqanore_Camera__1setRotation(JNIEnv *env, jobject cls, jlong camera, jobject value) {
    auto ptr = (arqanore::Camera *) camera;
    ptr->rotation = convert_quaternion(env, value);
}

void Java_be_labruyere_arqanore_Camera__1setFov(JNIEnv *env, jobject cls, jlong camera, jfloat value) {
    auto ptr = (arqanore::Camera *) camera;
    ptr->fov = value;
}

void Java_be_labruyere_arqanore_Camera__1setNear(JNIEnv *env, jobject cls, jlong camera, jfloat value) {
    auto ptr = (arqanore::Camera *) camera;
    ptr->near = value;
}

void Java_be_labruyere_arqanore_Camera__1setFar(JNIEnv *env, jobject cls, jlong camera, jfloat value) {
    auto ptr = (arqanore::Camera *) camera;
    ptr->far = value;
}
