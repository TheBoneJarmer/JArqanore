#include "be_labruyere_arqanore_Renderer.h"
#include "arqanore/window.h"
#include "arqanore/font.h"
#include "arqanore/renderer.h"
#include "jni_utils.h"
#include "arqanore/exceptions.h"
#include "arq_utils.h"

jobject Java_be_labruyere_arqanore_Renderer__1generateModelMatrix(JNIEnv *env, jclass cls, jobject obj_pos, jobject obj_rot, jobject obj_scl) {
    auto pos = convert_vector3(env, obj_pos);
    auto rot = convert_quaternion(env, obj_rot);
    auto scl = convert_vector3(env, obj_scl);
    auto mat = arqanore::Renderer::generate_model_matrix(pos, rot, scl);

    return convert_matrix4(env, mat);
}

jobject Java_be_labruyere_arqanore_Renderer__1generateViewMatrix(JNIEnv *env, jclass cls, jlong camera) {
    auto ptr = (arqanore::Camera *) camera;
    auto mat = arqanore::Renderer::generate_view_matrix(*ptr);

    return convert_matrix4(env, mat);
}

jobject Java_be_labruyere_arqanore_Renderer__1generateProjectionMatrix(JNIEnv *env, jclass cls, jlong camera, jlong window) {
    auto ptr1 = (arqanore::Camera *) camera;
    auto ptr2 = (arqanore::Window *) window;
    auto mat = arqanore::Renderer::generate_projection_matrix(*ptr1, ptr2);

    return convert_matrix4(env, mat);
}

void Java_be_labruyere_arqanore_Renderer__1setShader(JNIEnv *env, jclass cls, jlong shader, jint target) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        arqanore::Renderer::set_shader(ptr, target);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1switchShader(JNIEnv *env, jclass cls, jlong shader) {
    auto ptr = (arqanore::Shader *) shader;

    try {
        arqanore::Renderer::switch_shader(ptr);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1renderText(JNIEnv *env, jclass cls, jlong window, jlong font, jstring text, jobject obj_pos, jobject obj_scale, jobject obj_color) {
    auto ptr_window = (arqanore::Window *) window;
    auto ptr_font = (arqanore::Font *) font;
    auto pos = convert_vector2(env, obj_pos);
    auto color = convert_color(env, obj_color);
    auto scale = convert_vector2(env, obj_scale);

    try {
        arqanore::Renderer::render_text(ptr_window, ptr_font, convert_java_u16string(env, text), pos, scale, color);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1renderPolygon(JNIEnv *env, jclass cls, jlong window, jlong polygon, jlong texture, jobject obj_pos, jobject obj_scl, jobject obj_ori, jobject obj_off, jfloat angle, jboolean flip_hor, jboolean flip_vert, jobject obj_color) {
    auto ptr_window = (arqanore::Window *) window;
    auto ptr_polygon = (arqanore::Polygon *) polygon;
    auto pTexture = (arqanore::Texture *) nullptr;
    auto pos = convert_vector2(env, obj_pos);
    auto scl = convert_vector2(env, obj_scl);
    auto ori = convert_vector2(env, obj_ori);
    auto off = convert_vector2(env, obj_off);
    auto color = convert_color(env, obj_color);

    if (texture != 0) {
        pTexture = (arqanore::Texture *) texture;
    }

    try {
        arqanore::Renderer::render_polygon(ptr_window, ptr_polygon, pTexture, pos, scl, ori, off, angle, flip_hor, flip_vert, color);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1renderSprite(JNIEnv *env, jclass cls, jlong window, jlong sprite, jobject obj_pos, jobject obj_scl, jobject obj_ori, jfloat angle, jint frame_hor, jint frame_vert, jboolean flip_hor, jboolean flip_vert, jobject obj_color) {
    auto pWindow = (arqanore::Window *) window;
    auto pSprite = (arqanore::Sprite *) sprite;
    auto pos = convert_vector2(env, obj_pos);
    auto scl = convert_vector2(env, obj_scl);
    auto ori = convert_vector2(env, obj_ori);
    auto color = convert_color(env, obj_color);

    try {
        arqanore::Renderer::render_sprite(pWindow, pSprite, pos, scl, ori, angle, frame_hor, frame_vert, flip_hor, flip_vert, color);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1renderModel(JNIEnv *env, jclass cls, jlong window, jlong model, jobject obj_pos, jobject obj_rot, jobject obj_scl, jint frame) {
    auto ptrWindow = (arqanore::Window *) window;
    auto ptrModel = (arqanore::Model *) model;
    auto pos = convert_vector3(env, obj_pos);
    auto scl = convert_vector3(env, obj_scl);
    auto rot = convert_quaternion(env, obj_rot);

    try {
        arqanore::Renderer::render_model(ptrWindow, ptrModel, pos, rot, scl, frame);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}
