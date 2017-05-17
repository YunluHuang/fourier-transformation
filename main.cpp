// #include "bmp.h"
#include "DFT.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void testDFT_1();
void testDFT_2();
void testInverseDFT_1();

int main()
{
  testInverseDFT_1();
  return EXIT_SUCCESS;
}


////////////////////////////////////////////////////////////////////////////////
void testDFT_1() {
  DFT calculator;
  double real[4] = {10.0, 2.0, 50.0, 3.0};
  double img[4] = {0.0, 0.0, 0.0, 0.0};
  complex *output = calculator.dft_1D(real, img, 4);
  for(int i = 0; i < 4; i++) {
    cout << output[i].first << "+" << output[i].second <<"i ";
  }
  cout << endl;
  delete[] output;
}

void testDFT_2() {
  DFT calculator;
  double real[12] = {6.0, 4.0, 3.0, 4.0, 87.0, 5.0, 103.0, 1.0, 4.0, 7.0, 2.0, 90.0};
  double img[12];
  for(int i = 0; i < 12; i++) {
    img[i] = 0.0;
  }
  complex *output = calculator.dft_2D(real, img, 4, 3);
  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < 4; i++) {
      cout << output[i + 4 * j].first << "+" << output[i + 4 * j].second <<"i ";
    }
    cout << endl;
  }
  cout << endl;
  delete[] output;
}

void testInverseDFT_1() {
  DFT calculator;
  double real[4] = {65.0, -40.0, 55.0, -40.0};
  double img[4] = {0.0, 1.0, 0.0, -1.0};
  complex *output = calculator.inverse_dft_1D(real, img, 4);
  for(int i = 0; i < 4; i++) {
    cout << output[i].first << "+" << output[i].second <<"i ";
  }
  cout << endl;
  delete[] output;
}
