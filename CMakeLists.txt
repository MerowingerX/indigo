cmake_minimum_required(VERSION 3.10)

# set the project name
project(indigo)

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
#    ${PROJECT_SOURCE_DIR}/linux/usr/include
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/linux
    # this is a quite strange 
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/c++/10
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/c++/10/tr1
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/aarch64-linux-gnu
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/aarch64-linux-gnu/c++
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/aarch64-linux-gnu/c++/10
# if compiled in windows, the links in this directories are symbolic    
#    ${PROJECT_SOURCE_DIR}/linux/usr/include/avahi-compat-libdns_sd
    )

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/indigo_server)

add_subdirectory(indigo_drivers)