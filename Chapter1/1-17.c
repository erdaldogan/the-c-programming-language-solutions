#include<stdio.h>
#define MIN 80
#define MAXLINE 100

int my_getline(char line[], int limit);
void copy(char from[], char to[]);

int main(){
	int len = 0;
	char line[MAXLINE];
	
	while ((len = my_getline(line, MAXLINE)) > 0){
		if (len > MIN)
			printf("%s", line);
	}
	return 0;
	
}

int my_getline(char line[], int limit){
	int i, c;

	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n'){
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;	
}

void copy(char from[], char to[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
