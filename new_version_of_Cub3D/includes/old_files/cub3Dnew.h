#ifndef		CUB3DNEW_H
# define	CUB3DNEW_H

#include <stdio.h>
#include <math.h>

#include <stdlib.h>

# define CHAMPS		3.1416 / 3.0  // FOV

// # define CHAMPS		2  // FOV


# define START_DIR	0.
# define VEL_V		40 // скорость

# define PIXEL_SIZE     16

# define WALL_H 192
# define WALL_W 192
# define MAP_H	40
# define MAP_W	40

// # define WIDTH	768
// # define HEIGHT	480
# define WIDTH	MAP_W * PIXEL_SIZE * 1.5
# define HEIGHT	MAP_H * PIXEL_SIZE * 2

// # define WIDTH	1152
// # define HEIGHT	750

// # define WIDTH	1536
// # define HEIGHT	960

// # define WIDTH	2560
// # define HEIGHT	1600

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

# define U_LONG		15 //область видимости
# define G_LIGHT	1

/**
 * ЧБ С РОЗОВЫМ НЕБОМ
 */
# define MASK_R	0xFF0000
# define MASK_G	0x00FF00
# define MASK_B 0x0000FF
//# define COL_N		0xCCCCCC
# define COL_N		0xCCCCCC // левая сторона
# define COL_S		0xCCCCCC // правая сторона
# define COL_E		0xCCCCCC // лицевая сторона
# define COL_O		0xCCCCCC // тыльная сторона
# define COL_GD		0x000000 // пол
# define COL_SKY	0xFF66FF // небо


#define DEG(x)		(x * 180.0) / 3.1416

typedef int		t_uint;

enum			e_obj
{
	VOID = 48,
	WALL = 49,
	CAM = 50
};

typedef struct		s_pos
{
	t_uint			x;
	t_uint			y;
}					t_pos;

typedef struct  	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

typedef struct		s_screen
{
	int				h;
	int				w;
	t_pos			center;
}					t_screen;

typedef struct		s_obj
{
	t_uint			h;
	t_uint			w;
	t_uint			type;
	t_uint			text;
}					t_obj;

typedef struct  s_data {
    void		*img;
    char		*addr;
    int			bits_per_pixel;
    int			line_length;
    int			endian;
}               t_data;

/*
** game
*/
typedef struct  	s_cub
{
	t_screen		*screen;
	t_env       	*env;
	char        	**map;
	t_obj       	*wall;
	float			vel_h;
	float			vel_v;
	int				vel_h_bool;
	int				vel_v_bool;
    t_data          data_img;
}               	t_cub;


/*
**	init_var_02.c
*/
void				close_mlx(t_env *env);
//t_cam				*init_cam(t_cam *cam);
//t_env				*init_env(t_env *env);
//t_screen			*init_screen(t_screen *screen);

/*
**	init_var_01.c
*/
t_obj				*init_wall(t_obj *wall);
//t_cub				*init_cub3D(t_cub *cub);

/*
** raycaster.c
*/
//void				raycaster(t_cub *cub, t_cam *cam, char **map);
float				mes_princ(float ang);
void				darkness(t_cub *cub);


/*
** get_map.c + fonction a coder :: ........................
*/
char	**get_map(void);
void	print_map(char **map);


/*
** event_handle.c
*/
//int		keypress_hook(int key, void *param);

/*
** event_handle.c
*/
//int		loop_hook(void *param);
//int		keyrelease_hook(int key, void *param);

#endif