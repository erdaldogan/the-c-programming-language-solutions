#include<stdio.h>

int fahr2cel(int n); // fahrenheit to celcius

int main(){
	printf("%d Fahrenehit is %d°C\n", 72, fahr2cel(72));	

}

int fahr2cel(int f){
	return 5 * (f - 32) / 9;
}
