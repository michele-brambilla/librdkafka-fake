#include "rdkafka_int.h"
#include "utils.h"

#include <algorithm>

int rd_kafka_brokers_add(rd_kafka_t *rk, const char *brokerlist) {
  std::string list{ brokerlist };
  if (!brokersAddValid() || list.empty()) {
    return 0;
  }
  return std::count(list.begin(), list.end(), ',') + 1;
}

rd_kafka_resp_err_t rd_kafka_consumer_close(rd_kafka_t *rk) {
  if (!rk) {
    return RD_KAFKA_RESP_ERR_UNKNOWN;
  }
  return RD_KAFKA_RESP_ERR_NO_ERROR;
}

rd_kafka_message_t *rd_kafka_consumer_poll(rd_kafka_t *rk, int timeout_ms) {
  if (!getPollNumMessages()) {
    errno = ETIMEDOUT;
    return nullptr;
  }
  rd_kafka_message_t *rkmessage{ new rd_kafka_message_t };
  return rkmessage;
}

rd_kafka_resp_err_t rd_kafka_poll_set_consumer(rd_kafka_t *rk) {
  if (!pollSetConsumerValid()) {
    return RD_KAFKA_RESP_ERR__UNKNOWN_GROUP;
  }
  return RD_KAFKA_RESP_ERR_NO_ERROR;
}
