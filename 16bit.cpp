#include <cstdint>

using Fixed16 = std::int16_t;

constexpr Fixed16 kFixed16One = 1 << 15;
constexpr Fixed16 kFixed16Max = (1 << 15) - 1;
constexpr Fixed16 kFixed16Min = -(1 << 15);

inline Fixed16 FloatToFixed16(float f) {
  return static_cast<Fixed16>(f * kFixed16One);
}

inline float Fixed16ToFloat(Fixed16 x) {
  return static_cast<float>(x) / kFixed16One;
}

inline Fixed16 Fixed16Add(Fixed16 x, Fixed16 y) {
  return x + y;
}

inline Fixed16 Fixed16Sub(Fixed16 x, Fixed16 y) {
  return x - y;
}

inline Fixed16 Fixed16Mul(Fixed16 x, Fixed16 y) {
  return static_cast<Fixed16>((static_cast<std::int32_t>(x) * static_cast<std::int32_t>(y)) >> 15);
}

inline Fixed16 Fixed16Div(Fixed16 x, Fixed16 y) {
  return static_cast<Fixed16>((static_cast<std::int32_t>(x) << 15) / y);
}
