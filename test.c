#include "combinations.h"

#define ITEMSIZE(arr) (sizeof(arr[0]))
#define ARRLEN(arr) (sizeof(arr) / ITEMSIZE(arr))

int callback_char(void *comb, void *arg)
{
	size_t n = *(size_t *)arg;
	char *curcomb = (char *)comb;
	size_t i;

	printf("{ ");
	for (i = 0; i < n; ++i)
		printf("'%c' ", curcomb[i]);
	printf("}\n");

	return 0;
}

int callback_int(void *comb, void *arg)
{
	size_t n = *(size_t *)arg;
	int *curcomb = (int *)comb;
	size_t i;

	printf("{ ");
	for (i = 0; i < n; ++i)
		printf("%d ", curcomb[i]);
	printf("}\n");

	return 0;
}

int main()
{
	char carr[] = { 'a', 'b', 'c', 'd' };
	int iarr[] = { 1, 2, 3, 4, 5, 6, 7 };
	size_t n;

	n = 2;
	combinations(carr, ITEMSIZE(carr), ARRLEN(carr), n, callback_char, (void *)&n);
	printf("--------------------\n");
	n = 6;
	combinations(iarr, ITEMSIZE(iarr), ARRLEN(iarr), n, callback_int, (void *)&n);

	return 0;
}
