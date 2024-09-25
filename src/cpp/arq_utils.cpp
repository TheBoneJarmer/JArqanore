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
