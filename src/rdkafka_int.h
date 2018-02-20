#pragma once

struct rd_kafka_conf_s {
  int log_level;
} sasl;

struct rd_kafka_s {
  rd_kafka_conf_t rk_conf;
};