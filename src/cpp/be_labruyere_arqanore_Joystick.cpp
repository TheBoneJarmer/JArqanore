#include <string>
#include <arqanore/joystick.h>
#include "be_labruyere_arqanore_Joystick.h"
#include "arqanore/exceptions.h"
#include "jni_utils.h"

jboolean Java_be_labruyere_arqanore_Joystick__1isConnected(JNIEnv *env, jclass cls, jint jid) {
    try {
        return arqanore::Joystick::is_connected(jid);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return false;
}

jstring Java_be_labruyere_arqanore_Joystick__1getName(JNIEnv *env, jclass cls, jint jid) {
    try {
        auto value_str = arqanore::Joystick::get_name(jid);
        auto value_cstr = value_str.c_str();

        return env->NewStringUTF(value_cstr);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return nullptr;
}

jstring Java_be_labruyere_arqanore_Joystick__1getGuid(JNIEnv *env, jclass cls, jint jid) {
    try {
        auto value_str = arqanore::Joystick::get_guid(jid);
        auto value_cstr = value_str.c_str();

        return env->NewStringUTF(value_cstr);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return nullptr;
}

jfloatArray Java_be_labruyere_arqanore_Joystick__1getAxes(JNIEnv *env, jclass cls, jint jid) {
    try {
        auto axes = arqanore::Joystick::get_axes(jid);
        auto axes_arr = new float[axes.size()];

        for (int i = 0; i < axes.size(); i++) {
            axes_arr[i] = axes[i];
        }

        auto result = env->NewFloatArray(axes.size());
        env->SetFloatArrayRegion(result, 0, axes.size(), (const jfloat *) axes_arr);

        delete[] axes_arr;
        return result;
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return nullptr;
}

jintArray Java_be_labruyere_arqanore_Joystick__1getButtons(JNIEnv *env, jclass cls, jint jid) {
    try {
        auto axes = arqanore::Joystick::get_buttons(jid);
        auto axes_arr = new int[axes.size()];

        for (int i = 0; i < axes.size(); i++) {
            axes_arr[i] = axes[i];
        }

        auto result = env->NewIntArray(axes.size());
        env->SetIntArrayRegion(result, 0, axes.size(), (const jint *) axes_arr);

        delete[] axes_arr;
        return result;
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return nullptr;
}
