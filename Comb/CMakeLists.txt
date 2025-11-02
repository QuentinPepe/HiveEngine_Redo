cmake_minimum_required(VERSION 3.30.5)

add_library(comb STATIC)
target_include_directories(comb PUBLIC include PRIVATE src)
target_precompile_headers(comb PRIVATE include/comb/precomp.h)

# Link against Hive (core module)
target_link_libraries(comb PUBLIC hive)

# Add source files here
# target_sources(comb PRIVATE
#     src/comb/example.cpp
# )

# Module class sources
target_sources(comb PRIVATE
    src/comb/combmodule.cpp
    src/comb/log.cpp
)
