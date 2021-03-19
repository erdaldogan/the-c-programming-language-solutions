#include<stdio.h>

void squeeze(char s1[], char s2[]);

int main(){
	char s1[] = "strange times";
	char s2[] = "ai";
	char s3[] = "quick brown fox jumps over the lazy dog"; // every char in alphabet. try using this instead of s2 

	printf("s1: %s\ns2: %s\n", s1, s2);
	squeeze(s1, s2);
	printf("Squeezed: %s", s1);
}

void squeeze(char s1[], char s2[]){
	/* only lower-case letters */

	int alphabet[26] = {0}; // every element corresponds to a char in alphabet 
	int i, j, c;

	i = j = 0;
	while ((c = s2[i++]) != '\0'){
		if (c == ' '){
			continue;
		}
		alphabet[c - 'a'] = 1; // if a char is present in s2, corresponding position will be marked as 1
	}
	
	i = 0;
	while ((c = s1[i++]) != '\0'){
		if(alphabet[c - 'a'] == 0){
			s1[j++] = c;	
		}
	}
	s1[j] = '\0';
}
