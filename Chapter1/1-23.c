#include<stdio.h>
#define MAXLINE 1000

int read_input(char input[], int lim);
void remove_comments(char input[], int lim);
void copy(char from[], char to[]);

int main(){
	int len;
	char input[MAXLINE];

	while ((len = read_input(input, MAXLINE)) > 0){
		printf("Original:\n\n%s\n", input);
		remove_comments(input, MAXLINE);
		printf("\nUncommented:\n\n%s\n", input);
	}
}

int read_input(char input[], int lim){
	int i, c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++){
		input[i] = c;
	}
	input[i] = '\0';
	return i;
}

void remove_comments(char input[], int lim){
	int i, j; // index for input and temp string, respectively
	int c; // variable for iterating character-wise
	char tmp[lim];
	int in_block = 0;

	i = j = 0;
	while ((c = input[i++]) != '\0'){
		if (c == '\"'){
			tmp[j++] = '\"';
			while ((c = input[i++]) != '\"')
				tmp[j++] = c;
			tmp[j++] = '\"';
		}
		else if (c == '/'){
			c = input[i++];
			if (c == '*'){
				in_block = 1;
			}
			else if (c == '/')
				while ((c = input[i]) != '\n')
					i++;
		}
		else if (in_block){
			if (c == '*' && (c = input[i++] == '/'))
				in_block = 0;
		}
		else{
			tmp[j++] = c;
		}
	}
	copy(tmp, input);
}
void copy(char from[], char to[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
