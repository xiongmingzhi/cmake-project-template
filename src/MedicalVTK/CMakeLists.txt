set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake")#QT库的位置

set(medical_image
        main.cxx
        mainwindow.cxx)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
find_package(VTK REQUIRED)
add_executable(medicalVTK ${medical_image})
target_link_libraries(medicalVTK
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${VTK_LIBRARIES}
        )
install(TARGETS medicalVTK DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/src/MedicalVTK)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(vtkdemo)
endif()