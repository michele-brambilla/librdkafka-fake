#pragma once

#include "rdkafka.h"
#include "string.h"

const size_t name_size = 32;

struct rd_kafka_conf_s {
  int log_level;
};

struct rd_kafka_s {
  rd_kafka_type_t rk_type;
  rd_kafka_conf_t *rk_conf;
  char rk_name[name_size];
};

struct rd_kafka_broker_s { /* rd_kafka_broker_t */
  int32_t rkb_nodeid;
};
typedef struct rd_kafka_broker_s rd_kafka_broker_t;