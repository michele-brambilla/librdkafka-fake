//=== -*- C++ -*-===//
#pragma once

#include "rdkafkacpp.h"

extern "C" {
#include "../src/rdkafka.h"
}

#include <ostream>

/* #ifdef _MSC_VER */
/* typedef int mode_t; */
/* #pragma warning(disable : 4250) */
/* #endif */

namespace RdKafka {

class Mock {
public:
  static bool MetadataValid;
};

/* void consume_cb_trampoline(rd_kafka_message_t *msg, void *opaque); */
/* void log_cb_trampoline (const rd_kafka_t *rk, int level, */
/*                         const char *fac, const char *buf); */
/* void error_cb_trampoline (rd_kafka_t *rk, int err, const char *reason, */
/*                           void *opaque); */
/* void throttle_cb_trampoline (rd_kafka_t *rk, const char *broker_name, */
/* 			     int32_t broker_id, int throttle_time_ms, */
/* 			     void *opaque); */
/* int stats_cb_trampoline (rd_kafka_t *rk, char *json, size_t json_len, */
/*                          void *opaque); */
/* int socket_cb_trampoline (int domain, int type, int protocol, void *opaque);
 */
/* int open_cb_trampoline (const char *pathname, int flags, mode_t mode, */
/*                         void *opaque); */
/* void rebalance_cb_trampoline (rd_kafka_t *rk, */
/*                               rd_kafka_resp_err_t err, */
/*                               rd_kafka_topic_partition_list_t *c_partitions,
 */
/*                               void *opaque); */
/* void offset_commit_cb_trampoline0 ( */
/*         rd_kafka_t *rk, */
/*         rd_kafka_resp_err_t err, */
/*         rd_kafka_topic_partition_list_t *c_offsets, void *opaque); */

/* rd_kafka_topic_partition_list_t * */
/*     partitions_to_c_parts (const std::vector<TopicPartition*> &partitions);
 */

/* /\** */
/*  * @brief Update the application provided 'partitions' with info from
 * 'c_parts' */
/*  *\/ */
/* void update_partitions_from_c_parts (std::vector<TopicPartition*>
 * &partitions, */
/*                                      const rd_kafka_topic_partition_list_t
 * *c_parts); */

/* class EventImpl : public Event { */
/*  public: */
/*   ~EventImpl () {}; */

/*   EventImpl (Type type, ErrorCode err, Severity severity, */
/*              const char *fac, const char *str): */
/*   type_(type), err_(err), severity_(severity), fac_(fac ? fac : ""), */
/* 	  str_(str), id_(0), throttle_time_(0) {}; */

/*   EventImpl (Type type): */
/*   type_(type), err_(ERR_NO_ERROR), severity_(EVENT_SEVERITY_EMERG), */
/* 	  fac_(""), str_(""), id_(0), throttle_time_(0) {}; */

/*   Type        type () const { return type_; } */
/*   ErrorCode   err () const { return err_; } */
/*   Severity    severity () const { return severity_; } */
/*   std::string fac () const { return fac_; } */
/*   std::string str () const { return str_; } */
/*   std::string broker_name () const { */
/* 	  if (type_ == EVENT_THROTTLE) */
/* 		  return str_; */
/* 	  else */
/* 		  return std::string(""); */
/*   } */
/*   int         broker_id () const { return id_; } */
/*   int         throttle_time () const { return throttle_time_; } */

/*   Type        type_; */
/*   ErrorCode   err_; */
/*   Severity    severity_; */
/*   std::string fac_; */
/*   std::string str_;         /\* reused for THROTTLE broker_name *\/ */
/*   int         id_; */
/*   int         throttle_time_; */
/* }; */

class MessageImpl : public Message {
public:
  ~MessageImpl() {
    // if (free_rkmessage_)
    //   rd_kafka_message_destroy(const_cast<rd_kafka_message_t
    //   *>(rkmessage_));
    // if (key_)
    //   delete key_;
  };

  MessageImpl(RdKafka::Topic *topic, rd_kafka_message_t *rkmessage)
      // : topic_(topic), rkmessage_(rkmessage), free_rkmessage_(true),
      //   key_(NULL)
  {}

  MessageImpl(RdKafka::Topic *topic, rd_kafka_message_t *rkmessage, bool dofree)
      // : topic_(topic), rkmessage_(rkmessage), free_rkmessage_(dofree),
      //   key_(NULL)
  {}

  MessageImpl(RdKafka::Topic *topic, const rd_kafka_message_t *rkmessage)
      // : topic_(topic), rkmessage_(rkmessage), free_rkmessage_(false),
      //   key_(NULL)
  {}

  MessageImpl(rd_kafka_message_t *rkmessage) {}
  //     : topic_(NULL), rkmessage_(rkmessage), free_rkmessage_(true),
  // key_(NULL) {
  //   if (rkmessage->rkt) {
  //     topic_ = static_cast<Topic *>(rd_kafka_topic_opaque(rkmessage->rkt));
  //   }
  // }

  MessageImpl(RdKafka::Topic *topic, RdKafka::ErrorCode err)
      //   : topic_(topic), free_rkmessage_(false), key_(NULL) {
      // rkmessage_ = &rkmessage_err_;
      // memset(&rkmessage_err_, 0, sizeof(rkmessage_err_));
      // rkmessage_err_.err = static_cast<rd_kafka_resp_err_t>(err);}
  {}

  std::string errstr() const {
    /* FIXME: If there is an error string in payload (for consume_cb)
     *        it wont be shown since 'payload' is reused for errstr
     *        and we cant distinguish between consumer and producer.
     *        For the producer case the payload needs to be the original
     *        payload pointer. */
    // const char *es = rd_kafka_err2str(rkmessage_->err);
    // return std::string(es ? es : "");
    return "";
  }

  ErrorCode err() const {
    //    return static_cast<RdKafka::ErrorCode>(rkmessage_->err);
    return static_cast<RdKafka::ErrorCode>(0);
  }

  Topic *topic() const { // return topic_;
    return nullptr;
  }
  std::string topic_name() const {
    // if (rkmessage_->rkt)
    //   return rd_kafka_topic_name(rkmessage_->rkt);
    // else
    //   return "";
    return nullptr;
  }
  int32_t partition() const {
    return 0; // return rkmessage_->partition;
  }
  void *payload() const { // return rkmessage_->payload;
    return nullptr;
  }
  size_t len() const {
    return 0; // return rkmessage_->len;
  }
  const std::string *key() const {
    // if (key_) {
    //   return key_;
    // } else if (rkmessage_->key) {
    //   key_ = new std::string(static_cast<char const *>(rkmessage_->key),
    //                          *rkmessage_->key_len);
    //   return key_;
    // }
    return NULL;
  }
  const void *key_pointer() const {
    return nullptr; // return rkmessage_->key;
  }
  size_t key_len() const {
    return 0; // return rkmessage_->key_len;
  }

  int64_t offset() const {
    return 0; // return rkmessage_->offset;
  }

  MessageTimestamp timestamp() const {
    MessageTimestamp ts;
    // rd_kafka_timestamp_type_t tstype;
    // ts.timestamp = rd_kafka_message_timestamp(rkmessage_, &tstype);
    // ts.type = static_cast<MessageTimestamp::MessageTimestampType>(tstype);
    return ts;
  }

  void *msg_opaque() const {
    // return rkmessage_->_private;
    return nullptr;
  };

  int64_t latency() const {
    return 0; // return rd_kafka_message_latency(rkmessage_);
  }

  // RdKafka::Topic *topic_;
  // const rd_kafka_message_t *rkmessage_;
  // bool free_rkmessage_;
  // /* For error signalling by the C++ layer the .._err_ message is
  //  * used as a place holder and rkmessage_ is set to point to it. */
  // rd_kafka_message_t rkmessage_err_;
  // mutable std::string *key_;

private:
  /* "delete" copy ctor + copy assignment, for safety of key_ */
  MessageImpl(MessageImpl const &) /*= delete*/;
  MessageImpl &operator=(MessageImpl const &) /*= delete*/;
};

class ConfImpl : public Conf {
public:
  ConfImpl() = default;
  ~ConfImpl() = default;

  Conf::ConfResult set(const std::string &name, const std::string &value,
                       std::string &errstr);

  Conf::ConfResult set(const std::string &name, DeliveryReportCb *dr_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name, EventCb *event_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name, const Conf *topic_conf,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name, PartitionerCb *partitioner_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name,
                       PartitionerKeyPointerCb *partitioner_kp_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name, SocketCb *socket_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name, OpenCb *open_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name, RebalanceCb *rebalance_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult set(const std::string &name,
                       OffsetCommitCb *offset_commit_cb, std::string &errstr) {
    return Conf::CONF_OK;
  }

  Conf::ConfResult get(const std::string &name, std::string &value) const {
    rd_kafka_conf_res_t res = RD_KAFKA_CONF_INVALID;
    return static_cast<Conf::ConfResult>(res);
  }

  Conf::ConfResult get(DeliveryReportCb *&dr_cb) const { return Conf::CONF_OK; }

  Conf::ConfResult get(EventCb *&event_cb) const { return Conf::CONF_OK; }

  Conf::ConfResult get(PartitionerCb *&partitioner_cb) const {
    return Conf::CONF_OK;
  }

  Conf::ConfResult get(PartitionerKeyPointerCb *&partitioner_kp_cb) const {
    return Conf::CONF_OK;
  }

  Conf::ConfResult get(SocketCb *&socket_cb) const { return Conf::CONF_OK; }

  Conf::ConfResult get(OpenCb *&open_cb) const { return Conf::CONF_OK; }

  Conf::ConfResult get(RebalanceCb *&rebalance_cb) const {
    return Conf::CONF_OK;
  }

  Conf::ConfResult get(OffsetCommitCb *&offset_commit_cb) const {
    return Conf::CONF_OK;
  }

  std::list<std::string> *dump();

  Conf::ConfResult set(const std::string &name, ConsumeCb *consume_cb,
                       std::string &errstr) {
    return Conf::CONF_OK;
  }
};

class HandleImpl : virtual public Handle {
public:
  ~HandleImpl() = default;
  HandleImpl() = default;
  const std::string name() const {
    return "";
  };
  const std::string memberid() const { return nullptr; }
  int poll(int timeout_ms) {
    return 0;
  };
  int outq_len() {
    return 0;
  };

  void set_common_config(RdKafka::ConfImpl *confimpl);

  RdKafka::ErrorCode metadata(bool all_topics, const Topic *only_rkt,
                              Metadata **metadatap, int timeout_ms);

  ErrorCode pause(std::vector<TopicPartition *> &partitions);
  ErrorCode resume(std::vector<TopicPartition *> &partitions);

  ErrorCode query_watermark_offsets(const std::string &topic, int32_t partition,
                                    int64_t *low, int64_t *high,
                                    int timeout_ms) {
    return static_cast<ErrorCode>(0);
  }

  ErrorCode get_watermark_offsets(const std::string &topic, int32_t partition,
                                  int64_t *low, int64_t *high) {
    return static_cast<ErrorCode>(0);
  }

  Queue *get_partition_queue(const TopicPartition *partition);

  ErrorCode offsetsForTimes(std::vector<TopicPartition *> &offsets,
                            int timeout_ms);
  ErrorCode set_log_queue(Queue *queue);

  void yield() { // rd_kafka_yield(rk_);
  }

  const std::string clusterid(int timeout_ms) { return nullptr; }
};

class TopicImpl : virtual public Topic {
public:
  ~TopicImpl() {}

  const std::string name() const { return "fake-topic"; }

  bool partition_available(int32_t partition) const { return false; }

  ErrorCode offset_store(int32_t partition, int64_t offset) {
    return RdKafka::ERR_UNKNOWN;
  }

  static Topic *create(Handle &base, const std::string &topic, Conf *conf) {

    return new TopicImpl;
  }
};

/**
 * Metadata: Partition information handler
 */
class PartitionMetadataImpl : public RdKafka::PartitionMetadata {
public:
  // @TODO too much memory copy? maybe we should create a new vector class
  // that read directly from C arrays ?
  // @TODO use auto_ptr?
  PartitionMetadataImpl(const rd_kafka_metadata_partition_t *);

  int32_t id() const { return 0; }
  int32_t leader() const { return 0; }
  RdKafka::ErrorCode err() const { return RdKafka::ErrorCode::ERR_NO_ERROR; }

  const std::vector<int32_t> *replicas() const; // { return &replicas_; }
  const std::vector<int32_t> *isrs() const { return &isrs_; }

  ~PartitionMetadataImpl();

  // private:
  std::vector<int32_t> replicas_{ 0 }, isrs_{ 0 };
};

/**
 * Topic and Partition
 */
class TopicPartitionImpl : public TopicPartition {
public:
  ~TopicPartitionImpl() {};

  static TopicPartition *create(const std::string &topic, int partition);

  TopicPartitionImpl(const std::string &topic, int partition)
      : topic_(topic), partition_(partition) {}
  //,
  //   offset_(RdKafka::Topic::OFFSET_INVALID), err_(ERR_NO_ERROR) {}

  TopicPartitionImpl(const std::string &topic, int partition, int64_t offset)
      : topic_(topic), partition_(partition), offset_(offset),
        err_(ERR_NO_ERROR) {}

  TopicPartitionImpl(const rd_kafka_topic_partition_t *c_part) {}

  static void destroy(std::vector<TopicPartition *> &partitions);

  int partition() const { return partition_; }
  const std::string &topic() const { return topic_; }

  int64_t offset() const { return offset_; }

  ErrorCode err() const { return err_; }

  void set_offset(int64_t offset) { offset_ = offset; }

  std::ostream &operator<<(std::ostream &ostrm) const {
    return ostrm << topic_ << " [" << partition_ << "]";
  }

  std::string topic_{ "" };
  int partition_{ 0 };
  int64_t offset_{ 0 };
  ErrorCode err_;
};

class KafkaConsumerImpl : virtual public KafkaConsumer {
public:
  ~KafkaConsumerImpl() {}

  static KafkaConsumer *create(Conf *conf, std::string &errstr);

  ErrorCode assignment(std::vector<TopicPartition *> &partitions) override;
  ErrorCode subscription(std::vector<std::string> &topics) override;
  ErrorCode subscribe(const std::vector<std::string> &topics) override;
  ErrorCode unsubscribe() override;
  ErrorCode assign(const std::vector<TopicPartition *> &partitions) override;
  ErrorCode unassign() override;

  Message *consume(int timeout_ms) override;
  ErrorCode commitSync() override { return static_cast<ErrorCode>(0); }
  ErrorCode commitAsync() override { return static_cast<ErrorCode>(0); }
  ErrorCode commitSync(Message *message) override {
    return static_cast<ErrorCode>(0);
  }
  ErrorCode commitAsync(Message *message) override {
    return static_cast<ErrorCode>(0);
  }

  ErrorCode commitSync(std::vector<TopicPartition *> &offsets) override {
    return static_cast<ErrorCode>(0);
  }

  ErrorCode commitAsync(const std::vector<TopicPartition *> &offsets) override {
    return static_cast<ErrorCode>(0);
  }

  ErrorCode commitSync(OffsetCommitCb *offset_commit_cb) override {
    return static_cast<ErrorCode>(0);
  }

  ErrorCode commitSync(std::vector<TopicPartition *> &offsets,
                       OffsetCommitCb *offset_commit_cb) override {
    return static_cast<ErrorCode>(0);
  }

  ErrorCode committed(std::vector<TopicPartition *> &partitions,
                      int timeout_ms) override;
  ErrorCode position(std::vector<TopicPartition *> &partitions) override;

  ErrorCode close() override;

  ErrorCode seek(const TopicPartition &partition, int timeout_ms) override;

  ErrorCode offsets_store(std::vector<TopicPartition *> &offsets) override {
    return static_cast<ErrorCode>(0);
  }

  const std::string name() const override { return Handle.name(); }
  const std::string memberid() const override { return Handle.memberid(); }
  int poll(int timeout_ms) override { return Handle.poll(timeout_ms); }
  int outq_len() override { return Handle.outq_len(); }

  ErrorCode metadata(bool all_topics, const Topic *only_rkt,
                     Metadata **metadatap, int timeout_ms) override {
    return Handle.metadata(all_topics, only_rkt, metadatap, timeout_ms);
  }
  ErrorCode pause(std::vector<TopicPartition *> &partitions) override {
    return Handle.pause(partitions);
  }
  ErrorCode resume(std::vector<TopicPartition *> &partitions) override {
    return Handle.resume(partitions);
  }
  ErrorCode query_watermark_offsets(const std::string &topic, int32_t partition,
                                    int64_t *low, int64_t *high,
                                    int timeout_ms) override {
    return Handle.query_watermark_offsets(topic, partition, low, high,
                                          timeout_ms);
  }
  ErrorCode get_watermark_offsets(const std::string &topic, int32_t partition,
                                  int64_t *low, int64_t *high) override {
    return Handle.get_watermark_offsets(topic, partition, low, high);
  }
  ErrorCode offsetsForTimes(std::vector<TopicPartition *> &offsets,
                            int timeout_ms) override {
    return Handle.offsetsForTimes(offsets, timeout_ms);
  }
  Queue *get_partition_queue(const TopicPartition *partition) override {
    return Handle.get_partition_queue(partition);
  }
  ErrorCode set_log_queue(Queue *queue) override {
    return Handle.set_log_queue(queue);
  }
  void yield() override { return Handle.yield(); }

  const std::string clusterid(int timeout_ms) override;

private:
  HandleImpl Handle;
};

class MetadataImpl : public Metadata {
public:
  MetadataImpl(const rd_kafka_metadata_t *metadata);
  MetadataImpl();
  ~MetadataImpl();

  const std::vector<const BrokerMetadata *> *brokers() const {
    return &brokers_;
  }

  const std::vector<const TopicMetadata *> *topics() const; // { return
                                                            // &topics_; }

  const std::string orig_broker_name() const {
    return std::string(metadata_->orig_broker_name);
  }

  int32_t orig_broker_id() const { return metadata_->orig_broker_id; }

private:
  const rd_kafka_metadata_t *metadata_;
  std::vector<const BrokerMetadata *> brokers_;
  std::vector<const TopicMetadata *> topics_;
  std::string orig_broker_name_;
};

class TopicMetadataImpl : public RdKafka::TopicMetadata {
public:
  TopicMetadataImpl(const rd_kafka_metadata_topic_t *) {};

  ~TopicMetadataImpl() = default;

  const std::string topic() const { return topic_; }

  RdKafka::ErrorCode err() const { return Error; }

  const PartitionMetadataVector *partitions() const { return &partitions_; }

  // private:
  std::string topic_;
  std::vector<const RdKafka::PartitionMetadata *> partitions_;
  RdKafka::ErrorCode Error{ RdKafka::ERR_NO_ERROR };
};

// class QueueImpl : virtual public Queue {
//  public:
//   ~QueueImpl () {
//     rd_kafka_queue_destroy(queue_);
//   }
//   static Queue *create (Handle *base);
//   ErrorCode forward (Queue *queue);
//   Message *consume (int timeout_ms);
//   int poll (int timeout_ms);
//   void io_event_enable(int fd, const void *payload, size_t size);

//   rd_kafka_queue_t *queue_;
// };

//  class ConsumerImpl : virtual public Consumer, virtual public HandleImpl {
//  public:
//   ~ConsumerImpl () {
//     rd_kafka_destroy(rk_); };
//   static Consumer *create (Conf *conf, std::string &errstr);

//   ErrorCode start (Topic *topic, int32_t partition, int64_t offset);
//   ErrorCode start (Topic *topic, int32_t partition, int64_t offset,
//                    Queue *queue);
//   ErrorCode stop (Topic *topic, int32_t partition);
//   ErrorCode seek (Topic *topic, int32_t partition, int64_t offset,
//                   int timeout_ms);
//   Message *consume (Topic *topic, int32_t partition, int timeout_ms);
//   Message *consume (Queue *queue, int timeout_ms);
//   int consume_callback (Topic *topic, int32_t partition, int timeout_ms,
//                         ConsumeCb *cb, void *opaque);
//   int consume_callback (Queue *queue, int timeout_ms,
//                         RdKafka::ConsumeCb *consume_cb, void *opaque);
// };

/* class ProducerImpl : virtual public Producer, virtual public HandleImpl { */

/*  public: */
/*   ~ProducerImpl () { if (rk_) rd_kafka_destroy(rk_); }; */

/*   ErrorCode produce (Topic *topic, int32_t partition, */
/*                      int msgflags, */
/*                      void *payload, size_t len, */
/*                      const std::string *key, */
/*                      void *msg_opaque); */

/*   ErrorCode produce (Topic *topic, int32_t partition, */
/*                      int msgflags, */
/*                      void *payload, size_t len, */
/*                      const void *key, size_t key_len, */
/*                      void *msg_opaque); */

/*   ErrorCode produce (Topic *topic, int32_t partition, */
/*                      const std::vector<char> *payload, */
/*                      const std::vector<char> *key, */
/*                      void *msg_opaque); */

/*   ErrorCode produce (const std::string topic_name, int32_t partition, */
/*                      int msgflags, */
/*                      void *payload, size_t len, */
/*                      const void *key, size_t key_len, */
/*                      int64_t timestamp, */
/*                      void *msg_opaque); */

/*   ErrorCode flush (int timeout_ms) { */
/* 	  return static_cast<RdKafka::ErrorCode>(rd_kafka_flush(rk_, */
/* 								timeout_ms)); */
/*   } */

/*   static Producer *create (Conf *conf, std::string &errstr); */

/* }; */
} // namespace RdKafka
