#include <cmath>
#include <vector>

const double PI = 3.14159265358979323846;

std::vector<double> designFIRFilter(double cutoffFreq, double fs, int numTaps)
{
    std::vector<double> b(numTaps);

    double omegaC = 2 * PI * cutoffFreq / fs;
    double alpha = (numTaps - 1) / 2.0;

    for (int i = 0; i < numTaps; i++) {
        if (i == alpha) {
            b[i] = omegaC / PI;
        } else {
            b[i] = std::sin(omegaC * (i - alpha)) / (PI * (i - alpha));
        }
    }

    return b;
}

std::vector<double> filterSignal(const std::vector<double>& signal, const std::vector<double>& b)
{
    int numTaps = b.size();
    std::vector<double> filteredSignal(signal.size());

    for (int n = numTaps - 1; n < signal.size(); n++) {
        double sum = 0;
        for (int k = 0; k < numTaps; k++) {
            sum += b[k] * signal[n - k];
        }
        filteredSignal[n] = sum;
    }

    return filteredSignal;
}
