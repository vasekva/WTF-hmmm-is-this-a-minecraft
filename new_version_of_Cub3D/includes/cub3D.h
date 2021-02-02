
#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"

#include "libft.h"

# define WIDTH 0
# define HEIGHT 0


typedef struct  s_map
{
    char        *north;
    char        *south;
    char        *west;
    char        *east;
    char        *sprite;
}               t_map;

typedef struct  s_screen
{
    int         w;
    int         h;
}               t_screen;

typedef struct  s_ceiling
{
    int         r;
    int         g;
    int         b;
}               t_ceiling;

typedef struct  s_floor
{
    int         r;
    int         g;
    int         b;
}               t_floor;

typedef struct  s_cub3D
{
    t_screen    *screen;
    t_map       *map;
    t_floor     *floor;
    t_ceiling   *ceiling;
    int         count_of_recorded_values;
}               t_cub3D;

/*
* Убрать
*/
void    ft_print_structs(t_cub3D *cub3D);

int     ft_parse(char *map, t_cub3D *cub3D);
int		get_next_line(int fd, char **line);
int 	ft_write_color(char *str, char flag, t_cub3D *cub3D);

int		ft_parse_int(char *str);

int     ft_isidentifier(char *str);

#endif