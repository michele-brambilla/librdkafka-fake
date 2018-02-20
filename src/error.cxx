#include "rdkafka.h"

#define _ERR_DESC(ENUM, DESC)                                                  \
  [ENUM - RD_KAFKA_RESP_ERR__BEGIN] = { ENUM, #ENUM + 18 /*pfx*/, DESC }

// static const struct rd_kafka_err_desc rd_kafka_err_descs[] = {
//   _ERR_DESC(RD_KAFKA_RESP_ERR__BEGIN, NULL),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__BAD_MSG, "Local: Bad message format"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__BAD_COMPRESSION,
//             "Local: Invalid compressed data"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__DESTROY, "Local: Broker handle destroyed"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__FAIL,
//             "Local: Communication failure with broker"), // FIXME: too
// specific
//   _ERR_DESC(RD_KAFKA_RESP_ERR__TRANSPORT, "Local: Broker transport failure"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__CRIT_SYS_RESOURCE,
//             "Local: Critical system resource failure"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__RESOLVE, "Local: Host resolution failure"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__MSG_TIMED_OUT, "Local: Message timed out"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__PARTITION_EOF, "Broker: No more messages"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__UNKNOWN_PARTITION, "Local: Unknown
// partition"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__FS, "Local: File or filesystem error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__UNKNOWN_TOPIC, "Local: Unknown topic"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__ALL_BROKERS_DOWN,
//             "Local: All broker connections are down"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__INVALID_ARG,
//             "Local: Invalid argument or configuration"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__TIMED_OUT, "Local: Timed out"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__QUEUE_FULL, "Local: Queue full"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__ISR_INSUFF, "Local: ISR count insufficient"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__NODE_UPDATE, "Local: Broker node update"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__SSL, "Local: SSL error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__WAIT_COORD, "Local: Waiting for coordinator"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__UNKNOWN_GROUP, "Local: Unknown group"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__IN_PROGRESS, "Local: Operation in progress"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__PREV_IN_PROGRESS,
//             "Local: Previous operation in progress"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__EXISTING_SUBSCRIPTION,
//             "Local: Existing subscription"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__ASSIGN_PARTITIONS, "Local: Assign
// partitions"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__REVOKE_PARTITIONS, "Local: Revoke
// partitions"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__CONFLICT, "Local: Conflicting use"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__STATE, "Local: Erroneous state"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__UNKNOWN_PROTOCOL, "Local: Unknown protocol"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__NOT_IMPLEMENTED, "Local: Not implemented"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__AUTHENTICATION, "Local: Authentication
// failure"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__NO_OFFSET, "Local: No offset stored"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__OUTDATED, "Local: Outdated"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__TIMED_OUT_QUEUE, "Local: Timed out in queue"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__UNSUPPORTED_FEATURE,
//             "Local: Required feature not supported by broker"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__WAIT_CACHE, "Local: Awaiting cache update"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__INTR, "Local: Operation interrupted"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__KEY_SERIALIZATION,
//             "Local: Key serialization error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__VALUE_SERIALIZATION,
//             "Local: Value serialization error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__KEY_DESERIALIZATION,
//             "Local: Key deserialization error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__VALUE_DESERIALIZATION,
//             "Local: Value deserialization error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__PARTIAL, "Local: Partial response"),
//   //_ERR_DESC(RD_KAFKA_RESP_ERR__READ_ONLY, "Local: Read-only object"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__NOENT, "Local: No such entry"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__UNDERFLOW, "Local: Read underflow"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_UNKNOWN, "Unknown broker error"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NO_ERROR, "Success"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_OFFSET_OUT_OF_RANGE,
//             "Broker: Offset out of range"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_MSG, "Broker: Invalid message"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_UNKNOWN_TOPIC_OR_PART,
//             "Broker: Unknown topic or partition"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_MSG_SIZE, "Broker: Invalid message
// size"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_LEADER_NOT_AVAILABLE,
//             "Broker: Leader not available"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NOT_LEADER_FOR_PARTITION,
//             "Broker: Not leader for partition"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_REQUEST_TIMED_OUT, "Broker: Request timed
// out"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_BROKER_NOT_AVAILABLE,
//             "Broker: Broker not available"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_REPLICA_NOT_AVAILABLE,
//             "Broker: Replica not available"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_MSG_SIZE_TOO_LARGE,
//             "Broker: Message size too large"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_STALE_CTRL_EPOCH,
//             "Broker: StaleControllerEpochCode"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_OFFSET_METADATA_TOO_LARGE,
//             "Broker: Offset metadata string too large"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NETWORK_EXCEPTION,
//             "Broker: Broker disconnected before response received"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_GROUP_LOAD_IN_PROGRESS,
//             "Broker: Group coordinator load in progress"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_GROUP_COORDINATOR_NOT_AVAILABLE,
//             "Broker: Group coordinator not available"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NOT_COORDINATOR_FOR_GROUP,
//             "Broker: Not coordinator for group"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_TOPIC_EXCEPTION, "Broker: Invalid topic"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_RECORD_LIST_TOO_LARGE,
//             "Broker: Message batch larger than configured server "
//             "segment size"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NOT_ENOUGH_REPLICAS,
//             "Broker: Not enough in-sync replicas"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NOT_ENOUGH_REPLICAS_AFTER_APPEND,
//             "Broker: Message(s) written to insufficient number of "
//             "in-sync replicas"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_REQUIRED_ACKS,
//             "Broker: Invalid required acks value"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_ILLEGAL_GENERATION,
//             "Broker: Specified group generation id is not valid"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INCONSISTENT_GROUP_PROTOCOL,
//             "Broker: Inconsistent group protocol"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_GROUP_ID, "Broker: Invalid group.id"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_UNKNOWN_MEMBER_ID, "Broker: Unknown member"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_SESSION_TIMEOUT,
//             "Broker: Invalid session timeout"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_REBALANCE_IN_PROGRESS,
//             "Broker: Group rebalance in progress"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_COMMIT_OFFSET_SIZE,
//             "Broker: Commit offset data size is not valid"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_TOPIC_AUTHORIZATION_FAILED,
//             "Broker: Topic authorization failed"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_GROUP_AUTHORIZATION_FAILED,
//             "Broker: Group authorization failed"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_CLUSTER_AUTHORIZATION_FAILED,
//             "Broker: Cluster authorization failed"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_TIMESTAMP, "Broker: Invalid
// timestamp"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_UNSUPPORTED_SASL_MECHANISM,
//             "Broker: Unsupported SASL mechanism"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_ILLEGAL_SASL_STATE,
//             "Broker: Request not valid in current SASL state"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_UNSUPPORTED_VERSION,
//             "Broker: API version not supported"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_TOPIC_ALREADY_EXISTS,
//             "Broker: Topic already exists"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_PARTITIONS,
//             "Broker: Invalid number of partitions"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_REPLICATION_FACTOR,
//             "Broker: Invalid replication factor"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_REPLICA_ASSIGNMENT,
//             "Broker: Invalid replica assignment"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_CONFIG,
//             "Broker: Configuration is invalid"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_NOT_CONTROLLER,
//             "Broker: Not controller for cluster"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_REQUEST, "Broker: Invalid request"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_UNSUPPORTED_FOR_MESSAGE_FORMAT,
//             "Broker: Message format on broker does not support request"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_POLICY_VIOLATION,
//             "Broker: Isolation policy volation"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_OUT_OF_ORDER_SEQUENCE_NUMBER,
//             "Broker: Broker received an out of order sequence number"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_DUPLICATE_SEQUENCE_NUMBER,
//             "Broker: Broker received a duplicate sequence number"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_PRODUCER_EPOCH,
//             "Broker: Producer attempted an operation with an old epoch"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_TXN_STATE,
//             "Broker: Producer attempted a transactional operation in "
//             "an invalid state"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_PRODUCER_ID_MAPPING,
//             "Broker: Producer attempted to use a producer id which is "
//             "not currently assigned to its transactional id"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_INVALID_TRANSACTION_TIMEOUT,
//             "Broker: Transaction timeout is larger than the maximum "
//             "value allowed by the broker's max.transaction.timeout.ms"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_CONCURRENT_TRANSACTIONS,
//             "Broker: Producer attempted to update a transaction while "
//             "another concurrent operation on the same transaction was "
//             "ongoing"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_TRANSACTION_COORDINATOR_FENCED,
//             "Broker: Indicates that the transaction coordinator sending "
//             "a WriteTxnMarker is no longer the current coordinator for "
//             "a given producer"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_TRANSACTIONAL_ID_AUTHORIZATION_FAILED,
//             "Broker: Transactional Id authorization failed"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_SECURITY_DISABLED,
//             "Broker: Security features are disabled"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR_OPERATION_NOT_ATTEMPTED,
//             "Broker: Operation not attempted"),
//   _ERR_DESC(RD_KAFKA_RESP_ERR__END, NULL)
// };

const char *rd_kafka_err2str(rd_kafka_resp_err_t err) {
  static char ret[32];
  snprintf(ret, 32, "Error type %d", (int)err);
  // int idx = err - RD_KAFKA_RESP_ERR__BEGIN;
  // if (unlikely(err <= RD_KAFKA_RESP_ERR__BEGIN ||
  //              err >= RD_KAFKA_RESP_ERR_END_ALL ||
  //              !rd_kafka_err_descs[idx].desc)) {
  //   rd_snprintf(ret, sizeof(ret), "Err-%i?", err);
  //   return ret;
  // }
  //  return rd_kafka_err_descs[idx].desc;
  return ret;
}

const char *rd_kafka_err2name(rd_kafka_resp_err_t err) {
  static char ret[32];
  snprintf(ret, 32, "Error name %d", (int)err);
  // int idx = err - RD_KAFKA_RESP_ERR__BEGIN;
  // if (unlikely(err <= RD_KAFKA_RESP_ERR__BEGIN ||
  //              err >= RD_KAFKA_RESP_ERR_END_ALL ||
  //              !rd_kafka_err_descs[idx].desc)) {
  //   rd_snprintf(ret, sizeof(ret), "ERR_%i?", err);
  //   return ret;
  // }
  // return rd_kafka_err_descs[idx].name;
  return ret;
}