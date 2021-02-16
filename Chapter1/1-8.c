#include<stdio.h>

int main(){
	int b = 0, t = 0, nl = 0;
	int c;
	
	while(c != EOF){
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++t;
		else if (c == ' ')
			++b;
		c = getchar();
	}
	printf("\nNewlines: %d\nTabs: %d\nSpaces: %d\n", nl, t, b);
}
