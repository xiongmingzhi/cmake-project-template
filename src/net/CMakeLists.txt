set(net_SRCS
        Detection.cpp
        )

add_library(src_net ${net_SRCS})
#target_link_libraries(src_base pthread rt)

install(TARGETS src_net DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/src/net)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(tests)
endif()
