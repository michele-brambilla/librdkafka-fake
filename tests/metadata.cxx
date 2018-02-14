#include "rdkafkacpp_int.h"
#include "definitions.h"

#include <gtest/gtest.h>

#include <iostream>

class MetadataTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    RdKafka::Handle *h = new RdKafka::HandleImpl;
    RdKafka::Topic *rkt{ nullptr };
    setMetadataPointerValid();
    setMetadataReturnValueOk();
    err = h->metadata(1, rkt, &metadatap, 1000);
  }

  // virtual void TearDown() {}
  RdKafka::ErrorCode err;
  RdKafka::Metadata *metadatap{ nullptr };
};

TEST_F(MetadataTest, create_metadata_from_handle) {
  EXPECT_NE(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
}

TEST_F(MetadataTest, topic_metadata_vector_is_empty_by_default) {
  auto TopicMetadata = metadatap->topics();
  EXPECT_EQ(TopicMetadata->size(), 0);
}

TEST_F(MetadataTest, add_elements_to_topic_metadata_vector) {
  auto TopicMetadata = metadatap->topics();
  setTopicMetadataTopic(TopicMetadata, "topic-one");
  EXPECT_EQ(TopicMetadata->size(), 1);
  setTopicMetadataTopic(TopicMetadata, "topic-two");
  EXPECT_EQ(TopicMetadata->size(), 1);
  setTopicMetadataTopic(TopicMetadata, "topic-three");
  EXPECT_EQ(TopicMetadata->size(), 1);
}

TEST_F(MetadataTest, topic_metadata_vector_has_topic) {}

TEST_F(MetadataTest, get_partition_metadata_vector) {}
