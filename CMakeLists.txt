cmake_minimum_required(VERSION 3.2)
project(miniz-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(MINIZ_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

option(MINIZ_BUILD_TESTS "build executable for unit tests" ON)
option(MINIZ_BUILD_EXAMPLES "build executables for examples" ON)

# === tests
if(${MINIZ_BUILD_TESTS})
  file(GLOB TEST_SOURCE "${PROJECT_SOURCE_DIR}/tests/test.cpp")
  add_executable(miniz-cpp.test ${TEST_SOURCE})
  target_include_directories(miniz-cpp.test PRIVATE "${MINIZ_INCLUDE_DIR}")
endif()

# === examples
if(${MINIZ_BUILD_EXAMPLES})
  file(GLOB EXAMPLE_SOURCES "${PROJECT_SOURCE_DIR}/examples/*.cpp")
  foreach(SRC_PATH IN ITEMS ${EXAMPLE_SOURCES})
    get_filename_component(SRC_NAME "${SRC_PATH}" NAME_WE)
    set(EXE_NAME "example-${SRC_NAME}")
    add_executable(${EXE_NAME} ${SRC_PATH})
    target_include_directories(${EXE_NAME} PRIVATE "${MINIZ_INCLUDE_DIR}")
  endforeach()
endif()
