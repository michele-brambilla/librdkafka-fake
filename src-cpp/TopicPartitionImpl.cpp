#include "rdkafkacpp_int.h"
#include "utils.h"

RdKafka::TopicPartition::~TopicPartition() {}

RdKafka::TopicPartition *
RdKafka::TopicPartition::create(const std::string &topic, int partition) {
  if (!topicPartitionValid()) {
    return nullptr;
  }
  return new TopicPartitionImpl(topic, partition);
}

RdKafka::TopicPartition *
RdKafka::TopicPartition::create(const std::string &topic, int partition,
                                int64_t offset) {
  if (!topicPartitionValid()) {
    return nullptr;
  }
  return new TopicPartitionImpl(topic, partition);
}

void
RdKafka::TopicPartition::destroy(std::vector<TopicPartition *> &partitions) {
  for (std::vector<TopicPartition *>::iterator it = partitions.begin();
       it != partitions.end(); ++it)
    delete (*it);
  partitions.clear();
}
