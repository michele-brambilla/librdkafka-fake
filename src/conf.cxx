#include "rdkafka_int.h"

#include "utils.h"

rd_kafka_conf_t *rd_kafka_conf_new(void) {
  if (!configurationValid()) {
    return nullptr;
  }
  return new rd_kafka_conf_t;
}

rd_kafka_conf_res_t rd_kafka_conf_set(rd_kafka_conf_t *conf, const char *name,
                                      const char *value, char *errstr,
                                      size_t errstr_size) {
  if (!configurationOptionValid()) {
    // return error values
    snprintf(errstr, errstr_size, "Warning: invalid option %s with value %s",
             name, value);
    return RD_KAFKA_CONF_UNKNOWN;
  }

  // add option to options list
  std::pair<std::string, std::string> p({ name, value });
  addToConfigurationOptions(p);

  // set options valid
  strncpy(errstr, "", errstr_size);
  return RD_KAFKA_CONF_OK;
};

rd_kafka_conf_res_t rd_kafka_topic_conf_set(rd_kafka_topic_conf_t *conf,
                                            const char *name, const char *value,
                                            char *errstr, size_t errstr_size) {
  if (!topicConfSetValid()) {
    return RD_KAFKA_CONF_UNKNOWN;
  }
  return RD_KAFKA_CONF_OK;
}

void rd_kafka_set_log_level(rd_kafka_t *rk, int level) {
  rk->rk_conf->log_level = level;
}

//-----------------------------------------------------------
// Callbacks
void rd_kafka_conf_set_consume_cb(
    rd_kafka_conf_t *conf,
    void (*consume_cb)(rd_kafka_message_t *rkmessage, void *opaque)) {}

void rd_kafka_conf_set_dr_msg_cb(
    rd_kafka_conf_t *conf,
    void (*dr_msg_cb)(rd_kafka_t *rk, const rd_kafka_message_t *rkmessage,
                      void *opaque)) {}

void rd_kafka_conf_set_error_cb(rd_kafka_conf_t *conf,
                                void (*error_cb)(rd_kafka_t *rk, int err,
                                                 const char *reason,
                                                 void *opaque)) {}

void rd_kafka_conf_set_log_cb(rd_kafka_conf_t *conf,
                              void (*log_cb)(const rd_kafka_t *rk, int level,
                                             const char *fac,
                                             const char *buf)) {}

void rd_kafka_conf_set_rebalance_cb(
    rd_kafka_conf_t *conf,
    void (*rebalance_cb)(rd_kafka_t *rk, rd_kafka_resp_err_t err,
                         rd_kafka_topic_partition_list_t *partitions,
                         void *opaque)) {}

void rd_kafka_conf_set_stats_cb(rd_kafka_conf_t *conf,
                                int (*stats_cb)(rd_kafka_t *rk, char *json,
                                                size_t json_len,
                                                void *opaque)) {}

void rd_kafka_conf_set_opaque(rd_kafka_conf_t *conf, void *opaque) {}

void rd_kafka_conf_set_throttle_cb(rd_kafka_conf_t *conf,
                                   void (*throttle_cb)(rd_kafka_t *rk,
                                                       const char *broker_name,
                                                       int32_t broker_id,
                                                       int throttle_time_ms,
                                                       void *opaque)) {}
//-----------------------------------------------------------------