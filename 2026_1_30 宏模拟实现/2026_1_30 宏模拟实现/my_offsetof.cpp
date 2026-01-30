#include <stdio.h>

struct Test {
    char a;
    int b;
    double c;
};

#define OFFSET_OF(struct_type, member) ((size_t)&(((struct_type*)0)->member))

int main() {
    printf("Offset of a: %zu\n", OFFSET_OF(struct Test, a)); // 0
    printf("Offset of b: %zu\n", OFFSET_OF(struct Test, b)); // 4 »ò 8£¨¶ÔÆë£©
    printf("Offset of c: %zu\n", OFFSET_OF(struct Test, c)); // 8 »ò 16
    return 0;
}