#include <rdkafkacpp_int.h>

const int64_t RdKafka::Topic::OFFSET_BEGINNING = -2;
const int64_t RdKafka::Topic::OFFSET_END = -1;
const int64_t RdKafka::Topic::OFFSET_STORED = -1000;
const int64_t RdKafka::Topic::OFFSET_INVALID = -1001;

std::string RdKafka::err2str(RdKafka::ErrorCode err) {
  return std::string(rd_kafka_err2str(static_cast<rd_kafka_resp_err_t>(err)));
}