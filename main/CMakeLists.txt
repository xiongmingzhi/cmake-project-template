include_directories(${DIVISION_HEADERS_DIR})
set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})
target_link_libraries(main src_base)
install(TARGETS main DESTINATION bin)


