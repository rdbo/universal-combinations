#include <malloc.h>
#include <memory.h>

typedef long ssize_t;

void *create_result(void *arr, size_t size, size_t *indices, size_t n)
{
	/*
	 * Create possible result based on indices
	 */

	void *result;
	size_t i;

	result = calloc(n, size);
	if (!result)
		return NULL;
	
	for (i = 0; i < n; ++i) {
		void *src = &((char *)arr)[indices[i] * size]; /* pointer to arr + indices[i] * size */
		void *dst = &((char *)result)[i * size]; /* pointer to result + i * size */
		memcpy(dst, src, size);
	}

	return result;
}

void free_result(void *result)
{
	free(result);
}

int combinations(void *arr, size_t size, size_t len, size_t n, int (*callback)(void *comb, void *arg), void *arg)
{
	/*
	 * Parameters:
	 *   void *arr: array with unique elements
	 *   size_t size: size of each element of the array
	 *   size_t len: length of the array
	 *   size_t n: number of items per combination
	 *   int (*callback)(void *comb, void *arg): callback for each combination
	 *   void *arg: optional argument for the callback
	 */

	size_t *indices;
	size_t i;
	ssize_t j;
	void *comb;
	int cbret;
	int ret = -1;

	if (n > len)
		return ret;
	
	indices = (size_t *)calloc(n, sizeof(size_t));
	if (!indices)
		return ret;
	
	for (i = 0; i < n; ++i) /* set initial indices */
		indices[i] = i;
	
	/* create first combination */
	comb = create_result(arr, size, indices, n);
	if (!comb)
		return ret;
	
	cbret = callback(comb, arg);
	free_result(comb);
	if (cbret)
		goto EXIT_OK;
	
	/* generate remaining combinations */
	for (;;) {
		for (j = (long)n - 1; j >= 0; --j) {
			if (indices[j] < len + j - n) /* check if indices[j] is its highest possible value */
				break;
		}

		if (j < 0) /* loop didn't break, all indices are their highest possible value */
			break;

		++indices[j]; /* increment first not maxed out index */

		for (i = (size_t)(j + 1); i < n; ++i)
			indices[i] = indices[i - 1] + 1; /* set all indices after the first not maxed out one to their lowest value */

		/* create current combination */
		comb = create_result(arr, size, indices, n);
		if (!comb)
			return ret;
		
		cbret = callback(comb, arg);
		free_result(comb);
		if (cbret)
			goto EXIT_OK;
	}

EXIT_OK:
	ret = 0;
	return ret;
}
