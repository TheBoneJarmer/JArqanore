#pragma once

#include <jni.h>
#include <arqanore/color.h>
#include <arqanore/vector2.h>
#include <arqanore/vector3.h>
#include <arqanore/matrix3.h>

arqanore::Color convert_color(JNIEnv* env, jobject obj);

jobject convert_color(JNIEnv* env, arqanore::Color color);

arqanore::Vector2 convert_vector2(JNIEnv* env, jobject obj);

jobject convert_vector2(JNIEnv* env, arqanore::Vector2 vec);

arqanore::Vector3 convert_vector3(JNIEnv* env, jobject obj);

jobject convert_vector3(JNIEnv* env, arqanore::Vector3 vec);

arqanore::Quaternion convert_quaternion(JNIEnv* env, jobject obj);

jobject convert_quaternion(JNIEnv* env, arqanore::Quaternion vec);

arqanore::Matrix3 convert_matrix3(JNIEnv* env, jobject obj);

jobject convert_matrix3(JNIEnv* env, arqanore::Matrix3 mat);

arqanore::Matrix4 convert_matrix4(JNIEnv* env, jobject obj);

jobject convert_matrix4(JNIEnv* env, arqanore::Matrix4 vec);