#include "be_labruyere_arqanore_Vector2.h"
#include "arqanore/vector2.h"
#include "arq_utils.h"

jfloat Java_be_labruyere_arqanore_Vector2__1distance(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    auto v1 = convert_vector2(env, obj_v1);
    auto v2 = convert_vector2(env, obj_v2);

    return arqanore::Vector2::distance(v1, v2);
}

jfloat Java_be_labruyere_arqanore_Vector2__1angle(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    auto v1 = convert_vector2(env, obj_v1);
    auto v2 = convert_vector2(env, obj_v2);

    return arqanore::Vector2::angle(v1, v2);
}

jfloat Java_be_labruyere_arqanore_Vector2__1cross(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    auto v1 = convert_vector2(env, obj_v1);
    auto v2 = convert_vector2(env, obj_v2);

    return arqanore::Vector2::cross(v1, v2);
}

jfloat Java_be_labruyere_arqanore_Vector2__1dot(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    auto v1 = convert_vector2(env, obj_v1);
    auto v2 = convert_vector2(env, obj_v2);

    return arqanore::Vector2::dot(v1, v2);
}

jobject Java_be_labruyere_arqanore_Vector2__1normalized(JNIEnv *env, jclass cls, jobject obj) {
    auto v1 = convert_vector2(env, obj);
    auto v2 = arqanore::Vector2::normalized(v1);

    return convert_vector2(env, v2);
}

jobject Java_be_labruyere_arqanore_Vector2__1getConstZero(JNIEnv *env, jclass cls) {
    return convert_vector2(env, arqanore::Vector2::ZERO);
}

jobject Java_be_labruyere_arqanore_Vector2__1getConstOne(JNIEnv *env, jclass cls) {
    return convert_vector2(env, arqanore::Vector2::ONE);
}
