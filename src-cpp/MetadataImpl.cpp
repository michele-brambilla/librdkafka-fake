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

// /**
//  * Metadata: Partition information handler
//  */
// class PartitionMetadataImpl : public PartitionMetadata {
//  public:
//   // @TODO too much memory copy? maybe we should create a new vector class
// that read directly from C arrays?
//   // @TODO use auto_ptr?
//   PartitionMetadataImpl(const rd_kafka_metadata_partition_t
// *partition_metadata)
//   :partition_metadata_(partition_metadata) {
//     replicas_.reserve(partition_metadata->replica_cnt);
//     for(int i=0;i<partition_metadata->replica_cnt;++i)
//       replicas_.push_back(partition_metadata->replicas[i]);

//     isrs_.reserve(partition_metadata->isr_cnt);
//     for(int i=0;i<partition_metadata->isr_cnt;++i)
//       isrs_.push_back(partition_metadata->isrs[i]);
//   }

//   int32_t                    id() const {
//     return partition_metadata_->id;
//   }
//   int32_t                    leader() const {
//     return partition_metadata_->leader;
//   }
//   ErrorCode                  err() const {
//     return static_cast<ErrorCode>(partition_metadata_->err);
//   }

//   const std::vector<int32_t> *replicas() const {return &replicas_;}
//   const std::vector<int32_t> *isrs() const {return &isrs_;}

//   ~PartitionMetadataImpl() {};

//  private:
//   const rd_kafka_metadata_partition_t *partition_metadata_;
//   std::vector<int32_t> replicas_,isrs_;
// };

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

// const std::vector<RdKafka::BrokerMetadata*> RdKafka::MetadataImpl::brokers()
// const {
// 	return  {};
// }
