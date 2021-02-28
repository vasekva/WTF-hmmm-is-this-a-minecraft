
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#include "mlx.h"

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
}                   t_player;


typedef struct  s_cub3D
{
    t_env       *env;
    t_mlx		*mlx_img;
	t_keys      *keys;
    t_player    *player;
}               t_cub3D;

/*
* event_handle01.c
*/
    int		keyrelease_hook(int key, void *param);
    int		keypress_hook(int key, void *param);

/*
* ft_start_game.c
*/
    void	ft_start_game(t_cub3D *cub3D);


#endif