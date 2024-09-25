#include "be_labruyere_arqanore_Vector3.h"
#include "arqanore/vector3.h"
#include "arq_utils.h"

jfloat Java_be_labruyere_arqanore_Vector3__1distance(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    arqanore::Vector3 v1 = convert_vector3(env, obj_v1);
    arqanore::Vector3 v2 = convert_vector3(env, obj_v2);

    return arqanore::Vector3::distance(v1, v2);
}

jfloat Java_be_labruyere_arqanore_Vector3__1angle(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    arqanore::Vector3 v1 = convert_vector3(env, obj_v1);
    arqanore::Vector3 v2 = convert_vector3(env, obj_v2);

    return arqanore::Vector3::angle(v1, v2);
}

jfloat Java_be_labruyere_arqanore_Vector3__1dot(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    arqanore::Vector3 v1 = convert_vector3(env, obj_v1);
    arqanore::Vector3 v2 = convert_vector3(env, obj_v2);

    return arqanore::Vector3::dot(v1, v2);
}

jobject Java_be_labruyere_arqanore_Vector3__1cross(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2) {
    arqanore::Vector3 v1 = convert_vector3(env, obj_v1);
    arqanore::Vector3 v2 = convert_vector3(env, obj_v2);
    arqanore::Vector3 result = arqanore::Vector3::cross(v1, v2);

    return convert_vector3(env, result);
}

jobject Java_be_labruyere_arqanore_Vector3__1normalized(JNIEnv *env, jclass cls, jobject obj) {
    arqanore::Vector3 v = convert_vector3(env, obj);
    arqanore::Vector3 result = arqanore::Vector3::normalized(v);

    return convert_vector3(env, result);
}

jobject Java_be_labruyere_arqanore_Vector3__1lerp(JNIEnv *env, jclass cls, jobject obj_v1, jobject obj_v2, jfloat by) {
    arqanore::Vector3 v1 = convert_vector3(env, obj_v1);
    arqanore::Vector3 v2 = convert_vector3(env, obj_v2);
    arqanore::Vector3 result = arqanore::Vector3::lerp(v1, v2, by);

    return convert_vector3(env, result);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstZero(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::ZERO);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstOne(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::ONE);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstUp(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::UP);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstDown(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::DOWN);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstLeft(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::LEFT);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstRight(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::RIGHT);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstForward(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::FORWARD);
}

jobject Java_be_labruyere_arqanore_Vector3__1getConstBackward(JNIEnv *env, jclass cls) {
    return convert_vector3(env, arqanore::Vector3::BACKWARD);
}
