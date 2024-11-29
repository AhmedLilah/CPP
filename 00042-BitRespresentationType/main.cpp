#include <array>
#include <bit>
#include <cstdint>
#include <algorithm>

template <uint8_t size>
struct bitset {
        // Underlying storage for bit representation
        std::array<unsigned char, (size + 7) / 8> data{};

        // Constructors
        explicit bitset() = default; // Default constructor
        explicit bitset(const std::array<unsigned char, (size + 7) / 8>& init_data) : data(init_data) {}

        // Disable copy assignment and implicit conversions
        bitset& operator=(const bitset&) = delete;
        bitset(const bitset&) = default;
        bitset(bitset&&) noexcept = default;

        // Logical NOT operator
        bool operator!() const {
                return std::all_of(data.begin(), data.end(), [](unsigned char byte) { return byte == 0; });
        }

        // Logical AND operator (checks if both bitsets are non-zero)
        bool operator&&(const bitset& other) const {
                return !(*this == bitset{}) && !(other == bitset{});
        }

        // Logical OR operator (checks if at least one bitset is non-zero)
        bool operator||(const bitset& other) const {
                return !(*this == bitset{}) || !(other == bitset{});
        }

        // Bitwise NOT
        bitset operator~() const {
                bitset result;
                for (size_t i = 0; i < data.size(); ++i) {
                        result.data[i] = ~data[i];
                }
                return result;
        }

        // Bitwise AND
        bitset operator&(const bitset& other) const {
                bitset result;
                for (size_t i = 0; i < data.size(); ++i) {
                        result.data[i] = data[i] & other.data[i];
                }
                return result;
        }

        // Bitwise OR
        bitset operator|(const bitset& other) const {
                bitset result;
                for (size_t i = 0; i < data.size(); ++i) {
                        result.data[i] = data[i] | other.data[i];
                }
                return result;
        }

        // Bitwise XOR
        bitset operator^(const bitset& other) const {
                bitset result;
                for (size_t i = 0; i < data.size(); ++i) {
                        result.data[i] = data[i] ^ other.data[i];
                }
                return result;
        }

        // Left shift
        bitset operator<<(size_t shift) const {
                bitset result = *this;
                result <<= shift;
                return result;
        }

        // Right shift
        bitset operator>>(size_t shift) const {
                bitset result = *this;
                result >>= shift;
                return result;
        }

        // Left shift assignment
        bitset& operator<<=(size_t shift) {
                size_t byte_shift = shift / 8;
                size_t bit_shift = shift % 8;

                // Shift whole bytes
                if (byte_shift > 0) {
                        for (size_t i = data.size(); i-- > byte_shift;) {
                                data[i] = data[i - byte_shift];
                        }
                        std::fill(data.begin(), data.begin() + byte_shift, 0);
                }

                // Shift remaining bits
                if (bit_shift > 0) {
                        for (size_t i = data.size(); i-- > 1;) {
                                data[i] = (data[i] << bit_shift) | (data[i - 1] >> (8 - bit_shift));
                        }
                        data[0] <<= bit_shift;
                }

                return *this;
        }

        // Right shift assignment
        bitset& operator>>=(size_t shift) {
                size_t byte_shift = shift / 8;
                size_t bit_shift = shift % 8;

                // Shift whole bytes
                if (byte_shift > 0) {
                        for (size_t i = 0; i < data.size() - byte_shift; ++i) {
                                data[i] = data[i + byte_shift];
                        }
                        std::fill(data.end() - byte_shift, data.end(), 0);
                }

                // Shift remaining bits
                if (bit_shift > 0) {
                        for (size_t i = 0; i < data.size() - 1; ++i) {
                                data[i] = (data[i] >> bit_shift) | (data[i + 1] << (8 - bit_shift));
                        }
                        data[data.size() - 1] >>= bit_shift;
                }

                return *this;
        }

        // Logical comparison operators
        bool operator==(const bitset& other) const {
                return data == other.data;
        }

        bool operator!=(const bitset& other) const {
                return !(*this == other);
        }

        bool operator<(const bitset& other) const {
                return data < other.data;
        }

        bool operator<=(const bitset& other) const {
                return data <= other.data;
        }

        bool operator>(const bitset& other) const {
                return data > other.data;
        }

        bool operator>=(const bitset& other) const {
                return data >= other.data;
        }

        // Bitwise AND assignment
        bitset& operator&=(const bitset& other) {
                for (size_t i = 0; i < data.size(); ++i) {
                        data[i] &= other.data[i];
                }
                return *this;
        }

        // Bitwise OR assignment
        bitset& operator|=(const bitset& other) {
                for (size_t i = 0; i < data.size(); ++i) {
                        data[i] |= other.data[i];
                }
                return *this;
        }

        // Bitwise XOR assignment
        bitset& operator^=(const bitset& other) {
                for (size_t i = 0; i < data.size(); ++i) {
                        data[i] ^= other.data[i];
                }
                return *this;
        }
};

bitset<8> directBitLogicalOperations(bitset<8> a, bitset<8> b) {
        return std::bit_cast<bitset<8>>(std::bit_cast<bool>(a) && std::bit_cast<bool>(b));
}

bitset<8> directBitArithmaticOperations(bitset<8> a, bitset<8> b) {
        const uint8_t result = std::bit_cast<uint8_t>(a) + std::bit_cast<uint8_t>(b);
        return std::bit_cast<bitset<8>>(result);
}
