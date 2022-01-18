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
//	raycasting(cub);
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

static void 		init(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = NULL;
	cub3d->win_ptr = NULL;
	cub3d->image = NULL;
	cub3d->img_ptr = NULL;
	cub3d->c_spr = NULL;
	ft_memset(&cub3d->buf, 0, sizeof(t_buf));
	ft_memset(&cub3d->map, 0, sizeof(char**));
	ft_memset(&cub3d->act, 0, sizeof(t_action));
	ft_memset(&cub3d->tex, 0, sizeof(t_tex) * 7);
	ft_memset(&cub3d->flr, 0, sizeof(t_floor));
	ft_memset(&cub3d->spr, 0, sizeof(t_sprite));
}

static	void	set_buffer(int fd, t_cub3d *cub3d)
{
	char	*line;
	int		ret;

	cub3d->buf.content = ft_strdup("");
	while ((ret = get_next_line(fd, &line)))
	{
		cub3d->buf.content = ft_strjoin_free(cub3d->buf.content, line, 2);
		cub3d->buf.content = ft_strjoin_free(cub3d->buf.content, "\n", 1);
	}
	cub3d->buf.content = ft_strjoin_free(cub3d->buf.content, line, 2);
	cub3d->buf.buffer = ft_split_nl(cub3d->buf.content);
	close(fd);
}

void	assign_res(t_cub3d *cub3d)
{
	int i;
	int j;

	i = 0;
	while (cub3d->buf.buffer[i] && cub3d->buf.buffer[i][0] != 'R')
		i++;
	j = 1;
	cub3d->res_x = ft_atoi(&cub3d->buf.buffer[i][j]);
	while (cub3d->buf.buffer[i][j] && cub3d->buf.buffer[i][j] == ' ')
		j++;
	while (cub3d->buf.buffer[i][j] \
 		&& (cub3d->buf.buffer[i][j] >= '0' && cub3d->buf.buffer[i][j] <= '9'))
		j++;
	cub3d->res_y = ft_atoi(&cub3d->buf.buffer[i][j]);
	if (cub3d->res_x > 2560)
		cub3d->res_x = 2560;
	if (cub3d->res_y > 1440)
		cub3d->res_y = 1440;
	if (cub3d->res_x <= 0 || cub3d->res_y <= 0)
		exception(FOUR);
}

void 		init_cub3d(t_cub3d *cub3d, char *desc)
{
	int		fd;


	init(cub3d);
	if (!check_type(desc))
		exception(TWO);
//		display_error(cub3d, "Description file must be *.cub3d type.\n");
	if ((fd = open(desc, O_RDONLY)) < 0)
	{
		close(fd);
		exception(THREE);
//		display_error(cub3d, "Could not find map description.\n");
	}
	set_buffer(fd, cub3d);
	check_content(cub3d);
	assign_res(cub3d);
	init_map(cub3d);
	init_var(cub3d);
}

int			main(int argc, char **argv)
{
	t_cub3d cub3d;

	if (argc > 1)
	{
		init_cub3d(&cub3d, argv[1]);
		if (argc == 3 && !ft_strcmp(argv[2], "--save"))
			cub3d.screenshot = 1;
		if (!create_window(&cub3d))
			exception(THIRTY);
//			display_error(&cub3d, "Could not create window.\n");

		print_structs(&cub3d);


		mlx_hook(cub3d.win_ptr, 17, 0L, exit_prog, &cub3d);
		mlx_hook(cub3d.win_ptr, 2, (1L << 0), key_press, &cub3d);
		mlx_hook(cub3d.win_ptr, 3, (1L << 1), key_release, &cub3d);
		mlx_loop_hook(cub3d.mlx_ptr, motion, &cub3d);
		mlx_loop(cub3d.mlx_ptr);

	}
	else
		ft_putstr_fd("Please select descriptor file.\n", 1);
	return (0);
}