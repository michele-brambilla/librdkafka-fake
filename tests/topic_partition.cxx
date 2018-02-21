#include "rdkafka_int.h"
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

////////////////////////////////////////////////////
////////////////////////////////////////////////////
// TopicPartition

TEST(topic_partition, assign_non_empty_ptr_partition_default_success) {
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

TEST(topic_partition, assign_partition_invalid_failure) {
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

TEST(topic_partition, assign_partition_valid_success) {
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

// TEST(topic_partition, assign_non_empty_ptr_partition_default_success) {
//   // init
//   setConfigurationValid();
//   rd_kafka_conf_t *conf = rd_kafka_conf_new();
//   std::string errstr{ "", 100 };
//   rd_kafka_s *rk =
//       rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

//   rd_kafka_topic_partition_list_t *PartitionList{
//     new rd_kafka_topic_partition_list_t
//   };
//   rd_kafka_resp_err_t Resp = rd_kafka_assign(rk, PartitionList);

//   EXPECT_EQ(Resp, RD_KAFKA_RESP_ERR_NO_ERROR);
// }

TEST(topic_partition, subscribe_invalid_failure) {
  // init
  setConfigurationValid();
  rd_kafka_conf_t *conf = rd_kafka_conf_new();
  std::string errstr{ "", 100 };
  rd_kafka_s *rk =
      rd_kafka_new(RD_KAFKA_CONSUMER, conf, &errstr[0], errstr.size());

  rd_kafka_topic_partition_list_t *PartitionList{
    new rd_kafka_topic_partition_list_t
  };
  setKafkaConsumerSubscribeInvalid();
  rd_kafka_resp_err_t Resp = rd_kafka_subscribe(rk, PartitionList);

  EXPECT_NE(Resp, RD_KAFKA_RESP_ERR_NO_ERROR);
}

TEST(topic_partition, subscribe_partition_valid_success) {
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
  setKafkaConsumerSubscribeInvalid();
  // and make it valid again
  setKafkaConsumerSubscribeValid();
  rd_kafka_resp_err_t Resp = rd_kafka_subscribe(rk, PartitionList);

  EXPECT_EQ(Resp, RD_KAFKA_RESP_ERR_NO_ERROR);
}

TEST(topic_partition, topic_partition_new_default_success) {
  int32_t Partition = 0;
  const char *Topic = "new-topic";
  rd_kafka_topic_partition_t *TopicPartition =
      rd_kafka_topic_partition_new(Topic, Partition);
  EXPECT_NE(TopicPartition, nullptr);
}

TEST(topic_partition, topic_partition_invalid_failure) {
  int32_t Partition = 0;
  const char *Topic = "new-topic";
  setTopicPartitionInvalid();
  rd_kafka_topic_partition_t *TopicPartition =
      rd_kafka_topic_partition_new(Topic, Partition);
  EXPECT_EQ(TopicPartition, nullptr);
}

TEST(topic_partition, topic_partition_valid_success) {
  int Partition = 0;
  // make sure that is invalid
  setTopicPartitionInvalid();

  setTopicPartitionValid();
  rd_kafka_topic_partition_t *TopicPartition =
      rd_kafka_topic_partition_new("new-topic", Partition);
  EXPECT_NE(TopicPartition, nullptr);
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