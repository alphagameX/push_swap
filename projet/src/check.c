#include "global.h"
#include <stdlib.h>
#include "limits.h"

void rotate(t_ps *app, char *line, int *len) {
  if(ft_strncmp(line, "ra", 2) == 0) {
    r(&app->a, app->size_a);
    *len += 1;
   
  }

  if(ft_strncmp(line, "rb", 2) == 0) {
    r(&app->b, app->size_b);
    *len += 1;
  
  }

  if(ft_strncmp(line, "rra", 3) == 0) {
    rr(&app->a, app->size_a);
    *len += 1;
   
  }

  if(ft_strncmp(line, "rrb", 3) == 0) {
    rr(&app->b, app->size_b); 
    *len += 1;
  }


}

void push_swap(t_ps *app, char *line, int *len) {
  if(ft_strncmp(line, "pb", 2) == 0) {
      p(&app->b, &app->a, &app->size_b, &app->size_a);
      *len += 1;
  }
   if(ft_strncmp(line, "pa", 2) == 0) {
      p(&app->a, &app->b, &app->size_a, &app->size_b);
      *len += 1;
  }
  if(ft_strncmp(line, "sa", 2) == 0) {
    s(&app->a, app->size_a);
    *len += 1;
  }
  if(ft_strncmp(line, "sb", 2) == 0) {
    s(&app->b, app->size_b);
    *len += 1;
  }
}

void all(t_ps *app, char *line, int *len) {
  if(ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2) {
    rs(&app->a, &app->b, &app->size_a, &app->size_b);
    *len += 1;
    
  }
  if(ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3) {
    rrs(&app->a, &app->b, &app->size_a, &app->size_b);
    *len += 1;
   
  }
  if(ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2) {
    ss(app);
    *len += 1;
    
  }
    
}

int check_authorized(char *str) {
    static char *authorized[] = {
      "sa", "sb", "rra", "rrb", "rr", "ra", "rb", "rrr", "pa", "pb", "ss", NULL
    };
    int i;
    int compare;

    i = 0;
    compare = 0;
    while(authorized[i] != NULL) {
      if(ft_strncmp((const char *)str, (const char *)authorized[i], ft_strlen(authorized[i]) + 1) == 0)
        compare = 1;
      i++;
    }
    return (compare);
} 

int main(int argv, char **argc) {
    t_ps app;
    char *line;
    int ret;
    int len = 0;
  
    if(argv < 2)
		  return (0);
    init_app(&app);
    parse_args(&app.a, &app.size_a, argv, argc);
    ret = 1;
    while(ret) {
      if((ret = get_next_line(0, &line)) == -1 || (check_authorized(line) == 0 && *line != '\0')) {
        free_pile(&app.a, app.size_a);
        free_pile(&app.b, app.size_b);
        ft_putstr("Error\n");
        exit(1);
      }

      rotate(&app, line, &len);
      push_swap(&app, line, &len);
      all(&app, line, &len);
    }

    if(is_sorted(app.a, app.size_a))
      ft_putstr("OK\n");
    else
      ft_putstr("KO\n");
    return(0);
}