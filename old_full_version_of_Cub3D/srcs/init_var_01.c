#include "cub3D.h"
#include "check_errors.h"

t_cub   *init_cub3D(t_cub *cub)
{
    if (!cub)
        if (!(cub = (t_cub*)malloc(sizeof(t_cub))))
			check_errors(MALLOC, "wolf", "init_var_02.c");
    cub->env = init_env(NULL);
    cub->cam = init_cam(NULL);
    cub->screen = init_screen(NULL);
    cub->wall = init_wall(NULL);
    cub->map = get_map();
    cub->vel_h = 0;
    cub->vel_v = 0;
    cub->vel_v_bool = 0;
    cub->vel_h_bool = 0;
    // cub->col_sky = init_color(NULL, 0x00FCFF);
    // cub->col_gb = init_color(NULL, 0x007482);
    //cub->col_wl = init_color(NULL, COL_N);
    cub->col_sky = init_color(NULL, 0xFFFFFF);
    cub->col_gb = init_color(NULL, 0xFFFFFF);
    cub->col_wl = init_color(NULL, 0xFFFFFF);
    cub->shad = ((WIDTH / 2) / 256);
    cub->i_shad = 0;
    cub->i_light = 0;
    return (cub);
}

void    init_ray(t_ray *ray, float dir)
{
    ray->len = 0;
    ray->v_len = 0;
    ray->direction = dir;
}

t_color *init_color(t_color *color, unsigned int col)
{
    if (!color)
        if (!(color = (t_color *)malloc(sizeof(t_color))))
			check_errors(MALLOC, "color", "init_var_02.c");
    color->color = col;
    color->r = (col & MASK_R) >> (8 * 2);
    color->g = (col & MASK_G) >> 8;
    color->b = (col & MASK_B);
    color->alpha = 0;
    return (color);
}

t_obj   *init_wall(t_obj *wall)
{
    if (!wall)
        if (!(wall = malloc(sizeof(t_obj))))
			check_errors(MALLOC, "wall", "init_var_02.c");
    wall->h = WALL_H;
    wall->w = WALL_W;
    wall->type = WALL;
    wall->text = 0;
    return (wall);
}