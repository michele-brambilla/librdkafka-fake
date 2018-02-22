set(tgt "rdkafka++-fake")

add_library(
    ${tgt}
    ConfImpl.cpp
#    ConsumerImpl.cpp
    HandleImpl.cpp
    KafkaConsumerImpl.cpp
#    MessageImpl.cpp
    MetadataImpl.cpp
#    ProducerImpl.cpp
#    QueueImpl.cpp
    RdKafka.cpp
#    TopicImpl.cpp
    TopicPartitionImpl.cpp
#    MockImpl.cpp
)

target_compile_definitions(${tgt} PRIVATE ${compile_defs_common})
target_include_directories(${tgt} PRIVATE ${path_include_common})
target_include_directories(${tgt} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")