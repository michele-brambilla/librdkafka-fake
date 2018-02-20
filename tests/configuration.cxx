#include "rdkafka.h"
#include "utils.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(configuration, create_new_configuration_default_success) {
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  EXPECT_NE(conf, nullptr);
}

TEST(configuration, create_invalid_configuration) {
  setConfigurationInvalid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  EXPECT_EQ(conf, nullptr);
}

TEST(configuration, create_valid_configuration) {
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  EXPECT_NE(conf, nullptr);
}

TEST(configuration, set_rdkafka_option_success) {
  std::string errstr, errstr_empty;
  errstr.resize(100);
  errstr_empty.resize(100);

  // create new config (valid)
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  // set options valid
  setConfigurationOptionValid();
  resetConfigurationOptions();
  // std::cout << "Configuration:\n" << std::endl;
  // std::cout << dumpConfigurationOptions() << "\n";
  EXPECT_EQ(getConfigurationOptionsSize(), 0ul);

  int result =
      rd_kafka_conf_set(conf, "key1", "value1", &errstr[0], errstr.size());
  EXPECT_EQ(result, RD_KAFKA_CONF_OK);
  EXPECT_EQ(errstr, errstr_empty);
  EXPECT_EQ(getConfigurationOptionsSize(), 1ul);

  result = rd_kafka_conf_set(conf, "key2", "value2", &errstr[0], errstr.size());
  EXPECT_EQ(result, RD_KAFKA_CONF_OK);
  EXPECT_EQ(errstr, errstr_empty);
  EXPECT_EQ(getConfigurationOptionsSize(), 2ul);
}

TEST(configuration, set_rdkafka_option_failure) {
  std::string errstr, errstr_empty;
  errstr.resize(100);
  errstr_empty.resize(100);

  // create new config (valid)
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  // set options valid
  setConfigurationOptionInvalid();
  resetConfigurationOptions();
  // std::cout << "Configuration:\n" << std::endl;
  // std::cout << dumpConfigurationOptions() << "\n";
  EXPECT_EQ(getConfigurationOptionsSize(), 0ul);

  int result =
      rd_kafka_conf_set(conf, "key1", "value1", &errstr[0], errstr.size());

  EXPECT_EQ(result, RD_KAFKA_CONF_UNKNOWN);
  EXPECT_NE(errstr, errstr_empty);
  EXPECT_EQ(getConfigurationOptionsSize(), 0ul);
}
