# Usage

### Set a method (or function) Valid or Invalid

Success or failure of a ``librdkafka`` method or function can be set with the general syntax:

* ``set<Object>Valid();`` produces a success
* ``set<Object>Invalid();`` produces a failure

These functions have to be called before the method or function that in turn uess ``librdkafka``.

#### Behaviour and return value

The default behaviour is that all the methods/functions succeed in their task
Follows a list of all the available <Object>:

| Object | Affect | Description |
| --- | --- | --- |
|Configuration |``rd_kafka_conf_new`` ``Conf::create``	| If valid return a configuration, invalid return ``nullptr``	|
|ConfigurationOption |``rd_kafka_conf_set`` ``Conf::set``	| If valid the option is stored in a list and return , or ``Conf::CONF_OK``. If invalid don't accept the option and return ``RD_KAFKA_CONF_UNKNOWN`` or ``Conf::CONF_INVALID``. The function ``getConfigurationOptions`` returns the list of accepted options. |
|TopicConfSet	|	``rd_kafka_topic_conf_set``| If valid returns ``RD_KAFKA_CONF_OK``, else ``RD_KAFKA_CONF_UNKNOWN`` |
|Opaque	|``rd_kafka_opaque``	| If valid returns a pointer to ``rk->rk_conf->opaque``, else ``nullptr``|
|MetadataPointer	| ``Handle::metadata``	| If valid allocates a valid ``Metadata`` object and returns ``ERR_NO_ERROR``, else set it to ``nullptr`` and returns ``ERR_UNKNOWN``.|
|	MetadataTopic|	| |
|TopicPartition	|	|
|OffsetsForTimes	|	|
|KafkaConsumerAssign	|	|
|KafkaConsumerSubscribe	|	|
|	KafkaConsumerSubscription|	|
|	PollSetConsumer|	|
|BrokersAdd	|``rd_kafka_brokers_add``| If valid 
|KafkaNew	|``rd_kafka_new``| If valid creates and returns a new ``rd_kafka_t`` object that stores the type of object and a pointer to the ``rd_kafka_conf_t``|
|	TopicNew|``rd_kafka_topic_new``	| If valid returns a new ``rd_kafka_topic_t`` that stores a pointer to the topic name, else return ``nullptr``|

#### Utility functions

| Function | Description|
| --- | --- |
| getConfigurationOptionsSize() | |
| resetConfigurationOptions() | |
| dumpConfigurationOptionsString() | |
| getConfigurationOptions() | |
| addToConfigurationOptions(std::pair<std::string, std::string> &Opt) | |
| addBrokerMetadata(const int id, const std::string &host, const int port) | |
| addTopicMetadata(RdKafka::TopicMetadata &) | |
|addTopicPartitionMetadata(const std::string &Topic,const std::vector<int> Partition) | |
| resetTopicPartitionMetadata() | |
| getTopicPartitionMetadata() | |
| addToBrokersList(const char *broker) | |
|getBrokersList() | |
|resetBrokersList() | |
| setPollNumMessages(const int &NumMessages)| |
| getPollNumMessages() | |
| setOutqLen(const int &length)| |
| getOutqLen()| |
