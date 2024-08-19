#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

int* converter(int n);
int* negative_converter(int n);
void xor_op(int* a, int flag);
int bin_to_decimal(int* a);

int main()
{
	int x, z;

	printf("x: ");
	scanf("%d", &x);

	printf("z: ");
	scanf("%d", &z);

	int f_xor = x ^ z;
	int* f_xorc;

	if (f_xor < 0)
	{
		f_xorc = negative_converter(f_xor);
		xor_op(f_xorc, 1);
	}
	else
	{
		f_xorc = converter(f_xor);
		xor_op(f_xorc, 0);
	}

	return 0;
}

int bin_to_decimal(int* a)
{
	int n = 0;

	for (int i = 0; i < SIZE/2; ++i)
		n = n + a[i] * pow(2, i);

	return n;
}

void xor_op(int* a, int flag)
{
	int* b1 = calloc(SIZE/2, sizeof(int));
	int* b2 = calloc(SIZE/2, sizeof(int));

	for (int i = 0; i < SIZE/2; ++i)
	{
		b1[i] = a[i];
		b2[i] = a[i+15];
	}

	int n1 = bin_to_decimal(b1);
	int n2 = bin_to_decimal(b2);
	int s_xor = n1 ^ n2;

	if (flag) s_xor--;

	printf("%d\n", s_xor);

	free(b1);
	free(b2);
}

int* converter(int n)
{
	int* bin = calloc(SIZE, sizeof(int));

	int i = 0;
	while (n > 0) {
		bin[i] = n % 2;
		n = n / 2;
		i++;
	}

	return bin;

	free(bin);
}

int* negative_converter(int n)
{
	int* rev_bin = converter(n*-1);

	for (int i = 0; i < SIZE-1; ++i)
	{
		if (rev_bin[i] == 0) rev_bin[i] = 1;
		else rev_bin[i] = 0;
	}

	return rev_bin;

	free(rev_bin);
}
