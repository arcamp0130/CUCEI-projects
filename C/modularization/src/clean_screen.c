#include <stdio.h>

void cleanScreen() {
  printf("\033[H\033[J");
  return;
}