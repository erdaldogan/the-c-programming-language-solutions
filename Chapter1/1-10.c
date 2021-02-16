#include<stdio.h>
// exercise 1.10
// on unix use CTRL^H to give \b as input, CTRL^D as EOF
int main(){
	int c;
	while ((c = getchar()) != EOF){
		if (c == '\b'){
			putchar('\\');
			putchar('b');
		}
		else if (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		else if (c == '\\'){
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(c);
	}
}
