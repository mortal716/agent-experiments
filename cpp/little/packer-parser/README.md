# Packet Parser Agent Repair Experiment

## 1. Project Overview

This project evaluates whether structured failure feedback can improve
an AI agent's ability to locate and repair software defects.

The experiment compares two feedback mechanisms:

- Baseline Agent: receives raw build and test outputs.
- Improved Agent: receives raw outputs and structured failure information.

The same task, codebase, model, and execution budget should be used
for both agents.

## 2. Packet Format

Each packet consists of three fields:

| Field | Size | Description |
|---|---:|---|
| Version | 1 byte | Protocol version |
| Payload Length | 2 bytes | Payload length in big-endian order |
| Payload | N bytes | Packet payload |

The payload length specifies the number of payload bytes following
the packet header.

## 3. Parser Interface

The parser is defined as:

```cpp
bool parse_packet(
    const std::vector<std::uint8_t>& data,
    Packet& packet
);