add_library(
    rdkafka++
    ConfImpl.cpp
#    ConsumerImpl.cpp
    HandleImpl.cpp
    KafkaConsumerImpl.cpp
#    MessageImpl.cpp
#    MetadataImpl.cpp
#    ProducerImpl.cpp
#    QueueImpl.cpp
#    RdKafka.cpp
#    TopicImpl.cpp
    TopicPartitionImpl.cpp
    MockImpl.cpp
)

target_link_libraries(rdkafka++ PUBLIC rdkafka)

# Support '#include <rdkafcpp.h>'
target_include_directories(rdkafka++ PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")

install(
    TARGETS rdkafka++
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
    ARCHIVE DESTINATION "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
    RUNTIME DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    INCLUDES DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
#install(
#    FILES "rdkafkacpp.h"
#    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/librdkafka"
#)
