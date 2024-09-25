#include <cinttypes>
#include "be_labruyere_arqanore_Matrix4.h"
#include "arqanore/matrix4.h"
#include "jni_utils.h"
#include "arq_utils.h"

jobject Java_be_labruyere_arqanore_Matrix4__1identity(JNIEnv *env, jclass cls) {
    auto mat = arqanore::Matrix4::identity();
    return convert_matrix4(env, mat);
}

jobject Java_be_labruyere_arqanore_Matrix4__1scale(JNIEnv *env, jclass cls, jobject obj_mat, jobject obj_vec) {
    auto mat = convert_matrix4(env, obj_mat);
    auto vec = convert_vector3(env, obj_vec);

    mat = arqanore::Matrix4::scale(mat, vec);
    return convert_matrix4(env, mat);
}

jobject Java_be_labruyere_arqanore_Matrix4__1translate(JNIEnv *env, jclass cls, jobject obj_mat, jobject obj_vec) {
    auto mat = convert_matrix4(env, obj_mat);
    auto vec = convert_vector3(env, obj_vec);

    mat = arqanore::Matrix4::translate(mat, vec);
    return convert_matrix4(env, mat);
}

jobject Java_be_labruyere_arqanore_Matrix4__1rotate(JNIEnv *env, jclass cls, jobject obj_mat, jobject obj_quat) {
    auto mat = convert_matrix4(env, obj_mat);
    auto quat = convert_quaternion(env, obj_quat);

    mat = arqanore::Matrix4::rotate(mat, quat);
    return convert_matrix4(env, mat);
}

jobject Java_be_labruyere_arqanore_Matrix4__1perspective(JNIEnv *env, jclass cls, jobject obj_mat, jfloat fovy, jfloat ratio, jfloat near, jfloat far) {
    auto mat = convert_matrix4(env, obj_mat);

    mat = arqanore::Matrix4::perspective(mat, fovy, ratio, near, far);
    return convert_matrix4(env, mat);
}
