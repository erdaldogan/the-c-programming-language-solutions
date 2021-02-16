#include<stdio.h>

int main(){
	float fahrenheit, celcius;
	float lower, step;	
	lower = 0;
	step = 20;
		
	printf("\n\nFahrenheit\tCelcius (In Reverse)\n");
	for (fahrenheit = 300; fahrenheit >= lower; fahrenheit -= step)
		printf("%10.0f\t%7.2f\n", fahrenheit, (5.0/9.0) * (fahrenheit - 32));
	
}
