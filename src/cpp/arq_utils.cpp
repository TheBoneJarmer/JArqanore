#include "arq_utils.h"
#include "jni_utils.h"

arqanore::Color convert_color(JNIEnv *env, jobject obj) {
    auto cls = env->GetObjectClass(obj);
    auto fidR = env->GetFieldID(cls, "r", "I");
    auto fidG = env->GetFieldID(cls, "g", "I");
    auto fidB = env->GetFieldID(cls, "b", "I");
    auto fidA = env->GetFieldID(cls, "a", "I");

    auto color = arqanore::Color();
    color.r = env->GetIntField(obj, fidR);
    color.g = env->GetIntField(obj, fidG);
    color.b = env->GetIntField(obj, fidB);
    color.a = env->GetIntField(obj, fidA);

    return color;
}

jobject convert_color(JNIEnv *env, arqanore::Color color) {
    auto cls = env->FindClass("be/labruyere/arqanore/Color");
    auto mid = env->GetMethodID(cls, "<init>", "()V");
    auto fidR = env->GetFieldID(cls, "r", "I");
    auto fidG = env->GetFieldID(cls, "g", "I");
    auto fidB = env->GetFieldID(cls, "b", "I");
    auto fidA = env->GetFieldID(cls, "a", "I");

    auto obj = env->NewObject(cls, mid);
    env->SetIntField(obj, fidR, (int) color.r);
    env->SetIntField(obj, fidG, (int) color.g);
    env->SetIntField(obj, fidB, (int) color.b);
    env->SetIntField(obj, fidA, (int) color.a);

    return obj;
}

arqanore::Vector2 convert_vector2(JNIEnv *env, jobject obj) {
    auto cls = env->GetObjectClass(obj);
    auto fidX = env->GetFieldID(cls, "x", "F");
    auto fidY = env->GetFieldID(cls, "y", "F");

    auto vec = arqanore::Vector2();
    vec.x = env->GetFloatField(obj, fidX);
    vec.y = env->GetFloatField(obj, fidY);

    return vec;
}

jobject convert_vector2(JNIEnv *env, arqanore::Vector2 vec) {
    auto cls = env->FindClass("be/labruyere/arqanore/Vector2");
    auto mid = env->GetMethodID(cls, "<init>", "()V");
    auto fidX = env->GetFieldID(cls, "x", "F");
    auto fidY = env->GetFieldID(cls, "y", "F");

    auto obj = env->NewObject(cls, mid);
    env->SetFloatField(obj, fidX, vec.x);
    env->SetFloatField(obj, fidY, vec.y);

    return obj;
}

arqanore::Vector3 convert_vector3(JNIEnv *env, jobject obj) {
    auto cls = env->GetObjectClass(obj);
    auto fidX = env->GetFieldID(cls, "x", "F");
    auto fidY = env->GetFieldID(cls, "y", "F");
    auto fidZ = env->GetFieldID(cls, "z", "F");

    auto vec = arqanore::Vector3();
    vec.x = env->GetFloatField(obj, fidX);
    vec.y = env->GetFloatField(obj, fidY);
    vec.z = env->GetFloatField(obj, fidZ);

    return vec;
}

jobject convert_vector3(JNIEnv *env, arqanore::Vector3 vec) {
    auto cls = env->FindClass("be/labruyere/arqanore/Vector3");
    auto mid = env->GetMethodID(cls, "<init>", "()V");
    auto fidX = env->GetFieldID(cls, "x", "F");
    auto fidY = env->GetFieldID(cls, "y", "F");
    auto fidZ = env->GetFieldID(cls, "z", "F");

    auto obj = env->NewObject(cls, mid);
    env->SetFloatField(obj, fidX, vec.x);
    env->SetFloatField(obj, fidY, vec.y);
    env->SetFloatField(obj, fidZ, vec.z);

    return obj;
}

arqanore::Quaternion convert_quaternion(JNIEnv *env, jobject obj) {
    auto cls = env->GetObjectClass(obj);
    auto fidX = env->GetFieldID(cls, "x", "F");
    auto fidY = env->GetFieldID(cls, "y", "F");
    auto fidZ = env->GetFieldID(cls, "z", "F");
    auto fidW = env->GetFieldID(cls, "w", "F");

    auto quat = arqanore::Quaternion();
    quat.x = env->GetFloatField(obj, fidX);
    quat.y = env->GetFloatField(obj, fidY);
    quat.z = env->GetFloatField(obj, fidZ);
    quat.w = env->GetFloatField(obj, fidW);

    return quat;
}

jobject convert_quaternion(JNIEnv *env, arqanore::Quaternion vec) {
    auto cls = env->FindClass("be/labruyere/arqanore/Quaternion");
    auto mid = env->GetMethodID(cls, "<init>", "()V");
    auto fidX = env->GetFieldID(cls, "x", "F");
    auto fidY = env->GetFieldID(cls, "y", "F");
    auto fidZ = env->GetFieldID(cls, "z", "F");
    auto fidW = env->GetFieldID(cls, "w", "F");

    auto obj = env->NewObject(cls, mid);
    env->SetFloatField(obj, fidX, vec.x);
    env->SetFloatField(obj, fidY, vec.y);
    env->SetFloatField(obj, fidZ, vec.z);
    env->SetFloatField(obj, fidW, vec.w);

    return obj;
}

arqanore::Matrix3 convert_matrix3(JNIEnv *env, jobject obj) {
    auto cls = env->GetObjectClass(obj);
    auto fid = env->GetFieldID(cls, "values", "[F");

    auto java_arr = (jfloatArray) env->GetObjectField(obj, fid);
    auto arr = convert_java_float_array(env, java_arr);

    auto mat = arqanore::Matrix3();
    mat.values = arqanore::Matrix3::array(arr->elements);

    return mat;
}

jobject convert_matrix3(JNIEnv *env, arqanore::Matrix3 mat) {
    auto cls = env->FindClass("be/labruyere/arqanore/Matrix3");
    auto mid = env->GetMethodID(cls, "<init>", "()V");
    auto fid = env->GetFieldID(cls, "values", "[F");

    auto arr = arqanore::Matrix3::array(mat.values);
    auto java_arr = convert_java_float_array(env, arr, 9);

    auto obj = env->NewObject(cls, mid);
    env->SetObjectField(obj, fid, java_arr);

    return obj;
}

arqanore::Matrix4 convert_matrix4(JNIEnv *env, jobject obj) {
    auto cls = env->GetObjectClass(obj);
    auto fid = env->GetFieldID(cls, "values", "[F");

    auto java_arr = (jfloatArray) env->GetObjectField(obj, fid);
    auto arr = convert_java_float_array(env, java_arr);

    auto mat = arqanore::Matrix4();
    mat.values = arqanore::Matrix4::array(arr->elements);

    return mat;
}

jobject convert_matrix4(JNIEnv *env, arqanore::Matrix4 mat) {
    auto cls = env->FindClass("be/labruyere/arqanore/Matrix4");
    auto mid = env->GetMethodID(cls, "<init>", "()V");
    auto fid = env->GetFieldID(cls, "values", "[F");

    auto arr = arqanore::Matrix4::array(mat.values);
    auto java_arr = convert_java_float_array(env, arr, 16);

    auto obj = env->NewObject(cls, mid);
    env->SetObjectField(obj, fid, java_arr);

    return obj;
}
