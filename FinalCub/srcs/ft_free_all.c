#include "cub3d.h"

static void	ft_free_buf(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	ft_strdel(&cub3d->buf.content);
	if (cub3d->buf.buffer)
	{
		while (cub3d->buf.buffer[i])
		{
			ft_strdel(&cub3d->buf.buffer[i]);
			i++;
		}
		free(cub3d->buf.buffer);
	}
}

static void	ft_free_win(t_cub3d *cub3d)
{
	if (cub3d->image)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->image);
	if (cub3d->mlx_ptr && cub3d->win_ptr)
	{
		mlx_clear_window(cub3d->mlx_ptr, cub3d->win_ptr);
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	}
}

static void	ft_free_tex_spr(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		ft_strdel(&cub3d->tex[i].tex_path);
		if (cub3d->tex[i].image)
			free(cub3d->tex[i].image);
		if (cub3d->tex[i].tex_ptr)
			free(cub3d->tex[i].tex_ptr);
		i++;
	}
	if (cub3d->spr.distbuf)
		free(cub3d->spr.distbuf);
	if (cub3d->spr.sp_order)
		free(cub3d->spr.sp_order);
	if (cub3d->spr.sp_dist)
		free(cub3d->spr.sp_dist);
	if (cub3d->c_spr)
		free(cub3d->c_spr);
}

static void	ft_free_map(t_cub3d *cub)
{
	int	x;

	x = 0;
	if (cub->map)
	{
		while (x < cub->map_h)
		{
			ft_strdel(&cub->map[x]);
			x++;
		}
		free(cub->map);
	}
}

void	ft_free_all(t_cub3d *cub)
{
	ft_free_buf(cub);
	ft_free_win(cub);
	ft_free_map(cub);
	ft_free_tex_spr(cub);
}
