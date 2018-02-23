# Usage

### Set a method (or function) Valid or Invalid

Success or failure of a ``librdkafka`` method or function can be set with the general syntax:

* ``set[Object]Valid();`` produces a success
* ``set[Object]Invalid();`` produces a failure

These functions have to be called before the method or function that in turn uess ``librdkafka``.

#### Behaviour and return value

The default behaviour is that all the methods/functions succeed in their task.

Here a list of all the available [Object]s

| Object | Affect | Description |
| --- | --- | --- |
|Configuration |``rd_kafka_conf_new`` ``Conf::create``	| If valid return a configuration, invalid return ``nullptr``.	|
|ConfigurationOption |``rd_kafka_conf_set`` ``Conf::set``	| If valid the option is stored in a list and return , or ``Conf::CONF_OK``. If invalid don't accept the option and return ``RD_KAFKA_CONF_UNKNOWN`` or ``Conf::CONF_INVALID``. The function ``getConfigurationOptions`` returns the list of accepted options. |
|TopicConfSet	|	``rd_kafka_topic_conf_set``| If valid returns ``RD_KAFKA_CONF_OK``, else ``RD_KAFKA_CONF_UNKNOWN``. |
|Opaque	|``rd_kafka_opaque``	| If valid returns a pointer to ``rk->rk_conf->opaque``, else ``nullptr``.|
|MetadataPointer	| ``Handle::metadata``	| If valid allocates a valid ``Metadata`` object and returns ``ERR_NO_ERROR``, else set it to ``nullptr`` and returns ``ERR_UNKNOWN``.|
|TopicPartition	|``rd_kafka_topic_partition_new`` ``rd_kafka_topic_partition_list_new`` ``rd_kafka_topic_partition_list_add`` ``TopicPartition::create`` | If valid returns a valid object, else ``nullptr``.|
|OffsetsForTimes	|``Handle::offsetsForTimes``| If valid returns ``ERR_NO_ERROR``, else ``ERR__TIMED_OUT``.|
|KafkaConsumerAssign	|``rd_kafka_assign`` ``KafkaConsumer::assign``	| If valid returns ``RD_KAFKA_RESP_ERR_NO_ERROR``,``ERR_NO_ERROR`` else ``RD_KAFKA_RESP_ERR__ASSIGN_PARTITIONS``, ``ERR__ASSIGN_PARTITIONS``. |
|KafkaConsumerSubscribe	|``rd_kafka_subscribe``	| If valid returns ``RD_KAFKA_RESP_ERR_NO_ERROR`` else ``RD_KAFKA_RESP_ERR__TIMED_OUT``.|
|	KafkaConsumerSubscription|``rd_kafka_subscription``	|If valid returns ``RD_KAFKA_RESP_ERR_NO_ERROR`` else ``RD_KAFKA_RESP_ERR__TIMED_OUT``.|
|	PollSetConsumer|	``rd_kafka_poll_set_consumer``| If valid returns ``RD_KAFKA_RESP_ERR_NO_ERROR`` else ``RD_KAFKA_RESP_ERR__UNKNOWN_GROUP``.|
|KafkaNew	|``rd_kafka_new``| If valid creates and returns a new ``rd_kafka_t`` object that stores the type of object and a pointer to the ``rd_kafka_conf_t``|
|	TopicNew|``rd_kafka_topic_new``	| If valid returns a new ``rd_kafka_topic_t`` that stores a pointer to the topic name, else return ``nullptr``|

#### Utility functions

| Function | Description|
| --- | --- |
| getConfigurationOptionsSize() | Returns the number of valid options that have been set. |
| resetConfigurationOptions() | Delete all the configuration options. |
| dumpConfigurationOptionsString() | Returns a string containing all the options in the form *key : value*. |
| getConfigurationOptions() | Returns the list of onfigured options in the form of pairs *key : value*. |
| addToConfigurationOptions(std::pair<std::string, std::string> &Opt) | Adds a new option. |
|addTopicPartitionMetadata(const std::string &Topic,const std::vector<int> Partition) | |
| resetTopicPartitionMetadata() | Removes all the TopicPartition present in the Metadata.|
| getTopicPartitionMetadata() | Returns the vector of TopicPartition stored in the Metadata. |
| addToBrokersList(const char *broker) | Adds the brokers listed in the argument, comma separated, to the brokers list. |
|getBrokersList() | Returns the list of brokers. |
|resetBrokersList() | Remova all the elements from the brokers list. |
| setPollNumMessages(const int &NumMessages)| Sets the number of messages that poll returns |
| getPollNumMessages() | Returns the number of messages that poll returns. |
| setOutqLen(const int &length)| Set the length of the output queue. |
| getOutqLen()| Returns the length of the output message queue. |
