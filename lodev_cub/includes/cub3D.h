
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#include "mlx.h"
#include "libft.h"
#include "exception.h"

# define UP		    13
# define DOWN	    1
# define LEFT_A	    0
# define RIGHT_D    2
# define LEFT	    123
# define RIGHT		124
# define ESC	    53

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

# define MOVE_SPEED 1

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

typedef struct      s_keys
{
    int             leftKey;
    int             rightKey;
    int             upKey;
    int             downKey;
    int             escKey;
    int             leftAKey;
    int             rightDKey;
}                   t_keys;

typedef struct      s_player
{
    double          posX;
    double          posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}                   t_player;

typedef struct      s_map
{
    char            *north;
    char            *south;
    char            *west;
    char            *east;
    char            *sprite;
}                   t_map;

typedef struct      s_screen
{
    int             w;
    int				h;
}					t_screen;

typedef struct		s_floor
{
	int				r;
	int				g;
	int				b;
}					t_floor;

typedef struct		s_ceiling
{
	int				r;
	int				g;
	int				b;
}					t_ceiling;

typedef struct		s_array
{
	int		count_player_point;
	int		size;
	char	**map_arr;
}					t_array;

typedef struct  s_cub3D
{
	char		*file_path;
    t_screen    *screen;
    t_map       *map;
    t_floor     *floor;
	t_ceiling	*ceiling;
    t_env       *env;
    t_mlx		*mlx_img;
	t_keys      *keys;
    t_player    *player;
	t_array		*array;
}               t_cub3D;

int			get_next_line(int fd, char **line);
t_ceiling	*init_ceiling(t_ceiling *ceiling);
t_floor		*init_floor(t_floor *floor);
t_screen	*init_screen(t_screen *screen);
t_map		*init_map(t_map *map);
t_array		*init_array(t_array *array);

t_env       *init_env(t_env *env, t_cub3D *cub3d);
t_mlx		*init_mlx_img(t_mlx *mlx_img);
t_keys		*init_keys(t_keys *keys);
t_player	*init_player(t_player *player);


/*
* event_handle01.c
*/
    int		keyrelease_hook(int key, void *param);
    int		keypress_hook(int key, void *param);

/*
*	exception.c
*/
	void	exception(char *str);
	/*
	 * static	void	ft_print_exception(char *str);
	 */

/*
*	ft_check_array.c
*/
	void	ft_check_array(t_cub3D *cub3d);
	/*
	 * void	ft_check_last_lines(t_cub3D *cub3d);
	 * void	ft_check_top_lines(t_cub3D *cub3d);
	 * void	ft_check_longline(t_cub3D *cub3d, int line, int diff);
	 * void	ft_check_middle_lines(t_cub3D *cub3d, int i);
	 */

/*
* ft_parse.c
*/
	void	ft_parse(t_cub3D *cub3D);

/*
* ft_start_game.c
*/
    void	ft_start_game(t_cub3D *cub3D);



/*
* ft_parse_screen_size.c
*/
	int		ft_parse_screen_size(char *str, t_cub3D *cub3d);
	/*
	 * int			ft_read_height(char *str, int c, t_cub3D *cub3d);
	 * int			ft_read_width(char *str, int c, t_cub3D *cub3d);
	 * int			ft_parse_int(char *str)
	 * static int	ft_pow(int num, int i)
	 */
/*
*	ft_parse_path.c
*/    
	int		ft_parse_path(char *str, t_cub3D *cub3d);
	/*
	* static int ft_read_path(char *str, int start, int len, t_cub3D *cub3D);
	*/

/*
*	ft_parse_color.c
*/
	int		ft_parse_color(char *str, t_cub3D *cub3D);
	/*
	* static int		ft_read_colors(char *str, int i, int start, t_cub3D *cub3D, char identifier);
	* static int		ft_read_color(char *str, int i, char value, t_cub3D *cub3D, char identifier);
	* static int		ft_skip_spaces_and_zeros(char *str, int i);
	* static int		ft_write_color(int color, char symb_of_color, t_cub3D *cub3D, char identifier);
	*/

/*
*	ft_parse_map.c
*/
	int		ft_parse_array(char *str, t_cub3D *cub3d);
	int		ft_check_structs(t_cub3D *cub3d);






#endif