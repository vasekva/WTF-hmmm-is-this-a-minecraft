
#include "check_errors.h"
#include "mlx.h"


static void		aux_get_vlen(t_cub *cub, float len_x, float len_y, t_ray *ray)
{
	if (len_x <= len_y)
	{
		ray->len = len_x;
		cub->col_wl->color = ray->col_h;
	}
	else
	{
		ray->len = len_y;
		cub->col_wl->color = ray->col_v;
	}
}

static void    get_vlen(t_cam *cam, t_ray *ray, char **map, t_cub *cub)
{
	float   len_x;
	float   len_y;

	len_x = inter_hor(cam, ray, map);
	len_y = inter_vert(cam, ray, map);
	if (len_x == 0 && len_y != 0)
	{
		ray->len = len_y;
		cub->col_wl->color = ray->col_v;
	}
	else if (len_y == 0 && len_x != 0)
	{
		ray->len = len_x;
		cub->col_wl->color = ray->col_h;
	}
	else
		aux_get_vlen(cub, len_x, len_y, ray);
}

float   mes_princ(float ang)
{
	if (ang < 0.)
		return ((2. * 3.1416) + ang);
	else if (ang > 2. * 3.1416)
		return (ang - 2. * 3.1416);
	return (ang);
}

static void aux_caster(t_cub *cub, t_cam *cam)
{
	int		lost_l;

	lost_l = 0;
	if (cam->virtual_h > HEIGHT)
		cam->virtual_h = HEIGHT;
	lost_l = (int)(((int)G_LIGHT * (int)(cub->ray.v_len)) / (int)U_LONG);
	set_color(cub->col_wl);
	low_light(cub->col_wl, (t_uint)lost_l, -1);
	cub->col_gb->color = COL_GD;
	set_color(cub->col_gb);
	cub->col_sky->color = COL_SKY;
	set_color(cub->col_sky);
	draw_img(cub, cam, cub->ray);
}

void        raycaster(t_cub *cub, t_cam *cam, char **map)
{
	float   ang_strt;
	float   ang_end;
	float   inc;

	if (!cub->env || !cam)
		check_errors(NUL, "wolf->env || cam", "raycaster.c");
	cam->i = 0;
	cub->env->img = mlx_new_image(cub->env->mlx, WIDTH, HEIGHT);
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&(cub->ray), mes_princ(ang_strt));
		get_vlen(cam, &(cub->ray), map, cub);
		cub->ray.v_len = cub->ray.len *
			(float)(cos(ang_strt - cam->direction));
		cam->virtual_h = (float)(cam->dist_proj
			* (HEIGHT / 2)) / cub->ray.v_len;
		aux_caster(cub, cam);
		ang_strt -= inc;
	}
	mlx_put_image_to_window(cub->env->mlx, 
		cub->env->win, cub->env->img, 0, 0);
	mlx_destroy_image(cub->env->mlx, cub->env->img);
}