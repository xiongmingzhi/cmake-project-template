set(base_SRCS
        CirQueue.cpp
        division.cpp
        )

add_library(src_base ${base_SRCS})
#target_link_libraries(src_base pthread rt)

install(TARGETS src_base DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/src/base)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(tests)
endif()
