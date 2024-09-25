#include <cinttypes>
#include "be_labruyere_arqanore_Sprite.h"
#include "arqanore/sprite.h"
#include "arqanore/exceptions.h"
#include "jni_utils.h"

jlong Java_be_labruyere_arqanore_Sprite__1create(JNIEnv *env, jobject cls, jstring path, jint frame_width, jint frame_height) {
    try {
        return (intptr_t) new arqanore::Sprite(convert_java_string(env, path), frame_width, frame_height);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }

    return 0;
}

void Java_be_labruyere_arqanore_Sprite__1destroy(JNIEnv *env, jobject cls, jlong sprite) {
    delete (arqanore::Sprite *) sprite;
}

jint Java_be_labruyere_arqanore_Sprite__1getWidth(JNIEnv *env, jobject cls, jlong sprite) {
    auto ptr = (arqanore::Sprite *) sprite;
    return ptr->get_width();
}

jint Java_be_labruyere_arqanore_Sprite__1getHeight(JNIEnv *env, jobject cls, jlong sprite) {
    auto ptr = (arqanore::Sprite *) sprite;
    return ptr->get_height();
}

jint Java_be_labruyere_arqanore_Sprite__1getFrameWidth(JNIEnv *env, jobject cls, jlong sprite) {
    auto ptr = (arqanore::Sprite *) sprite;
    return ptr->get_frame_width();
}

jint Java_be_labruyere_arqanore_Sprite__1getFrameHeight(JNIEnv *env, jobject cls, jlong sprite) {
    auto ptr = (arqanore::Sprite *) sprite;
    return ptr->get_frame_height();
}

jint Java_be_labruyere_arqanore_Sprite__1getFramesHor(JNIEnv *env, jobject cls, jlong sprite) {
    auto ptr = (arqanore::Sprite *) sprite;
    return ptr->get_frames_hor();
}

jint Java_be_labruyere_arqanore_Sprite__1getFramesVert(JNIEnv *env, jobject cls, jlong sprite) {
    auto ptr = (arqanore::Sprite *) sprite;
    return ptr->get_frames_vert();
}
