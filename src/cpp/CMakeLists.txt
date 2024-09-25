cmake_minimum_required(VERSION 3.21)
project(jarqanore)

set(CMAKE_CXX_STANDARD 20)
add_library(jarqanore SHARED 
		tbj/tbj.cpp
		tbj/tbj.h
		jni_utils.cpp
		jni_utils.h
		arq_utils.h
		arq_utils.cpp
		be_labruyere_arqanore_Arqanore.h
		be_labruyere_arqanore_Arqanore.cpp
		be_labruyere_arqanore_Window.cpp
		be_labruyere_arqanore_Window.h
		be_labruyere_arqanore_Keyboard.cpp
		be_labruyere_arqanore_Keyboard.h
		be_labruyere_arqanore_Mouse.cpp
		be_labruyere_arqanore_Mouse.h
		be_labruyere_arqanore_Font.cpp
		be_labruyere_arqanore_Font.h
		be_labruyere_arqanore_Polygon.cpp
		be_labruyere_arqanore_Polygon.h
		be_labruyere_arqanore_MathHelper.cpp
		be_labruyere_arqanore_MathHelper.h
		be_labruyere_arqanore_Joystick.cpp
		be_labruyere_arqanore_Joystick.h
		be_labruyere_arqanore_Audio.cpp
		be_labruyere_arqanore_Audio.h
		be_labruyere_arqanore_Sound.cpp
		be_labruyere_arqanore_Sound.h
		be_labruyere_arqanore_Renderer.cpp
		be_labruyere_arqanore_Renderer.h
		be_labruyere_arqanore_Shader.cpp
		be_labruyere_arqanore_Shader.h
		be_labruyere_arqanore_Shaders.cpp
		be_labruyere_arqanore_Shaders.h
		be_labruyere_arqanore_Color.cpp
		be_labruyere_arqanore_Color.h
		be_labruyere_arqanore_Vector2.cpp
		be_labruyere_arqanore_Vector2.h
		be_labruyere_arqanore_Texture.cpp
		be_labruyere_arqanore_Texture.h
		be_labruyere_arqanore_Sprite.cpp
		be_labruyere_arqanore_Sprite.h
		be_labruyere_arqanore_Vector3.cpp
		be_labruyere_arqanore_Vector3.h
		be_labruyere_arqanore_Light.cpp
		be_labruyere_arqanore_Light.h
		be_labruyere_arqanore_Camera.cpp
		be_labruyere_arqanore_Camera.h
		be_labruyere_arqanore_Material.cpp
		be_labruyere_arqanore_Material.h
		be_labruyere_arqanore_Mesh.cpp
		be_labruyere_arqanore_Mesh.h
		be_labruyere_arqanore_MeshAnimation.cpp
		be_labruyere_arqanore_MeshAnimation.h
		be_labruyere_arqanore_MeshFrame.cpp
		be_labruyere_arqanore_MeshFrame.h
		be_labruyere_arqanore_Model.cpp
		be_labruyere_arqanore_Model.h
		be_labruyere_arqanore_Scene.cpp
		be_labruyere_arqanore_Scene.h
		be_labruyere_arqanore_Matrix3.cpp
		be_labruyere_arqanore_Matrix3.h
		be_labruyere_arqanore_Matrix4.cpp
		be_labruyere_arqanore_Matrix4.h
		be_labruyere_arqanore_Quaternion.cpp
		be_labruyere_arqanore_Quaternion.h)

if (DEFINED ENV{JAVA_HOME})
	set(JAVA_HOME $ENV{JAVA_HOME})
endif()

if (UNIX)	
	target_include_directories(jarqanore PRIVATE ${JAVA_HOME}/include)
	target_include_directories(jarqanore PRIVATE ${JAVA_HOME}/include/linux)
	target_link_libraries(jarqanore PRIVATE arqanore glfw freetype soloudw -Wl,-rpath='$ORIGIN:$ORIGIN/lib')
endif (UNIX)

if (WIN32)
	target_include_directories(jarqanore PRIVATE C:/Include)
	target_link_directories(jarqanore PRIVATE C:/Lib)
	target_include_directories(jarqanore PRIVATE ${JAVA_HOME}/include)
	target_include_directories(jarqanore PRIVATE ${JAVA_HOME}/include/win32)
	target_link_libraries(jarqanore PRIVATE arqanore glfw3 freetype soloudw)
endif (WIN32)
