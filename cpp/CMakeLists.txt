cmake_minimum_required(VERSION 3.1)
project (ctypes_ex)
set(CMAKE_CXX_STANDARD 17)

add_library(c_demo SHARED
    sample.c
)

add_library(cpp_demo SHARED
    sample_lib.hh
    sample_lib.cc
    sample_lib_pyi.cc
)

add_executable(main
    main.cc
)
target_link_libraries(main
    cpp_demo
)