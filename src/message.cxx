#include "rdkafka_int.h"
#include "utils.h"

void rd_kafka_msg_destroy(rd_kafka_t *rk, rd_kafka_msg_t *rkm) {}

int rd_kafka_msg_new(rd_kafka_itopic_t *rkt, int32_t force_partition,
                     int msgflags, char *payload, size_t len, const void *key,
                     size_t keylen, void *msg_opaque) {
  return -1;
}

int rd_kafka_produce_batch(rd_kafka_topic_t *app_rkt, int32_t partition,
                           int msgflags, rd_kafka_message_t *rkmessages,
                           int message_cnt) {
  return -1;
}

int32_t rd_kafka_msg_partitioner_random(const rd_kafka_topic_t *rkt,
                                        const void *key, size_t keylen,
                                        int32_t partition_cnt, void *rkt_opaque,
                                        void *msg_opaque) {
  return -1;
}

int32_t rd_kafka_msg_partitioner_consistent(const rd_kafka_topic_t *rkt,
                                            const void *key, size_t keylen,
                                            int32_t partition_cnt,
                                            void *rkt_opaque,
                                            void *msg_opaque) {
  return -1;
}

int32_t rd_kafka_msg_partitioner_consistent_random(
    const rd_kafka_topic_t *rkt, const void *key, size_t keylen,
    int32_t partition_cnt, void *rkt_opaque, void *msg_opaque) {
  return -1;
}

int rd_kafka_msg_partitioner(rd_kafka_itopic_t *rkt, rd_kafka_msg_t *rkm,
                             int do_lock) {
  return 0;
}

void rd_kafka_message_destroy(rd_kafka_message_t *rkmessage) {}

rd_kafka_message_t *rd_kafka_message_new(void) {
  // rd_kafka_msg_t *rkm = rd_calloc(1, sizeof(*rkm));
  return new rd_kafka_message_t;
}

rd_kafka_message_t *rd_kafka_message_setup(rd_kafka_op_t *rko,
                                           rd_kafka_message_t *rkmessage) {
  return nullptr;
}

int64_t rd_kafka_message_timestamp(const rd_kafka_message_t *rkmessage,
                                   rd_kafka_timestamp_type_t *tstype) {
  return 0;
}

int64_t rd_kafka_message_latency(const rd_kafka_message_t *rkmessage) {
  return 0;
}

int rd_kafka_poll(rd_kafka_t *rk, int timeout_ms) {
  return getPollNumMessages();
}