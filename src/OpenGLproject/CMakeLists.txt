#if(assimp_FOUND)
#    message(STATUS "Found assimp: ${assimp_INCLUDE_DIRS}")
#else()
#    message(FATAL_ERROR "Could not find assimp")
#endif()
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/)
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/GLFW)
include_directories(${PROJECT_SOURCE_DIR}/lib/)


# 添加目标链接
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.6/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# 执行编译命令
set(Rectangle glad.c rectangle.cpp)
add_executable(OpenGL ${Rectangle})

set(Myshader glad.c myshader.cpp)
add_executable(MyShader ${Myshader} ${OpenGL})

# mac下这步很重要
if (APPLE)
    target_link_libraries(OpenGL "-framework OpenGL")
    target_link_libraries(OpenGL  "-framework GLUT")
endif()