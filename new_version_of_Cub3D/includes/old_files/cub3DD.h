#ifndef		CUB3DD_H
# define	CUB3DD_H

#include <stdio.h>
#include <math.h>

#include <stdlib.h>

# define CHAMPS		3.1416 / 3.0  // FOV

// # define CHAMPS		2  // FOV


# define START_DIR	0.
# define VEL_V		40 // скорость

# define WALL_H 192
# define WALL_W 192
# define MAP_H	40
# define MAP_W	40
# define WIDTH	768
# define HEIGHT	480

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

typedef struct		s_lay
{
	void			*img;
	t_uint			bpp;
	t_uint			line;
	t_uint			endian;
	t_uint			depht;
}					t_lay;

typedef	struct		s_ray
{
	float			len;
	float			v_len;
	unsigned int	col_h;
	unsigned int	col_v;
	float			direction;
}					t_ray;

typedef struct  	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

typedef struct		s_cam
{
	float			direction;
	float			champs;
	t_pos			pos;
	t_uint			dist_proj;
	t_uint			h_cam;
	t_uint			i;
	t_uint			j;
	float			virtual_h;
}					t_cam;

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

typedef struct		s_color
{
	unsigned int	color;
	unsigned int	alpha;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

/*
** game
*/

typedef struct  	s_cub
{
	t_screen		*screen;
	t_cam       	*cam;
	t_env       	*env;
	char        	**map;
	t_obj       	*wall;
	float			vel_h;
	float			vel_v;
	int				vel_h_bool;
	int				vel_v_bool;
	int				shad;
	int				i_shad;
	int				i_light;
	t_color     	*col_sky;
	t_color     	*col_gb;
	t_color     	*col_wl;
	t_ray       	ray;
	t_lay       	lay;
	char        	*img;
}               	t_cub;


/*
** draw.c
*/

void				draw(t_env *env, t_cam *cam);
void				draw_img(t_cub *cub, t_cam *cam, t_ray ray);

/*
** color.c
*/
void				set_color(t_color *col);
t_uint				rgb_to_color(t_uint r, t_uint g, t_uint b);
void				low_light(t_color *color, unsigned int inc, int sign);

/*
**	init_var_02.c
*/
void				new_lay(t_env *env, t_lay *lay, t_uint depht);
void				close_mlx(t_env *env);
//t_cam				*init_cam(t_cam *cam);
//t_env				*init_env(t_env *env);
//t_screen			*init_screen(t_screen *screen);

/*
**	init_var_01.c
*/
void				init_ray(t_ray *ray, float direction);
t_color				*init_color(t_color *color, unsigned int col);
t_obj				*init_wall(t_obj *wall);
//t_cub				*init_cub3D(t_cub *cub);

/*
** raycaster.c
*/
//void				raycaster(t_cub *cub, t_cam *cam, char **map);
float				mes_princ(float ang);
void				darkness(t_cub *cub);

/*
** ray_len.c
*/
float				inter_hor(t_cam *cam, t_ray *ray, char **map);
float				inter_vert(t_cam *cam, t_ray *ray, char **map);
void				map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h);
void				map_pos_vert(t_cam *cam, t_ray *ray, t_pos *pos, t_uint w);
float				mes_ang(float ang);

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
int		expose_hook(void *param);
//int		keyrelease_hook(int key, void *param);

#endif