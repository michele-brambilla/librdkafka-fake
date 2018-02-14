//=== -*- C++ -*-===//
#pragma once

#include <list>
#include <string>
#include <map>

#include "rdkafkacpp_int.h"
#include "definitions.h"

namespace utils {
	class Storage {
	public:
	static std::list<std::pair<std::string,std::string>> ConfigurationOptions;

	static bool MetadataPointerValid;
	static bool MetadataTopicValid;
	static RdKafka::ErrorCode MetadataErrorCode;


	static std::list<std::pair<std::string,std::string>> MetadataList;
	static std::list<RdKafka::BrokerMetadata> BrokerMetadataList;
	static std::list<RdKafka::TopicMetadata> TopicMetadataList;
	static RdKafka::ErrorCode TopicMetadataErrorCode;


	void reset() {
		ConfigurationOptions.clear();
	}
	
	void addBrokerMetadata(const int id, const std::string& host, const int port);
	void addTopicMetadata() {};

	};

}