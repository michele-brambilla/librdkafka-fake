#include <iostream>
#include <string>
#include <vector>

#include "rdkafkacpp_int.h"

RdKafka::TopicPartition::~TopicPartition () {
}

RdKafka::TopicPartition *
RdKafka::TopicPartition::create (const std::string &topic, int partition) {
  return new TopicPartitionImpl(topic, partition);
}

RdKafka::TopicPartition *
RdKafka::TopicPartition::create (const std::string &topic, int partition,
                                 int64_t offset) {
  return new TopicPartitionImpl(topic, partition, offset);
}

void
RdKafka::TopicPartition::destroy (std::vector<TopicPartition*> &partitions) {
  for (std::vector<TopicPartition*>::iterator it = partitions.begin() ;
       it != partitions.end(); ++it)
    delete(*it);
  partitions.clear();
}
