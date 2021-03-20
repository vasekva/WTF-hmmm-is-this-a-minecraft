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

static int	check_type(char *desc_file)
{
	int i;
	int ind;

	i = 0;
	ind = 0;
	while (desc_file[i])
	{
		if (desc_file[i] == '.')
			ind = i;
		i++;
	}
	if (!ft_strcmp(&desc_file[ind], ".cub"))
		return (1);
	return (0);
}

void 		init_cub3d(t_cub3d *cub, char *desc)
{
	int		fd;

//	init(cub);
	/**
	 * init_desc(t_cub3d *cub, char *desc);
	 */
		/**
		 * init(cub);
		 */
			cub->mlx_ptr = NULL;
			cub->win_ptr = NULL;
			cub->image = NULL;
			cub->img_ptr = NULL;
			cub->c_spr = NULL;
			ft_memset(&cub->buf, 0, sizeof(t_buf));
			ft_memset(&cub->map, 0, sizeof(char**));
			ft_memset(&cub->act, 0, sizeof(t_action));
			ft_memset(&cub->tex, 0, sizeof(t_tex) * 7);
			ft_memset(&cub->flr, 0, sizeof(t_floor));
			ft_memset(&cub->spr, 0, sizeof(t_sprite));
		/**
		 * end of init
		 */
			if (!check_type(desc))
				display_error(cub, "Description file must be *.cub type.\n");
			if ((fd = open(desc, O_RDONLY)) < 0)
			{
				close(fd);
				display_error(cub, "Could not find map description.\n");
			}
	//	set_buffer(fd, cub);
		/**
		 * set_buffer(fd, cub);
		 */
			char	*line;
			int		ret;

			cub->buf.content = ft_strdup("");
			while ((ret = get_next_line(fd, &line)))
			{
				cub->buf.content = ft_strjoin_free(cub->buf.content, line, 2);
				cub->buf.content = ft_strjoin_free(cub->buf.content, "\n", 1);
			}
			cub->buf.content = ft_strjoin_free(cub->buf.content, line, 2);
		/**
		 * end of set_buffer
		 */
		cub->buf.buffer = ft_split_nl(cub->buf.content);
		close(fd);
	/**
	 * end of init_desc
	 */
	check_content(cub);
//	assign_res(cub);
	/**
	 * assign_res(cub);
	 */
		int i;
		int j;

		i = 0;
		while (cub->buf.buffer[i] && cub->buf.buffer[i][0] != 'R')
			i++;
		j = 1;
		cub->res_x = ft_atoi(&cub->buf.buffer[i][j]);
		while (cub->buf.buffer[i][j] && cub->buf.buffer[i][j] == ' ')
			j++;
		while (cub->buf.buffer[i][j] \
			&& (cub->buf.buffer[i][j] >= '0' && cub->buf.buffer[i][j] <= '9'))
			j++;
		cub->res_y = ft_atoi(&cub->buf.buffer[i][j]);
		if (cub->res_x > 2560)
			cub->res_x = 2560;
		if (cub->res_y > 1440)
			cub->res_y = 1440;
		if (cub->res_x <= 0 || cub->res_y <= 0)
			display_error(cub, "Resolution not valid.\n");
	/**
	 * end of assign_res
	 */
	init_map(cub);
	init_var(cub);
}

int			main(int argc, char **argv)
{
	t_cub3d	cub;

	if (argc > 1)
	{
		init_cub3d(&cub, argv[1]);
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
