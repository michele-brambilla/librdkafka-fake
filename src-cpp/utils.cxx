#include "utils.h"

std::list<std::pair<std::string, std::string>>
    utils::Storage::ConfigurationOptions;

std::vector<std::pair<std::string, std::vector<int>>>
    utils::Storage::FakeTopicPartitionMetadata;

bool utils::Storage::MetadataPointerValid = true;
bool utils::Storage::MetadataTopicValid = true;
RdKafka::ErrorCode utils::Storage::MetadataErrorCode;

//////////////////
// configuration-related functions
size_t getConfigurationOptionsSize() {
  return utils::Storage::ConfigurationOptions.size();
}

//////////////////
// Metadata-related functions
void setMetadataPointerValid() { utils::Storage::MetadataPointerValid = true; }
void setMetadataPointerInvalid() {
  utils::Storage::MetadataPointerValid = false;
}
bool metadataPointerValid() { return utils::Storage::MetadataPointerValid; }

void setMetadataReturnValueOk() {
  utils::Storage::MetadataErrorCode = RdKafka::ERR_NO_ERROR;
}
void setMetadataReturnValueError() {
  utils::Storage::MetadataErrorCode = RdKafka::ERR_UNKNOWN;
};
int getMetadataReturnValue() { return int(utils::Storage::MetadataErrorCode); };

void setMetadataTopicInvalid() { utils::Storage::MetadataTopicValid = false; }
void setMetadataTopicValid() { utils::Storage::MetadataTopicValid = true; }
bool metadataTopicValid() { return utils::Storage::MetadataTopicValid; }

void addTopicMetadata(RdKafka::TopicMetadata &) {}

void addTopicPartitionMetadata(const std::string &Topic,
                               const std::vector<int> Partition) {
  utils::Storage::FakeTopicPartitionMetadata.emplace_back(Topic, Partition);
}
void resetTopicPartitionMetadata() {
  utils::Storage::FakeTopicPartitionMetadata.clear();
}