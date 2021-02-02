#include "cub3Dnew.h"
#include "mlx.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*
** Отрисовка стен
*/
void	ft_print_wall(t_cub *cub, char **world_map, int x, int y, int color)
{
	int moveX = x * PIXEL_SIZE;
	int moveY = y * PIXEL_SIZE;

	if (world_map[x][y] == '1')
	{
	 	for (int n = 0; n < PIXEL_SIZE - 1; n++)
		{
			for (int num = 0; num < PIXEL_SIZE - 1; num++)
			{
				my_mlx_pixel_put(&cub->data_img, moveX + n, moveY + num, color);
			}
		}
	}
}
/*
** Отрисовка игрока
*/
void	ft_print_player(t_cub *cub, int color)
{
	int posX = 30;
	int posY = 30;

	int moveX = posX * PIXEL_SIZE;
	int moveY = posY * PIXEL_SIZE;

	for (int n = 0; n < PIXEL_SIZE / 2; n++)
		{
			for (int num = 0; num < PIXEL_SIZE / 2; num++)
			{
				my_mlx_pixel_put(&cub->data_img, moveX + n, moveY + num, color);
			}
		}
}

int     loop_hook(void *param)
{
    t_cub   *cub;
    t_pos   pos;
    t_pos   tmp;

    if (param)
    {
        //raycaster(cub, cub->cam, cub->map);
        for (int x = 0; x < MAP_H; x++)
        {
            for (int y = 0; y < MAP_W; y++)
            {
                ft_print_wall(cub, cub->map, x, y, WHITE);
                ft_print_player(cub, GREEN);
            }
        }
        mlx_put_image_to_window(cub->env->mlx, cub->env->win, cub->env->img, 0, 0);
        mlx_loop(cub->env->mlx);
    }
    return (0);
}

static void     aux_press(int key, t_cub *cub)
{
    if (key == UP && !cub->vel_v_bool)
    {
        cub->vel_v = VEL_V;
        cub->vel_v_bool = 1;
    }
    if (key == DOWN && !cub->vel_v_bool)
    {
        cub->vel_v = -VEL_V;
        cub->vel_v_bool = 1;
    }
}

int             keypress_hook(int key, void *param)
{
    t_cub   *cub;

    if (param)
    {
        cub = (t_cub *)param;
        if (key == ESC)
            exit(0);
        if (key == LEFT && !cub->vel_h_bool)
        {
            cub->vel_h = 0.02;
            cub->vel_h_bool = 1;
        }
        if (key == RIGHT && !cub->vel_h_bool)
        {
            cub->vel_h = -0.02;
            cub->vel_h_bool = 1;
        }
        aux_press(key, cub);
    }
    return (1);
}

int     keyrelease_hook(int key, void *param)
{
    t_cub   *cub;

    if (param)
    {
        cub = (t_cub *)param;
        if (key == LEFT || key == RIGHT)
            cub->vel_h_bool = 0;
        if (key == UP || key == DOWN)
            cub->vel_v_bool = 0;
    }
    return (1);
}

t_obj   *init_wall(t_obj *wall)
{
    if (!wall)
        wall = malloc(sizeof(t_obj));
    wall->h = WALL_H;
    wall->w = WALL_W;
    wall->type = WALL;
    wall->text = 0;
    return (wall);
}

t_screen    *init_screen(t_screen *screen)
{
    if (!screen)
        screen = (t_screen *)malloc(sizeof(t_screen));
    screen->h = HEIGHT;
    screen->w = WIDTH;
    screen->center.x = WIDTH / 2;
    screen->center.y = HEIGHT / 2;
    return (screen);
}

t_env       *init_env(t_env *env)
{
    t_cub cub;
    if (!env)
        env = malloc(sizeof(t_env));
    env->win = NULL;
    env->mlx = mlx_init();
    cub.data_img.img = mlx_new_image(env->mlx, MAP_H * PIXEL_SIZE, MAP_W * PIXEL_SIZE);
    cub.data_img.addr = mlx_get_data_addr(cub.data_img.img, &cub.data_img.bits_per_pixel, &cub.data_img.line_length, &cub.data_img.endian);
    env->win = mlx_new_window(env->mlx, HEIGHT, WIDTH, "Cub3D");
    return (env);
}

t_cub   *init_cub3D(t_cub *cub)
{
    cub->env = init_env(NULL);
    cub->screen = init_screen(NULL);
    cub->wall = init_wall(NULL);
    cub->map = get_map();
    cub->vel_h = 0;
    cub->vel_v = 0;
    cub->vel_v_bool = 0;
    cub->vel_h_bool = 0;
    return (cub);
}

void        close_mlx(t_env *env)
{
    mlx_destroy_window(env->mlx, env->win);
}

int     main(int argc, char **argv)
{
    t_cub cub;

    if (argc)
    {
        init_cub3D(&cub);
        mlx_key_hook(cub.env->win, keyrelease_hook, &cub);
        mlx_hook(cub.env->win, 2, 1L<<0, keypress_hook, &cub);
        mlx_loop_hook(cub.env->mlx, loop_hook, &cub);
        mlx_loop(cub.env->mlx);
    }
    close_mlx(cub.env);
    return (0);
}