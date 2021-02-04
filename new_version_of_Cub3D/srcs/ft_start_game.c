#include "cub3D.h"
#include "mlx.h"

void					ft_start_game(t_cub3D *cub3D)
{
    void    *mlx;
    void    *mlx_win;
    t_mlx  img;

	cub3D->env->mlx = mlx_init();
    cub3D->env->win = mlx_new_window(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h, "cub3D");
	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);

	ft_draw_cub_from_cubs(cub3D);			

	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
	mlx_loop(cub3D->env->mlx);
}