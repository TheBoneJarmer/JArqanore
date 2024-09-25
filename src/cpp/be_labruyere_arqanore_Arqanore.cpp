#include <string>
#include <array>
#include "be_labruyere_arqanore_Arqanore.h"
#include "arqanore/arqanore.h"
#include "jni_utils.h"

jintArray Java_be_labruyere_arqanore_Arqanore__1getVersion(JNIEnv *env, jclass cls) {
    std::array<int, 3> arr = arqanore::Arqanore::get_version();
    const jint arr_raw[]{arr[0], arr[1], arr[2]};

    jintArray arr_java = env->NewIntArray(3);
    env->SetIntArrayRegion(arr_java, 0, 3, arr_raw);
    
    return arr_java;
}

jstring Java_be_labruyere_arqanore_Arqanore__1getOpenGLVersion(JNIEnv *env, jclass cls) {
    std::string value = arqanore::Arqanore::get_opengl_version();
    return convert_java_string(env, value);
}
