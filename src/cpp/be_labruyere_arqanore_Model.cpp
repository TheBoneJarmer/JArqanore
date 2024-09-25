#include "arqanore/model.h"
#include "be_labruyere_arqanore_Model.h"
#include "jni_utils.h"
#include "arqanore/exceptions.h"

jlong Java_be_labruyere_arqanore_Model__1create(JNIEnv *env, jobject cls, jstring path) {
    try {
        std::string path_str = convert_java_string(env, path);
        arqanore::Model *ptr = new arqanore::Model(path_str);

        return (intptr_t) ptr;
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return 0;
}

void Java_be_labruyere_arqanore_Model__1destroy(JNIEnv *env, jobject cls, jlong model) {
    delete (arqanore::Model *) model;
}

jlongArray Java_be_labruyere_arqanore_Model__1getMeshes(JNIEnv *env, jobject cls, jlong model) {
    arqanore::Model *ptr = (arqanore::Model *) model;
    jint length = (jint) ptr->meshes.size();
    jlong buffer[ptr->meshes.size()];

    for (int i = 0; i < ptr->meshes.size(); i++) {
        buffer[i] = (intptr_t) &ptr->meshes[i];
    }

    jlongArray array = env->NewLongArray(length);
    env->SetLongArrayRegion(array, 0, length, buffer);

    return array;
}

jint Java_be_labruyere_arqanore_Model__1totalVertices(JNIEnv *env, jobject cls, jlong model) {
    arqanore::Model *ptr = (arqanore::Model *) model;
    return ptr->total_vertices();
}

jint Java_be_labruyere_arqanore_Model__1totalTexcoords(JNIEnv *env, jobject cls, jlong model) {
    arqanore::Model *ptr = (arqanore::Model *) model;
    return ptr->total_texcoords();
}

jint Java_be_labruyere_arqanore_Model__1totalNormals(JNIEnv *env, jobject cls, jlong model) {
    arqanore::Model *ptr = (arqanore::Model *) model;
    return ptr->total_normals();
}

jint Java_be_labruyere_arqanore_Model__1totalFrames(JNIEnv *env, jobject cls, jlong model) {
    arqanore::Model *ptr = (arqanore::Model *) model;
    return ptr->total_frames();
}

void Java_be_labruyere_arqanore_Model__1calculateNormals(JNIEnv *env, jobject cls, jlong model, jboolean flip) {
    arqanore::Model *ptr = (arqanore::Model *) model;
    ptr->calculate_normals(flip);
}
