cmake_minimum_required(VERSION 3.2)
project(RdKafkaFake)

#include(GNUInstallDirs)

set(config_install_dir "lib/cmake/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Find modules
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")

# Conan
if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
  include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
  conan_basic_setup(NO_OUTPUT_DIRS SKIP_RPATH)
endif()

find_package(Googletest)
find_package(RdKafka REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(path_include_common ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src-cpp)


#add_subdirectory(src)
add_subdirectory(src-cpp)

#if(RDKAFKA_BUILD_EXAMPLES)
#  add_subdirectory(examples)
#endif()

if(${have_gtest})
  enable_testing()
  add_subdirectory(tests)
endif()