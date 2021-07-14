#include <cstddef>
#include <cstdio>

/* NOTES:

 * For Loops:
 init statement executes before first iteration executeas: can initialize variables for the loop
 
 * Conditional expression: evaluated before each iteration
    if true: iteration proceeds
    if false: loop terminates
 
 * Iteration statement:
    executes after each iteration 
        increment variable coverage over a range of values

 * SYNTAX:
 1)  for(init-statement; conditional; iteration-statement){
         -- do something -- 
     }

 2)  for(element-type element-name : array-name) {
        -- do something -- 
     }
*/

int main() {
    //Example 1
 unsigned long maximum = 0; //initialize maximum to smallest value possible
 unsigned long values[] =  {3, 50, 200410, 2874, 0}; // array values
 for(size_t i=0; i <5; i++) { // iterator variable i range 0-4 to check values element is greater current ma 
    if (values[i] > maximum) maximum = values[i]; // if yes, set maximum to new value
    }
 printf("The maximum value is %lu\n", maximum);

   //Example 2
 unsigned long max = 0;
 unsigned long value_s[] = {3, 50, 200410, 2874, 0};
 for(unsigned long value : value_s) { // for loop iterates over values
    if(value > max) max = value; // because i is gone, for loop simplifies. allows use of each element of values directly.
    }
 printf("The maximum value is %lu.\n", max); //variable maximum must be established as max because of redirection

char alphabet[27];
for (int i=0; i<26; i++){
    alphabet[i] = i + 97; //a is 97 in ASCII 
    }
    alphabet[26] = 0; //make alphabet variable null terminated string
    printf("\n%s\n", alphabet);
    for (int i = 0; i<26; i++){ //reset each alphabet element
        alphabet[i] = i + 65; //A is 65 in ASCII
    } 
    printf("\n%s\n", alphabet);
}
