#include <cmath>
#include <vector>

const double PI = std::acos(-1.0);

std::vector<double> generateSignal(double freq1, double freq2, double freq3, double fs, double duration)
{
    std::vector<double> signal;
    double t = 0;
    while (t < duration) {
        double value = std::sin(2 * PI * freq1 * t) + std::sin(2 * PI * freq2 * t) + std::sin(2 * PI * freq3 * t);
        signal.push_back(value);
        t += 1 / fs;
    }
    return signal;
}