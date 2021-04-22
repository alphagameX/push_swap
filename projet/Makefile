
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
		$(wildcard src/checker/*.c) \
		src/parse.c
		
all:
	@make all -C libft
	@gcc -o $(PS) $(PUSH) -Llibft -l ft 
	@gcc -o $(CH) $(CHECK) -Llibft -l ft 

clean:
	@rm -rf $(PS)
	@rm -rf $(CH) 

fclean: clean
	@make fclean -C libft

re: fclean all

run: re
	@valgrind --leak-check=full ./push_swap 2 10 10 | ./checker 2 10 10

valgrind:
	@sh ../valgrind/run.sh
	