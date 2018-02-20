#include "rdkafka_conf.h"
#include "rdkafka.h"

#include "definitions.h"

rd_kafka_conf_t *rd_kafka_conf_new(void) {
  if (!configurationValid()) {
    return nullptr;
  }
  return new rd_kafka_conf_t;
}

rd_kafka_conf_res_t rd_kafka_conf_set(rd_kafka_conf_t *conf, const char *name,
                                      const char *value, char *errstr,
                                      size_t errstr_size) {};