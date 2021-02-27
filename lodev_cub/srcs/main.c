
#include "cub3D.h"

t_player	*init_player(t_player *player, t_cub3D *cub3D)
{
	player = malloc(sizeof(t_player));
	player->leftKey = 0;
	player->rightKey = 0;
	player->upKey = 0;
	player->downKey = 0;
	player->escKey = 0;
	player->rightDKey = 0;
	player->leftAKey = 0;
	return (player);
}

t_env       *init_env(t_env *env, t_cub3D *cub3D)
{
    env = malloc(sizeof(t_env));
    env->win = NULL;
	env->mlx = NULL;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, 1920, 1080, "Hello world!");
    return (env);
}

t_mlx		*init_mlx_img(t_mlx *mlx_img)
{
	mlx_img = malloc(sizeof(t_mlx));
	mlx_img->img = NULL;
	mlx_img->addr = NULL;
	mlx_img->bits_per_pixel = 0;
	mlx_img->line_length = 0;
	mlx_img->endian = 0;
	return (mlx_img);
}

static void    	init_cub3D(t_cub3D *cub3D)
{
	cub3D->env = init_env(NULL, cub3D); // mlx_init, mlx_new_win...
	cub3D->mlx_img = init_mlx_img(NULL); //инициализация структуры для my_mlx_pixel_put
	cub3D->player = init_player(NULL, cub3D); // инициализация данных персонажа
}

static int		loop_hook(void *param)
{
    t_cub3D   *cub3D;

    if (param)
    {
        cub3D = (t_cub3D *)param;
		ft_start_game(cub3D);
    }
    return (0);
}

int	main(void)
{
	t_cub3D cub3D;

	init_cub3D(&cub3D);

	mlx_hook(cub3D.env->win, 2, 1L<<0, keypress_hook, &cub3D);
	mlx_hook(cub3D.env->win, 3, 1L<<0, keyrelease_hook, &cub3D);
	mlx_loop_hook(cub3D.env->mlx, loop_hook, &cub3D);
	ft_start_game(&cub3D);
}