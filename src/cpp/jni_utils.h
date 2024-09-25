#ifndef JNI_UTILS_HPP
#define JNI_UTILS_HPP

#include <jni.h>
#include <string>
#include <vector>

template<class T>
struct JavaArray {
    T *elements = nullptr;
    int length = 0;
};

struct JavaCallback {
    jmethodID mid = nullptr;
    jclass cls = nullptr;
    JNIEnv *env = nullptr;

    bool is_empty() const {
        return this->cls == nullptr || this->mid == nullptr;
    }
};

const char *convert_java_string(JNIEnv *env, jstring src);

std::u16string convert_java_u16string(JNIEnv *env, jstring src);

jstring convert_java_string(JNIEnv *env, std::string src);

jfloatArray convert_java_float_array(JNIEnv *env, float *arr, jsize length);

jfloatArray convert_java_float_array(JNIEnv *env, std::vector<float> &v);

JavaArray<float> *convert_java_float_array(JNIEnv *env, jfloatArray arr);

JavaArray<jobject> *convert_java_object_array(JNIEnv *env, jobjectArray arr);

JavaCallback *get_java_callback(JNIEnv *env, jstring class_name, jstring method_name, const char *signature);

void throw_java_exception(JNIEnv *env, const char *message, const char *class_name = "be/labruyere/arqanore/exceptions/ArqanoreException");

void throw_java_exception(JNIEnv *env, const std::string &message, const char *class_name = "be/labruyere/arqanore/exceptions/ArqanoreException");

#endif
