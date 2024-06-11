add_executable(demotest vtkdemo.cpp)
target_link_libraries(demotest ${VTK_LIBRARIES})

add_executable(vtk19_imageVistModify vtk19_imageVistModify.cpp)
target_link_libraries(vtk19_imageVistModify ${VTK_LIBRARIES})

add_executable(vtk20_imageCast vtk20_imageCast.cpp)
target_link_libraries(vtk20_imageCast ${VTK_LIBRARIES})

add_executable(vtk22_imageExtractComponents vtk22_imageExtractComponents.cpp)
target_link_libraries(vtk22_imageExtractComponents ${VTK_LIBRARIES})

add_executable(vtk24_imageCastColor vtk24_imageCastColor.cpp)
target_link_libraries(vtk24_imageCastColor ${VTK_LIBRARIES})

add_executable(vtk25_imageVOI vtk25_imageVOI.cpp)
target_link_libraries(vtk25_imageVOI ${VTK_LIBRARIES})

add_executable(vtk27_imageExactSlic vtk27_imageExactSlic.cpp)
target_link_libraries(vtk27_imageExactSlic ${VTK_LIBRARIES})

add_executable(vtk29_imageColorHistogram vtk29_imageColorHistogram.cpp)
target_link_libraries(vtk29_imageColorHistogram ${VTK_LIBRARIES})

add_executable(vtk50_vtkFeatureEdges vtk50_vtkFeatureEdges.cpp)
target_link_libraries(vtk50_vtkFeatureEdges ${VTK_LIBRARIES})

add_executable(vtk57_landMark vtk57_landMark.cpp)
target_link_libraries(vtk57_landMark ${VTK_LIBRARIES})

add_executable(vtk58_ICP vtk58_ICP.cpp)
target_link_libraries(vtk58_ICP ${VTK_LIBRARIES})

add_executable(vtk81_vtkObject vtk81_vtkObject.cpp)
target_link_libraries(vtk81_vtkObject ${VTK_LIBRARIES})

