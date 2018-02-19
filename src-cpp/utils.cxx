#include "utils.h"

std::list<std::pair<std::string, std::string> > Storage::ConfigurationOptions;

std::vector<const RdKafka::TopicMetadata *> Storage::FakeTopicPartitionMetadata;

bool Storage::ConfigurationValid = true;
bool Storage::MetadataPointerValid = true;
bool Storage::MetadataTopicValid = true;
RdKafka::ErrorCode Storage::MetadataErrorCode;

bool Storage::TopicPartitionPointerValid = true;
bool Storage::OffsetsForTimesValid = true;
bool Storage::KafkaConsumerAssign = true;

//////////////////
// Configuration
size_t getConfigurationOptionsSize() {
  return Storage::ConfigurationOptions.size();
}
void resetConfigurationOptions() { Storage::ConfigurationOptions.clear(); }
void setConfigurationValid() { Storage::ConfigurationValid = true; }
void setConfigurationInvalid() { Storage::ConfigurationValid = false; }
bool configurationValid() { return Storage::ConfigurationValid; }

//////////////////
// Metadata
void setMetadataPointerValid() { Storage::MetadataPointerValid = true; }
void setMetadataPointerInvalid() { Storage::MetadataPointerValid = false; }
bool metadataPointerValid() { return Storage::MetadataPointerValid; }

void setMetadataReturnValueOk() {
  Storage::MetadataErrorCode = RdKafka::ERR_NO_ERROR;
}
void setMetadataReturnValueError() {
  Storage::MetadataErrorCode = RdKafka::ERR_UNKNOWN;
};
int getMetadataReturnValue() {
  return int(Storage::MetadataErrorCode);
};

void setMetadataTopicInvalid() { Storage::MetadataTopicValid = false; }
void setMetadataTopicValid() { Storage::MetadataTopicValid = true; }
bool metadataTopicValid() { return Storage::MetadataTopicValid; }

//////////////////
// TopicPartition
void addTopicMetadata(RdKafka::TopicMetadata &) {}

void addTopicPartitionMetadata(const std::string &Topic,
                               const std::vector<int> Partitions) {
  RdKafka::PartitionMetadataImpl *pm =
      new RdKafka::PartitionMetadataImpl{ nullptr };
  pm->replicas_ = Partitions;
  RdKafka::TopicMetadataImpl *tm = new RdKafka::TopicMetadataImpl{ nullptr };
  tm->topic_ = Topic;
  tm->partitions_.push_back(pm);
  Storage::FakeTopicPartitionMetadata.push_back(tm);
}
void resetTopicPartitionMetadata() {
  Storage::FakeTopicPartitionMetadata.clear();
}
void setTopicPartitionValid() { Storage::TopicPartitionPointerValid = true; }
void setTopicPartitionInvalid() { Storage::TopicPartitionPointerValid = false; }
bool topicPartitionValid() { return Storage::TopicPartitionPointerValid; }

////////////////
// offsetsForTimes
void setOffsetsForTimesValid() { Storage::OffsetsForTimesValid = true; }
void setOffsetsForTimesInvalid() { Storage::OffsetsForTimesValid = false; }
bool offsetsForTimesValid() { return Storage::OffsetsForTimesValid; }

////////////////
// KafkaConsumer
void setKafkaConsumerAssignValid() { Storage::KafkaConsumerAssign = true; }
void setKafkaConsumerAssignInvalid() { Storage::KafkaConsumerAssign = false; }
bool kafkaConsumerAssignValid() { return Storage::KafkaConsumerAssign; }