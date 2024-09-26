#include <cstdint>
#include <arqanore/font.h>
#include <arqanore/exceptions.h>
#include "be_labruyere_arqanore_Font.h"
#include "jni_utils.h"

jlong Java_be_labruyere_arqanore_Font__1create(JNIEnv* env, jobject sender, jstring path, jint width, jint height)
{
    try
    {
        return reinterpret_cast<intptr_t>(new arqanore::Font(convert_java_string(env, path), width, height));
    }
    catch (arqanore::ArqanoreException& ex)
    {
        throw_java_exception(env, ex.what());
    }

    return 0;
}

void Java_be_labruyere_arqanore_Font__1destroy(JNIEnv* env, jobject sender, jlong font)
{
    delete reinterpret_cast<arqanore::Font*>(font);
}

jfloat Java_be_labruyere_arqanore_Font__1measure(JNIEnv* env, jobject sender, jlong font, jstring text, jfloat scale)
{
    auto* ptr = reinterpret_cast<arqanore::Font*>(font);
    return ptr->measure(convert_java_u16string(env, text), scale);
}
