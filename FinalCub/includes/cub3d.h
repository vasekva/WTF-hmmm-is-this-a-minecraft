#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "exceptions.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define W 13
# define A 0
# define S 1
# define D 2

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

# define ESC 53
# define SHIFT 257

# define BUFFER_SIZE 21

typedef struct s_crds
{
	double		x;
	double		y;
}				t_crds;

typedef struct s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			key_a;
	int			key_d;
	double		m_speed;
	double		r_speed;
}				t_keys;

typedef struct s_texture
{
	int			texture;
	void		*ptr_texture;
	char		*path_texture;
	int			column;
	int			color;
	int			width;
	int			height;
	void		*image;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_floor
{
	double		wall_x;
	double		wall_y;
	double		weight;
	double		distance;
	double		x;
	double		y;
	int			texture_x;
	int			texture_y;
}				t_floor;

typedef struct s_sprite
{
	double		*buf_distance;
	double		*distance;
	int			num_of_sprites;
	int			*sprite_order;
	double		x;
	double		y;
	double		inv_det;
	double		trans_form_x;
	double		trans_form_y;
	int			sprite_screen;
	int			height;
	int			widht;
	int			start_draw_x;
	int			start_draw_y;
	int			end_draw_x;
	int			end_draw_y;
	int			sprite_text_x;
	int			sprite_text_y;
}				t_sprite;

typedef struct s_clr
{
	int			r;
	int			g;
	int			b;
}				t_clr;

typedef struct s_mlx
{
	void		*p_mlx;
	void		*p_win;
	void		*image;
	void		*p_img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct s_dda2d
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dx;
	double		delta_dy;
	int			map_x;
	int			map_y;
	double		side_dx;
	double		side_dy;
	int			step_x;
	int			step_y;
}				t_dda2d;

typedef struct s_dda3d
{
	int			side;
	double		wall_dist;
	int			line_h;
	int			draw_start;
	int			draw_end;
}				t_dda3d;

typedef struct s_move
{
	double		olddir_x;
	double		oldplane_x;
	double		plane_x;
	double		plane_y;
}				t_move;

typedef struct s_cub3d
{
	char		**buff;
	int			flag_buff;
	t_mlx		*mlx;
	t_crds		*spr_crds;
	t_sprite	sprite;
	t_player	player;
	t_dda2d		dda2d;
	t_dda3d		dda3d;
	t_move		move;
	t_keys		keys;
	t_floor		floor;
	t_texture	texture[7];
	t_clr		color;
	char		*file_path;
	char		**map;
	int			map_h;
	int			map_w;
	int			scr_w;
	int			scr_h;
	double		wall_x;
	int			screenshot;
}				t_cub3d;

typedef struct s_bmp
{
	int				filesize;
	char			*img;
	unsigned char	fileheader[14];
	unsigned char	infoheader[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

/*
** ./INIT/
*/
void	ft_check_file(t_cub3d *cub3d);
void	ft_check_map(t_cub3d *cub3d);
	/*
	**	FT_CHECK_PARAMS.C
	*/
void	ft_check_map(t_cub3d *cub3d);
	/*
	**	FT_DEF_SPRITES.C
	*/
void	ft_def_spr_dist(t_cub3d *cub3d);
void	ft_spr_sort(int *order, double *dist, int number);

void	ft_found_and_fill_map(t_cub3d *cub3d);
void	ft_init_cub3d(t_cub3d *cub3d);
	/*
	**	FT_INIT_MAP.C
	*/
void	ft_init_map(t_cub3d *cub3d);
int		is_map_symbol(char c);
int		is_map_line(t_cub3d *cub3d, char *line);

void	ft_init_vars02(t_cub3d *cub3d);
int		ft_parse_color(char *line, int ind, t_cub3d *cub3d);
void	ft_read_screen_size(t_cub3d *cub3d);
void	ft_read_textures(t_cub3d *cub3d);
/*
** END_OF_INIT
*/

/*
**	UTILS.C
*/
void	ft_count_sprites(t_cub3d *cub3d);
	/*
	**	FT_UTILS_FOR_COLOR.C
	*/
int		create_rgb(int r, int g, int b);
int		ft_parse_int(char *str);
	/*
	**	FT_UTILS_FOR_DRAW.C
	*/
void	get_color(t_cub3d *cub, int ind, int x, int y);
void	color_dist(t_cub3d *cub, int ind, double dis);
void	draw_pix(t_cub3d *cub, int ind, int x, int y);
void	ft_set_tex_coor(t_cub3d *cub3d, int i);
/*
**	END_OF_UTILS
*/

/*
**	ANOTHER IN SRCS
*/
	/*
	**	EVENT_HANDLE.C
	*/
int		key_press(int key, t_cub3d *cub3d);
int		key_release(int key, t_cub3d *cub3d);

void	exception(char *str);
void	ft_check_params01(t_cub3d *cub3d);
void	ft_convert_bmp(t_cub3d *cub3d);
void	ft_draw_floor(t_cub3d *cub3d, int x);
void	ft_draw_sprites(t_cub3d *cub);
void	ft_draw_walls(t_cub3d *cub3d, int x);
void	draw_all(t_cub3d *cub3d, int x);
void	ft_move_forw_bacw(t_cub3d *cub3d);
void	ft_move_side(t_cub3d *cub3d);
int		get_next_line(int fd, char **line);
int		main(int argc, char **argv);
void	start_raycast(t_cub3d *cub3d);
/*
**	END
*/
#endif