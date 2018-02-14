#include "definitions.h"
#include "rdkafkacpp_int.h"

#include <gtest/gtest.h>

#include <iostream>

class MetadataTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    RdKafka::Handle *h = new RdKafka::HandleImpl;
    RdKafka::Topic *rkt{nullptr};
    setMetadataPointerValid();
    setMetadataReturnValueOk();
    err = h->metadata(1, rkt, &metadatap, 1000);
  }

  // virtual void TearDown() {}
  RdKafka::ErrorCode err;
  RdKafka::Metadata *metadatap{nullptr};
};

// TEST(partition_metadata, initial_replicas_array_not_empty) {
//   RdKafka::PartitionMetadataImpl pm{nullptr};
//   EXPECT_EQ(pm.replicas()->size(), 0);
// }

// TEST(partition_metadata, add_replicas) {
//   RdKafka::PartitionMetadataImpl pm{nullptr};
//   EXPECT_EQ(pm.replicas()->size(), 1);
//   EXPECT_EQ(pm.replicas()->size(), 2);
// }

// TEST(topic_metadata, is_empty_and_not_error) {
//   RdKafka::TopicMetadataImpl tm(nullptr);
//   EXPECT_EQ(tm.topic(), "");
//   EXPECT_EQ(tm.err(), RdKafka::ERR_NO_ERROR);
//   EXPECT_EQ(tm.partitions()->size(), 0);
// }

// TEST(topic_metadata, add_topic_and_partitions_array) {
//   RdKafka::TopicMetadataImpl tm(nullptr);

//   EXPECT_EQ(tm.topic(), "");
//   EXPECT_EQ(tm.err(), RdKafka::ERR_NO_ERROR);
//   EXPECT_EQ(tm.partitions()->size(), 0);
// }

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
  addTopicPartitionMetadata("topic-1", {0});
  // TopicMetadataV->push_back(item);
  // setTopicMetadataTopic(TopicMetadata, "topic-one");
  EXPECT_EQ(TopicMetadata->size(), 1);
  addTopicPartitionMetadata("topic-2", {0, 1});
  // setTopicMetadataTopic(TopicMetadata, "topic-two");
  // EXPECT_EQ(TopicMetadata->size(), 1);
  // setTopicMetadataTopic(TopicMetadata, "topic-three");
  // EXPECT_EQ(TopicMetadata->size(), 1);
}

// TEST_F(MetadataTest, topic_metadata_vector_has_topic) {}

// TEST_F(MetadataTest, get_partition_metadata_vector) {}
