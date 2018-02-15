#include <stddef.h>
#include <string>
#include <vector>

namespace RdKafka {
class TopicMetadata;
}

size_t getConfigurationOptionsSize();
void resetConfigurationOptions();

void addBrokerMetadata(const int id, const std::string &host, const int port);
void addTopicMetadata();

void setMetadataPointerValid();
void setMetadataPointerInvalid();
bool metadataPointerValid();
void setMetadataReturnValueOk();
void setMetadataReturnValueError();
int getMetadataReturnValue();
void setMetadataTopicInvalid();
void setMetadataTopicValid();
bool metadataTopicValid();

void addTopicMetadata(RdKafka::TopicMetadata &);
void addTopicPartitionMetadata(const std::string &Topic,
                               const std::vector<int> Partition);
void resetTopicPartitionMetadata();
void setTopicPartitionValid();
void setTopicPartitionInvalid();
bool topicPartitionValid();

void setOffsetsForTimesValid();
void setOffsetsForTimesInvalid();
bool offsetsForTimesValid();

void setKafkaConsumerAssignValid();
void setKafkaConsumerAssignInvalid();
bool kafkaConsumerAssignValid();