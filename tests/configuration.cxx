#include "rdkafkacpp.h"
#include "definitions.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(configuration, create_new_configuration) {
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  EXPECT_NE(conf, nullptr);
}

TEST(configuration, set_rdkafka_option) {
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  std::string errstr;
  EXPECT_EQ(getConfigurationOptionsSize(), 0ul);
  conf->set("key1", "value1", errstr);
  EXPECT_EQ(getConfigurationOptionsSize(), 1ul);
}

TEST(configuration, dump_configuration) {
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  std::list<std::string> *dump = conf->dump();
  EXPECT_EQ(dump->size(), getConfigurationOptionsSize());
}

// TEST(configuration,get_metadata) {
// 	RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
// RdKafka::Metadata* metadatap = new RdKafka::MetadataImpl;
// 	RdKafka::Topic* Topic{nullptr};
// 	auto metadata = conf->metadata(1, Topic,metadatap,1);
// }
