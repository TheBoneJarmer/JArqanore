#include <iostream>
#include "be_labruyere_arqanore_Matrix3.h"
#include "arqanore/matrix3.h"
#include "jni_utils.h"
#include "arq_utils.h"

jobject Java_be_labruyere_arqanore_Matrix3__1inverse(JNIEnv *env, jclass cls, jobject obj) {
    auto mat_src = convert_matrix3(env, obj);
    auto mat_dest = arqanore::Matrix3::inverse(mat_src);

    return convert_matrix3(env, mat_dest);
}

jobject Java_be_labruyere_arqanore_Matrix3__1transpose(JNIEnv *env, jclass cls, jobject obj) {
    auto mat_src = convert_matrix3(env, obj);
    auto mat_dest = arqanore::Matrix3::transpose(mat_src);

    return convert_matrix3(env, mat_dest);
}
