#include "be_labruyere_arqanore_Quaternion.h"
#include "arqanore/quaternion.h"
#include "arq_utils.h"

jobject Java_be_labruyere_arqanore_Quaternion__1eulerAngles(JNIEnv *env, jclass cls, jobject obj) {
    auto quat = convert_quaternion(env, obj);
    auto result = arqanore::Quaternion::euler_angles(quat);

    return convert_vector3(env, result);
}

jobject Java_be_labruyere_arqanore_Quaternion__1normalize(JNIEnv *env, jclass cls, jobject obj) {
    auto quat = convert_quaternion(env, obj);
    auto result = arqanore::Quaternion::normalize(quat);

    return convert_quaternion(env, result);
}

jobject Java_be_labruyere_arqanore_Quaternion__1rotate__Lbe_labruyere_arqanore_Quaternion_2FLbe_labruyere_arqanore_Vector3_2(JNIEnv *env, jclass cls, jobject obj_quat, jfloat angle, jobject obj_axis) {
    auto quat = convert_quaternion(env, obj_quat);
    auto axis = convert_vector3(env, obj_axis);
    auto result = arqanore::Quaternion::rotate(quat, angle, axis);

    return convert_quaternion(env, result);
}

jobject Java_be_labruyere_arqanore_Quaternion__1rotate__Lbe_labruyere_arqanore_Quaternion_2Lbe_labruyere_arqanore_Vector3_2(JNIEnv *env, jclass cls, jobject obj_quat, jobject obj_axis) {
    auto quat = convert_quaternion(env, obj_quat);
    auto axis = convert_vector3(env, obj_axis);
    auto result = arqanore::Quaternion::rotate(quat, axis);

    return convert_quaternion(env, result);
}
