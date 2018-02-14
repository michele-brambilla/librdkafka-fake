#include <iostream>
#include <string>
#include <list>

#include "utils.h"

  RdKafka::Topic::~Topic() {}
// void RdKafka::consume_cb_trampoline(rd_kafka_message_t *msg, void *opaque) {
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);
//   RdKafka::Topic* topic = static_cast<Topic *>(rd_kafka_topic_opaque(msg->rkt));

//   RdKafka::MessageImpl message(topic, msg, false /*don't free*/);

//   handle->consume_cb_->consume_cb(message, opaque);
// }

// void RdKafka::log_cb_trampoline (const rd_kafka_t *rk, int level,
//                                  const char *fac, const char *buf) {
//   if (!rk) {
//     rd_kafka_log_print(rk, level, fac, buf);
//     return;
//   }

//   void *opaque = rd_kafka_opaque(rk);
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);

//   if (!handle->event_cb_) {
//     rd_kafka_log_print(rk, level, fac, buf);
//     return;
//   }

//   RdKafka::EventImpl event(RdKafka::Event::EVENT_LOG,
//                            RdKafka::ERR_NO_ERROR,
//                            static_cast<RdKafka::Event::Severity>(level),
//                            fac, buf);

//   handle->event_cb_->event_cb(event);
// }


// void RdKafka::error_cb_trampoline (rd_kafka_t *rk, int err,
//                                    const char *reason, void *opaque) {
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);

//   RdKafka::EventImpl event(RdKafka::Event::EVENT_ERROR,
//                            static_cast<RdKafka::ErrorCode>(err),
//                            RdKafka::Event::EVENT_SEVERITY_ERROR,
//                            NULL,
//                            reason);

//   handle->event_cb_->event_cb(event);
// }


// void RdKafka::throttle_cb_trampoline (rd_kafka_t *rk, const char *broker_name,
// 				      int32_t broker_id,
// 				      int throttle_time_ms,
// 				      void *opaque) {
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);

//   RdKafka::EventImpl event(RdKafka::Event::EVENT_THROTTLE);
//   event.str_ = broker_name;
//   event.id_ = broker_id;
//   event.throttle_time_ = throttle_time_ms;

//   handle->event_cb_->event_cb(event);
// }


// int RdKafka::stats_cb_trampoline (rd_kafka_t *rk, char *json, size_t json_len,
//                                   void *opaque) {
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);

//   RdKafka::EventImpl event(RdKafka::Event::EVENT_STATS,
//                            RdKafka::ERR_NO_ERROR,
//                            RdKafka::Event::EVENT_SEVERITY_INFO,
//                            NULL, json);

//   handle->event_cb_->event_cb(event);

//   return 0;
// }


// int RdKafka::socket_cb_trampoline (int domain, int type, int protocol,
//                                    void *opaque) {
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);

//   return handle->socket_cb_->socket_cb(domain, type, protocol);
// }

// int RdKafka::open_cb_trampoline (const char *pathname, int flags, mode_t mode,
//                                  void *opaque) {
//   RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);

//   return handle->open_cb_->open_cb(pathname, flags, static_cast<int>(mode));
// }


RdKafka::ErrorCode RdKafka::HandleImpl::metadata (bool all_topics,
                                                  const Topic *only_rkt,
                                                  Metadata **metadatap, 
                                                  int timeout_ms) {

  if(metadataPointerValid()) {
    *metadatap = new MetadataImpl(nullptr);
  } else {
    *metadatap = nullptr;
  }

  // RdKafka::Conf* conf;
  // if(metadataTopicValid()) {
  //   only_rkt = TopicImpl::create(*this,"",conf);
  //   std::cout << "metadata_topic_is_valid : " << only_rkt << "\n";
  // } else {
  //   std::cout << "metadata_topic_is_invalid\n";
  //   only_rkt = nullptr;
  // }

  return ErrorCode(getMetadataReturnValue());
}

/**
 * Convert a list of C partitions to C++ partitions
 */
// static void c_parts_to_partitions (const rd_kafka_topic_partition_list_t
//                                    *c_parts,
//                                    std::vector<RdKafka::TopicPartition*>
//                                    &partitions) {
//   // partitions.resize(c_parts->cnt);
//   // for (int i = 0 ; i < c_parts->cnt ; i++)
//   //   partitions[i] = new RdKafka::TopicPartitionImpl(&c_parts->elems[i]);
// }

// static void free_partition_vector (std::vector<RdKafka::TopicPartition*> &v) {
//   // for (unsigned int i = 0 ; i < v.size() ; i++)
//   //   delete v[i];
//   // v.clear();
// }

// void
// RdKafka::rebalance_cb_trampoline (rd_kafka_t *rk,
//                                   rd_kafka_resp_err_t err,
//                                   rd_kafka_topic_partition_list_t *c_partitions,
//                                   void *opaque) {
//   // RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);
//   // std::vector<RdKafka::TopicPartition*> partitions;

//   // c_parts_to_partitions(c_partitions, partitions);

//   // handle->rebalance_cb_->rebalance_cb(
//   // 				      dynamic_cast<RdKafka::KafkaConsumer*>(handle),
//   // 				      static_cast<RdKafka::ErrorCode>(err),
//   // 				      partitions);

//   // free_partition_vector(partitions);
// }


// void
// RdKafka::offset_commit_cb_trampoline0 (
//     rd_kafka_t *rk,
//     rd_kafka_resp_err_t err,
//     rd_kafka_topic_partition_list_t *c_offsets, void *opaque) {
//   // OffsetCommitCb *cb = static_cast<RdKafka::OffsetCommitCb *>(opaque);
//   // std::vector<RdKafka::TopicPartition*> offsets;

//   // if (c_offsets)
//   //   c_parts_to_partitions(c_offsets, offsets);

//   // cb->offset_commit_cb(static_cast<RdKafka::ErrorCode>(err), offsets);

//   // free_partition_vector(offsets);
// }

// static void
// offset_commit_cb_trampoline (
//     rd_kafka_t *rk,
//     rd_kafka_resp_err_t err,
//     rd_kafka_topic_partition_list_t *c_offsets, void *opaque) {
//   // RdKafka::HandleImpl *handle = static_cast<RdKafka::HandleImpl *>(opaque);
//   // RdKafka::offset_commit_cb_trampoline0(rk, err, c_offsets,
//   //                                       handle->offset_commit_cb_);
// }


void RdKafka::HandleImpl::set_common_config (RdKafka::ConfImpl *confimpl) {

//   rd_kafka_conf_set_opaque(confimpl->rk_conf_, this);

//   if (confimpl->event_cb_) {
//     rd_kafka_conf_set_log_cb(confimpl->rk_conf_,
//                              RdKafka::log_cb_trampoline);
//     rd_kafka_conf_set_error_cb(confimpl->rk_conf_,
//                                RdKafka::error_cb_trampoline);
//     rd_kafka_conf_set_throttle_cb(confimpl->rk_conf_,
// 				  RdKafka::throttle_cb_trampoline);
//     rd_kafka_conf_set_stats_cb(confimpl->rk_conf_,
//                                RdKafka::stats_cb_trampoline);
//     event_cb_ = confimpl->event_cb_;
//   }

//   if (confimpl->socket_cb_) {
//     rd_kafka_conf_set_socket_cb(confimpl->rk_conf_,
//                                 RdKafka::socket_cb_trampoline);
//     socket_cb_ = confimpl->socket_cb_;
//   }

//   if (confimpl->open_cb_) {
// #ifndef _MSC_VER
//     rd_kafka_conf_set_open_cb(confimpl->rk_conf_, RdKafka::open_cb_trampoline);
//     open_cb_ = confimpl->open_cb_;
// #endif
//   }

//   if (confimpl->rebalance_cb_) {
//     rd_kafka_conf_set_rebalance_cb(confimpl->rk_conf_,
//                                    RdKafka::rebalance_cb_trampoline);
//     rebalance_cb_ = confimpl->rebalance_cb_;
//   }

//   if (confimpl->offset_commit_cb_) {
//     rd_kafka_conf_set_offset_commit_cb(confimpl->rk_conf_,
//                                        offset_commit_cb_trampoline);
//     offset_commit_cb_ = confimpl->offset_commit_cb_;
//   }

//   if (confimpl->consume_cb_) {
//     rd_kafka_conf_set_consume_cb(confimpl->rk_conf_,
//                                  RdKafka::consume_cb_trampoline);
//     consume_cb_ = confimpl->consume_cb_;
//   }

}


RdKafka::ErrorCode
RdKafka::HandleImpl::pause (std::vector<RdKafka::TopicPartition*> &partitions) {
  // rd_kafka_topic_partition_list_t *c_parts;
  // rd_kafka_resp_err_t err;

  // c_parts = partitions_to_c_parts(partitions);

  // err = rd_kafka_pause_partitions(rk_, c_parts);

  // if (!err)
  //   update_partitions_from_c_parts(partitions, c_parts);

  // rd_kafka_topic_partition_list_destroy(c_parts);

  // return static_cast<RdKafka::ErrorCode>(err);
  return static_cast<RdKafka::ErrorCode>(0);
}


RdKafka::ErrorCode
RdKafka::HandleImpl::resume (std::vector<RdKafka::TopicPartition*> &partitions) {
  // rd_kafka_topic_partition_list_t *c_parts;
  // rd_kafka_resp_err_t err;

  // c_parts = partitions_to_c_parts(partitions);

  // err = rd_kafka_resume_partitions(rk_, c_parts);

  // if (!err)
  //   update_partitions_from_c_parts(partitions, c_parts);

  // rd_kafka_topic_partition_list_destroy(c_parts);

  // return static_cast<RdKafka::ErrorCode>(err);
  return static_cast<RdKafka::ErrorCode>(0);
}

RdKafka::Queue *
RdKafka::HandleImpl::get_partition_queue (const TopicPartition *part) {
  // rd_kafka_queue_t *rkqu;
  // rkqu = rd_kafka_queue_get_partition(rk_,
  //                                     part->topic().c_str(),
  //                                     part->partition());

  // if (rkqu == NULL)
  //   return NULL;

  // RdKafka::QueueImpl *queueimpl = new RdKafka::QueueImpl;
  // queueimpl->queue_ = rkqu;

  // return queueimpl;
  return nullptr;
}

RdKafka::ErrorCode
RdKafka::HandleImpl::set_log_queue (RdKafka::Queue *queue) {
        // rd_kafka_queue_t *rkqu = NULL;
        // if (queue) {
        //         QueueImpl *queueimpl = dynamic_cast<QueueImpl *>(queue);
        //         rkqu = queueimpl->queue_;
        // }
        // return static_cast<RdKafka::ErrorCode>(
        //         rd_kafka_set_log_queue(rk_, rkqu));
  return static_cast<RdKafka::ErrorCode>(0);
}

namespace RdKafka {

// rd_kafka_topic_partition_list_t *
// partitions_to_c_parts (const std::vector<RdKafka::TopicPartition*> &partitions){
//   rd_kafka_topic_partition_list_t *c_parts;

//   c_parts = rd_kafka_topic_partition_list_new((int)partitions.size());

//   for (unsigned int i = 0 ; i < partitions.size() ; i++) {
//     const RdKafka::TopicPartitionImpl *tpi =
//         dynamic_cast<const RdKafka::TopicPartitionImpl*>(partitions[i]);
//     rd_kafka_topic_partition_t *rktpar =
//       rd_kafka_topic_partition_list_add(c_parts,
// 					tpi->topic_.c_str(), tpi->partition_);
//     rktpar->offset = tpi->offset_;
//   }

//   return c_parts;
// }


// /**
//  * @brief Update the application provided 'partitions' with info from 'c_parts'
//  */
// void
// update_partitions_from_c_parts (std::vector<RdKafka::TopicPartition*> &partitions,
// 				const rd_kafka_topic_partition_list_t *c_parts) {
//   for (int i = 0 ; i < c_parts->cnt ; i++) {
//     rd_kafka_topic_partition_t *p = &c_parts->elems[i];

//     /* Find corresponding C++ entry */
//     for (unsigned int j = 0 ; j < partitions.size() ; j++) {
//       RdKafka::TopicPartitionImpl *pp =
// 	dynamic_cast<RdKafka::TopicPartitionImpl*>(partitions[j]);
//       if (!strcmp(p->topic, pp->topic_.c_str()) &&
// 	  p->partition == pp->partition_) {
// 	pp->offset_ = p->offset;
// 	pp->err_ = static_cast<RdKafka::ErrorCode>(p->err);
//       }
//     }
//   }
// }

};

