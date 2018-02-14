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
  EXPECT_EQ(TopicMetadata->size(), 1);
  addTopicPartitionMetadata("topic-2", {0, 1});
  EXPECT_EQ(TopicMetadata->size(), 2);
  addTopicPartitionMetadata("topic-3", {0, 1, 2, 3});
  EXPECT_EQ(TopicMetadata->size(), 3);
}

TEST_F(MetadataTest, reset_topic_metadata_vector) {
  auto TopicMetadata = metadatap->topics();
  ASSERT_EQ(TopicMetadata->size(), 3);
  resetTopicPartitionMetadata();
  EXPECT_EQ(TopicMetadata->size(), 0);
}

TEST_F(MetadataTest, topic_metadata_vector_has_topic) {
  std::string SelectedTopic{"topic-2"};
  addTopicPartitionMetadata("topic-1", {0});
  addTopicPartitionMetadata(SelectedTopic, {0, 1});
  addTopicPartitionMetadata("topic-3", {0, 1, 2, 3});

  using PartitionMetadataVector =
      std::vector<const RdKafka::PartitionMetadata *>;
  const PartitionMetadataVector *pmv{nullptr};

  EXPECT_EQ(pmv, nullptr);
  for (auto &t : *metadatap->topics()) {
    if (t->topic() == SelectedTopic) {
      pmv = t->partitions();
      break;
    }
  }
  EXPECT_NE(pmv, nullptr);
}

TEST_F(MetadataTest, topic_metadata_vector_has_not_topic) {
  std::string SelectedTopic{"expect-missing"};
  // addTopicPartitionMetadata("topic-1", {0});
  // addTopicPartitionMetadata("topic-2", {0, 1});
  // addTopicPartitionMetadata("topic-3", {0, 1, 2, 3});

  using PartitionMetadataVector =
      std::vector<const RdKafka::PartitionMetadata *>;
  const PartitionMetadataVector *pmv{nullptr};

  EXPECT_EQ(pmv, nullptr);
  for (auto &t : *metadatap->topics()) {
    if (t->topic() == SelectedTopic) {
      pmv = t->partitions();
      break;
    }
  }
  EXPECT_EQ(pmv, nullptr);
}

TEST_F(MetadataTest, topic_metadata_id) {
  std::string SelectedTopic{"topic-2"};

  using PartitionMetadataVector =
      std::vector<const RdKafka::PartitionMetadata *>;
  const PartitionMetadataVector *pmv{nullptr};
  for (auto &t : *metadatap->topics()) {
    if (t->topic() == SelectedTopic) {
      pmv = t->partitions();
      break;
    }
  }

  ASSERT_TRUE(!pmv->empty());
  for (auto p : *pmv) {
    std::cout << p->id() << "\n";
    // pushTopicPartition(TopicName, p->id());
    // if (!TopicPartitionVector.back()) {
    //   LOG(Sev::Error, "Error: unable to create partition {} for topic {}",
    //       p->id(), TopicName);
    //   return SEC::topic_partition_error;
    // }
  }
}

// TEST_F(MetadataTest, get_partition_metadata_vector) {}
