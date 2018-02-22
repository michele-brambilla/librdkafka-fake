add_library(
    rdkafka-fake-utils
	utils.cxx
)

target_include_directories(rdkafka-fake-utils PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")
set_target_properties(rdkafka-fake-utils PROPERTIES PUBLIC_HEADER "utils.h")
configure_file(utils.h ${CMAKE_HEADER_OUTPUT_DIRECTORY}/utils.h)