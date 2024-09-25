#pragma once

#include <jni.h>
#include <arqanore/color.h>
#include <arqanore/vector2.h>

arqanore::Color convert_color(JNIEnv* env, jobject obj);

jobject convert_color(JNIEnv* env, arqanore::Color color);

arqanore::Vector2 convert_vector2(JNIEnv* env, jobject obj);

jobject convert_vector2(JNIEnv* env, arqanore::Vector2 vec);
