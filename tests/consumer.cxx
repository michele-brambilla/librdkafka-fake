#include "rdkafkacpp_int.h"
#include "utils.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(consumer, create_new_consumer) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);

  EXPECT_NE(Consumer, nullptr);
}

TEST(consumer, get_invalid_metadata_from_consumer) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);

  RdKafka::Topic *rkt{ nullptr };
  RdKafka::Metadata *metadatap{ nullptr };

  // expect metadata pointer to be invalid, return no error
  setMetadataPointerInvalid();
  setMetadataReturnValueOk();
  int Timeout{ 1000 };
  RdKafka::ErrorCode err = Consumer->metadata(1, rkt, &metadatap, Timeout);
  EXPECT_EQ(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);

  // expect metadata pointer to be valid but return error
  setMetadataPointerValid();
  setMetadataReturnValueError();
  err = Consumer->metadata(1, rkt, &metadatap, Timeout);
  EXPECT_NE(metadatap, nullptr);
  EXPECT_NE(err, RdKafka::ERR_NO_ERROR);
}

TEST(consumer, get_valid_metadata_from_consumer) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);
  RdKafka::Topic *rkt{ nullptr };
  RdKafka::Metadata *metadatap{ nullptr };

  // expect metadata to be valid
  setMetadataPointerValid();
  setMetadataReturnValueOk();
  int Timeout{ 1000 };
  RdKafka::ErrorCode err = Consumer->metadata(1, rkt, &metadatap, Timeout);
  EXPECT_NE(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
}

TEST(consumer, offset_for_times_success) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);
  setOffsetsForTimesValid();

  std::vector<RdKafka::TopicPartition *> TopicPartitionVector;
  int Timeout{ 1000 };
  RdKafka::ErrorCode err =
      Consumer->offsetsForTimes(TopicPartitionVector, Timeout);

  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
}

TEST(consumer, offset_for_times_failure) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);
  setOffsetsForTimesInvalid();

  std::vector<RdKafka::TopicPartition *> TopicPartitionVector;
  int Timeout{ 1000 };
  RdKafka::ErrorCode err =
      Consumer->offsetsForTimes(TopicPartitionVector, Timeout);

  EXPECT_NE(err, RdKafka::ERR_NO_ERROR);
}

TEST(consumer, assign_topic_partition_success) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);

  std::vector<RdKafka::TopicPartition *> TopicPartitionVector;
  setKafkaConsumerAssignValid();
  RdKafka::ErrorCode err = Consumer->assign(TopicPartitionVector);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
}

TEST(consumer, assign_topic_partition_failure) {
  std::string ErrorString;
  RdKafka::Conf *Configuration =
      RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::KafkaConsumer *Consumer =
      RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);

  std::vector<RdKafka::TopicPartition *> TopicPartitionVector;
  setKafkaConsumerAssignInvalid();
  RdKafka::ErrorCode err = Consumer->assign(TopicPartitionVector);
  EXPECT_NE(err, RdKafka::ERR_NO_ERROR);
}
