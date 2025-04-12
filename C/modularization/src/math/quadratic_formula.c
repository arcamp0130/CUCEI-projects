#include <math.h>

void quadraticFormula(float a, float b, float c, float *result)
{
  float denominator = 0, numerator = 0, delta = 0, square = 0;

  delta = (b * b) - 4 * (a * c);
  denominator = 2 * a;
  square = sqrt(delta);

  numerator = (-1 * b) + square; // x_1
  *(result) = numerator / denominator;
  
  numerator = (-1 * b) - square; // x_2
  *(result + 1) = numerator / denominator;

  return;
}