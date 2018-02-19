set(tgt "tests")
set(sources
configuration.cxx
consumer.cxx
handle.cxx
metadata.cxx
tests.cxx
topic_partition.cxx
)

add_executable(${tgt} ${sources})
target_compile_definitions(${tgt} PRIVATE ${compile_defs_common})
target_include_directories(${tgt} PRIVATE ${path_include_common})
target_link_libraries(${tgt} ${libraries_common} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/librdkafka++-fake.a )
add_gtest_to_target(${tgt})
