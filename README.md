# librdkafka-fake
Fake implemantation of librdkafka for testing purposes. 
Testing a project that requires ``librdkafa`` is non-trivial: one should set up a Kafka broker, or something that pretends to be a Kafka broker, to let functions and methods have a non timeout response. ``librdkafka-fake`` can be used to have a valid (or invalid) response from ~~all~~some RdKafka methods setting valid or invalid return values and errors **without** a broker up and running.

## Install

The dependencies can be installed either manually or using [conan](https://www.conan.io/)

Requires:
- librdkafka
- gtest (optional)

To install using conan the add the following remote is required:
- https://api.bintray.com/conan/ess-dmsc/conan

Before configuring the project install the dependencies. In the build folder:

``conan install ${path_to_source_directory}/conan``

Configure the build using **cmake**:

``cmake ${path_to_source_directory}``

Finally build:

``make``

## Usage

See [here](USAGE.md) for all a detailed description.

The tests present a wide variety of fake calls. When a method can return a valid or invalid value, the general syntax is

```
set<Object>Valid();
set<Object>Invalid();
```

before tha actual invocation of the method.

Other examples:

- topicPartition metadata can be add using

```c++
addTopicPartitionMetadata("my-topic",{0,1,2});
```

- number of configuration options that have been set:

```c++
size_t num_elements = getConfigurationOptionsSize();
```

### How to modify CMakeLists.txt

To fake the ``librdkafka`` calls in your project remove the ``librdkafka++.a`` archive from the link targets and add ``librdkafka++-fake.a``

Example:

```cmake
set(libraries_testing ${libraries_common})
list(REMOVE_ITEM libraries_testing ${RDKAFKA_LIBRARIES_CXX})
list(APPEND libraries_testing ${path_to_build_directory}/lib/librdkafka++-fake.a)

# Your cmake commands here
# ...

target_link_libraries(${tgt} ${libraries_testing})
```

## Test

To build tests use

``cmake -DREQUIRE_GTEST:Bool=1 ${path_to_source_directory}``

Tests require ``GoogleTests`` to be present on the system. If conan is used to build dependencies GoogleTest is installed.

The default cmake configuration is ``Debug``. In this configuration the coverage report is created. To create a nice coverage report **gcov** + **lcov** can be used:

```
build
run tests
gcov src-cpp/CMakeFiles/rdkafka++.dir/ -r
lcov -c -d src-cpp/CMakeFiles/rdkafka++.dir/ -o ${coverage_test_output}
genhtml -o {new_folder_for_html} ${coverage_test_output}

```

## TODO

The project currently implements the methods required to test the ``Streamer`` class of ``kafka-to-nexus``. C++ classes and methods non used are not (or not properly) implemented.

There is no implementation for the plain C library.
