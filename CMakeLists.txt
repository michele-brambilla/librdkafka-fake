cmake_minimum_required(VERSION 3.2)
project(RdKafkaFake)

# Conan
if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
  include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
  conan_basic_setup(NO_OUTPUT_DIRS SKIP_RPATH)
endif()

# Find modules
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")
find_package(Googletest)
include(CodeCoverage)


set(config_install_dir "lib/cmake/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_HEADER_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/include)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g0")
if (DEFINED _GLIBCXX_USE_CXX11_ABI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=${_GLIBCXX_USE_CXX11_ABI}")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -O0 -fno-inline -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -O3")

if(${COVERAGE})
  APPEND_COVERAGE_COMPILER_FLAGS()
  set(COVERAGE_EXCLUDES 'tests/*' '*gtest*' 'CMakeFiles/*')
#  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} --coverage")
  set(GCOV_PREFIX ${PROJECT_BINARY_DIR})
endif()

if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9.3")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=auto")
endif()

set(path_include_common
  ${PROJECT_SOURCE_DIR}/src 
  ${PROJECT_SOURCE_DIR}/src-cpp 
  ${PROJECT_SOURCE_DIR}/utils
)

add_subdirectory(utils)
add_subdirectory(src)
add_subdirectory(src-cpp)

if(${have_gtest})
  enable_testing()
  add_subdirectory(tests)
  add_test(NAME test COMMAND ${CMAKE_BINARY_DIR}/tests/tests)
endif()

if(${COVERAGE})
  if(${GCOVR_PATH})
 SETUP_TARGET_FOR_COVERAGE_COBERTURA(
     NAME coverage                    # New target name
     EXECUTABLE ${PROJECT_BINARY_DIR}/tests/tests # Executable in PROJECT_BINARY_DIR
     DEPENDENCIES tests         # Dependencies to build first
 )
  else()
 SETUP_TARGET_FOR_COVERAGE(
     NAME coverage                    # New target name
     EXECUTABLE ${PROJECT_BINARY_DIR}/tests/tests # Executable in PROJECT_BINARY_DIR
     DEPENDENCIES tests         # Dependencies to build first
     )
  endif()
endif()
