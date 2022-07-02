/* cat <filename> | ./wordcount
 * n1 = new line
 * nw = space
 * nc = char
*/

#include <stdio.h>

#define IN 0 /* Inside a word */
#define OUT 1 /* Outside a word */

/* count lines, words, and characters in input */
int main(){
	int c, n1, nw, nc, state;
	state = OUT;
	n1 = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')	
			++n1;
		if (c == ' ' || c == '\n' || c == '\t')	//c is blank \| c is newline \| c is tab
			state = OUT;
		else if ( state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n" , n1, nw, nc);
}
