#include "utils.h"
#include "storage.h"

class Storage;

bool Storage::ConfigurationValid = true;
bool Storage::ConfigurationOptionValid = true;
std::list<std::pair<std::string, std::string> > Storage::ConfigurationOptions{};
bool Storage::ConfOpaqueValid = true;

bool Storage::TopicConfSetValid = false;

std::vector<const RdKafka::TopicMetadata *> Storage::FakeTopicPartitionMetadata;

bool Storage::MetadataPointerValid = true;
bool Storage::MetadataTopicValid = true;
RdKafka::ErrorCode Storage::MetadataErrorCode;

bool Storage::TopicPartitionPointerValid = true;
bool Storage::OffsetsForTimesValid = true;
bool Storage::KafkaNewValid = true;
bool Storage::KafkaConsumerAssign = true;
bool Storage::KafkaConsumerSubscribeValid = true;
bool Storage::KafkaConsumerSubscriptionValid = true;

bool Storage::PollSetConsumer = true;

bool Storage::TopicValid = true;

bool Storage::PollNumMessages = 0;

//////////////////
// Configuration
void resetConfigurationOptions() { Storage::ConfigurationOptions.clear(); }

void setConfigurationValid() { Storage::ConfigurationValid = true; }

void setConfigurationInvalid() { Storage::ConfigurationValid = false; }

bool configurationValid() { return Storage::ConfigurationValid; }

void setConfigurationOptionValid() { Storage::ConfigurationOptionValid = true; }

void setConfigurationOptionInvalid() {
  Storage::ConfigurationOptionValid = false;
}

bool configurationOptionValid() { return Storage::ConfigurationOptionValid; }

size_t getConfigurationOptionsSize() {
  return Storage::ConfigurationOptions.size();
}

void addToConfigurationOptions(std::pair<std::string, std::string> &Opt) {
  Storage::ConfigurationOptions.push_back(Opt);
}

std::string dumpConfigurationOptions() {
  std::string Result;
  for (std::pair<std::string, std::string> &Opt :
       Storage::ConfigurationOptions) {
    Result += Opt.first + " : " + Opt.second + "\n";
  }
  return Result;
}

const std::list<std::pair<std::string, std::string> > &
getConfigurationOptions() {
  return Storage::ConfigurationOptions;
}

void setTopicConfSetValid() { Storage::TopicConfSetValid = true; }

void setTopicConfSetInvalid() { Storage::TopicConfSetValid = false; }

bool topicConfSetValid() { return Storage::TopicConfSetValid; }

void setOpaqueValid() { Storage::ConfOpaqueValid = true; }

void setOpaqueInvalid() { Storage::ConfOpaqueValid = false; }

bool opaqueValid() { return Storage::ConfOpaqueValid; }

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

size_t getTopicPartitionMetadataSize() {
  return Storage::FakeTopicPartitionMetadata.size();
}

const std::vector<const RdKafka::TopicMetadata *> &getTopicPartitionMetadata() {
  return Storage::FakeTopicPartitionMetadata;
}

void setTopicPartitionValid() { Storage::TopicPartitionPointerValid = true; }

void setTopicPartitionInvalid() { Storage::TopicPartitionPointerValid = false; }

bool topicPartitionValid() { return Storage::TopicPartitionPointerValid; }

////////////////
// offsetsForTimes
void setOffsetsForTimesValid() { Storage::OffsetsForTimesValid = true; }
void setOffsetsForTimesInvalid() { Storage::OffsetsForTimesValid = false; }
bool offsetsForTimesValid() { return Storage::OffsetsForTimesValid; }

void setKafkaNewValid() { Storage::KafkaNewValid = true; }

void setKafkaNewInvalid() { Storage::KafkaNewValid = false; }

bool kafkaNewValid() { return Storage::KafkaNewValid; }

////////////////
// KafkaConsumer

void setKafkaConsumerAssignValid() { Storage::KafkaConsumerAssign = true; }
void setKafkaConsumerAssignInvalid() { Storage::KafkaConsumerAssign = false; }
bool kafkaConsumerAssignValid() { return Storage::KafkaConsumerAssign; }

void setKafkaConsumerSubscribeValid() {
  Storage::KafkaConsumerSubscribeValid = true;
}
void setKafkaConsumerSubscribeInvalid() {
  Storage::KafkaConsumerSubscribeValid = false;
}
bool kafkaConsumerSubscribeValid() {
  return Storage::KafkaConsumerSubscribeValid;
}

void setKafkaConsumerSubscriptionValid() {
  Storage::KafkaConsumerSubscriptionValid = true;
}
void setKafkaConsumerSubscriptionInvalid() {
  Storage::KafkaConsumerSubscriptionValid = false;
}
bool kafkaConsumerSubscriptionValid() {
  return Storage::KafkaConsumerSubscriptionValid;
}

void setPollSetConsumerValid() { Storage::PollSetConsumer = true; }
void setPollSetConsumerInvalid() { Storage::PollSetConsumer = false; }
bool pollSetConsumerValid() { return Storage::PollSetConsumer; }
////////////////
// Broker
bool Storage::BrokersAddValid = true;

void setBrokersAddValid() { Storage::BrokersAddValid = true; }
void setBrokersAddInvalid() { Storage::BrokersAddValid = false; }
bool brokersAddValid() { return Storage::BrokersAddValid; }

//////////////////
// Topic
void setTopicNewValid() { Storage::TopicValid = true; }
void setTopicNewInvalid() { Storage::TopicValid = false; }
bool topicNewValid() { return Storage::TopicValid; }

//////////////////
// Poll
void setPollNumMessages(const int &NumMessages) {
  Storage::PollNumMessages = NumMessages;
}
int getPollNumMessages() { return Storage::PollNumMessages; }

/////////////////
// Producer
void setOutqLen(const int &Length) { Storage::PollNumMessages = Length; }
int getOutqLen() { return Storage::PollNumMessages; }
