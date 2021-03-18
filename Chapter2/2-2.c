#include<stdio.h>

/* 

Exervise 2.2 Re-write the for loop below without using && or || operators

for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;

*/

int main(){
	int i;
	for(i = 0; i < lim - 1; i++){
		if((c = getchar()) != '\n'){
			if(c != EOF){
				s[i] = c;
			}	
			else { break; }	
		}
		else { break; }
	}	
}
