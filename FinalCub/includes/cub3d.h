#ifndef		CUB3D_H
# define	CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "exceptions.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_H 4

# define KEY_TAB 48
# define KEY_SPACE 49
# define KEY_ESC 53
# define KEY_SHIFT 257

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef	struct	s_buf
{
	char		**buffer;
}				t_buf;

typedef	struct	s_coor
{
	double		x;
	double		y;
}				t_coor;

typedef	struct	s_action
{
	int			up;
	int			down;
	int			r_left;
	int			m_left;
	int			r_right;
	int			m_right;
	double		m_speed;
	double		r_speed;
	int			hud;	
}				t_action;

typedef struct	s_tex
{
	int			texture;
	int			col;
	int			color;
	int			width;
	int			height;
	char		*tex_path;
	void		*image;
	void		*tex_ptr;
	int			bit_pix;
	int			size_line;
	int			endian;
	int			pix;
}				t_tex;

typedef struct	s_floor
{
	double		fl_x_wall;
	double		fl_y_wall;
	double		cur_dist;
	double		weight;
	double		cur_fl_x;
	double		cur_fl_y;
	int			fl_tex_x;
	int			fl_tex_y;
}				t_floor;

typedef struct	s_sprite
{
	double		*distbuf;
	int			nb_sprite;
	int			*sp_order;
	double		*sp_dist;
	double		sp_x;
	double		sp_y;
	double		inv_det;
	double		trans_x;
	double		trans_y;
	int			sp_screen;
	int			sp_h;
	int			sp_w;
	int			draw_startx;
	int			draw_endx;
	int			draw_starty;
	int			draw_endy;
	int			tsp_x;
	int			tsp_y;
}				t_sprite;


typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
}					t_clr;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
//	 char			*addr;
	void			*image;
	void			*img_ptr;
	int				bit_pix;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct	s_player
{
	double		pos_x; // поз-я персонажа по иксу
	double		pos_y; // поз-я персонажа по игрику
	double		dir_x; // направление перса по иксу
	double		dir_y; // направление перса по игрику		
}				t_player;

typedef	struct	s_cub3d
{
	t_mlx		*mlx;
	t_player	player;
	
	char		*path;

//	int			bits_pix;
	t_buf		buf; // структура с прочитанным файлом
	char		**map;
	int			map_h; // кол-во строк карты
	int			map_w; // кол-во символов в карте
	t_action	act; // структура клавиш
	t_tex		tex[7]; // массив текстур
	t_floor		flr; // структура пола
	t_sprite	spr; // структура спрайтов
	t_coor		*c_spr; // координаты спрайтов
	int			scr_w; // ширина экрана
	int			scr_h; // высота экрана

	double		raydir_x;
	double		raydir_y;

	double		delta_dx;
	double		delta_dy;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		side_dx;
	double		side_dy;
	int			side;
	double		wall_dist;
	int			line_h;
	int			draw_start;
	int			draw_end;

	double		olddir_x;
	double		oldplane_x;
	double		plane_x;
	double		plane_y;

	double		wall_x;

	int			screenshot;
	t_clr		color;
}				t_cub3d;

typedef struct		s_bmp
{
	int				filesize;
	char			*img;
	unsigned char	fileheader[14];
	unsigned char	infoheader[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;




int		ft_parse_color(char *line, int ind, t_cub3d *cub3d);


/*
** FT_UTILS_FOR_COLOR.C
*/
	int	create_rgb(int r, int g, int b);
	int	ft_parse_int(char *str);


	void	ft_init_map(t_cub3d *cub3d);
	int 	is_map_symbol(char c);
	int 	is_map_line(t_cub3d *cub3d, char *line);

void	print_structs(t_cub3d *cub3d);
void	ft_found_and_fill_map(t_cub3d *cub3d);


/*
**	FT_DEF_SPRITES.C
*/
	void 	ft_spr_sort(int *order, double *dist, int number);
	void 	ft_def_spr_dist(t_cub3d *cub3d);



/*
**	FT_UTILS_FOR_DRAW.C
*/
	void	get_color(t_cub3d *cub, int ind, int x, int y);
	void	color_dist(t_cub3d *cub, int ind, double dis);
	void	draw_pix(t_cub3d *cub, int ind, int x, int y);
	void	ft_set_tex_coor(t_cub3d *cub3d, int i);

/*
**	FT_DRAW.C
*/
	void	draw_all(t_cub3d *cub3d, int x);

/*
**	FT_DRAW_FLOOR.C
*/
	void	ft_draw_floor(t_cub3d *cub3d, int x);

/*
**	FT_DRAW_SPRITES.C
*/
	void	ft_draw_sprites(t_cub3d *cub);

/*
**	FT_DRAW_WALLS.C
*/
	void 	ft_draw_walls(t_cub3d *cub3d, int x);

/*
**	FT_FREE_ALL.C
*/
	void	ft_free_all(t_cub3d *cub);

/*
**	EVENT_HANDLE.C
*/
	int		key_press(int key, t_cub3d *cub3d);
	int		key_release(int key, t_cub3d *cub3d);

/*
**	EXCEPTION.C
*/
	void	exception(t_cub3d *cub3d, char *str);

/*
**	EXIT.C
*/
	int		exit_prog(t_cub3d *cub);

/*
**	FT_CHECK_FILE.C
*/
	void	ft_check_file(t_cub3d *cub3d);

/*
**	FT_CHECK_MAP.C
*/
	void	ft_check_map(t_cub3d *cub3d);

/*
**	FT_CHECK_PARAMS.C
*/
	void	ft_check_params01(t_cub3d *cub3d);

/*
**	FT_CONVERT_BMP.C
*/
	void	ft_convert_bmp(t_cub3d *cub3d);

/*
**	FT_MOVE_FORW_BACW.C
*/
	void	ft_move_forw_bacw(t_cub3d *cub3d);

/*
**	FT_MOVE_SIDE.C
*/
	void	ft_move_side(t_cub3d *cub3d);

/*
**	FT_READ_SCREENSIZE.C
*/
	void	ft_read_screen_size(t_cub3d *cub3d);

/*
**	FT_READ_TEXTURES.C
*/
	void	ft_read_textures(t_cub3d *cub3d);

/*
**	FT_START_GAME.C
*/
	int	ft_start_game(t_cub3d *cub3d);

/*
**	FT_UTILS_FOR_SPRITES.C
*/
	void	ft_count_sprites(t_cub3d *cub3d);


/*
** 	GET_NEXT_LINE.C
*/
	int	get_next_line(int fd, char **line);

/*
**	FT_INIT_CUB3D.C
*/
	void	ft_init_cub3d(t_cub3d *cub3d);



/*
**	FT_INIT_VARS.C
*/
	void	ft_init_vars02(t_cub3d *cub3d);

/*
**	MAIN.C
*/
	int	main(int argc, char **argv);
	int	ft_check_fileformat(char *argument);

/*
**	RAYCASTING.C
*/
	void	raycasting(t_cub3d *cub3d);

#endif