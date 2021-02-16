#include<stdio.h>
#define MAXLINE 100
#define TABWIDTH 8

int my_getline(char line[], int lim);
void entab(char line[], int tabwidth);
void copy(char from[], char to[]);

int main(){
	int len;
	char line[MAXLINE];
	while ((len = my_getline(line, MAXLINE)) > 0){
		printf("Original: \t%s\n", line);
		entab(line, TABWIDTH);
		printf("Entabbed: \t%s\n", line);
	}
}

int my_getline(char line[], int lim){
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}

void entab(char line[], int tw){
	/* 
	Replace the 'tw' number of spaces with \t characters
	In order to sustain similar spacing, append blanks after 'tw' spaces if necessary.
	
	i.e. tw = 8. Replace every 8 blanks with a single tab. If there are 10 consecutive
	blanks; replace with a single \t and 2 blanks.
	*/

	int i, j; // indexes for input and tmp string, respectively
	int blank; // blanks to append
	int c; // temporary variable for character-wise iterartion
	int bc, tc; // blank counter, tab counter
	char tmp[MAXLINE];

	i = 0;	
	j = 0;
	bc = 0;
	while ((c = line[i++]) != '\0'){
		if (c == ' '){
			bc++;
			while ((c = line[i++]) == ' ')
				bc++;
			
			tc = bc / tw; // performs integer division
			while (tc-- > 0)
				tmp[j++] = '\t';
			
			blank = bc % tw;
			while (blank-- > 0)
				tmp[j++] = ' ';
	
			bc = 0;
		}
		tmp[j++] = c;
	}
	tmp[j] = '\0';
	copy(tmp, line);
}

void copy(char from[], char to[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
