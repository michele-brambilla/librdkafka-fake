#include "rdkafka_int.h"
#include "utils.h"

const char *rd_kafka_name(const rd_kafka_t *rk) { return rk->rk_name; }

rd_kafka_t *rd_kafka_new(rd_kafka_type_t type, rd_kafka_conf_t *conf,
                         char *errstr, size_t errstr_size) {
  if (!conf) {
    strncpy(errstr, "Invalid configuration", errstr_size);
    return nullptr;
  }
  if (!kafkaNewValid()) {
    strncpy(errstr, "Invalid producer or consumer", errstr_size);
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

void *rd_kafka_opaque(const rd_kafka_t *rk) {
  if (!opaqueValid()) {
    return nullptr;
  }
  return rk->rk_conf->opaque;
}

void rd_kafka_dump(FILE *fp, rd_kafka_t *rk) {}