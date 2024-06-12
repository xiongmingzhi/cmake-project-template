set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#set(AUTOGEN_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR})
if(MSV)
    set(CMAKE_PREFIX_PATH "D:/soft/Qt5.12.11/5.12.11/msvc2017_64/lib/cmake")
else()
    set(CMAKE_PREFIX_PATH "/Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake")#QT库的位置

endif()

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(src_Qtproject)

target_link_libraries(src_Qtproject
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

install(TARGETS src_Qtproject DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/src/Qtproject)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(uitest)
    add_subdirectory(myMainWindowtests)
endif()
