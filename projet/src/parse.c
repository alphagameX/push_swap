#include "global.h"
#include "stdio.h"

void init_app(t_ps *app) {
	app->a = init_pile();
	app->b = init_pile();
	app->size_a = 0;
	app->size_b = 0;
}

static int		is_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == '\f' || c == '\r' ||
		c == '\v' || c == ' ')
		return (1);
	return (0);
}

long ft_atol(char *str) {
	int				i;
	int				sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int ft_is_number(char *str) {
	int i;

	i = 0;
	if(str == NULL || *str == '\0')
		return (0);
	while(str[i] != '\0') {
		if(ft_isdigit((int)str[i]) == 0 && str[i] != '-')
			return (0);
		i++;
	} 
	return (1);
}

void parse_args(t_pile **pile_a, int *size, int argv, char **argc) {
	int arg;
	long value;

	arg = 1;
	while(arg < argv) {
		
		value = ft_atol(argc[arg]);
		if(value > INT_MAX || !ft_is_number(argc[arg])) {
			free_pile(pile_a, *size);
			ft_printf("Error\n");
			exit(0);
		}
		add_to_end(pile_a, size, (int)value);
		arg++;
	} 
	if(has_duplicate(*pile_a, *size) == true) {
		free_pile(pile_a, *size);
		ft_printf("Error\n");
		exit(0);
	}
}