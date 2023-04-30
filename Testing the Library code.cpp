int main()
{
    // 32-bit floating-point arithmetic
    double fs = 1000;
    double duration = 1;
    std::vector<double> signal32 = generateSignal(11, 12, 13, fs, duration);
    std::vector<double> b32 = designFIRFilter(13
