set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake")#QT库的位置

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

#add_executable(MyMainWindow  MyMainWindow.cpp main.cpp)
set(
        Qtproject_MyMainWindow
        MyMainWindow.cpp
)
add_library(src_Qtproject ${Qtproject_MyMainWindow})

target_link_libraries(src_Qtproject
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

install(TARGETS src_Qtproject DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/src/Qtproject)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(tests)
endif()
