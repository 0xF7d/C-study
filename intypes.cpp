#include <cstdio>

/* NOTES:
 
 * Key:
 
 * Integers:
 
*/


int main() {
unsigned short a = 0b10101010;
printf("%hu\n", a); //binary of a
int b = 0123;
printf("%d\n", b); //octal of b
unsigned long long d = 0xFFFFFFFFFFFFFFFF;
printf("%llu\n", d); //hex of d
unsigned int e = 3669732608;
printf("Yabba %x!\n", e); //hex of 3669732608 is dabbad00
unsigned int f = 69;
printf("There are %u,%o leaves here.\n", f, f); //octal of 69 is 105
double an = 6.0221409e23;
printf("Avogadro's Number: %le %lf %lg\n", an, an, an); //sci notation of double, decimal rep of long double, specifier's choice
float hp = 9.75;
printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp); //sci notation, float, specifier's choice.
}
