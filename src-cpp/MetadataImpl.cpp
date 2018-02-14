#include "utils.h"

#include <string>
#include <vector>

RdKafka::BrokerMetadata::~BrokerMetadata(){};
RdKafka::PartitionMetadata::~PartitionMetadata(){};
RdKafka::TopicMetadata::~TopicMetadata(){};
RdKafka::Metadata::~Metadata(){};

/**
 * Metadata: Broker information handler implementation
 */
class BrokerMetadataImpl : public RdKafka::BrokerMetadata {
public:
  int32_t id() const override { return 0; }
  const std::string host() const override { return "fake-host"; }
  int port() const override { return 9092; }
  ~BrokerMetadataImpl() {}

private:
  // int Id;
  // std::string Host;
  // int Port;
};

void utils::Storage::addBrokerMetadata(const int id, const std::string &host,
                                       const int port) {
  BrokerMetadataImpl bmi;
}

/**
 * Metadata: Topic information handler
 */

// class TopicMetadataImpl : public RdKafka::TopicMetadata {
// public:
//   TopicMetadataImpl(const rd_kafka_metadata_topic_t *){};

//   ~TopicMetadataImpl() = default;

//   const std::string topic() const { return topic_; }

// private:
//   friend void setTopicMetadataTopic(TopicMetadataImpl *, const std::string
//   &);

//   friend void addTopicMetadataPartitionMetadata(TopicMetadata &);
//   std::string topic_;
//   std::vector<const RdKafka::PartitionMetadata *> partitions_;
// };

void setTopicMetadataTopic(void *Target, const std::string &topic) {
  // Target->topic_ = topic;
}

void addTopicMetadataPartitionMetadata() {}

RdKafka::PartitionMetadataImpl::PartitionMetadataImpl(
    const rd_kafka_metadata_partition_t *) {
  //  addTopicPartitionMetadata("topic-name", {0});
}
RdKafka::PartitionMetadataImpl::~PartitionMetadataImpl() {
  resetTopicPartitionMetadata();
}

const std::vector<int32_t> *RdKafka::PartitionMetadataImpl::replicas() const {
  if (utils::Storage::FakeTopicPartitionMetadata.size() == 0) {
    std::runtime_error("Has to be initialised before usage");
    std::cout << "Has to be initialised before usage\n";
    return nullptr;
  }
  // return utils::Storage::FakeTopicPartitionMetadata[0]->partitions();
}

RdKafka::MetadataImpl::MetadataImpl(const rd_kafka_metadata_t *)
//:metadata_(metadata)
{
  // brokers_.reserve(metadata->broker_cnt);
  // for(int i=0;i<metadata->broker_cnt;++i)
  //   brokers_.push_back(new BrokerMetadataImpl(&metadata->brokers[i]));

  // topics_.reserve(metadata->topic_cnt);
  // for(int i=0;i<metadata->topic_cnt;++i)
  //   topics_.push_back(new TopicMetadataImpl(&metadata->topics[i]));
}

RdKafka::MetadataImpl::~MetadataImpl() {
  // for(size_t i=0;i<brokers_.size();++i)
  //   delete brokers_[i];
  // for(size_t i=0;i<topics_.size();++i)
  //   delete topics_[i];

  // if(metadata_)
  //   rd_kafka_metadata_destroy(metadata_);
}
const std::vector<const RdKafka::TopicMetadata *> *
RdKafka::MetadataImpl::topics() const {
  return &utils::Storage::FakeTopicPartitionMetadata;
}

// const std::vector<RdKafka::BrokerMetadata*> RdKafka::MetadataImpl::brokers()
// const {
// 	return  {};
// }
