#include "DFT.h"
#include <math.h>

#define PI M_PI

using namespace std;

complex * DFT::dft_1D(double *real, double *img, int n) {
  complex *F = new complex[n];
  for(int k = 0; k < n; k++) {
    F[k] = dft_single_ele_1D(real, img, n, k);
  }
  return F;
}

complex * DFT::dft_2D(double *real, double *img, int m, int n) {
  complex *F = new complex[m * n];
  for(int k = 0; k < m; k++) {
    for(int l = 0; l < n; l++) {
      F[k + l * m] = dft_single_ele_2D(real, img, m, n, k, l);
    }
  }
  return F;
}

complex * DFT::inverse_dft_1D(double *real, double *img, int n) {
  complex *f = new complex[n];
  for(int k = 0; k < n; k++) {
    complex tmp = dft_single_ele_1D(real, img, n, -k);
    f[k].first = (1.0 / n) * tmp.first;
    f[k].second = (1.0 / n) * tmp.second;
  }
  return f;
}

complex * DFT::inverse_dft_2D(double *real, double *img, int m, int n) {
  complex *f = new complex[m * n];
  for(int k = 0; k < m; k++) {
    for(int l = 0; l < n; l++) {
      complex tmp = dft_single_ele_2D(real, img, m, n, -k, -l);
      f[k + m * l].first = (1.0 / m / n) * tmp.first;
      f[k + m * l].second = (1.0 / m / n) * tmp.second;
    }
  }
  return f;
}

////////////////////////////////////////////////////////////////////////////////
complex DFT::calculate_e_term(int i, double k_n, double real, double img) {
  double theta = 2.0 * PI * k_n;
  double i_theta = i * theta;
  double cos_i = cos(i_theta);
  double sin_i = sin(i_theta);
  double x_i_real = cos_i * real + sin_i * img;
  double x_i_img = cos_i * img - sin_i * real;
  return make_pair(x_i_real, x_i_img);
}

complex DFT::dft_single_ele_1D(double *real, double *img, int n, int k) {

  double x_real = 0.0;
  double x_img = 0.0;
  for(int i = 0; i < n; i++) {
    complex x_i = calculate_e_term(i, (double)k/n, real[i], img[i]);
    x_real += x_i.first;
    x_img += x_i.second;
  }

  return make_pair(x_real, x_img);

}

complex DFT::dft_single_ele_2D(double *real, double *img, int m, int n, int k, int l) {
  double xy_real = 0.0;
  double xy_img = 0.0;

  for(int i = 0; i < m; i++) {
    double y_real = 0.0;
    double y_img = 0.0;

    for(int j = 0; j < n; j++) {
      int offset = i + j*m;
      complex y_j = calculate_e_term(j, (double)l/n, real[offset], img[offset]);
      y_real += y_j.first;
      y_img += y_j.second;
    }

    complex x_i = calculate_e_term(i, (double)k/m, y_real, y_img);
    xy_real += x_i.first;
    xy_img += x_i.second;
  }

  return make_pair(xy_real, xy_img);
}
