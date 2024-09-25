#include "be_labruyere_arqanore_Shader.h"
#include "arqanore/shader.h"
#include "jni_utils.h"
#include "arqanore/exceptions.h"
#include "arq_utils.h"

jlong Java_be_labruyere_arqanore_Shader__1create(JNIEnv *env, jobject cls) {
    return (intptr_t) new arqanore::Shader();
}

void Java_be_labruyere_arqanore_Shader__1destroy(JNIEnv *env, jobject cls, jlong shader) {
    delete (arqanore::Shader *) shader;
}

void Java_be_labruyere_arqanore_Shader__1addVertexSource(JNIEnv *env, jobject cls, jlong shader, jstring source, jint source_type) {
    auto ptr = (arqanore::Shader *) shader;
    auto str_source = convert_java_string(env, source);
    auto uint_source_type = (unsigned int) source_type;

    try {
        ptr->add_vertex(str_source, uint_source_type);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1addFragmentSource(JNIEnv *env, jobject cls, jlong shader, jstring source, jint source_type) {
    auto ptr = (arqanore::Shader *) shader;
    auto str_source = convert_java_string(env, source);
    auto uint_source_type = (unsigned int) source_type;

    try {
        ptr->add_fragment(str_source, uint_source_type);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1compile(JNIEnv *env, jobject cls, jlong shader) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->compile();
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform1i(JNIEnv *env, jobject cls, jlong shader, jstring name, jint i) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_1i(convert_java_string(env, name), (int) i);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform2i(JNIEnv *env, jobject cls, jlong shader, jstring name, jint i1, jint i2) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_2i(convert_java_string(env, name), (int) i1, (int) i2);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform3i(JNIEnv *env, jobject cls, jlong shader, jstring name, jint i1, jint i2, jint i3) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_3i(convert_java_string(env, name), (int) i1, (int) i2, (int) i3);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform4i(JNIEnv *env, jobject cls, jlong shader, jstring name, jint i1, jint i2, jint i3, jint i4) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_4i(convert_java_string(env, name), (int) i1, (int) i2, (int) i3, (int) i4);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform1f(JNIEnv *env, jobject cls, jlong shader, jstring name, jfloat f) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_1f(convert_java_string(env, name), (float) f);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform2f(JNIEnv *env, jobject cls, jlong shader, jstring name, jfloat f1, jfloat f2) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_2f(convert_java_string(env, name), (float) f1, (float) f2);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform3f(JNIEnv *env, jobject cls, jlong shader, jstring name, jfloat f1, jfloat f2, jfloat f3) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_3f(convert_java_string(env, name), (float) f1, (float) f2, (float) f3);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform4f(JNIEnv *env, jobject cls, jlong shader, jstring name, jfloat f1, jfloat f2, jfloat f3, jfloat f4) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_4f(convert_java_string(env, name), (float) f1, (float) f2, (float) f3, (float) f4);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform1d(JNIEnv *env, jobject cls, jlong shader, jstring name, jdouble d) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_1d(convert_java_string(env, name), (double) d);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform2d(JNIEnv *env, jobject cls, jlong shader, jstring name, jdouble d1, jdouble d2) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_2d(convert_java_string(env, name), (double) d1, (double) d2);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform3d(JNIEnv *env, jobject cls, jlong shader, jstring name, jdouble d1, jdouble d2, jdouble d3) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_3d(convert_java_string(env, name), (double) d1, (double) d2, (double) d3);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniform4d(JNIEnv *env, jobject cls, jlong shader, jstring name, jdouble d1, jdouble d2, jdouble d3, jdouble d4) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        ptr->set_uniform_4d(convert_java_string(env, name), (double) d1, (double) d2, (double) d3, (double) d4);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniformVec2(JNIEnv *env, jobject cls, jlong shader, jstring name, jobject obj_vec) {
    auto ptr = (arqanore::Shader *) shader;
    auto vec = convert_vector2(env, obj_vec);

    try {
        ptr->set_uniform_vec2(convert_java_string(env, name), vec);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniformVec3(JNIEnv *env, jobject cls, jlong shader, jstring name, jobject obj_vec) {
    auto ptr = (arqanore::Shader *) shader;
    auto vec = convert_vector3(env, obj_vec);

    try {
        ptr->set_uniform_vec3(convert_java_string(env, name), vec);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniformMat3(JNIEnv *env, jobject cls, jlong shader, jstring name, jobject obj_mat) {
    auto ptr = (arqanore::Shader *) shader;
    auto mat = convert_matrix3(env, obj_mat);

    try {
        ptr->set_uniform_mat3(convert_java_string(env, name), mat);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniformMat4(JNIEnv *env, jobject cls, jlong shader, jstring name, jobject obj_mat) {
    auto ptr = (arqanore::Shader *) shader;
    auto mat = convert_matrix4(env, obj_mat);

    try {
        ptr->set_uniform_mat4(convert_java_string(env, name), mat);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniformRgba(JNIEnv *env, jobject cls, jlong shader, jstring name, jobject obj_color) {
    auto ptr = (arqanore::Shader *) shader;
    auto color = convert_color(env, obj_color);

    try {
        ptr->set_uniform_rgba(convert_java_string(env, name), color);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setUniformRgb(JNIEnv *env, jobject cls, jlong shader, jstring name, jobject obj_color) {
    auto ptr = (arqanore::Shader *) shader;
    auto color = convert_color(env, obj_color);

    try {
        ptr->set_uniform_rgb(convert_java_string(env, name), color);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setTexture(JNIEnv *env, jobject cls, jlong shader, jint index, jlong texture) {
    auto ptr1 = (arqanore::Shader *) shader;
    auto ptr2 = (arqanore::Texture *) texture;

    try {
        ptr1->set_texture(index, ptr2);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Shader__1setSprite(JNIEnv *env, jobject cls, jlong shader, jint index, jlong sprite) {
    auto ptr1 = (arqanore::Shader *) shader;
    auto ptr2 = (arqanore::Sprite *) sprite;

    try {
        ptr1->set_sprite(index, ptr2);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}
