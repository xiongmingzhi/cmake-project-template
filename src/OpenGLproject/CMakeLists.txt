#find_package(assimp REQUIRED) # 添加assimp
include_directories(/usr/local/Cellar/assimp/5.1.5/include)
include_directories(/usr/local/Cellar/assimp/5.1.5/lib)
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
#link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# 执行编译命令
add_executable(rectangle  glad.c rectangle.cpp )
target_link_libraries(rectangle ${GLEW_LINK} ${GLFW_LINK})

add_executable(myshader glad.c myshader.cpp)
target_link_libraries(myshader ${GLEW_LINK} ${GLFW_LINK})

add_executable(assimp_test assimp_test.cpp)
target_link_libraries(assimp_test ${GLEW_LINK} ${GLFW_LINK})
