#pragma once

#include "rdkafka.h"
#include "string.h"

const size_t name_size = 32;

typedef int64_t rd_ts_t;

struct rd_kafka_conf_s {
  int log_level;
  void *opaque = (void *)0x01;
};

typedef struct rd_kafka_s {
  rd_kafka_type_t rk_type;
  rd_kafka_conf_t *rk_conf;
  char rk_name[name_size];
} rd_kafka_t;

typedef struct rd_kafka_broker_s { /* rd_kafka_broker_t */
  int32_t rkb_nodeid;
} rd_kafka_broker_t;

typedef struct rd_kafka_msg_s {
  rd_kafka_message_t rkm_rkmessage;
} rd_kafka_msg_t;

typedef struct rd_kafka_itopic_s {
  rd_kafka_t *rkt_rk;
} rd_kafka_itopic_t;

struct rd_kafka_topic_s {
  rd_kafka_t *rkt_rk;
  char *rk_topic_name;
};

typedef struct rd_kafka_op_s {
  void *empty;
} rd_kafka_op_t;

typedef struct rd_list_s {
  int rl_size;
  int rl_cnt;
  void **rl_elems;
  void (*rl_free_cb)(void *);
  int rl_flags;
#define RD_LIST_F_ALLOCATED 0x1
#define RD_LIST_F_SORTED 0x2
#define RD_LIST_F_FIXED_SIZE 0x4
#define RD_LIST_F_UNIQUE 0x8
} rd_list_t;