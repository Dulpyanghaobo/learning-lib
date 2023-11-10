#include <stdio.h>

int main(int argc, char const *argv[])
{
  int x;
  x = ~0;
  int all_bits = !~x;
  printf("Testing all bits 1 (x = 0x%X): %d\n", x, all_bits);
  /* code */
  x = 0;
  int all_bits_zero = !x;
  printf("Testing all bits 0 (x = 0x%X): %d\n",x, all_bits_zero);

  x = 0x123123FF;
  int lowest_byte_all_one = !((x & 0xFF) ^ 0XFF);
    printf("Lowest byte all 1 (x = 0x%X): %d\n", x, lowest_byte_all_one);


    // 测试D: 最高有效字节中的位都为0
    x = 0x10FFFFFF; // 设置x的最高有效字节为0，其他位为1
    long a = 0x00111111111111FF;
long highest_byte_all_one = !(a >> ((sizeof(long) - 1) << 3));
    printf("Highest byte all 0 (a = 0x%lX): %ld\n", a, highest_byte_all_one);


  return 0;
}
