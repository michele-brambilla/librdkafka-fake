#include <string>
#include <list>
#include <map>

#include "rdkafkacpp_int.h"
#include "utils.h"

RdKafka::ConfImpl::ConfResult RdKafka::ConfImpl::set(const std::string &name,
						     const std::string &value,
						     std::string &errstr) {
  std::pair<std::string,std::string> p({name,value});
  utils::Storage::ConfigurationOptions.push_back(p);

  rd_kafka_conf_res_t res;
  return static_cast<Conf::ConfResult>(res);
}


std::list<std::string> *RdKafka::ConfImpl::dump () {

  const char **arrc;
  size_t cnt;
  std::list<std::string> *arr;
  arr = new std::list<std::string>();
  for (auto& it: utils::Storage::ConfigurationOptions)
  arr->push_back(it.first+" : "+it.second); 

  return arr;
}

RdKafka::Conf *RdKafka::Conf::create (ConfType type) {
  ConfImpl *conf = new ConfImpl;

  return conf;
}
