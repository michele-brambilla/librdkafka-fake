#include "rdkafkacpp_int.h"
#include "utils.h"

#include <string>
#include <vector>


RdKafka::BrokerMetadata::~BrokerMetadata() {};
// RdKafka::PartitionMetadata::RdKafka::~PartitionMetadata() {};
// RdKafka::TopicMetadata::RdKafka::~TopicMetadata() {};
RdKafka::Metadata::~Metadata() {};


/**
 * Metadata: Broker information handler implementation
 */
class BrokerMetadataImpl : public RdKafka::BrokerMetadata {
 public:
  int32_t      id() const{return 0;}
  const std::string host() const {return "fake-host";}
  int port() const {return 9092;}
  virtual ~BrokerMetadataImpl() {}
 private:
};

// /**
//  * Metadata: Partition information handler
//  */
// class PartitionMetadataImpl : public PartitionMetadata {
//  public:
//   // @TODO too much memory copy? maybe we should create a new vector class that read directly from C arrays?
//   // @TODO use auto_ptr?
//   PartitionMetadataImpl(const rd_kafka_metadata_partition_t *partition_metadata)
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

// /**
//  * Metadata: Topic information handler
//  */
// class TopicMetadataImpl : public TopicMetadata{
//  public:
//   TopicMetadataImpl(const rd_kafka_metadata_topic_t *topic_metadata)
//   :topic_metadata_(topic_metadata),topic_(topic_metadata->topic) {
//     partitions_.reserve(topic_metadata->partition_cnt);
//     for(int i=0;i<topic_metadata->partition_cnt;++i)
//       partitions_.push_back(
//         new PartitionMetadataImpl(&topic_metadata->partitions[i])
//       );
//   }

//   ~TopicMetadataImpl(){
//     for(size_t i=0;i<partitions_.size();++i)
//       delete partitions_[i];
//   }

//   const std::string topic() const {return topic_;}
//   const std::vector<const PartitionMetadata *> *partitions() const {
//     return &partitions_;
//   }
//   ErrorCode err() const {return static_cast<ErrorCode>(topic_metadata_->err);}

//  private:
//   const rd_kafka_metadata_topic_t *topic_metadata_;
//   const std::string topic_;
//   std::vector<const PartitionMetadata *> partitions_;

// };

RdKafka::MetadataImpl::MetadataImpl(const rd_kafka_metadata_t *metadata)
:metadata_(metadata)
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

// const std::vector<RdKafka::BrokerMetadata*> RdKafka::MetadataImpl::brokers() const {
// 	return  {};
// }
