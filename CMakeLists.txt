cmake_minimum_required(VERSION 3.12)

project("checkers"
    VERSION 0.1
    DESCRIPTION "libdill example"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)

set(SOURCES
    src/main.c
)


# Also look for Find-cmake modules here
#set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/sdl2")

find_package(Threads)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE
  "${CMAKE_SOURCE_DIR}/libs/libdill/include"
) 
target_link_libraries(main PRIVATE
  "${CMAKE_SOURCE_DIR}/libs/libdill/lib/libdill.a"
  "${CMAKE_THREAD_LIBS_INIT}"
)
