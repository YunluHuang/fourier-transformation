#pragma once
#include <utility>

typedef std::pair<double, double> complex;

class DFT {
private:
  complex calculate_e_term(int i, double theta, double real, double img);
  complex dft_single_ele_1D(double *real, double *img, int n, int k);
  complex dft_single_ele_2D(double *real, double *img, int m, int n, int k, int l);

public:
  /**

  */
  complex * dft_1D(double *real, double *img, int n);
  /**
    This 2D Discrete Fourier Transformation is applied to a mxn grid
  */
  complex * dft_2D(double *real, double *img, int m, int n);

  complex * inverse_dft_1D(double *real, double *img, int n);

  complex * inverse_dft_2D(double *real, double *img, int m, int n);

};
