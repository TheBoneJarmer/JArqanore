#include <cinttypes>
#include "arqanore/mesh.h"
#include "be_labruyere_arqanore_Mesh.h"
#include "jni_utils.h"

jlong Java_be_labruyere_arqanore_Mesh__1create(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::Mesh();
}

void Java_be_labruyere_arqanore_Mesh__1destroy(JNIEnv *env, jobject cls, jlong mesh) {
    delete (arqanore::Mesh *) mesh;
}

jfloatArray Java_be_labruyere_arqanore_Mesh__1getVertices(JNIEnv *env, jobject cls, jlong mesh) {
    auto ptr = (arqanore::Mesh *) mesh;
    auto jarr = convert_java_float_array(env, ptr->vertices);

    return jarr;
}

jfloatArray Java_be_labruyere_arqanore_Mesh__1getNormals(JNIEnv *env, jobject cls, jlong mesh) {
    auto ptr = (arqanore::Mesh *) mesh;
    auto jarr = convert_java_float_array(env, ptr->normals);

    return jarr;
}

jfloatArray Java_be_labruyere_arqanore_Mesh__1getTexCoords(JNIEnv *env, jobject cls, jlong mesh) {
    auto ptr = (arqanore::Mesh *) mesh;
    auto jarr = convert_java_float_array(env, ptr->texcoords);

    return jarr;
}

jstring Java_be_labruyere_arqanore_Mesh__1getName(JNIEnv *env, jobject cls, jlong mesh) {
    auto ptr = (arqanore::Mesh *) mesh;
    return convert_java_string(env, ptr->name);
}

jlong Java_be_labruyere_arqanore_Mesh__1getAnimation(JNIEnv *env, jobject cls, jlong mesh) {
    auto ptr = (arqanore::Mesh *) mesh;
    return (intptr_t) &ptr->animation;
}

jlong Java_be_labruyere_arqanore_Mesh__1getMaterial(JNIEnv *env, jobject cls, jlong mesh) {
    auto ptr = (arqanore::Mesh *) mesh;
    return (intptr_t) &ptr->material;
}