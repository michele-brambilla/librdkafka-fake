set(tgt "tests")
set(sources
#c
configuration.cxx
consumer.cxx
topic_partition.cxx
#c++
configuration-cpp.cxx
consumer-cpp.cxx
handle-cpp.cxx
metadata-cpp.cxx
topic_partition-cpp.cxx
)
add_executable(${tgt} tests.cxx ${sources})
add_dependencies(${tgt} rdkafka-fake rdkafka++-fake rdkafka-fake-utils)

target_compile_definitions(${tgt} PRIVATE ${compile_defs_common})
target_include_directories(${tgt} PRIVATE ${path_include_common})
target_link_libraries(${tgt} ${libraries_common} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/librdkafka-fake.a
												 ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/librdkafka++-fake.a
												 ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/librdkafka-fake-utils.a )
add_gtest_to_target(${tgt})
