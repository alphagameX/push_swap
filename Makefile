
PS = push_swap
CH = checker

FILE =  $(wildcard src/*.c) \
		$(wildcard src/pile/*.c) \
		$(wildcard src/garbage/*.c) 

all:
	@gcc -o $(PS) $(FILE) -Lvendor/libft -l ft 

test:
	@node vendor/script/index.js

visual:
	python3 push_swap_visualizer/pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
