
PS = push_swap
CH = checker

FILE = $(wildcard src/*.c)

FILE_PS = $(wildcard src/ps/*.c) $(FILE)
FILE_CH = $(wildcard src/ch/*.c) $(FILE)


all:
	@gcc $(FILE_PS) -o $(PS) -Lvendor/libft -l ft
	@gcc $(FILE_CH) -o $(CH) -Lvendor/libft -l ft

tester:
	@node vendor/script/index.js