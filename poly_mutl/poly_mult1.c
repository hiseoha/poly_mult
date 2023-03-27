#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_mult(polynomial A, polynomial B);

polynomial poly_mult(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;

	int i, j;

	for (i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;
	C.degree = A.degree + B.degree;

	for (i = 0; i < A.degree + 1; i++)
		for (j = 0; j < B.degree + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];

	return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a = { 3, {4, 3, 2, 1,} };
	polynomial b = { 2, {3, 2, 8} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_mult(a, b);
	printf("----\n°á°ú: ");
	print_poly(c);

	return 0;
}