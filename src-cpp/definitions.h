
size_t getConfigurationOptionsSize();

void setMetadataPointerValid();
void setMetadataPointerInvalid();
bool metadataPointerValid();
void setMetadataReturnValueOk();
void setMetadataReturnValueError();
int getMetadataReturnValue();
void setMetadataTopicInvalid();
void setMetadataTopicValid();
bool metadataTopicValid();

class TopicMetadataImpl;
void setTopicMetadataTopic(TopicMetadataImpl *, const std::string &);
void addTopicMetadataPartitionMetadata();
