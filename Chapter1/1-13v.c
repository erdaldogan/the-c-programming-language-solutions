#include<stdio.h>
#define CHAR_COUNT 10

// exercise 1.13

int main(){
	int c, len, i, j, wc;
	int longest;
	len = wc = longest = 0;
	int wl[CHAR_COUNT];
	printf("Start typing your intput. In order to print the histogram you must type EOF(Ctrl-D in *nix) at the beginning of a line.\n");
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			wl[wc] = len;	
			if (len > longest)
				longest = len;
			++wc;
			len = 0;
		}
		else{
			if (len > CHAR_COUNT)
				continue;
			++len;
		}
	}
	printf("\n");
	for (i = 0; i <= longest; ++i){
		printf("%*d|", 3, longest - i);
		for (j = 0; j < wc; ++j){
			if (i == longest){
				printf("========");
			}
			else if ((longest - i) <= wl[j])
				printf("\t*");
			else
				printf("\t ");

		}
		printf("\n");
	}	
	for (i = 0; i < wc; ++i)
		printf("  \t%d", i);
	printf("\nX Axis: Position of the word in the input. 0: first word, 1: second...");
	printf("\nY Axis: # of characters.\n");
	return 0;
}
