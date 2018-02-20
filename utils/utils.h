//=== -*- C++ -*-===//
#pragma once

#include <list>
#include <map>
#include <string>

#include "definitions.h"
#include "../src-cpp/rdkafkacpp_int.h"

class Storage {
public:
  // configuration
  static bool ConfigurationValid;
  static bool ConfigurationOptionValid;
  static std::list<std::pair<std::string, std::string> > ConfigurationOptions;

  static std::vector<const RdKafka::TopicMetadata *> FakeTopicPartitionMetadata;

  static bool MetadataPointerValid;
  static bool MetadataTopicValid;
  static RdKafka::ErrorCode MetadataErrorCode;

  static std::list<std::pair<std::string, std::string> > MetadataList;
  static std::list<RdKafka::BrokerMetadata> BrokerMetadataList;
  static std::list<RdKafka::TopicMetadata> TopicMetadataList;
  static RdKafka::ErrorCode TopicMetadataErrorCode;

  // TopicPartition
  static bool TopicPartitionPointerValid;

  // offsetsForTimes
  static bool OffsetsForTimesValid;

  // KafkaConsumer::assign
  static bool KafkaConsumerAssign;
};
