//=== -*- C++ -*-===//
#pragma once

#include <list>
#include <map>
#include <string>

#include "definitions.h"
#include "rdkafkacpp_int.h"

namespace utils {
class Storage {
public:
  static std::list<std::pair<std::string, std::string>> ConfigurationOptions;
  static std::vector<std::pair<std::string, std::vector<int>>>
      FakeTopicPartitionMetadata;

  static bool MetadataPointerValid;
  static bool MetadataTopicValid;
  static RdKafka::ErrorCode MetadataErrorCode;

  static std::list<std::pair<std::string, std::string>> MetadataList;
  static std::list<RdKafka::BrokerMetadata> BrokerMetadataList;
  static std::list<RdKafka::TopicMetadata> TopicMetadataList;
  static RdKafka::ErrorCode TopicMetadataErrorCode;

  void reset() { ConfigurationOptions.clear(); }

  void addBrokerMetadata(const int id, const std::string &host, const int port);
  void addTopicMetadata(){};
};

} // namespace utils