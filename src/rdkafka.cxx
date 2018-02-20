#include "rdkafka_int.h"
#include "utils.h"

const char *rd_kafka_name(const rd_kafka_t *rk) { return rk->rk_name; }

rd_kafka_t *rd_kafka_new(rd_kafka_type_t type, rd_kafka_conf_t *conf,
                         char *errstr, size_t errstr_size) {
  if (!conf) {
    strncpy(errstr, "Invalid configuration", errstr_size);
    return nullptr;
  }
  if (!kafkaConsumerValid()) {
    strncpy(errstr, "Invalid consumer", errstr_size);
    return nullptr;
  }
  // set no error
  strncpy(errstr, "", errstr_size);
  // store minimal informations
  rd_kafka_t *rk = new rd_kafka_t;
  rk->rk_conf = conf;
  rk->rk_type = type;

  return rk;
}

void rd_kafka_destroy(rd_kafka_t *rk) {
  if (rk) {
    delete rk;
  }
}