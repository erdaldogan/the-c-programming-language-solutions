#include<stdio.h>
#define MAXLINE 100

int my_getline(char line[], int lim);
void reverse(char str[], int len);

int main(){
	int len;
	char line[MAXLINE];
	while((len = my_getline(line, MAXLINE)) > 0){
		printf("Len: %d\n", len);
		printf("Original: %s", line);
		reverse(line, len);
		printf("Reversed: %s", line);
	}
}

int my_getline(char line[], int lim){
	int i, c;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n'){
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return i;	
}

void reverse(char str[], int len){
	int i, j, tmp;
	
	i = 0;
	j = len - 2; // last two characters are newline and end of str, \n & \0
	while (i < j){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++, j--;
	}
}
