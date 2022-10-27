include_directories(${DIVISION_HEADERS_DIR})
set(SOURCE_FILES out_test.cpp)
add_executable(out_tests ${SOURCE_FILES})
#target_link_libraries(out_tests division)
install(TARGETS out_tests DESTINATION bin)

