
PS = push_swap
CH = checker

PILE = 	$(wildcard src/pile/*.c) \
		$(wildcard src/pile/basic/*.c) \
		$(wildcard src/pile/garbage/*.c) 

MOVING = $(wildcard src/moving/rules/*.c) \
		 $(wildcard src/moving/step_1/*.c) \
		 $(wildcard src/moving/step_2/*.c) \
		 $(wildcard src/moving/step_3/*.c) 

PUSH =  $(PILE) \
		$(MOVING) \
		src/main.c src/parse.c

CHECK = $(PILE) \
		$(MOVING) \
		src/check.c src/parse.c
		

all:
	@make all -C libft
	@gcc -o $(PS) $(PUSH) -Llibft -l ft 
	@gcc -o $(CH) $(CHECK) -Llibft -l ft 

fclean:
	@make fclean -C vendor/libft
	@rm -rf $(PS)
	@rm -rf $(CH) 

re: fclean all

run: re
	@valgrind ./push_swap 2 3 1 4 5 8 10 | ./checker 2 3 1 4 5 8 10

valgrind:
	@sh ../valgrind/run.sh
	


visual:
	python3 push_swap_visualizer/pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`


	