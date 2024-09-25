#include <arqanore/window.h>
#include <iostream>
#include "be_labruyere_arqanore_Window.h"

#include <arqanore/arqanore.h>

#include "jni_utils.h"
#include "arqanore/exceptions.h"
#include "arq_utils.h"

/* CALLBACKS */
JavaCallback *window_open_cb_data;
JavaCallback *window_close_cb_data;
JavaCallback *window_update_cb_data;
JavaCallback *window_render2d_cb_data;
JavaCallback *window_render3d_cb_data;
JavaCallback *window_resize_cb_data;
JavaCallback *window_position_cb_data;
JavaCallback *window_char_cb_data;

void handle_java_callback(arqanore::Window *window, JavaCallback *cb) {
    if (cb == nullptr) {
        return;
    }

    if (cb->is_empty()) {
        return;
    }

    auto env = cb->env;
    auto cls = cb->cls;
    auto mid = cb->mid;

    env->CallStaticVoidMethod(cls, mid);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        window->close();
    }
}

void window_open_cb(arqanore::Window *window) {
    handle_java_callback(window, window_open_cb_data);
}

void window_close_cb(arqanore::Window *window) {
    handle_java_callback(window, window_close_cb_data);
}

void window_update_cb(arqanore::Window *window, double at) {
    auto cb = window_update_cb_data;

    if (cb == nullptr || cb->is_empty()) {
        return;
    }

    auto env = cb->env;
    auto cls = cb->cls;
    auto mid = cb->mid;

    env->CallStaticVoidMethod(cls, mid, at);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        window->close();
    }
}

/*void window_opengl_cb(arqanore::Window *window, std::string type, std::string severity, std::string message) {
    auto cb = window_opengl_cb_data;

    if (cb == nullptr || cb->is_empty()) {
        return;
    }

    JNIEnv *env = cb->env;
    jclass cls = cb->cls;
    jmethodID mid = cb->mid;

    jstring str_type = convert_java_string(env, type);
    jstring str_severity = convert_java_string(env, severity);
    jstring str_message = convert_java_string(env, message);

    env->CallStaticVoidMethod(cls, mid, str_type, str_severity, str_message);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        window->close();
    }
}*/

void window_render2d_cb(arqanore::Window *window) {
    handle_java_callback(window, window_render2d_cb_data);
}

void window_render3d_cb(arqanore::Window *window) {
    handle_java_callback(window, window_render3d_cb_data);
}

void window_resize_cb(arqanore::Window *window, int width, int height) {
    auto cb = window_resize_cb_data;

    if (cb == nullptr || cb->is_empty()) {
        return;
    }

    auto env = cb->env;
    auto cls = cb->cls;
    auto mid = cb->mid;

    env->CallStaticVoidMethod(cls, mid, width, height);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        window->close();
    }
}

void window_position_cb(arqanore::Window *window, int x, int y) {
    auto cb = window_position_cb_data;

    if (cb == nullptr || cb->is_empty()) {
        return;
    }

    auto env = cb->env;
    auto cls = cb->cls;
    auto mid = cb->mid;

    env->CallStaticVoidMethod(cls, mid, x, y);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        window->close();
    }
}

void window_char_cb(arqanore::Window *window, unsigned int codePoint) {
    auto cb = window_char_cb_data;

    if (cb == nullptr || cb->is_empty()) {
        return;
    }

    auto env = cb->env;
    auto cls = cb->cls;
    auto mid = cb->mid;

    env->CallStaticVoidMethod(cls, mid, codePoint);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        window->close();
    }
}

/* WRAPPER METHODS */
jint Java_be_labruyere_arqanore_Window__1getWidth(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->get_width();
}

jint Java_be_labruyere_arqanore_Window__1getHeight(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->get_height();
}

jint Java_be_labruyere_arqanore_Window__1getX(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->get_x();
}

jint Java_be_labruyere_arqanore_Window__1getY(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->get_y();
}

jboolean Java_be_labruyere_arqanore_Window__1getVSync(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->get_vsync();
}

jstring Java_be_labruyere_arqanore_Window__1getTitle(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return convert_java_string(env, ptr->get_title());
}

jobject Java_be_labruyere_arqanore_Window__1getClearColor(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    auto color = convert_color(env, ptr->get_clear_color());

    return color;
}

jdouble Java_be_labruyere_arqanore_Window__1getFps(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->get_fps();
}

jboolean Java_be_labruyere_arqanore_Window__1isClosed(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->is_closed();
}

jboolean Java_be_labruyere_arqanore_Window__1isMinimized(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->is_minimized();
}

jboolean Java_be_labruyere_arqanore_Window__1isMaximized(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->is_maximized();
}

jboolean Java_be_labruyere_arqanore_Window__1isVisible(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    return ptr->is_visible();
}

void Java_be_labruyere_arqanore_Window__1setWidth(JNIEnv *env, jobject cls, jlong window, jint value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_width(value);
}

void Java_be_labruyere_arqanore_Window__1setHeight(JNIEnv *env, jobject cls, jlong window, jint value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_height(value);
}

void Java_be_labruyere_arqanore_Window__1setX(JNIEnv *env, jobject cls, jlong window, jint value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_x(value);
}

void Java_be_labruyere_arqanore_Window__1setY(JNIEnv *env, jobject cls, jlong window, jint value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_y(value);
}

void Java_be_labruyere_arqanore_Window__1setVSync(JNIEnv *env, jobject cls, jlong window, jboolean value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_vsync(value);
}

void Java_be_labruyere_arqanore_Window__1setTitle(JNIEnv *env, jobject cls, jlong window, jstring value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_title(convert_java_string(env, value));
}

void Java_be_labruyere_arqanore_Window__1setClearColor(JNIEnv *env, jobject cls, jlong window, jobject color) {
    auto ptr = (arqanore::Window *) window;
    auto clr = convert_color(env, color);

    ptr->set_clear_color(clr);
}

void Java_be_labruyere_arqanore_Window__1setClosed(JNIEnv *env, jobject cls, jlong window, jboolean value) {
    auto ptr = (arqanore::Window *) window;
    ptr->set_closed(value);
}

void Java_be_labruyere_arqanore_Window__1setOpenCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_open_cb_data = get_java_callback(env, class_name, method_name, "()V");
}

void Java_be_labruyere_arqanore_Window__1setCloseCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_close_cb_data = get_java_callback(env, class_name, method_name, "()V");
}

void Java_be_labruyere_arqanore_Window__1setUpdateCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_update_cb_data = get_java_callback(env, class_name, method_name, "(D)V");
}

void Java_be_labruyere_arqanore_Window__1setRender2DCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_render2d_cb_data = get_java_callback(env, class_name, method_name, "()V");
}

void Java_be_labruyere_arqanore_Window__1setRender3DCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_render3d_cb_data = get_java_callback(env, class_name, method_name, "()V");
}

void Java_be_labruyere_arqanore_Window__1setResizeCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_resize_cb_data = get_java_callback(env, class_name, method_name, "(II)V");
}

void Java_be_labruyere_arqanore_Window__1setPositionCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_position_cb_data = get_java_callback(env, class_name, method_name, "(II)V");
}

void Java_be_labruyere_arqanore_Window__1setCharCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_char_cb_data = get_java_callback(env, class_name, method_name, "(I)V");
}

/*void Java_be_labruyere_arqanore_Window__1setOpenGLCallback(JNIEnv *env, jobject cls, jlong window, jstring class_name, jstring method_name) {
    window_opengl_cb_data = get_java_callback(env, class_name, method_name, "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
}*/

jlong Java_be_labruyere_arqanore_Window__1create(JNIEnv *env, jobject cls, jint width, jint height, jstring title) {
    auto winWidth = (int) width;
    auto winHeight = (int) height;
    auto winTitle = convert_java_string(env, title);

    auto ptr = new arqanore::Window(winWidth, winHeight, winTitle);
    ptr->on_open(window_open_cb);
    ptr->on_close(window_close_cb);
    ptr->on_update(window_update_cb);
    ptr->on_render2d(window_render2d_cb);
    ptr->on_render3d(window_render3d_cb);
    ptr->on_resize(window_resize_cb);
    ptr->on_position(window_position_cb);
    ptr->on_char(window_char_cb);

    return (intptr_t) ptr;
}

void Java_be_labruyere_arqanore_Window__1destroy(JNIEnv *env, jobject cls, jlong window) {
    delete (arqanore::Window *) window;

    delete window_open_cb_data;
    delete window_close_cb_data;
    delete window_update_cb_data;
    delete window_render2d_cb_data;
    delete window_render3d_cb_data;
    delete window_resize_cb_data;
    delete window_position_cb_data;
    delete window_char_cb_data;
}

void Java_be_labruyere_arqanore_Window__1open(JNIEnv *env, jobject cls, jlong window, jboolean fullscreen, jboolean maximized, jboolean resizable) {
    auto ptr = (arqanore::Window *) window;

    try {
        ptr->open(fullscreen, maximized, resizable);
    } catch (arqanore::ArqanoreException &ex) {
        throw_java_exception(env, ex.what());
    } catch (arqanore::GlfwException &ex) {
        throw_java_exception(env, "A GLFW error occurred. Error code: '" + std::to_string(ex.get_code()) + "'. Error description: '" + ex.what() + "'.");
    } catch (std::exception &ex) {
        throw_java_exception(env, ex.what());
    } catch (...) {
        throw_java_exception(env, "Unknown error occurred");
    }
}

void Java_be_labruyere_arqanore_Window__1close(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    ptr->close();
}

void Java_be_labruyere_arqanore_Window__1minimize(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    ptr->minimize();
}

void Java_be_labruyere_arqanore_Window__1maximize(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    ptr->maximize();
}

void Java_be_labruyere_arqanore_Window__1restore(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    ptr->restore();
}

void Java_be_labruyere_arqanore_Window__1show(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    ptr->show();
}

void Java_be_labruyere_arqanore_Window__1hide(JNIEnv *env, jobject cls, jlong window) {
    auto ptr = (arqanore::Window *) window;
    ptr->hide();
}
