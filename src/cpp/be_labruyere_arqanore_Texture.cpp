#include <cinttypes>
#include "be_labruyere_arqanore_Texture.h"
#include "arqanore/texture.h"
#include "jni_utils.h"
#include "arqanore/exceptions.h"

jlong Java_be_labruyere_arqanore_Texture__1create(JNIEnv *env, jobject cls, jstring path) {
    auto str_path = convert_java_string(env, path);

    try {
        return (intptr_t) new arqanore::Texture(str_path);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return 0;
}

void Java_be_labruyere_arqanore_Texture__1destroy(JNIEnv *env, jobject cls, jlong texture) {
    delete (arqanore::Texture *) texture;
}

jint Java_be_labruyere_arqanore_Texture__1getWidth(JNIEnv *env, jobject cls, jlong texture) {
    auto ptr = (arqanore::Texture *) texture;
    return ptr->width;
}

jint Java_be_labruyere_arqanore_Texture__1getHeight(JNIEnv *env, jobject cls, jlong texture) {
    auto ptr = (arqanore::Texture *) texture;
    return ptr->height;
}
