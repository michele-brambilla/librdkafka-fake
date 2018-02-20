#include "rdkafka_int.h"
#include "utils.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(consumer, create_new_consumer_default_valid) {
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());
  EXPECT_NE(rk, nullptr);
}

TEST(consumer, create_new_consumer_invalid_configuration_is_nullptr) {
  setConfigurationInvalid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());
  EXPECT_EQ(rk, nullptr);
}

TEST(consumer, create_new_consumer_valid) {
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerValid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());
  EXPECT_NE(rk, nullptr);
}

TEST(consumer, create_new_consumer_invalid_is_nullptr) {
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerInvalid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());
  EXPECT_EQ(rk, nullptr);
}

TEST(consumer, add_broker_default_success) {
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerValid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());
  int result = rd_kafka_brokers_add(rk, "localhost:9092");
  EXPECT_GT(result, 0);
}

TEST(consumer, add_broker_success) {
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerValid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  setBrokersAddValid();
  EXPECT_EQ(rd_kafka_brokers_add(rk, "localhost:9092"), 1);
  EXPECT_EQ(rd_kafka_brokers_add(rk, "localhost:9092,localhost:9091"), 2);
  int result =
      rd_kafka_brokers_add(rk, "localhost:9092,localhost:9091,localhost:9090");
  EXPECT_EQ(result, 3);
}

TEST(consumer, add_broker_failure) {
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerValid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  setBrokersAddInvalid();
  EXPECT_NE(rd_kafka_brokers_add(rk, "localhost:9092"), 1);
}

TEST(consumer, add_broker_empty_string_cause_failure) {
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerValid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  setBrokersAddValid();
  EXPECT_EQ(rd_kafka_brokers_add(rk, ""), 0);
}

TEST(consumer, destroy_success_if_pointer_valid) {
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  setKafkaConsumerValid();
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());
  EXPECT_EQ(rd_kafka_consumer_close(rk), RD_KAFKA_RESP_ERR_NO_ERROR);
}

TEST(consumer, destroy_failure_if_pointer_invalid) {
  EXPECT_NE(rd_kafka_consumer_close(nullptr), RD_KAFKA_RESP_ERR_NO_ERROR);
}
