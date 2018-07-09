cmake_minimum_required(VERSION 2.8)
project("Iterators")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(WIN32)
  set(EXEC_NAME "iterator")
else()
  set(EXEC_NAME "iterator.out")
endif()

set(SRC src/main.c
  src/include/iterator.h
  src/include/iterator.c
  src/include/linked_list.h
  src/include/linked_list.c)

add_executable(${EXEC_NAME} ${SRC})
