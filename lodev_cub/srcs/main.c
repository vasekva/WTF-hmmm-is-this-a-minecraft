/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:55 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:30:00 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void    	init_cub3D(t_cub3D *cub3d, char *path)
{
	cub3d->file_path = path;
	cub3d->screen = init_screen(NULL);
	cub3d->floor = init_floor(NULL);
	cub3d->ceiling = init_ceiling(NULL);
	cub3d->map = init_map(NULL);
	cub3d->array = init_array(NULL);

	ft_parse(cub3d);
	cub3d->env = init_env(NULL, cub3d); // mlx_init, mlx_new_win...
	cub3d->mlx_img = init_mlx_img(NULL); //инициализация структуры для my_mlx_pixel_put
	cub3d->keys = init_keys(NULL); // инициализация клавиш
	cub3d->player = init_player(NULL);
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
