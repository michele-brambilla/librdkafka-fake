/// \file definitions.h
/// \brief Fake implementation of the Apache Kafka C/C++ consumer and producer
/// client library.
///
///	This file contains the functions that allow to query or modify the
/// return value or status of the fake classes

#include <stddef.h>
#include <string>
#include <vector>
#include <list>

namespace RdKafka {
class TopicMetadata;
}

/// @defgroup Configuration RdKafka::Configuration
//  This is the first group
///  @{

/// @brief      Make Conf::create returns a valid configuration
/// @return
void setConfigurationValid();

/// @brief      Make Conf::create returns an invalid configuration (empty
/// pointer)
/// @return
void setConfigurationInvalid();

/// @brief      Return the validity of the configuration
///
/// @return     true if the configuration is valid, else false.
/// @remarks    Default is true
bool configurationValid();

/// @brief      Mark the option passed to the Configuration as valid
/// @return
void setConfigurationOptionValid();

/// @brief      Mark the option passed to the Configuration as invalid
/// @return
void setConfigurationOptionInvalid();

/// @brief      Returns the validity of the option
///
/// @return     true if the option is valid, else false
/// @remarks    Default is true
bool configurationOptionValid();

/// @brief      Gets the number of Kafka options that have been configured.
///
/// @return     The configuration options size.
///
size_t getConfigurationOptionsSize();

/// @brief      Reset the configuration options
/// @return
void resetConfigurationOptions();

/// @brief      Returns the configuration options
/// @return		A string containing the list of (option,value)
std::string dumpConfigurationOptionsString();

//------------------------------------------------------------------------------
/// @brief      Returns the list of configuration options
///
/// @return     A reference to the list of configuration options.
///
const std::list<std::pair<std::string, std::string> > &
getConfigurationOptions();

//------------------------------------------------------------------------------
/// @brief      Adds to options to configuration list.
///
/// @param      Opt   The option
///
void addToConfigurationOptions(std::pair<std::string, std::string> &Opt);

void setTopicConfSetValid();
void setTopicConfSetInvalid();
bool topicConfSetValid();

//------------------------------------------------------------------------------
/// @brief      Sets the rd_kafka_opaque valid.
///
void setOpaqueValid();

//------------------------------------------------------------------------------
/// @brief      Sets the rd_kafka_opaque invalid.
///
void setOpaqueInvalid();

//------------------------------------------------------------------------------
/// @brief      Retruns the validity of rd_kafka_opaque
///
/// @return     true if valid, else false
/// @remarks    Default is valid
bool opaqueValid();

/// @}

void addBrokerMetadata(const int id, const std::string &host, const int port);
void addTopicMetadata();

void setMetadataPointerValid();
void setMetadataPointerInvalid();
bool metadataPointerValid();

void setMetadataReturnValueOk();
void setMetadataReturnValueError();
int getMetadataReturnValue();

void setMetadataTopicInvalid();
void setMetadataTopicValid();
bool metadataTopicValid();

void addTopicMetadata(RdKafka::TopicMetadata &);
void addTopicPartitionMetadata(const std::string &Topic,
                               const std::vector<int> Partition);
void resetTopicPartitionMetadata();

/// @brief      Returns the number of TopicPartition present.
///
/// @return     The number of TopicPartition in Metadata.
///
size_t getTopicPartitionMetadataSize();
//------------------------------------------------------------------------------
/// @brief      Gets a reference to the vector of TopicMetadata.
///
/// @return     The topic partition metadata.
///
const std::vector<const RdKafka::TopicMetadata *> &getTopicPartitionMetadata();
void setTopicPartitionValid();
void setTopicPartitionInvalid();
bool topicPartitionValid();

void setOffsetsForTimesValid();
void setOffsetsForTimesInvalid();
bool offsetsForTimesValid();

//------------------------------------------------------------------------------
// KafkaConsumer

void setKafkaConsumerAssignValid();
void setKafkaConsumerAssignInvalid();
bool kafkaConsumerAssignValid();

//------------------------------------------------------------------------------
/// @brief      Sets rd_kafka_subscribe.succeed
///
void setKafkaConsumerSubscribeValid();
//------------------------------------------------------------------------------
/// @brief      Sets rd_kafka_subscribe fail
///
void setKafkaConsumerSubscribeInvalid();
//------------------------------------------------------------------------------
/// @brief      Return the success or failure of rd_kafka_subscribe
///
/// @return     true if succeed, else false
/// @remark     Defautl is succeed
bool kafkaConsumerSubscribeValid();

//------------------------------------------------------------------------------
/// @brief      Sets rd_kafka_subscription.succeed
///
void setKafkaConsumerSubscriptionValid();
//------------------------------------------------------------------------------
/// @brief      Sets rd_kafka_subscription fail
///
void setKafkaConsumerSubscriptionInvalid();
//------------------------------------------------------------------------------
/// @brief      Return the success or failure of rd_kafka_subscription
///
/// @return     true if succeed, else false
/// @remark     Defautl is succeed
bool kafkaConsumerSubscriptionValid();

/// @brief      Sets rd_kafka_poll_set_consumer valid.
///
void setPollSetConsumerValid();
//------------------------------------------------------------------------------
/// @brief      Sets rd_kafka_poll_set_consumer invalid.
///
void setPollSetConsumerInvalid();
//------------------------------------------------------------------------------
/// @brief      Return the validity of rd_kafka_poll_set_consumer
///
/// @return     true if valid, else false
/// @remark     Default is valid
bool pollSetConsumerValid();

//------------------------------------------------------------------------------
/// @brief      Sets brokers_add valid.
///
void setBrokersAddValid();

/// @brief      Sets brokers_add invalid.
///
void setBrokersAddInvalid();

/// @brief      Returns the validity of brokers_add
///
/// @return     true if the brokers are valid, else false
/// @remark    	Default is true
bool brokersAddValid();

/// @brief      Adds the broker to BrokersList.
///
/// @param[in]  broker  The broker to be added
///
void addToBrokersList(const char *broker);

/// @brief      Gets the list of registered brokers.
///
/// @return     The list of brokers.
///
const std::list<std::string> &getBrokersList();

/// @brief      Remove all the brokers from BrokersList
///
void resetBrokersList();

/// @brief      Sets the new instance of producer or consumer valid.
///
void setKafkaNewValid();

/// @brief      Sets the new instance of producer or consumer invalid.
///
void setKafkaNewInvalid();

/// @brief      Returns the validity of the new instance of producer or consumer
///
/// @return     true if the producer or consumer is valid, else false
/// @remark    	Default is true
bool kafkaNewValid();

void setTopicNewValid();
void setTopicNewInvalid();
bool topicNewValid();

//------------------------------------------------------------------------------
/// @brief      Sets count of messages  that rd_kafka_poll returns
///
/// @param[in]  NumMessages  The messages count
///
void setPollNumMessages(const int &NumMessages);
//------------------------------------------------------------------------------
/// @brief      Returns the number of messages that rd_kafka_poll counts
///
/// @return     The number of messages.
/// @remark     default is 0
int getPollNumMessages();

//------------------------------------------------------------------------------
/// @brief      Sets the number of messages in the output queue
///
/// @param[in]  length  The number of messages
///
void setOutqLen(const int &length);
//------------------------------------------------------------------------------
/// @brief      Gets the number of messages in the output queue
///
/// @return     The number of messages
/// @remark     Default is 0
int getOutqLen();