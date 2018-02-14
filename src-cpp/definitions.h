#include <stddef.h>
#include <string>

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

void setTopicMetadataTopic(void *, const std::string &);
void addTopicMetadataPartitionMetadata();
