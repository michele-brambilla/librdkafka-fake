set(tgt "rdkafka-fake")

add_library(
    ${tgt}
    conf.cxx
    consumer.cxx
    producer.cxx
    error.cxx
    message.cxx
    topic_partition.cxx
    rdkafka.cxx
)

#target_link_libraries(${tgt} PUBLIC rdkafka)
target_compile_definitions(${tgt} PRIVATE ${compile_defs_common})
target_include_directories(${tgt} PRIVATE ${path_include_common})
target_include_directories(${tgt} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")