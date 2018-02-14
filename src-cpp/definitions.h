#include <stddef.h>
#include <string>

size_t getConfigurationOptionsSize();

void setMetadataPointerValid();
void setMetadataPointerInvalid();
bool metadataPointerValid();
void setMetadataReturnValueOk();
void setMetadataReturnValueError();
int getMetadataReturnValue();
void setMetadataTopicInvalid();
void setMetadataTopicValid();
bool metadataTopicValid();

namespace RdKafka {
class TopicMetadata;
}
void addTopicMetadata(RdKafka::TopicMetadata &);
void addTopicPartitionMetadata(const std::string &Topic,
                               const std::vector<int> Partition);
void resetTopicPartitionMetadata();
