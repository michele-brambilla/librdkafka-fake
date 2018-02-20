#include "rdkafkacpp_int.h"

#include "utils.h"

RdKafka::ConfImpl::ConfResult RdKafka::ConfImpl::set(const std::string &name,
                                                     const std::string &value,
                                                     std::string &errstr) {
  if (!configurationOptionValid()) {
    errstr = "Warning: invalid option " + name + "with value " + value;
    return Conf::CONF_INVALID;
  }
  // add option to options list
  std::pair<std::string, std::string> p({ name, value });
  addToConfigurationOptions(p);
  // set no error
  errstr = "";
  return Conf::CONF_OK;
}

std::list<std::string> *RdKafka::ConfImpl::dump() {
  std::list<std::string> *arr;
  arr = new std::list<std::string>();
  for (auto &it : getConfigurationOptions())
    arr->push_back(it.first + " : " + it.second);
  return arr;
}

RdKafka::Conf *RdKafka::Conf::create(ConfType type) {
  if (!configurationValid()) {
    return nullptr;
  }
  return new ConfImpl;
}
