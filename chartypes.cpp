#include <cstdio>
#include <cstddef>

/* NOTES:
 
 * Key:
    PF: prefix, FS: format specifier 

 * Characters:
    char literal: single constant char, (''), if other type provide prefix (EX: 'J' declares literal; L'J' declares wchar_t)
    char: default type, always 1 byte. May or may not be signed (EX: ASCII) 
    char16_t: Used for 2-byte character sets (EX: UTF-16). PF: u 
    char32_t: Used for 4-byte character sets (EX: UTF-32). PF: U 
    signed char: Same as char but guaranteed to be signed
    unsigned char: Same as char but guaranteed to be unsigned
    wchar_t: Large enough to contain the largest character of the implementation’s locale (EX: Unicode) PF: L

    word is 2 bytes side by side (16 bits)
    double word is 2 words side by side (32 bits)
    qaud word is 2 double words side by side (64 bits)

    If embed Unicode into string literal - look into wprintf()

 * Escape Characters:
    Newline: '\n' 
    Hori Tab: '\t'
    Vert Tab: '\v' 
    backspace: '\b' 
    carriage return: '\r'
    form feed: '\f' 
    Alert: '\a' 
    Backslash: '\\'
    Question Mark: '? or \?'
    Single Quote '\''
    Double Quote: '\"'
    null: '\0'

 * Format Specifiers:
    %c: character
    %lc: character literal
    %d: int bool True(1) or False(0)
    %zu: size_t decimal representation
    %zx: size_t hex representation
    %s: narror strings (EX 8)

 * Comparison Operators:
    ==: equality
    !=: not/inequality
    >: greater than
    <: less than
    >=: greater than/or equal
    <=: less than/or equal

 * Logical Operators:
    !: negation EX: !true = false
    &&: And
    ||: Or

 * std::btye:
    raw memory (requires <cstddef.h>).
    arithmetic can be used on char but not std::byte, 'std::' is called a namespace
    size_t can encode a size of object(2 to 200bytes)
    identical to unsigned long long on 64bit architectures.
    int sizes could change based off OS
    std::size can be used with any container that exposes a size method

 * Void:
    empty set of values, C++ disallows void objects
    used as return type of functs that dont return any value.

 * Arrays:
    sequence of identical typed variables, which include contained type and number of contained elements.
    syntax: element type before brackets of size (int x_array[100];)
    sizeof to obtain total size in bytes
        #of elements: sizeof(x)/sizeof(y) (EX: 7)
	
KEY
NULL:string terminator,EOT:end of transmission/terminates shell session,BELL:causes device to make noise,BS:backspace(erase last character),HT:horizontal tab(move cursor to right)LF:line feed(end-of-line marker),CR:carriage return(used in combination with LF as EOL for Windows),SUB:substitute char/end of file/ctrl-Z/suspend

*/

int main() {
// 1) char literals
char x = 'M';
wchar_t y = L'Z';
printf("\nWindows binaries start with %c%lc.\n", x, y);

// 2) boolean
bool b1 = true;
bool b2 = false; 
printf("\n%d %d\n", b1, b2); // 1 && 0

// 3) comparison
printf("\n 7 == 7: %d\n", 7 == 7); //1
printf(" 7 != 7: %d\n", 7 != 7); //0
printf(" 7 > 20: %d\n", 7 > 20); //0
printf(" 7 >= 20: %d\n", 7 >= 20); //0
printf(" 7 < 20: %d\n", 7 < 20); //1
printf(" 7 <= 20: %d\n", 7 <= 20); //1

// 4) logical operators: !  && ||
bool t = true;
bool f = false;
printf("\n!true: %d\n", !t); //0
printf("true && false: %d\n", t && f); //0
printf("true && !false: %d\n", t && !f); //1
printf("true || false: %d\n", t || f); //1
printf("false || false: %d\n", f || f); //0

// 5) std::byte: int sizes 
size_t size_c = sizeof(char); //1
printf("\nchar: %zu\n", size_c);
size_t size_s = sizeof(short); //2
printf("short: %zu\n", size_s);
size_t size_i = sizeof(int); //4
printf("int: %zu\n", size_i);
size_t size_l = sizeof(long); //4
printf("long: %zu\n", size_l);
size_t size_ll = sizeof(long long); //8
printf("long long: %zu\n", size_ll);

// 6) Arrays indexing begins at 0
int x_array[] = {1, 2, 3, 4};
printf("\narray: %d\n", x_array[2]);
x_array[2]=100;
printf("array: %d\n", x_array[2]);

// 7) # of elements in array
//short array[] = {104,105,32,98,105,108,108,0};
//size_t n_elements = (sizeof(array)/sizeof(short))

// 8) narrow string literals
char house[] = "a house of gold.";
printf("\nA book holds %s\n", house);

}
