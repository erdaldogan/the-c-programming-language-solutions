#include<stdio.h>
#define TABWIDTH 8
#define MAXLINE 1000

int my_getline(char str[], int limit);
void detab(char str[], int tab_width);
void copy(char from[], char to[]);

int main(){
	int len;
	char line[MAXLINE];
	
	while ((len = my_getline(line, MAXLINE)) > 0){
		printf("Original: \t%s\n", line);
		detab(line, TABWIDTH);
		printf("Detabbed: \t%s\n", line);
	}

}

int my_getline(char str[], int lim){
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		str[i] = c;
	if (c == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return i; 
}

void detab(char str[], int tw){
	/* 
	Copy each char in the given string to a tmp string iteratively, until the end of the string.
	When a \t is found, put tw amount of blanks in the tmp string.
	Finally, copy tmp strig to the original
	*/
	int i, j, c;
	char tmp[MAXLINE];

	i = 0; // index for original string
	j = 0; // index for tmp string	
	while ((c = str[i++]) != '\0' && c != EOF){
		if(c == '\t'){
			for (int k = 0; k < tw; k++)
				tmp[j++] = ' ';
		}
		else{
			tmp[j++] = c;	
		}
	}
	tmp[j] = '\0';
	copy(tmp, str);
}

void copy(char from[], char to[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
