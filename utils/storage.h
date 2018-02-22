//=== -*- C++ -*-===//
#pragma once

#include "../src-cpp/rdkafkacpp_int.h"

class Storage {
public:
  // configuration
  static bool ConfigurationValid;
  static bool ConfigurationOptionValid;
  static std::list<std::pair<std::string, std::string> > ConfigurationOptions;
  static bool TopicConfSetValid;
  static bool ConfOpaqueValid;

  static std::vector<const RdKafka::TopicMetadata *> FakeTopicPartitionMetadata;

  static bool MetadataPointerValid;
  static bool MetadataTopicValid;
  static RdKafka::ErrorCode MetadataErrorCode;

  static std::list<std::pair<std::string, std::string> > MetadataList;
  static std::list<RdKafka::BrokerMetadata> BrokerMetadataList;
  static std::list<RdKafka::TopicMetadata> TopicMetadataList;
  static RdKafka::ErrorCode TopicMetadataErrorCode;

  // new instance of producer or consumer
  static bool KafkaNewValid;

  // TopicPartition
  static bool TopicPartitionPointerValid;

  // offsetsForTimes
  static bool OffsetsForTimesValid;

  // KafkaConsumer
  static bool KafkaConsumerAssign;
  static bool PollSetConsumer;
  static bool KafkaConsumerSubscribeValid;
  static bool KafkaConsumerSubscriptionValid;

  // broker
  static bool BrokersAddValid;
  static std::list<std::string> BrokersList;

  // Topic
  static bool TopicValid;

  // Poll
  static bool PollNumMessages;

  // Producer
  static int ProducerOutqLen;
};
