/*
    This is meant to be an amusing exercise only
*/

#include <iostream>

void convertToBinary(unsigned int n) {
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main()
{
    int x = 255;
    convertToBinary(x);
}
