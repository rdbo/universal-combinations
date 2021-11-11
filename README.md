# Universal Combinations Algorithm in C
```c
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
```
Result:
```
{ 'a' 'b' }
{ 'a' 'c' }
{ 'a' 'd' }
{ 'b' 'c' }
{ 'b' 'd' }
{ 'c' 'd' }
--------------------
{ 1 2 3 4 5 6 }
{ 1 2 3 4 5 7 }
{ 1 2 3 4 6 7 }
{ 1 2 3 5 6 7 }
{ 1 2 4 5 6 7 }
{ 1 3 4 5 6 7 }
{ 2 3 4 5 6 7 }
```
