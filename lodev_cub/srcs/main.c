#include "cub3d.h"

static void	init_map(t_cub3d *cub)
{
	create_map(cub);
	adjust_map(cub);
	complete_map(cub);
	check_map(cub);
}

static int	create_window(t_cub3d *cub)
{
	if (!(cub->mlx_ptr = mlx_init()))
		return (0);
	get_textures(cub);
	if (!(cub->image = mlx_new_image(cub->mlx_ptr, cub->res_x, cub->res_y)))
		return (0);
	cub->img_ptr = mlx_get_data_addr(cub->image, &cub->bit_pix, \
									&cub->size_line, &cub->endian);
	raycasting(cub);
	if (cub->screenshot)
	{
		convert_bmp(cub);
		exit_prog(cub);
	}
	if (!(cub->win_ptr = \
		mlx_new_window(cub->mlx_ptr, cub->res_x, cub->res_y, "cub3d")))
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_cub3d	cub;

	if (argc > 1)
	{
		init_desc(&cub, argv[1]);
		check_content(&cub);
		assign_res(&cub);
		init_map(&cub);
		init_var(&cub);
		if (argc == 3 && !ft_strcmp(argv[2], "--save"))
			cub.screenshot = 1;
		if (!create_window(&cub))
			display_error(&cub, "Could not create window.\n");
		mlx_hook(cub.win_ptr, 17, 0L, exit_prog, &cub);
		mlx_hook(cub.win_ptr, 2, (1L << 0), key_press, &cub);
		mlx_hook(cub.win_ptr, 3, (1L << 1), key_release, &cub);
		mlx_loop_hook(cub.mlx_ptr, motion, &cub);
		mlx_loop(cub.mlx_ptr);
	}
	else
		ft_putstr_fd("Please select descriptor file.\n", 1);
	return (0);
}
