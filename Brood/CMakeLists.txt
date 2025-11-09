cmake_minimum_required(VERSION 3.30.5)

# Base test sources (always present)
set(LARVAE_TEST_SOURCES
    main.cpp
    ../Comb/tests/test_platform.cpp
    ../Comb/tests/test_linear.cpp
    ../Comb/tests/test_pool.cpp
    ../Comb/tests/test_slab.cpp
    ../Comb/tests/test_stack.cpp
    ../Comb/tests/test_buddy.cpp
    ../Wax/tests/test_array.cpp
    ../Wax/tests/test_span.cpp
    ../Wax/tests/test_vector.cpp
)

# GPU tests (conditional, requires Vulkan)
if(swarm_use_vulkan)
    list(APPEND LARVAE_TEST_SOURCES gpu/test_gpu_allocator.cpp)
endif()

# Create the test executable
add_executable(larvae_runner ${LARVAE_TEST_SOURCES})

# Link against Larvae testing framework and modules to test
target_link_libraries(larvae_runner PRIVATE
    larvae
    hive
    comb
)

target_include_directories(larvae_runner PRIVATE
    ${CMAKE_SOURCE_DIR}/Wax/include
    ${CMAKE_SOURCE_DIR}/Comb/include
)

# Set output directory
set_target_properties(larvae_runner PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Add test to CTest
enable_testing()
add_test(NAME AllTests COMMAND larvae_runner)

# Create the benchmark executable
add_executable(larvae_benchmark
    main_benchmark.cpp
    ../Comb/tests/benchmark_linear.cpp
    ../Comb/tests/benchmark_pool.cpp
    ../Comb/tests/benchmark_slab.cpp
    ../Comb/tests/benchmark_stack.cpp
    ../Comb/tests/benchmark_buddy.cpp
    ../Wax/tests/benchmark_array.cpp
    ../Wax/tests/benchmark_span.cpp
    ../Wax/tests/benchmark_vector.cpp
)

target_link_libraries(larvae_benchmark PRIVATE
    larvae
    hive
    comb
)

target_include_directories(larvae_benchmark PRIVATE
    ${CMAKE_SOURCE_DIR}/Wax/include
    ${CMAKE_SOURCE_DIR}/Comb/include
)

set_target_properties(larvae_benchmark PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
