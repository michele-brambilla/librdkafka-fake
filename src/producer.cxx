#include "rdkafka_int.h"
#include "utils.h"

int rd_kafka_outq_len(rd_kafka_t *rk) { return getOutqLen(); }

int rd_kafka_produce(rd_kafka_topic_t *rkt, int32_t partition, int msgflags,
                     void *payload, size_t len, const void *key, size_t keylen,
                     void *msg_opaque) {
  return rd_kafka_msg_new((rd_kafka_itopic_t *)rkt, partition, msgflags,
                          (char *)payload, len, key, keylen, msg_opaque);
}