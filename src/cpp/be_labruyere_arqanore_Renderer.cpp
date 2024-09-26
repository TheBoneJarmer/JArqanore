#include <arqanore/window.h>
#include <arqanore/font.h>
#include <arqanore/renderer.h>
#include <arqanore/exceptions.h>
#include "be_labruyere_arqanore_Renderer.h"
#include "jni_utils.h"
#include "arq_utils.h"

void Java_be_labruyere_arqanore_Renderer__1setShader(JNIEnv *env, jclass cls, jlong shader, jint target) {
    auto ptr = reinterpret_cast<arqanore::Shader*>(shader);

    try {
        arqanore::Renderer::set_shader(ptr, target);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1switchShader(JNIEnv *env, jclass cls, jlong shader) {
    auto ptr = reinterpret_cast<arqanore::Shader*>(shader);

    try {
        arqanore::Renderer::switch_shader(ptr);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1renderText(JNIEnv *env, jclass cls, jlong window, jlong font, jstring text, jobject obj_pos, jobject obj_scale, jobject obj_color) {
    auto ptr_window = reinterpret_cast<arqanore::Window*>(window);
    auto ptr_font = reinterpret_cast<arqanore::Font*>(font);
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
    auto ptr_window = reinterpret_cast<arqanore::Window*>(window);
    auto ptr_polygon = reinterpret_cast<arqanore::Polygon*>(polygon);
    auto pTexture = static_cast<arqanore::Texture*>(nullptr);
    auto pos = convert_vector2(env, obj_pos);
    auto scl = convert_vector2(env, obj_scl);
    auto ori = convert_vector2(env, obj_ori);
    auto off = convert_vector2(env, obj_off);
    auto color = convert_color(env, obj_color);

    if (texture != 0) {
        pTexture = reinterpret_cast<arqanore::Texture*>(texture);
    }

    try {
        arqanore::Renderer::render_polygon(ptr_window, ptr_polygon, pTexture, pos, scl, ori, off, angle, flip_hor, flip_vert, color);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    }
}

void Java_be_labruyere_arqanore_Renderer__1renderSprite(JNIEnv *env, jclass cls, jlong window, jlong sprite, jobject obj_pos, jobject obj_scl, jobject obj_ori, jfloat angle, jint frame_hor, jint frame_vert, jboolean flip_hor, jboolean flip_vert, jobject obj_color) {
    auto pWindow = reinterpret_cast<arqanore::Window*>(window);
    auto pSprite = reinterpret_cast<arqanore::Sprite*>(sprite);
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
