#include "rdkafka_int.h"
#include "utils.h"

#include <algorithm>
#include <iostream>

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