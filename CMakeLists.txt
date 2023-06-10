cmake_minimum_required(VERSION 3.2)
project(miniz-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(MINIZ_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

option(MINIZ_BUILD_TESTS "build executable for unit tests" ON)
option(MINIZ_BUILD_EXAMPLES "build executables for examples" ON)

# === tests

if(${MINIZ_BUILD_TESTS})
  set(TMPDIR "${CMAKE_CURRENT_BINARY_DIR}/tmp" CACHE PATH "directory for temp files from custom commands during build")
  set(TESTDIR "${PROJECT_SOURCE_DIR}/tests")
  file(MAKE_DIRECTORY "${TMPDIR}")
  add_custom_command(OUTPUT test.xlsx.o
    WORKING_DIRECTORY ${TMPDIR}
    COMMAND ${CMAKE_C_COMPILER}
      -D__raw_file_path__='"${TESTDIR}/test.xlsx.bin"'
      "${TESTDIR}/test.xlsx.S"
      -c -o "${CMAKE_CURRENT_BINARY_DIR}/test.xlsx.o"
    DEPENDS "${TMPDIR}" "${TESTDIR}/test.xlsx.S"
    COMMENT "generating resource file test.xlsx.o"
  )
  file(GLOB TEST_SOURCE "${PROJECT_SOURCE_DIR}/tests/test.cpp")
  add_executable(miniz-cpp.test ${TEST_SOURCE} test.xlsx.o)
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
