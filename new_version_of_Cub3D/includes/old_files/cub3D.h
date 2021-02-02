
#ifndef		CUB3D_H
# define	CUB3D_H

#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

# define VEL_V		15 // скорость

# define UP		13
# define DOWN	1
# define RIGHT	2
# define LEFT	0
# define ESC	53

# define RED	0xFF0000
# define GREEN	0x008000
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF
# define YELLOW	0xFFFF00

# define WALL           1
# define VOID           0

# define WALL_H 		192
# define WALL_W 		192
# define MAP_H			40
# define MAP_W			40
# define screen_height	1320
# define screen_width 	2000

# define PIXEL_SIZE     16

typedef int		t_uint;


typedef struct  s_data {
    void		*img;
    char		*addr;
    int			bits_per_pixel;
    int			line_length;
    int			endian;
}               t_data;

// typedef struct  	s_env
// {
// 	void			*mlx;
// 	void			*win;
// 	void			*img;
// }					t_env;

typedef struct  s_cub {
    char        **map;
	// t_env		*env;
	void			*mlx;
	void			*win;
	void			*env_img;
    t_data  		img;
}               t_cub;

char    **get_map(void);


#endif