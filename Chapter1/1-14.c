#include<stdio.h>
#define CHAR_COUNT 128

int main(){
	int chars[CHAR_COUNT] = {0};
	int c, i, j, freq;
	freq = 0;	
	while ((c = getchar()) != EOF){
		++chars[c];
	}

	for (i = 33; i < CHAR_COUNT; ++i){ // 33 is where the human-readable chars start at ASCII
		freq = chars[i];
		if (freq > 0){
			printf("%*c|", 2, i);
			for (j = 0; j < freq; ++j)
				printf("=");
			putchar('\n');
		}
	}

}
