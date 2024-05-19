#include <stdio.h>
#include <conio.h>
#include <math.h>

int dectobinary(int num, int binary) {
    int a, i = 0;
    while (num != 0) {
        a = num % 2;
        binary = a * pow(10, i) + binary;
        i = i + 1;
        num = num / 2;
    }
    return binary;
}

int binaryAddition(int a, int b) {
    int carry = 0, result = 0, bit = 1;
    while (a != 0 || b != 0) {
        int bit_a = a % 10;
        int bit_b = b % 10;
        int sum = bit_a + bit_b + carry;
        result += (sum % 2) * bit;
        carry = sum / 2;
        a /= 10;
        b /= 10;
        bit *= 10;
    }
    result += carry * bit;
    return result;
}

int logicalShiftLeft(int num) {
    return num * 10;
}

int logicalShiftRight(int num) {
    return num / 10;
}

int boothMultiply(int multiplicand, int multiplier) {
    int accumulator = 0;
    int bitMask = 1;
    while (multiplier != 0) {
        if (multiplier % 10 == 1) {
            accumulator = binaryAddition(accumulator, multiplicand);
        }
        multiplicand = logicalShiftLeft(multiplicand);
        multiplier = logicalShiftRight(multiplier);
        bitMask *= 10;
    }
    return accumulator;
}

int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary != 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main() {
    int multiplicand, multiplier, binary1 = 0, binary2 = 0, a, b;
    printf("Enter the multiplicand: ");
    scanf("%d", &multiplicand);
    printf("Enter the multiplier: ");
    scanf("%d", &multiplier);
    a = dectobinary(multiplicand, binary1);
    b = dectobinary(multiplier, binary2);
    int product = boothMultiply(a, b);
    printf("Product of the two binary numbers: %d (binary)\n", product);
    printf("Product in decimal: %d\n", binaryToDecimal(product));
    getch();
    return 0;
}