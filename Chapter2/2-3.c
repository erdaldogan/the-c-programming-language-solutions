#include<stdio.h>
#define MAXLEN 10

/* 
Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
*/

unsigned int htoi(char hex[]);

int main(){
	int i = 0;
	int c;
	char in[MAXLEN];

	printf("Enter an hexadecimal number (optional 0x or 0X, max. 10 chars): ");
	while ((c = getchar()) != '\n' && i < MAXLEN - 1){
		in[i++] = c;
	}
	in[i] = '\0';
	printf("Your input in hex: %s\n", in);
	printf("Your input converted to decimal: %u\n", htoi(in));
	return 0;

}

unsigned int htoi(char h[]){
	int i = 0;
	unsigned short int num; // decimal value of hex digit,
	char c; // temp variable for storing hex chars
	unsigned int dec = 0; // decimal correspondence of hex

	if (h[0] == '0' && (h[1] == 'x' || h[1] == 'X')){
		i = 2;
	}	
	while ((c = h[i++]) != '\0'){
		if (c >= '0' && c <= '9'){
			num = c - '0';	
		}
		else if (c >= 'a' && c <= 'f'){
			num = c - 'a' + 10;
		}
		else if (c >= 'A' && c <= 'F'){
			num = c - 'A' + 10;
		}
			
		dec = 16 * dec + num;	
	}
	return dec;

}
