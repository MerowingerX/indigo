cmake_minimum_required(VERSION 3.10)

# set the project name
project(indigo)

set (triple "x86_64-linux-gnu")
set (LIBDIR /usr/lib/${triple})

# remember that we need to setup this for cross compile on linux
# cmake for a cross compile for arm with clang
add_compile_options(
#   -std=c++17
#    -nostdinc
#    -nostdlib
#    -nostdinc++
#    -nostdlib++
#    -nostdlibinc
    )
# add the source files
# we want:
# compile for Linux
add_compile_definitions(INDIGO_LINUX)
# compile static drivers
# add_compile_definitions(STATIC_DRIVERS)
# we also want to manage the Raspberry Pi
add_compile_definitions(RPI_MANAGEMENT)
# we have some specific include direectories (be sure, that the target triplet is set correctly)
include_directories(BEFORE SYSTEM 
    ${PROJECT_SOURCE_DIR}/indigo_server
    ${PROJECT_SOURCE_DIR}/indigo_drivers
    ${PROJECT_SOURCE_DIR}/indigo_libs
    ${PROJECT_SOURCE_DIR}/indigo_libs/externals/novas
    #${PROJECT_SOURCE_DIR}/indigo_libs/externals/libjpeg
    ${PROJECT_SOURCE_DIR}/indigo_libs/externals/hidapi
    #${PROJECT_SOURCE_DIR}/indigo_libs/externals/libtiff
    #${PROJECT_SOURCE_DIR}/indigo_libs/externals/libusb
    ${PROJECT_SOURCE_DIR}/indigo_linux_drivers
    )

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/indigo_server)
add_subdirectory(indigo_drivers)
