#include <arqanore/polygon.h>
#include "be_labruyere_arqanore_Polygon.h"
#include "jni_utils.h"
#include "arqanore/exceptions.h"

using namespace arqanore;

jlong Java_be_labruyere_arqanore_Polygon__1create(JNIEnv *env, jclass cls, jfloatArray arr_vertices, jfloatArray arr_texcoords) {
    if (arr_vertices == nullptr) {
        throw_java_exception(env, "Vertices array cannot be null");
        return 0;
    }

    if (arr_texcoords == nullptr) {
        throw_java_exception(env, "Texcoords array cannot be null");
        return 0;
    }

    auto jarr_vertices = convert_java_float_array(env, arr_vertices);
    auto jarr_texcoords = convert_java_float_array(env, arr_texcoords);
    auto vector_vertices = std::vector<float>();
    auto vector_texcoords = std::vector<float>();

    for (int i = 0; i < jarr_vertices->length; i++) {
        auto el = jarr_vertices->elements[i];
        vector_vertices.push_back(el);
    }

    for (int i = 0; i < jarr_texcoords->length; i++) {
        auto el = jarr_texcoords->elements[i];
        vector_texcoords.push_back(el);
    }

    try {
        return (intptr_t) new Polygon(vector_vertices, vector_texcoords);
    } catch (arqanore::ArqanoreException& ex) {
        throw_java_exception(env, ex.what());
    }

    return 0;
}

void Java_be_labruyere_arqanore_Polygon__1destroy(JNIEnv *env, jclass cls, jlong polygon) {
    delete (Polygon *) polygon;
}