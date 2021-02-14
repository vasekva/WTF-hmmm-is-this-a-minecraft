
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#include "mlx.h"
#include "libft.h"

# define PI 3.1415926535
# define PI2 (PI / 2)
# define PI3 ((3 * PI) / 2) 

# define WIDTH 0
# define HEIGHT 0

# define UP		    13
# define DOWN	    1
# define LEFT	    0
# define RIGHT      2
# define LEFT_A	    123
# define RIGHT_D	124
# define ESC	    53

# define SIZE_OF_CUB 100
# define SIZE_OF_PLAYER (SIZE_OF_CUB / 2)
// # define MOVESPEED 35
# define LONG_VIEW 8

// # define color_of_wall_minimap 0x00808080
# define color_of_wall_minimap  0x00FF9933
# define color_of_field_minimap 0x00000000
# define color_of_background    0x00696969

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
    int         center_w;
    int         center_h;
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

typedef struct	s_mlx
{
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_mlx;

typedef struct  	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

typedef struct      s_player2D
{
    int             color_minicubeRU;
    int             color_minicubeRD;
    int             color_minicubeLU;
    int             color_minicubeLD;
    int             color_of_player;
    int             color_of_cross;
}                   t_player2D;

typedef struct      s_player
{
    t_player2D      *player2D;
    int             arrayX;
    int             arrayY;
    int             leftKey;
    int             rightKey;
    int             upKey;
    int             downKey;
    int             escKey;
    int             leftAKey;
    int             rightDKey;
    double			degree;
    double			posX;
	double			posY;
    double			posDirX;
    double			posDirY;
    double			posA;
}                   t_player;

typedef struct  s_cub3D
{
	char		*file_path;
    t_screen    *screen;
    t_map       *map;
    t_floor     *floor;
    t_ceiling   *ceiling;
	t_parser	*parser;
	char		**array;
    t_env       *env;
	t_mlx		*mlx_img;
	t_player	*player;
}               t_cub3D;

/*
* Убрать
*/
void    ft_print_structs(t_cub3D *cub3D);
int		get_next_line(int fd, char **line);
void	print_DDALine(float x1, float y1, float x2, float y2, t_cub3D *cub3D, int color);

void	ft_draw_rays(t_cub3D *cub3D);

/*
* event_handle01.c
*/
    int	keyrelease_hook(int key, void *param);
    int	keypress_hook(int key, void *param);

/*
* ft_parse.c
*/
    int     ft_parse(t_cub3D *cub3D);
/*
* static int 	check_identifier(char *str, t_cub3D *cub3D)
* static int 	ft_read_path(char *str, t_cub3D *cub3D, char *flag)
* static int 	ft_parse_screen_size(char *str, t_cub3D *cub3D)
* static int 	check_line(char *str, t_cub3D *cub3D)
* static void	ft_count_mapsize
*/


/*
* ft_start_game.c
*/
    void	ft_start_game(t_cub3D *cub3D);
/*
* static void		ft_fill_background(t_cub3D *cub3D)
* static void		ft_draw_user(t_cub3D *cub3D)
* static void		ft_draw_corner_cubes(t_cub3D *cub3D, char hor_flag, char vert_flag, int color)
* static void		ft_draw_cross2D(t_cub3D *cub3D)
* static void		draw_cub_in_pixel2D(int x, int y, int size, int color, t_cub3D *cub3D)
* static void		ft_draw_cub_from_cubs(t_cub3D *cub3D) // вызывается в ft_start_game
* static void		draw_cub_in_pixel(int y, int x, t_cub3D *cub3D) // TODO сменить у и x местами
* static void		my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
*/

/*
* ft_utils.c
*/
    int		    ft_isidentifier(char *str);
    int		    ft_parse_int(char *str);

/*
* ft_write_color.c
*/
	int 	ft_write_color(char *str, char flag, t_cub3D *cub3D);

/*
* init_array.c
*/
    void		init_array(t_cub3D *cub3D);
/*
* static void	read_and_copy_in_array(t_cub3D *cub3D)
* static int	ft_check_line_map(char *line, int number_of_line, t_cub3D *cub3D)
* static int	check_line_for_map(char *line)
*/

/*
* init_structs01.c
*/
    t_screen    *init_screen(t_screen *screen);
    t_map       *init_map(t_map *map);
    t_floor     *init_floor(t_floor *floor);
    t_ceiling   *init_ceiling(t_ceiling *ceiling);
    t_parser 	*init_parser(t_parser *parser);

/*
* init_structs02.c
*/
    t_env       *init_env(t_env *env, t_cub3D *cub3D);
    t_player	*init_player(t_player *player, t_cub3D *cub3D);
    t_mlx		*init_mlx_img(t_mlx *mlx_img);
    t_player	*init_player(t_player *player, t_cub3D *cub3D);

#endif