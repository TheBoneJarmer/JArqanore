#include <arqanore/scene.h>
#include <cinttypes>
#include "be_labruyere_arqanore_Scene.h"

jlongArray Java_be_labruyere_arqanore_Scene__1getLights(JNIEnv *env, jclass cls) {
    auto &lights = arqanore::Scene::lights;
    jint length = (int) lights.size();
    jlong buffer[lights.size()];

    for (int i = 0; i < lights.size(); i++) {
        buffer[i] = (intptr_t) &lights[i];
    }

    auto array = env->NewLongArray(length);
    env->SetLongArrayRegion(array, 0, length, buffer);

    return array;
}

jlongArray Java_be_labruyere_arqanore_Scene__1getCameras(JNIEnv *env, jclass cls) {
    auto &cameras = arqanore::Scene::cameras;
    jint length = (int) cameras.size();
    jlong buffer[cameras.size()];

    for (int i = 0; i < cameras.size(); i++) {
        buffer[i] = (intptr_t) &cameras[i];
    }

    auto array = env->NewLongArray(length);
    env->SetLongArrayRegion(array, 0, length, buffer);

    return array;
}

jint Java_be_labruyere_arqanore_Scene__1getActiveCamera(JNIEnv *env, jclass cls) {
    return (int) arqanore::Scene::active_camera;
}

void Java_be_labruyere_arqanore_Scene__1reset(JNIEnv *env, jclass cls) {
    arqanore::Scene::reset();
}

void Java_be_labruyere_arqanore_Scene__1addCamera(JNIEnv *env, jclass cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    arqanore::Scene::cameras.push_back(*ptr);
}

void Java_be_labruyere_arqanore_Scene__1addLight(JNIEnv *env, jclass cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    arqanore::Scene::lights.push_back(*ptr);
}
