#include <stdio.h>

int int_shift_are_arithmetic() {
  int x = -121;
  int shift = x >> 1;

  return shift < 0;
}

int main(int argc, char const *argv[])
{
  int result = int_shift_are_arithmetic();
  printf("Does this machine use arithmetic shifts for ints? %s\n", result ? "yes" : "no");
  return 0;
}
