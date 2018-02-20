/// \file definitions.h
/// \brief Fake implementation of the Apache Kafka C/C++ consumer and producer
/// client library.
///
///	This file contains the functions that allow to query or modify the
/// return value or status of the fake classes

#include <stddef.h>
#include <string>
#include <vector>

namespace RdKafka {
class TopicMetadata;
}

/// @defgroup Configuration RdKafka::Configuration
//  This is the first group
///  @{

/// \brief      Make Conf::create returns a valid configuration
/// \return
void setConfigurationValid();

/// \brief      Make Conf::create returns an invalid configuration (empty
/// pointer)
/// \return
void setConfigurationInvalid();

/// \brief      Return the validity of the configuration
///
/// \return     true if the configuration is valid, else false.
/// \remarks    Default is true
///
bool configurationValid();

/// \brief      Mark the option passed to the Configuration as valid
/// \return
void setConfigurationOptionValid();

/// \brief      Mark the option passed to the Configuration as invalid
/// \return
void setConfigurationOptionInvalid();

/// \brief      Query the validity of the option
///
/// \return     true if the option is valid, else false
/// \remarks    Default is true
bool configurationOptionValid();

/// \brief      Gets the number of Kafka options that have been configured.
///
/// \return     The configuration options size.
///
size_t getConfigurationOptionsSize();

/// \brief      Reset the configuration options
/// \return
void resetConfigurationOptions();

/// \brief      Returns the configuration options
/// \return		A string containing the list of (option,value)
std::string dumpConfigurationOptions();
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
void setTopicPartitionValid();
void setTopicPartitionInvalid();
bool topicPartitionValid();

void setOffsetsForTimesValid();
void setOffsetsForTimesInvalid();
bool offsetsForTimesValid();

void setKafkaConsumerAssignValid();
void setKafkaConsumerAssignInvalid();
bool kafkaConsumerAssignValid();