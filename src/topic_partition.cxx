#include "rdkafka_int.h"
#include "utils.h"

//////////////////////////
// Partition

rd_kafka_resp_err_t
rd_kafka_assign(rd_kafka_t *rk, const rd_kafka_topic_partition_list_t *plist) {
  if (!kafkaConsumerAssignValid() || !plist) {
    return RD_KAFKA_RESP_ERR__ASSIGN_PARTITIONS;
  }
  return RD_KAFKA_RESP_ERR_NO_ERROR;
}

//////////////////////////
// Topic

const char *rd_kafka_topic_state_names[] = { "unknown", "exists", "notexists" };

int rd_kafka_topic_metadata_update(rd_kafka_itopic_t *rkt,
                                   const struct rd_kafka_metadata_topic *mdt,
                                   rd_ts_t ts_insert) {
  return -1;
}

void rd_kafka_topic_destroy(rd_kafka_topic_t *app_rkt) {
  // rd_kafka_topic_destroy_app(app_rkt);
}

int rd_kafka_topic_cmp_s_rkt(const void *_a, const void *_b) { return 0; }

rd_kafka_topic_t *rd_kafka_topic_new(rd_kafka_t *rk, const char *topic,
                                     rd_kafka_topic_conf_t *conf) {
  if (!topicNewValid()) {
    return nullptr;
  }
  return new rd_kafka_topic_t;
}

const char *rd_kafka_topic_name(const rd_kafka_topic_t *app_rkt) {
  // return rkt->rkt_topic->str;
  return nullptr;
}

int rd_kafka_topic_partition_cnt_update(rd_kafka_itopic_t *rkt,
                                        int32_t partition_cnt) {
  return -1;
}

void rd_kafka_topic_metadata_none(rd_kafka_itopic_t *rkt) {}

rd_list_t *rd_kafka_topic_get_all_partitions(rd_kafka_itopic_t *rkt) {
  return nullptr;
}

int rd_kafka_topic_partition_available(const rd_kafka_topic_t *app_rkt,
                                       int32_t partition) {
  return -1;
}

void *rd_kafka_topic_opaque(const rd_kafka_topic_t *app_rkt) {
  // return rd_kafka_topic_a2i(app_rkt)->rkt_conf.opaque;
  return nullptr;
}
