#include <arqanore/mathhelper.h>
#include "be_labruyere_arqanore_MathHelper.h"

jfloat Java_be_labruyere_arqanore_MathHelper__1radians(JNIEnv *env, jclass cls, jfloat degrees) {
    return arqanore::MathHelper::radians(degrees);
}

jfloat Java_be_labruyere_arqanore_MathHelper__1degrees(JNIEnv *env, jclass cls, jfloat radians) {
    return arqanore::MathHelper::degrees(radians);
}

jfloat Java_be_labruyere_arqanore_MathHelper__1lerp(JNIEnv *env, jclass cls, jfloat d1, jfloat d2, jfloat by) {
    return arqanore::MathHelper::lerp(d1, d2, by);
}

jfloat Java_be_labruyere_arqanore_MathHelper__1clamp(JNIEnv *env, jclass cls, jfloat value, jfloat min, jfloat max) {
    return arqanore::MathHelper::clamp(value, min, max);
}
