#include "rdkafka.h"
#include "utils.h"

#include <gtest/gtest.h>

TEST(partition, assign_empty_ptr_partition_failure) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  rd_kafka_topic_partition_list_t *PartitionList{ nullptr };
  rd_kafka_resp_err_t Resp = rd_kafka_assign(rk, PartitionList);

  EXPECT_EQ(Resp, RD_KAFKA_RESP_ERR__ASSIGN_PARTITIONS);
}

TEST(partition, assign_non_empty_ptr_partition_default_success) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  rd_kafka_topic_partition_list_t *PartitionList{
    new rd_kafka_topic_partition_list_t
  };
  rd_kafka_resp_err_t Resp = rd_kafka_assign(rk, PartitionList);

  EXPECT_EQ(Resp, RD_KAFKA_RESP_ERR_NO_ERROR);
}

TEST(partition, assign_partition_invalid_failure) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  rd_kafka_topic_partition_list_t *PartitionList{
    new rd_kafka_topic_partition_list_t
  };
  setKafkaConsumerAssignInvalid();
  rd_kafka_resp_err_t Resp = rd_kafka_assign(rk, PartitionList);

  EXPECT_EQ(Resp, RD_KAFKA_RESP_ERR__ASSIGN_PARTITIONS);
}

TEST(partition, assign_partition_valid_success) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  rd_kafka_topic_partition_list_t *PartitionList{
    new rd_kafka_topic_partition_list_t
  };

  // make sure that it's invalid
  setKafkaConsumerAssignInvalid();
  // and make it valid again
  setKafkaConsumerAssignValid();
  rd_kafka_resp_err_t Resp = rd_kafka_assign(rk, PartitionList);

  EXPECT_EQ(Resp, RD_KAFKA_RESP_ERR_NO_ERROR);
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
// Topic

TEST(topic, create_topic_default_success) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  std::string topic{ "fake-topic" };
  rd_kafka_topic_t *rkt = rd_kafka_topic_new(rk, topic.c_str(), nullptr);
  EXPECT_NE(rkt, nullptr);
}

TEST(topic, create_topic_invalid_success) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  std::string topic{ "fake-topic" };

  setTopicNewInvalid();
  rd_kafka_topic_t *rkt = rd_kafka_topic_new(rk, topic.c_str(), nullptr);
  EXPECT_EQ(rkt, nullptr);
}

TEST(topic, create_topic_valid_success) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  std::string topic{ "fake-topic" };

  setTopicNewValid();
  rd_kafka_topic_t *rkt = rd_kafka_topic_new(rk, topic.c_str(), nullptr);
  EXPECT_NE(rkt, nullptr);
}