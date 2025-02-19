#include <stdio.h>
#include <stdlib.h>

void cleanScreen() {
  printf("\033[H\033[J");
}

int main() {
  cleanScreen();
  
  return 0;
}