#include "rdkafka_int.h"
#include "utils.h"

int rd_kafka_outq_len(rd_kafka_t *rk) { return getOutqLen(); }