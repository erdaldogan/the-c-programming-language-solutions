#include<stdio.h>
#define CHAR_COUNT 10 // 10 chars at max

int main(){
	int c, len, i;
	len = 0;
	printf("Type your input. Horizontal histogram of each word in your input according to their lenghts will be printed: (Max. word length %d characters, rest will be truncated)\n", CHAR_COUNT);
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){ // if a word seperator
			printf("%*s", (CHAR_COUNT + 2) - len, "|"); 

			/* %*s is a format specifier that allows programmer to declare how much space
			 * to allocate for the string. This is being used in order to justify the
			 * output. WC+2 allows us to have space after the longest word. Subtracting the
			 * len is for the dynamic spacing after the words so that | would be justified. 
			*/
			for (i = 0; i < len; ++i)
				printf("=");
			putchar('\n');
			len = 0;
		}
		else{
			if (len > CHAR_COUNT)
				continue;
			putchar(c);
			++len;
		}
	}
}
