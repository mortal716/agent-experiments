#include "packet.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

void test_normal_packet() {
    const std::vector<std::uint8_t> data = {
        1, 0, 5, 'h', 'e', 'l', 'l', 'o'
    };

    Packet packet{};
    const bool result = parse_packet(data, packet);

    assert(result);
    assert(packet.version == 1);
    assert(packet.payload == "hello");

    std::cout << "[PASS] normal packet\n";
}

void test_truncated_packet() {
    const std::vector<std::uint8_t> data = {
        1, 0, 5, 'h', 'i'
    };

    Packet packet{};
    const bool result = parse_packet(data, packet);

    // The parser should reject truncated input.
    assert(!result);

    std::cout << "[PASS] truncated packet\n";
}

void test_empty_payload() {
    const std::vector<std::uint8_t> data = {
        1, 0, 0
    };

    Packet packet{};
    const bool result = parse_packet(data, packet);

    assert(result);
    assert(packet.version == 1);
    assert(packet.payload.empty());

    std::cout << "[PASS] empty payload\n";
}

int main() {
    test_normal_packet();
    test_truncated_packet();
    test_empty_payload();

    std::cout << "All tests passed\n";
    return 0;
}
