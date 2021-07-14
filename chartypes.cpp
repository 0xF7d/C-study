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

 * ASCII:
   		       Control codes Printable characters 
	|-------------------------------------------------------------|
	|	0d 0x Code |  0d 0x Char   | 0d 0x Char  | 0d 0x Char |
	|-------------------------------------------------------------| 
	|	0  0   NULL|  32  20 SPACE | 64 40   @   | 96  60  `  |
	|	1  1   SOH |  33  21   !   | 65 41   A   | 97  61  a  | 
	|	2  2   STX |  34  22   "   | 66 42   B   | 98  62  b  |  
	|	3  3   ETX |  35  23   #   | 67 43   C   | 99  63  c  |  
	|	4  4   EOT |  36  24   $   | 68 44   D   | 100 64  d  |  
	|	5  5   ENQ |  37  25   %   | 69 45   E   | 101 65  e  |  
	|	6  6   ACK |  38  26   &   | 70 46   F   | 102 66  f  | 
	|	7  7   BEL |  39  27   '   | 71 47   G   | 103 67  g  |  
	|	8  8   BS  |  40  28   (   | 72 48   H   | 104 68  h  |   
	|	9  9   HT  |  41  29   )   | 73 49   I   | 105 69  i  |  
	|	10 0a  LF  |  42  2a   *   | 74 4a   J   | 106 6a  j  |  
	|	11 0b  VT  |  43  2b   +   | 75 4b   K   | 107 6b  k  |   
	|	12 0c  FF  |  44  2c   ,   | 76 4c   L   | 108 6c  l  |   
	|	13 0d  CR  |  45  2d   -   | 77 4d   M   | 109 6d  m  |    
	|	14 0e  SO  |  46  2e   .   | 78 4e   N   | 110 6e  n  |    
	|	15 0f  SI  |  47  2f   /   | 79 4f   O   | 111 6f  o  |   
	|	16 10  DLE |  48  30   0   | 80 50   P   | 112 70  p  |   
	|	17 11  DC1 |  49  31   1   | 81 51   Q   | 113 71  q  |   
	|	18 12  DC2 |  50  32   2   | 82 52   R   | 114 72  r  |   
	|	19 13  DC3 |  51  33   3   | 83 53   S   | 115 73  s  |   
	|	20 14  DC4 |  52  34   4   | 84 54   T   | 116 74  t  |  
	|	21 15  NAK |  53  35   5   | 85 55   U   | 117 75  u  |  
	|	22 16  SYN |  54  36   6   | 86 56   V   | 118 76  v  |  
	|	23 17  ETB |  55  37   7   | 87 57   W   | 119 77  w  | 
	|	24 18  CAN |  56  38   8   | 88 58   X   | 120 78  x  |  
	|	25 19  EM  |  57  39   9   | 89 59   Y   | 121 79  y  |      
	|	26 1a  SUB |  58  3a   :   | 90 5a   Z   | 122 7a  z  |     
	|	27 ab  ESC |  59  3b   ;   | 91 5b   [   | 123 7b  {  |        
	|	28 1c  FS  |  60  3c   <   | 92 5c   \   | 124 7c  |  |      
	|	29 1d  GS  |  61  3d   =   | 93 5d   ]   | 125 7d  }  |       
	|	30 1e  RS  |  62  3f   >   | 94 5e   ^   | 126 7e  ~  |    
	|	31 1f  US  |  63  3e   ?   | 95 5f   _   | 127 7f  DEL|     
	|-------------------------------------------------------------|

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
