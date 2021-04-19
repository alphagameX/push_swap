#include "global.h"

void rotate(t_ps *app, char *line) {
  if(ft_strncmp(line, "ra", 2))
    r(&app->a, app->size_a);
  if(ft_strncmp(line, "rb", 2))
    r(&app->b, app->size_b);
  if(ft_strncmp(line, "rra", 2))
    rr(&app->a, app->size_a); 
  if(ft_strncmp(line, "rrb", 2))
    rr(&app->b, app->size_b); 
}

void

int main(int argv, char **argc) {
    t_ps app;
    char *line;
    int ret;

    if(argv < 2)
		  return (0);
    init_app(&app);
    parse_args(&app.a, &app.size_a, argv, argc);

    ret = 1;
    while(ret) {

      if((ret = get_next_line(0, &line)) == -1)
        break;

      rotate(&app, line);
      push(&app, line);
    }

    //show_pile(app.a, app.size_a);

    return(0);
}