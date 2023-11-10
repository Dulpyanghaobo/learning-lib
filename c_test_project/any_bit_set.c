#include <stdio.h>
int odd_ones(unsigned x) {
  x ^= x >> 16;
  printf("x >> 16 = %x\n", x);
  x ^= x >> 8;
    printf("x >> 8 = %x\n", x);
  x ^= x >> 4;
      printf("x >> 4 = %x\n", x);

  x ^= x >> 2;
        printf("x >> 2 = %x\n", x);

  x ^= x >> 1;
          printf("x >> 1 = %x\n", x);

  return x & 1;
}
int leftmost_one(unsigned x) {
    // 先将最左边的1右边的所有位都变成1
    x |= x >> 1;
    printf("x >> 1 = %x\n", x);
    x |= x >> 2;
    printf("x >> 2 = %x\n", x);
    x |= x >> 4;
    printf("x >> 4 = %x\n", x);
    x |= x >> 8;
    printf("x >> 8 = %x\n", x);
    x |= x >> 16;
    printf("x >> 16 = %x\n", x);

    // 然后，通过右移一位并取反，得到一个仅在最左边的1位为1的数
    return x & ~(x >> 1);
}

int lower_one_mask(int n) {
  if (n == sizeof(int)<<3) {
    return -1;
  }
  return (1 << n) - 1;
}

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(unsigned) * 8;  // 计算位宽
    n = n % w;  // 防止n大于w的情况
    return (x << n) | (x >> (w - n));  // 左移并将溢出的部分加到右侧
}

int firs_bits(int x,int n) {
  int w = sizeof(int) * 8;
  int shift = w - n;
  int shiftd = (x << shift) >> shift;
  return x == shiftd;
}

int main(int argc, char const *argv[])
{
  // int x = odd_ones(0xFFFFFFFE);
  // printf("x = %d\n", x);
  // /* code */
  // int a = leftmost_one(0x2132131F);
  //   printf("a = %x\n", a);
  // int a = lower_one_mask(4);
  int a = rotate_left(0x2132131F,24);
  printf("a = %x\n", a);
  int b = firs_bits(0x1123123, 24);
    printf("b = %d\n", b);

  return 0;
}
