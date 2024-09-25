#include <cinttypes>
#include "arqanore/mesh.h"
#include "be_labruyere_arqanore_MeshAnimation.h"

jlong Java_be_labruyere_arqanore_MeshAnimation__1create(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::MeshAnimation();
}

void Java_be_labruyere_arqanore_MeshAnimation__1destroy(JNIEnv *env, jobject, jlong animation) {
    delete (arqanore::MeshAnimation *) animation;
}

jlongArray Java_be_labruyere_arqanore_MeshAnimation__1getFrames(JNIEnv *env, jobject cls, jlong animation) {
    auto ptr = (arqanore::MeshAnimation*)animation;
    jint length = (int)ptr->frames.size();
    jlong buffer[ptr->frames.size()];

    for (int i=0; i<ptr->frames.size(); i++) {
        buffer[i] = (intptr_t) &ptr->frames[i];
    }

    auto array = env->NewLongArray(length);
    env->SetLongArrayRegion(array, 0, length, buffer);

    return array;
}
