#include<stdio.h>
#define MAXLINE 1000
#define TABWIDTH 8
#define COLWIDTH 30

int my_getline(char line[], int limit);
void fold(char line[], int column_width);
void copy(char from[], char to[]);
int blank_or_tab(int c);

int main(){
	int len;
	char line[MAXLINE];

	printf("Type the input and press <Enter>. It will be broken into lines that contain 30 characters at max.\n");
	while ((len = my_getline(line, MAXLINE)) > 0){
		printf("\nOriginal: \n\n%s\n", line);
		fold(line, COLWIDTH);
		printf("Folded: \n\n%s\n", line);	
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

void fold(char line[], int cw){
	int i, j; // index for input and temp strings, respectively
	int lw; // width of each line
	int c; // temporary variable for iterating character-wise
	char tmp[MAXLINE];
	
	i = j = 0;
	lw = 0;
	while ((c = line[i]) != '\0'){
		lw++;
		if (lw > cw){ // line width exceeds the column width
			while (!blank_or_tab(c = line[i--])){ // iterate backward until the last blank or tab before 'cw'-th column
				j--;
			}	
			tmp[j++] = '\n'; // append newline at the first space position before 'cw'-th column
			while (!blank_or_tab(c = line[++i]) && c != '\0'){
				tmp[j++] = c; // append chars until the end of word that had to be splitted at the edge
			}
			lw = 0; // reset the linewidth counter since a new line has been created 
		}
		else{
			tmp[j++] = c;
		}
		i++;
	}
	tmp[j] = '\0';
	copy(tmp, line);
}

void copy(char from[], char to[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}

int blank_or_tab(int c){ // blank or tab
	/* 
	   this function allows us to use '\t' and ' ' in the input interchangeably
	 */
	return c == ' ' || c ==  '\t';
}
