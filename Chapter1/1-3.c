#include<stdio.h>

int main(){
	float fahrenheit, celcius;
	float lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	
	fahrenheit = lower;
	printf("Fahrenheit\tCelcius\n");
	while (fahrenheit <= upper){
		celcius = (5.0/9.0) * (fahrenheit - 32);
		printf("%10.0f\t%7.2f\n", fahrenheit, celcius);
		fahrenheit += step;
	}
}
