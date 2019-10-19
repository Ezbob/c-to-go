cmake_minimum_required(VERSION 3.12)

project("checkers"
    VERSION 0.1
    DESCRIPTION "libdill example"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)

set(SERVER_SOURCES
    src/server.c
)

set(SERVER
  "server"
)

# Also look for Find-cmake modules here
#set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/sdl2")

find_package(Threads)

include_directories(
  "${CMAKE_SOURCE_DIR}/libs/include"
) 

link_libraries(
  "${CMAKE_SOURCE_DIR}/libs/lib/libdill.a"
  "${CMAKE_THREAD_LIBS_INIT}"
)

add_executable(${SERVER} ${SERVER_SOURCES})

