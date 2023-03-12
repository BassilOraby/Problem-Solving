/* log2 example */
#include <stdio.h>      /* printf */
#include <cmath>

int main()
{
	double result;
	int param;
	param = 16;
	result = log2(param);
	printf("log2 (%d) = %f.\n", param, result);
	(floor(result) == result) ? printf("True") : printf("False");
	return 0;
}