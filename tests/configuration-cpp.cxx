#include "rdkafkacpp.h"
#include "utils.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(configuration_cpp, create_new_configuration_default_success) {
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  EXPECT_NE(conf, nullptr);
}

TEST(configuration_cpp, set_rdkafka_option_success) {
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  std::string errstr;
  setConfigurationOptionValid();
  EXPECT_EQ(getConfigurationOptionsSize(), 0ul);
  RdKafka::Conf::ConfResult result = conf->set("key1", "value1", errstr);
  EXPECT_EQ(result, RdKafka::Conf::CONF_OK);
  EXPECT_TRUE(errstr.empty());
  EXPECT_EQ(getConfigurationOptionsSize(), 1ul);
}

TEST(configuration_cpp, set_rdkafka_option_failure) {
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  std::string errstr;
  setConfigurationOptionInvalid();
  EXPECT_EQ(getConfigurationOptionsSize(), 1ul);
  RdKafka::Conf::ConfResult result = conf->set("key1", "value1", errstr);
  EXPECT_NE(result, RdKafka::Conf::CONF_OK);
  EXPECT_FALSE(errstr.empty());
  EXPECT_EQ(getConfigurationOptionsSize(), 1ul);
}

TEST(configuration_cpp, create_invalid_configuration) {
  setConfigurationInvalid();
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  EXPECT_EQ(conf, nullptr);
}

TEST(configuration_cpp, create_valid_configuration) {
  setConfigurationValid();
  RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  EXPECT_NE(conf, nullptr);
}
