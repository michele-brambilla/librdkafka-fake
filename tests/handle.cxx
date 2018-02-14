#include "rdkafkacpp_int.h"
#include "definitions.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(handle, create_new_handle) {
  RdKafka::Handle *h = new RdKafka::HandleImpl;
  EXPECT_NE(h, nullptr);
}

TEST(handle, get_invalid_metadata_from_handle) {
  RdKafka::Handle *h = new RdKafka::HandleImpl;
  RdKafka::Topic *rkt{ nullptr };
  RdKafka::Metadata *metadatap{ nullptr };

  // expect metadata pointer to be invalid, return no error
  setMetadataPointerInvalid();
  setMetadataReturnValueOk();
  RdKafka::ErrorCode err = h->metadata(1, rkt, &metadatap, 1000);
  EXPECT_EQ(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);

  // expect metadata pointer to be valid but return error
  setMetadataPointerValid();
  setMetadataReturnValueError();
  err = h->metadata(1, rkt, &metadatap, 1000);
  EXPECT_NE(metadatap, nullptr);
  EXPECT_NE(err, RdKafka::ERR_NO_ERROR);
}

TEST(handle, get_valid_metadata_from_handle) {
  RdKafka::Handle *h = new RdKafka::HandleImpl;
  RdKafka::Topic *rkt{ nullptr };
  RdKafka::Metadata *metadatap{ nullptr };

  // expect metadata to be valid
  setMetadataPointerValid();
  setMetadataReturnValueOk();
  RdKafka::ErrorCode err = h->metadata(1, rkt, &metadatap, 1000);
  EXPECT_NE(metadatap, nullptr);
  EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
}

// TEST(handle,get_topic_from_handle) {
// 	RdKafka::Handle* h = new RdKafka::HandleImpl;
// 	RdKafka::Topic* rkt{nullptr};
// 	RdKafka::Metadata *metadatap{nullptr};
// 	setMetadataPointerValid();
// 	setMetadataReturnValueOk();

// 	// expect metadata to be invalid
// 	setMetadataTopicInvalid();
// 	RdKafka::ErrorCode err = h->metadata(1, rkt, &metadatap, 1000);
// 	EXPECT_NE(metadatap, nullptr);
// 	EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
// 	EXPECT_EQ(rkt, nullptr);

// 	// expect metadata to be invalid
// 	setMetadataTopicValid();
// 	err = h->metadata(1, rkt, &metadatap, 1000);
// 	EXPECT_NE(metadatap, nullptr);
// 	EXPECT_EQ(err, RdKafka::ERR_NO_ERROR);
// 	EXPECT_NE(rkt, nullptr);
// }
