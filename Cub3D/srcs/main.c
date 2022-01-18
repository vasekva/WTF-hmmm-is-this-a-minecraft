#include "cub3d.h"

static int	create_window(t_cub3d *cub3d)
{
	cub3d->mlx->p_mlx = mlx_init();
	if (!cub3d->mlx->p_mlx)
		return (0);
	ft_read_textures(cub3d);
	cub3d->mlx->image
		= mlx_new_image(cub3d->mlx->p_mlx, cub3d->scr_w, cub3d->scr_h);
	if (!cub3d->mlx->image)
		return (0);
	cub3d->mlx->p_img
		= mlx_get_data_addr(cub3d->mlx->image, &cub3d->mlx->bits_per_pixel,
			&cub3d->mlx->line_length, &cub3d->mlx->endian);
	if (!cub3d->mlx->p_img)
		return (0);
	cub3d->mlx->p_win
		= mlx_new_window(cub3d->mlx->p_mlx, cub3d->scr_w,
			cub3d->scr_h, "cub3d");
	if (!cub3d->mlx->p_win)
		return (0);
	return (1);
}

static void	ft_has_screen(t_cub3d *cub3d, char *arg, int argc, int flag)
{
	if (argc == 3)
	{
		if (ft_strlen(arg) != 6)
			exception(THIRTYSIX);
		flag = ft_strncmp(arg, "--save", ft_strlen(arg));
		if (flag == 1 || flag == -1)
			exception(THIRTYSIX);
		cub3d->screenshot = 1;
	}
}

static int	ft_start_game(t_cub3d *cub3d)
{
	if (cub3d->keys.up == 1 || cub3d->keys.down == 1)
		ft_move_forw_bacw(cub3d);
	if (cub3d->keys.key_a == 1 || cub3d->keys.key_d == 1
		|| cub3d->keys.left == 1 || cub3d->keys.right == 1)
		ft_move_side(cub3d);
	start_raycast(cub3d);
	mlx_put_image_to_window(cub3d->mlx->p_mlx,
		cub3d->mlx->p_win, cub3d->mlx->image, 0, 0);
	if (cub3d->screenshot)
	{
		write(1, "Creating a screenshot. Wait...\n", 32);
		ft_convert_bmp(cub3d);
		write(1, "Done!\n", 7);
		exit(0);
	}		
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		flag;

	flag = 0;
	if (argc > 1)
	{
		cub3d.file_path = ft_strdup(argv[1]);
		if (!cub3d.file_path)
			exception(THIRTYTWO);
		ft_init_cub3d(&cub3d);
		ft_has_screen(&cub3d, argv[2], argc, flag);
		flag = create_window(&cub3d);
		if (!flag)
			exception(TWELVE);
		mlx_hook(cub3d.mlx->p_win, 17, (1L << 0), ft_exit, &cub3d);
		mlx_hook(cub3d.mlx->p_win, 2, (1L << 0), key_press, &cub3d);
		mlx_hook(cub3d.mlx->p_win, 3, (1L << 1), key_release, &cub3d);
		mlx_loop_hook(cub3d.mlx->p_mlx, ft_start_game, &cub3d);
		mlx_loop(cub3d.mlx->p_mlx);
	}
	else
	{
		exception(FORTY);
	}
	return (0);
}
