#include "be_labruyere_arqanore_Sound.h"
#include "arqanore/sound.h"
#include "jni_utils.h"

jlong Java_be_labruyere_arqanore_Sound__1create(JNIEnv *env, jobject sender, jstring path) {
    return (intptr_t) new arqanore::Sound(convert_java_string(env, path));
}

void Java_be_labruyere_arqanore_Sound__1destroy(JNIEnv *env, jobject sender, jlong sound) {
    delete (arqanore::Sound *) sound;
}

jboolean Java_be_labruyere_arqanore_Sound__1isPaused(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    return ptr->paused();
}

jboolean Java_be_labruyere_arqanore_Sound__1isLooping(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    return ptr->looping();
}

jboolean Java_be_labruyere_arqanore_Sound__1isPlaying(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    return ptr->playing();
}

jdouble Java_be_labruyere_arqanore_Sound__1getVolume(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    return ptr->volume();
}

jdouble Java_be_labruyere_arqanore_Sound__1getPan(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    return ptr->pan();
}

void Java_be_labruyere_arqanore_Sound__1setLooping(JNIEnv *env, jobject sender, jlong sound, jboolean value) {
    auto *ptr = (arqanore::Sound *) sound;
    ptr->looping(value);
}

void Java_be_labruyere_arqanore_Sound__1setPaused(JNIEnv *env, jobject sender, jlong sound, jboolean value) {
    auto *ptr = (arqanore::Sound *) sound;
    ptr->paused(value);
}

void Java_be_labruyere_arqanore_Sound__1setVolume(JNIEnv *env, jobject sender, jlong sound, jdouble value) {
    auto *ptr = (arqanore::Sound *) sound;
    ptr->volume(value);
}

void Java_be_labruyere_arqanore_Sound__1setPan(JNIEnv *env, jobject sender, jlong sound, jdouble value) {
    auto *ptr = (arqanore::Sound *) sound;
    ptr->pan(value);
}

void Java_be_labruyere_arqanore_Sound__1play(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    ptr->play();
}

void Java_be_labruyere_arqanore_Sound__1stop(JNIEnv *env, jobject sender, jlong sound) {
    auto *ptr = (arqanore::Sound *) sound;
    ptr->stop();
}
