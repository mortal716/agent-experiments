cmake_minimum_required(VERSION 3.16)

project(packet_parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(packet_parser
    src/packet.cpp
)

target_include_directories(packet_parser
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(test_packet
    tests/test_packet.cpp
)

target_link_libraries(test_packet
    PRIVATE
        packet_parser
)

# ---- AddressSanitizer：让越界读稳定暴露 ----
target_compile_options(test_packet PRIVATE -fsanitize=address -g -Wall -Wextra)
target_link_options(test_packet PRIVATE -fsanitize=address)

enable_testing()

add_test(
    NAME packet_tests
    COMMAND test_packet
)
