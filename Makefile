all:
	gcc -o test -g -Wall -Wextra -Wpedantic test.c combinations.c
clean:
	if [ -f test ]; then rm test; fi