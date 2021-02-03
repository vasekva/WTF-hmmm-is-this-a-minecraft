
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

typedef struct	s_parse
{
	int			c_screen_size;
	int			c_color_floor;
	int			c_color_ceiling;
    int         c_north;
    int			c_south;
	int			c_west;
	int			c_east;
	int			c_sprite;
    int         count_of_recorded_values;
	int			count_of_map_lines;
	int			max_strlen_of_map;
}				t_parser;

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
	char		*file_path;
    t_screen    *screen;
    t_map       *map;
    t_floor     *floor;
    t_ceiling   *ceiling;
	t_parser	*parser;
	char		*cub;
	char		**array;
}               t_cub3D;

/*
* Убрать
*/
void    ft_print_structs(t_cub3D *cub3D);

int     ft_parse(t_cub3D *cub3D);
int		get_next_line(int fd, char **line);
int 	ft_write_color(char *str, char flag, t_cub3D *cub3D);

int		ft_parse_int(char *str);

int     ft_isidentifier(char *str);

#endif