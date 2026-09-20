#pragma once

#include <cstdint>
#include <string>
#include <vector>

struct Packet {
    std::uint8_t version;
    std::string payload;
};

bool parse_packet(const std::vector<std::uint8_t>& data, Packet& packet);
