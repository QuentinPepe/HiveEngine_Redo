# Wax - HiveEngine Standard Library Alternative
cmake_minimum_required(VERSION 3.20)

# Wax is a header-only library for now (Array, Span are header-only)
add_library(Wax INTERFACE)

target_include_directories(Wax
    INTERFACE
        include
)

target_link_libraries(Wax
    INTERFACE
        Hive      # Core (assertions, types)
        Comb      # Allocators
)

target_compile_features(Wax
    INTERFACE
        cxx_std_20
)

# Tests
add_executable(wax_tests
    tests/test_array.cpp
)

target_link_libraries(wax_tests
    PRIVATE
        Wax
        Larvae
        Hive
        Comb
)

# Precompiled headers need explicit include directories
target_include_directories(wax_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Larvae/include
        ${CMAKE_SOURCE_DIR}/Hive/include
        ${CMAKE_SOURCE_DIR}/Comb/include
        include
)

target_precompile_headers(wax_tests
    PRIVATE
        <larvae/larvae.h>
        <wax/containers/array.h>
)
