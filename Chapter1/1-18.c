#include<stdio.h>
#define MAXLINE 100

int my_getline(char line[], int limit);
void trim_blanks(char line[], int len);

main(){
	int len;
	char line[MAXLINE];
	while((len = my_getline(line, MAXLINE)) > 0){
		if (len == 1)
			continue;
		trim_blanks(line, len);
		printf("Content:\n\t%s\n", line);
	}
	return 0;
}

int my_getline(char line[], int limit){
	int i, c;
	for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i){
		line[i] = c;
	}
	if (c == '\n'){
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return i;
}

void trim_blanks(char line[], int len){
	/*
	Idea is to use i as a pointer to last non blank/tab character.
	Iterate backwards until the current char is neither blank nor tab.
	When you reach to last valid char, append newline and end of string respectively.
	 */

	int i = len - 2; // last two chars are \n and \0

	for (; line[i] == ' ' || line[i] == '\t'; --i)
		;
	
	line[++i] = '\n';
	line[++i] = '\0';
}
