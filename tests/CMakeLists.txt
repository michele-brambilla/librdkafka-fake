set(tgt "tests")
set(sources
configuration.cxx
handle.cxx
consumer.cxx
tests.cxx
)

add_executable(${tgt} ${sources})
target_compile_definitions(${tgt} PRIVATE ${compile_defs_common})
target_include_directories(${tgt} PRIVATE ${path_include_common})
target_link_libraries(${tgt} ${libraries_common} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/librdkafka++.a )
add_gtest_to_target(${tgt})
