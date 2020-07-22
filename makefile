cmd = gcc -Wall -Werror -Wextra -Wno-format -pedantic -g
file = main1.c

main: 
	clear;
	@betty *.c holberton.h
	@test ! -e a.out || rm a.out
	cp test/$(file) .
	$(cmd) *.c; rm $(file)
	@./a.out

main2:
	clear;
	@test ! -e a.out || rm a.out
	$(cmd) $(file)
	@./a.out

3: file=3-strcpy.c
3: main

4: file=4-string.c
4: main

5: file=5-for-string.c
5: main

6: file=6-int.c fsubc.c fsubs.c
6: mai
