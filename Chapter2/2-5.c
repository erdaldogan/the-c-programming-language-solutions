#include<stdio.h>

int any(char s1[], char s2[]);

int main(){
	char s1[] = "hello world!";
	char s2[] = "w";
	printf("s1: %s\ns2: %s\n", s1, s2);
	printf("First index of chars in s2 in s1: %d\n", any(s1, s2));
}

int any(char s1[], char s2[]){
	int i = 0;
	int alphabet[26] = {0};
	int c;

	while((c = s2[i++]) != '\0'){
		alphabet[c - 'a'] = 1;	
	}
	
	i = 0;
	while((c = s1[i]) != '\0'){
		if (c == ' ') {
			;
		}
		else if (alphabet[c - 'a'] == 1){
			return i;
		}
		i++;
	}
	return -1;
}
