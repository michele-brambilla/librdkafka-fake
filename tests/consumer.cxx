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
  RdKafka::ErrorCode err = Consumer->metadata(1, rkt, &metadatap, 1000);
  EXPECT_EQ(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);

  // expect metadata pointer to be valid but return error
  setMetadataPointerValid();
  setMetadataReturnValueError();
  err = Consumer->metadata(1, rkt, &metadatap, 1000);
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
  RdKafka::ErrorCode err = Consumer->metadata(1, rkt, &metadatap, 1000);
  EXPECT_NE(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
}
