#include <stdio.h>

int get_mob(int x) {
  int swift_val = (sizeof(int) - 1) << 3;

  int xright = x >> swift_val;

  return xright & 0xFF;
}

int is_little_endian() {
  union  {
    int theIntegral;
    char singleByte;
  }testUnion;
  testUnion.theIntegral = 1;
  return testUnion.singleByte == 1;
}

int generate_x_y(int x, int y) {
  return (x & 0xFF) | (y & ~0xFF);
}

int equal_all_bits_zero(int x) {
  int all_bits = !~x;
  int all_bits_zero = !x;
  int lowest_byte_all_one = !((x & 0xFF) ^ 0xFF);
  int highest_byte_all_zero = !(x >> ((sizeof(int) - 1) << 3));
  return 0
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    // 创建一个掩码，用于清除第i个字节
    unsigned mask = ~(0xFF << (i << 3));
    // 将b移到正确的位置
    unsigned new_byte = b << (i << 3);
    // 使用掩码清除x中的第i个字节，然后加上新字节
    return (x & mask) | new_byte;
}

int main() {
    // if (is_little_endian()) {
    //     printf("This machine is Little-Endian.\n");
    // } else {
    //     printf("This machine is Big-Endian.\n");
    // }
    // int x = 0x89ABCDEF;
    // int y = 0x76543211;
    // int z = generate_x_y(x, y);
    // printf("this z is %d\n", z);

    int x = 0x12345678;
    // int i = 2;
    // unsigned char b = 0xAB;
    // unsigned result = replace_byte(x, i, b);
    printf("this mob is %d\n", get_mob(x)); // 预期输出：0x12AB5678
    
    return 0;
}
