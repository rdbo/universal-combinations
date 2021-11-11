#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <stdio.h>

int combinations(void *arr, size_t size, size_t len, size_t n, int (*callback)(void *comb, void *arg), void *arg);

#endif
