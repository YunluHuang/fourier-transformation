#pragma once
#include <utility>

typedef std::pair<double, double> complex;

class FFT {
public:
  complex * fft_1D(double *real, double *img, int n);
};
