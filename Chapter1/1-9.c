#include<stdio.h>
/* exercise 1.9 */

int main(){
	int c, prev;
	prev = ' ';
	
	while ((c = getchar()) != EOF){
		while (c == ' ' && prev == ' '){
			c = getchar();
		}
		putchar(c);
		prev = c;
	}

}
