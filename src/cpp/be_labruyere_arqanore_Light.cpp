#include <cinttypes>
#include "be_labruyere_arqanore_Light.h"
#include "arqanore/light.h"
#include "arq_utils.h"

jlong Java_be_labruyere_arqanore_Light__1create__(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::Light();
}

jlong Java_be_labruyere_arqanore_Light__1create__I(JNIEnv *env, jobject cls, jint type) {
    return (intptr_t) new arqanore::Light(type);
}

void Java_be_labruyere_arqanore_Light__1destroy(JNIEnv *env, jobject cls, jlong light) {
    delete (arqanore::Light *) light;
}

jint Java_be_labruyere_arqanore_Light__1getLightType(JNIEnv *env, jobject cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    return (int) ptr->type;
}

jobject Java_be_labruyere_arqanore_Light__1getSource(JNIEnv *env, jobject cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    return convert_vector3(env, ptr->source);
}

jobject Java_be_labruyere_arqanore_Light__1getColor(JNIEnv *env, jobject cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    return convert_color(env, ptr->color);
}

jboolean Java_be_labruyere_arqanore_Light__1isEnabled(JNIEnv *env, jobject cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    return ptr->enabled;
}

jfloat Java_be_labruyere_arqanore_Light__1getStrength(JNIEnv *env, jobject cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    return ptr->strength;
}

jfloat Java_be_labruyere_arqanore_Light__1getRange(JNIEnv *env, jobject cls, jlong light) {
    auto ptr = (arqanore::Light *) light;
    return ptr->range;
}

void Java_be_labruyere_arqanore_Light__1setLightType(JNIEnv *env, jobject cls, jlong light, jint value) {
    auto ptr = (arqanore::Light *) light;
    ptr->type = value;
}

void Java_be_labruyere_arqanore_Light__1setSource(JNIEnv *env, jobject cls, jlong light, jobject value) {
    auto ptr = (arqanore::Light *) light;
    ptr->source = convert_vector3(env, value);
}

void Java_be_labruyere_arqanore_Light__1setColor(JNIEnv *env, jobject cls, jlong light, jobject value) {
    auto ptr = (arqanore::Light *) light;
    ptr->color = convert_color(env, value);;
}

void Java_be_labruyere_arqanore_Light__1setEnabled(JNIEnv *env, jobject cls, jlong light, jboolean value) {
    auto ptr = (arqanore::Light *) light;
    ptr->enabled = value;
}

void Java_be_labruyere_arqanore_Light__1setStrength(JNIEnv *env, jobject cls, jlong light, jfloat value) {
    auto ptr = (arqanore::Light *) light;
    ptr->strength = value;
}

void Java_be_labruyere_arqanore_Light__1setRange(JNIEnv *env, jobject cls, jlong light, jfloat value) {
    auto ptr = (arqanore::Light *) light;
    ptr->range = value;
}
