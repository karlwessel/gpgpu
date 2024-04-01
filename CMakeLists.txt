cmake_minimum_required(VERSION 3.19...3.29)
project(gpgpu LANGUAGES C CXX)

include(CTest)

add_subdirectory(openmp)

add_subdirectory(opencl)

add_subdirectory(hip)



