#include<stdio.h>
#include<limits.h>
#include<math.h>

int main(){
	printf("Header File:\n");
	printf("\tUnsigned 'char' MIN: %d, MAX: %d\n", 0, UCHAR_MAX);
	printf("\tUnsigned 'short' MIN %d, MAX: %d\n", 0, USHRT_MAX);
	printf("\tUnsigned 'int' MIN: %d, MAX: %u\n", 0, UINT_MAX);
	printf("\tUnsigned 'long' MIN: %d, MAX: %lu\n", 0, ULONG_MAX);
	putchar('\n');
	printf("\tSigned 'char' MIN: %d, MAX: %d\n", CHAR_MIN, CHAR_MAX);
	printf("\tSigned 'short' MIN %d, MAX: %d\n", SHRT_MIN, SHRT_MAX);
	printf("\tSigned 'int' MIN: %d, MAX: %d\n", INT_MIN, INT_MAX);
	printf("\tSigned 'long' MIN: %lu, MAX: %lu\n", LONG_MIN, LONG_MAX);


	printf("\nComputation:\n");
	printf("\tUnsigned 'char' MIN: %d, MAX: %.0f\n", 0, pow(2, CHAR_BIT) - 1);
//	printf("\tUnsigned 'short' MIN %d, MAX: %.0f\n", 0, pow(2, SHRT_BIT));
	printf("\tUnsigned 'int' MIN: %d, MAX: %0.f\n", 0, pow(2, WORD_BIT) - 1);
	printf("\tUnsigned 'long' MIN: %d, MAX: %0.f\n", 0, pow(2, LONG_BIT) - 1);
	putchar('\n');
	printf("\tSigned 'char' MIN: %.0f, MAX: %.0f\n", -1 * pow(2, CHAR_BIT - 1), pow(2, CHAR_BIT - 1) -1);
//	printf("\tSigned 'short' MIN %.0f, MAX: %.0f\n", -1 * pow(2, SHRT_BIT - 1), SHRT_MAX);
	printf("\tSigned 'int' MIN: %.0f, MAX: %.0f\n", -1 * pow(2, WORD_BIT - 1), pow(2, WORD_BIT - 1) - 1);
	printf("\tSigned 'long' MIN: %.0f, MAX: %.0f\n", -1 * pow(2, LONG_BIT - 1), pow(2, LONG_BIT - 1) - 1);
}
