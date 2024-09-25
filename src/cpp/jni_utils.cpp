#include <iostream>
#include "jni_utils.h"

using namespace std;

const char *convert_java_string(JNIEnv *env, jstring src) {
    if (src == nullptr) {
        return nullptr;
    }

    return env->GetStringUTFChars(src, nullptr);
}

jstring convert_java_string(JNIEnv *env, std::string src) {
    auto cstr = src.c_str();
    return env->NewStringUTF(cstr);
}

std::u16string convert_java_u16string(JNIEnv *env, jstring src) {
    if (src == nullptr) {
        return nullptr;
    }

    const jchar* chars = env->GetStringChars(src, nullptr);
    jsize chars_length = env->GetStringLength(src);
    std::u16string result;

    for (int i=0; i<chars_length; i++) {
        result += chars[i];
    }

    return result;
}

jfloatArray convert_java_float_array(JNIEnv *env, std::vector<float> &v) {
    float arr_elements[v.size()];
    int arr_length = (int) v.size();

    for (int i = 0; i < arr_length; i++) {
        arr_elements[i] = v[i];
    }

    return convert_java_float_array(env, arr_elements, arr_length);
}

jfloatArray convert_java_float_array(JNIEnv *env, float *arr, jsize length) {
    auto jarr = env->NewFloatArray(length);
    env->SetFloatArrayRegion(jarr, 0, length, arr);

    return jarr;
}

JavaArray<float> *convert_java_float_array(JNIEnv *env, jfloatArray arr) {
    auto result = new JavaArray<float>();
    result->length = env->GetArrayLength(arr);
    result->elements = env->GetFloatArrayElements(arr, nullptr);

    return result;
}

JavaArray<jobject> *convert_java_object_array(JNIEnv *env, jobjectArray arr) {
    auto result = new JavaArray<jobject>();
    result->length = env->GetArrayLength(arr);
    result->elements = new jobject[result->length];

    for (int i = 0; i < result->length; i++) {
        result->elements[i] = env->GetObjectArrayElement(arr, i);
    }

    return result;
}

JavaCallback *get_java_callback(JNIEnv *env, jstring class_name, jstring method_name, const char *signature) {
    auto method_name_cstr = convert_java_string(env, method_name);
    auto class_name_cstr = convert_java_string(env, class_name);
    auto cls = env->FindClass(class_name_cstr);

    if (cls == nullptr) {
        throw_java_exception(env, "Could not find class '" + string(class_name_cstr) + "'");
        return nullptr;
    }

    auto mid = env->GetStaticMethodID(cls, method_name_cstr, signature);

    if (mid == nullptr) {
        throw_java_exception(env, "Could not find static method '" + string(method_name_cstr) + "' with signature '" + string(signature) + "'");
        return nullptr;
    }

    auto clb = new JavaCallback();
    clb->env = env;
    clb->cls = cls;
    clb->mid = mid;

    return clb;
}

void throw_java_exception(JNIEnv *env, const char *message, const char *class_name) {
    jclass cls = env->FindClass(class_name);

    if (cls == nullptr) {
        throw runtime_error("Unable to throw java exception. Exception class '" + (string) class_name + "' not found.");
    }

    env->ThrowNew(cls, message);
}

void throw_java_exception(JNIEnv *env, const std::string &message, const char *class_name) {
    throw_java_exception(env, message.c_str(), class_name);
}
