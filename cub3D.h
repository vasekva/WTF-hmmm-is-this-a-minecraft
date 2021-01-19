

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# define mapWidth 24
# define mapHeight 24
# define w 1280
# define h 1024

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *mlx_win;
    int         key_code;
}               t_vars;

typedef struct	s_coord
{
	int			world_map[mapWidth][mapHeight];
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		frameTime;
	double		moveSpeed;
	double		rotSpeed;
}				t_coords;

int		ft_abs(int num);
int		create_trgb(int t, int r, int g, int b);
int		key_press(int key, t_coords *coords);

#endif