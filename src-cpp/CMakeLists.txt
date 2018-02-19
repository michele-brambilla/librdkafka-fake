add_library(
    rdkafka++-fake
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
	utils.cxx
)

target_link_libraries(rdkafka++-fake PUBLIC rdkafka)

target_include_directories(rdkafka++-fake PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")
set_target_properties(rdkafka++-fake PROPERTIES PUBLIC_HEADER "definitions.h")
