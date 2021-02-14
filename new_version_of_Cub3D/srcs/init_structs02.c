#include "cub3D.h"

t_env       *init_env(t_env *env, t_cub3D *cub3D)
{
    env = malloc(sizeof(t_env));
    env->win = NULL;
	env->mlx = NULL;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, cub3D->screen->w, cub3D->screen->h, "cub3D");
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

t_player2D	*init_player2D(t_player2D *player2D, t_player *player)
{
	player2D = malloc(sizeof(t_player2D));
	player2D->color_minicubeRU = 0x0000FF00;
	player2D->color_minicubeRD = 0x0000FF00;
	player2D->color_minicubeLU = 0x0000FF00;
	player2D->color_minicubeLD = 0x0000FF00;
	player2D->color_of_player = 0x009932CC;
	player2D->color_of_cross = player2D->color_of_player;
	return (player2D);
}

t_player	*init_player(t_player *player, t_cub3D *cub3D)
{
	player = malloc(sizeof(t_player));
	player->player2D = init_player2D(NULL, player);
	player->arrayX = 0;
    player->arrayY = 0;
	player->leftKey = 0;
	player->rightKey = 0;
	player->upKey = 0;
	player->downKey = 0;
	player->escKey = 0;
	player->degree = 0;
	player->posX = 0;
	player->posY = 0;
	player->posA = 0;
	player->posDirX = 0;
	player->posDirY = 0;
	return (player);
}