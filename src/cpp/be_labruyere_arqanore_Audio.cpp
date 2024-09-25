#include "be_labruyere_arqanore_Audio.h"
#include "arqanore/audio.h"

void Java_be_labruyere_arqanore_Audio__1stop(JNIEnv *env, jclass cls) {
    arqanore::Audio::stop();
}
