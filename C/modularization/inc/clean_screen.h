#ifndef CLEAN_SCREEN_H_INCLUDED
#define CLEAN_SCREEN_H_INCLUDED

void cleanScreen() {
  printf("\033[H\033[J");
  return;
}

#endif // CLEAN_SCREEN_H_INCLUDED