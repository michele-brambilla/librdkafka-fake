#include "rdkafkacpp_int.h"
#include "utils.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(consumer,create_new_consumer) {
	std::string ErrorString;
	RdKafka::Conf* Configuration = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);	
    RdKafka::KafkaConsumerImpl* Consumer = RdKafka::KafkaConsumerImpl::create(Configuration, ErrorString);


}