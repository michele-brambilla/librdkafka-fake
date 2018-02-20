add_library(
    rdkafka-fake-utils
	utils.cxx
)

target_link_libraries(rdkafka-fake-utils PUBLIC rdkafka)

target_include_directories(rdkafka-fake-utils PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")
set_target_properties(rdkafka-fake-utils PROPERTIES PUBLIC_HEADER "definitions.h")
configure_file(definitions.h ${CMAKE_HEADER_OUTPUT_DIRECTORY}/definitions.h)