# librdkafka-fake
Fake implemantation of librdkafka for testing purposes. 
Testing a project that requires ``librdkafa`` is non-trivial: one should set up a Kafka broker, or something that pretends to be a Kafka broker, to let functions and methods have a non timeout response. ``librdkafka-fake`` can be used to have a valid (or invalid) response from ~~all~~some RdKafka functions and methods setting valid or invalid return values and errors **without** a broker up and running.

## Build

The dependencies can be installed either manually or using [conan](https://www.conan.io/)

Requires:
- gtest (optional)

To install using conan the add the following remote is required:
- https://api.bintray.com/conan/ess-dmsc/conan

Before configuring the project install the dependencies. In the build folder:

``conan install ${path_to_source_directory}/conan``

Configure the build using **cmake**:

``cmake ${path_to_source_directory}``

Finally build:

``make``

## Test

To build tests use

``cmake -DREQUIRE_GTEST:Bool=1 ${path_to_source_directory}``

Tests require ``GoogleTests`` to be present on the system. If conan is used to build dependencies GoogleTest is installed.

The default cmake configuration is ``Debug``. 

## Coverage

To enable the generation of coverage file, set the flag ``COVERAGE`` to ``true`` during configuration:

``cmake -DCOVERAGE:Bool=1 ${path_to_source_directory}``

To generate the coverage report

``make coverage``

works with ``lcov`` and ``gcovr``

## Usage

See [here](USAGE.md) for all a detailed description.

The tests present a wide variety of fake calls. When a function or method can return a valid or invalid value, the general syntax is

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

To fake the ``librdkafka`` calls in your project remove ``librdkafka.a`` and/or ``librdkafka++.a`` from the link targets and add ``librdkafka-fake.a`` and/or ``librdkafka++-fake.a`` and ``librdkafka-fake-utils.a``

Example:

```cmake
set(libraries_testing ${libraries_common})
list(REMOVE_ITEM libraries_testing ${RDKAFKA_LIBRARIES_C} ${RDKAFKA_LIBRARIES_CXX})
list(APPEND libraries_testing ${path_to_build_directory}/lib/librdkafka-fake.a ${path_to_build_directory}/lib/librdkafka++-fake.a ${path_to_build_directory}/lib/librdkafka-fake-utils.a)

# Your cmake commands here
# ...

target_link_libraries(${tgt} ${libraries_testing})
```


## TODO

The project currently implements the methods required to test ``kafka-to-nexus``. Functions, classes and methods non used are not (or not properly) implemented.

