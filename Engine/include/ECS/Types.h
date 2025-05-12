






#pragma once
#include <bitset>
#include <cstdint>

using Entity = uint32_t;
static const uint8_t MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;
