#include "rdkafkacpp_int.h"
#include "utils.h"

RdKafka::KafkaConsumer::~KafkaConsumer() = default;

RdKafka::KafkaConsumer *RdKafka::KafkaConsumer::create(RdKafka::Conf *conf,
                                                       std::string &errstr) {
  KafkaConsumer *rkc = new RdKafka::KafkaConsumerImpl;
  return rkc;
}

RdKafka::ErrorCode
RdKafka::KafkaConsumerImpl::subscribe(const std::vector<std::string> &topics) {
  return static_cast<RdKafka::ErrorCode>(0);
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::unsubscribe() {
  return static_cast<RdKafka::ErrorCode>(0);
}

RdKafka::Message *RdKafka::KafkaConsumerImpl::consume(int timeout_ms) {

  // rkmessage = rd_kafka_consumer_poll(this->rk_, timeout_ms);

  // if (!rkmessage)
  //   return new RdKafka::MessageImpl(NULL, RdKafka::ERR__TIMED_OUT);

  //  return new RdKafka::MessageImpl(rkmessage);
  return nullptr;
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::assignment(
    std::vector<RdKafka::TopicPartition *> &partitions) {
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode
RdKafka::KafkaConsumerImpl::subscription(std::vector<std::string> &topics) {
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::assign(
    const std::vector<TopicPartition *> &partitions) {
  if (!kafkaConsumerAssignValid()) {
    return RdKafka::ERR__ASSIGN_PARTITIONS;
  }
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::unassign() {
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::committed(
    std::vector<RdKafka::TopicPartition *> &partitions, int timeout_ms) {
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::position(
    std::vector<RdKafka::TopicPartition *> &partitions) {
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode
RdKafka::KafkaConsumerImpl::seek(const RdKafka::TopicPartition &partition,
                                 int timeout_ms) {
  return RdKafka::ERR_NO_ERROR;
}

RdKafka::ErrorCode RdKafka::KafkaConsumerImpl::close() {
  return RdKafka::ERR_NO_ERROR;
}

const std::string RdKafka::KafkaConsumerImpl::clusterid(int timeout_ms) {
  return "fake-cluster";
}
