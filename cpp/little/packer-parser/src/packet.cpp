#include "packet.hpp"

bool parse_packet(const std::vector<std::uint8_t>& data, Packet& packet) {
    if (data.size() < 3) {
        return false;
    }

    packet.version = data[0];

    const std::uint16_t declared_length =
        (static_cast<std::uint16_t>(data[1]) << 8) |
        static_cast<std::uint16_t>(data[2]);

    // The declared length is the payload size; the 3-byte header
    // is already excluded from it, so validate against the bytes
    // remaining after the header.
    if (declared_length > data.size() - 3) {
        return false;
    }

    packet.payload.assign(
        data.begin() + 3,
        data.begin() + 3 + declared_length
    );

    return true;
}
