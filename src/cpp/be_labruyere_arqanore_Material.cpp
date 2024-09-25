#include <cinttypes>
#include "be_labruyere_arqanore_Material.h"
#include "arqanore/material.h"
#include "jni_utils.h"
#include "arq_utils.h"

jlong Java_be_labruyere_arqanore_Material__1create(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::Material();
}

void Java_be_labruyere_arqanore_Material__1destroy(JNIEnv *env, jobject cls, jlong material) {
    delete (arqanore::Material *) material;
}

jstring Java_be_labruyere_arqanore_Material__1getName(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;
    return convert_java_string(env, ptr->name);
}

jobject Java_be_labruyere_arqanore_Material__1getColor(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, ptr->color);

    return clr;
}

jobject Java_be_labruyere_arqanore_Material__1getDiffuse(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, ptr->diffuse);

    return clr;
}

jobject Java_be_labruyere_arqanore_Material__1getAmbient(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, ptr->ambient);

    return clr;
}

jobject Java_be_labruyere_arqanore_Material__1getSpecular(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, ptr->specular);

    return clr;
}

jfloat Java_be_labruyere_arqanore_Material__1getShininess(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;
    return ptr->shininess;
}

jlong Java_be_labruyere_arqanore_Material__1getDiffuseMap(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;

    if (ptr->diffuse_map == nullptr) {
        return 0;
    }

    return (intptr_t) &ptr->diffuse_map;
}

jlong Java_be_labruyere_arqanore_Material__1getAmbientMap(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;

    if (ptr->ambient_map == nullptr) {
        return 0;
    }

    return (intptr_t) &ptr->ambient_map;
}

jlong Java_be_labruyere_arqanore_Material__1getSpecularMap(JNIEnv *env, jobject cls, jlong material) {
    auto ptr = (arqanore::Material *) material;

    if (ptr->specular_map == nullptr) {
        return 0;
    }

    return (intptr_t) &ptr->specular_map;
}

void Java_be_labruyere_arqanore_Material__1setName(JNIEnv *env, jobject cls, jlong material, jstring value) {
    auto ptr = (arqanore::Material *) material;
    ptr->name = convert_java_string(env, value);
}

void Java_be_labruyere_arqanore_Material__1setColor(JNIEnv *env, jobject cls, jlong material, jobject value) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, value);

    ptr->color = clr;
}

void Java_be_labruyere_arqanore_Material__1setDiffuse(JNIEnv *env, jobject cls, jlong material, jobject value) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, value);

    ptr->diffuse = clr;
}

void Java_be_labruyere_arqanore_Material__1setAmbient(JNIEnv *env, jobject cls, jlong material, jobject value) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, value);

    ptr->ambient = clr;
}

void Java_be_labruyere_arqanore_Material__1setSpecular(JNIEnv *env, jobject cls, jlong material, jobject value) {
    auto ptr = (arqanore::Material *) material;
    auto clr = convert_color(env, value);

    ptr->specular = clr;
}

void Java_be_labruyere_arqanore_Material__1setShininess(JNIEnv *env, jobject cls, jlong material, jfloat value) {
    auto ptr = (arqanore::Material *) material;
    ptr->shininess = value;
}

void Java_be_labruyere_arqanore_Material__1setDiffuseMap(JNIEnv *env, jobject cls, jlong material, jlong value) {
    auto ptr = (arqanore::Material *) material;

    if (value == 0) {
        ptr->diffuse_map = nullptr;
    } else {
        auto ptr2 = (arqanore::Texture *) value;
        ptr->diffuse_map = new arqanore::Texture(*ptr2);
    }
}

void Java_be_labruyere_arqanore_Material__1setAmbientMap(JNIEnv *env, jobject cls, jlong material, jlong value) {
    auto ptr = (arqanore::Material *) material;

    if (value == 0) {
        ptr->ambient_map = nullptr;
    } else {
        auto ptr2 = (arqanore::Texture *) value;
        ptr->ambient_map = new arqanore::Texture(*ptr2);
    }
}

void Java_be_labruyere_arqanore_Material__1setSpecularMap(JNIEnv *env, jobject cls, jlong material, jlong value) {
    auto ptr = (arqanore::Material *) material;

    if (value == 0) {
        ptr->specular_map = nullptr;
    } else {
        auto ptr2 = (arqanore::Texture *) value;
        ptr->specular_map = new arqanore::Texture(*ptr2);
    }
}
