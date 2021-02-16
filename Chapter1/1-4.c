#include<stdio.h>

int main(){
	float fahrenheit, celcius;
	float lower, upper, step;	
	lower = 0;
	upper = 300;
	step = 20;

	celcius = lower; 
	printf("\nCelcius\tFahrenheit\n");
	while (celcius <= upper){
		fahrenheit = (9.0/5.0) * celcius + 32;
		printf("%7.0f\t%10.2f\n", celcius, fahrenheit);
		celcius += step;
	}
	
}
