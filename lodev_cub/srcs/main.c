
#include "cub3D.h"

t_keys	*init_keys(t_keys *keys, t_cub3D *cub3D)
{
	keys = malloc(sizeof(t_keys));
	keys->leftKey = 0;
	keys->rightKey = 0;
	keys->upKey = 0;
	keys->downKey = 0;
	keys->escKey = 0;
	keys->rightDKey = 0;
	keys->leftAKey = 0;
	return (keys);
}

t_env       *init_env(t_env *env, t_cub3D *cub3D)
{
    env = malloc(sizeof(t_env));
    env->win = NULL;
	env->mlx = NULL;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, cub3D->screen->w, cub3D->screen->h, "Hello world!");
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

t_player	*init_player(t_player *player, t_cub3D *cub3D)
{
	player = malloc(sizeof(t_player));
	player->posX = 22;
	player->posY = 12;
	//initial direction vector
	player->dirX = -1;
	player->dirY = 0;
	//the 2d raycaster version of camera plane
	player->planeX = 0;
	player->planeY = 0.66;
	return (player);
}

t_screen	*init_screen(t_screen *screen, t_cub3D *cub3D)
{
    if (!screen)
        screen = (t_screen *)malloc(sizeof(t_screen));
	// screen->w = 0;
	screen->w = 960;
	// screen->h = 0;
	screen->h = 1080;
	return (screen);
}

// t_map		*init_map(t_map *map)
// {
// 	if (!map)
// 		map = (t_map *)malloc(sizeof(t_map));
// 	map->north = NULL;
// 	map->south = NULL;
// 	map->west = NULL;
// 	map->east = NULL;
// 	map->sprite = NULL;
// 	return (map);
// }

// t_floor		*init_floor(t_floor *floor)
// {
// 	if (!floor)
// 		floor = (t_floor *)malloc(sizeof(t_floor));
// 	floor->r = 0;
// 	floor->g = 0;
// 	floor->b = 0;
// 	return (floor);
// }

// t_ceiling	*init_ceiling(t_ceiling *ceiling)
// {
// 	if (!ceiling)
// 		ceiling = (t_ceiling *)malloc(sizeof(t_ceiling));
// 	ceiling->r = 0;
// 	ceiling->g = 0;
// 	ceiling->b = 0;
// 	return (ceiling);
// }

static void    	init_cub3D(t_cub3D *cub3D, char *path)
{
	cub3D->file_path = path;
	cub3D->screen = init_screen(NULL, cub3D);

	cub3D->env = init_env(NULL, cub3D); // mlx_init, mlx_new_win...
	cub3D->mlx_img = init_mlx_img(NULL); //инициализация структуры для my_mlx_pixel_put
	cub3D->keys = init_keys(NULL, cub3D); // инициализация клавиш
	cub3D->player = init_player(NULL, cub3D);

	ft_parse(cub3D);
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

int	main(int argc, char **argv)
{
	t_cub3D cub3D;

	if (argc == 2)
	{
		init_cub3D(&cub3D, argv[1]);
		mlx_hook(cub3D.env->win, 2, 1L<<0, keypress_hook, &cub3D);
		mlx_hook(cub3D.env->win, 3, 1L<<0, keyrelease_hook, &cub3D);
		mlx_loop_hook(cub3D.env->mlx, loop_hook, &cub3D);
		mlx_loop(cub3D.env->mlx);
	}
}