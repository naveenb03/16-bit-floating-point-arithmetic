#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std::complex_literals;

constexpr float kSampleRate = 44100;
constexpr float kDuration = 1;
constexpr float kOmega11 = 2 * M_PI * 11;
constexpr float kOmega12 = 2 * M_PI * 12;
constexpr float kOmega13 = 2 * M_PI * 13;

inline float Sin(float omega, float t) {
  return std::sin(omega * t);
}

std::vector<float> GenerateSignal() {
  std::vector<float> signal;
  signal.reserve(static_cast<std::size_t>(kDuration * kSampleRate));
  for (float t = 0; t < kDuration; t += 1 / kSampleRate) {
    float x = Sin(kOmega11, t) + Sin(kOmega12, t) + Sin(kOmega13, t);
    signal.push_back(x);
  }
  return signal;
}

std::vector<float> FIRFilter(const std::vector<float>& input, float cutoff_frequency) {
  constexpr int kOrder = 100;
  std::vector<float> impulse_response(kOrder + 1);
  float omega_c = 2 * M_PI * cutoff_frequency / kSampleRate;
  for (int n = -kOrder / 2; n <= kOrder / 2; ++n) {
    if (n ==

