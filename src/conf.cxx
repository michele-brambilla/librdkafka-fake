#include "rdkafka_conf.h"
#include "rdkafka.h"

#include "utils.h"

#include "string.h"

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
  Storage::ConfigurationOptions.push_back(p);

  // set options valid
  strncpy(errstr, "", errstr_size);
  return RD_KAFKA_CONF_OK;
};