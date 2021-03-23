#include "cub3d.h"

static	int	ft_check_fileformat(char *argument)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (argument[i])
	{
		if (argument[i] == '.')
			pos = i;
		i++;
	}
	if (!ft_strncmp(&argument[pos], ".cub", ft_strlen(&argument[pos])))
		return (-1);
	return (0);
}

void	ft_set_buffer(int fd, t_cub3d *cub3d)
{
	char	*line;
	int		cwr;

	cub3d->buf.content = ft_strdup("");
	while (1)
	{
		cwr = get_next_line(fd, &line);
		if (cwr == 0)
			break ;
		cub3d->buf.content = ft_strjoin(cub3d->buf.content, line, 2);
		cub3d->buf.content = ft_strjoin(cub3d->buf.content, "\n", 1);
	}
	cub3d->buf.content = ft_strjoin(cub3d->buf.content, line, 2);
	cub3d->buf.buffer = ft_split_nl(cub3d->buf.content);
	close(fd);
}

void	init(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = NULL;
	cub3d->win_ptr = NULL;
	cub3d->image = NULL;
	cub3d->img_ptr = NULL;
	cub3d->c_spr = NULL;
	ft_memset(&cub3d->buf, 0, sizeof(t_buf));
	ft_memset(&cub3d->map, 0, sizeof(char **));
	ft_memset(&cub3d->act, 0, sizeof(t_action));
	ft_memset(&cub3d->tex, 0, sizeof(t_tex) * 7);
	ft_memset(&cub3d->flr, 0, sizeof(t_floor));
	ft_memset(&cub3d->spr, 0, sizeof(t_sprite));
}

void	ft_read_screen_size(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->buf.buffer[i] && cub3d->buf.buffer[i][0] != 'R')
		i++;
	j = 1;
	cub3d->res_x = ft_atoi(&cub3d->buf.buffer[i][j]);
	while (cub3d->buf.buffer[i][j] && cub3d->buf.buffer[i][j] == ' ')
		j++;
	while (cub3d->buf.buffer[i][j]
		&& (cub3d->buf.buffer[i][j] >= '0'
			&& cub3d->buf.buffer[i][j] <= '9'))
		j++;
	cub3d->res_y = ft_atoi(&cub3d->buf.buffer[i][j]);
	if (cub3d->res_x > 2560)
		cub3d->res_x = 2560;
	if (cub3d->res_y > 1440)
		cub3d->res_y = 1440;
	if (cub3d->res_x <= 0 || cub3d->res_y <= 0)
		exception(SIX);
}

void	init_cub3d(t_cub3d *cub3d, char *arg)
{
	int	fd;

	init(cub3d);
	if (!ft_check_fileformat(arg))
		exception(ONE);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		exception(TWO);
	}
	ft_set_buffer(fd, cub3d);
	ft_check_file(cub3d);
	ft_read_screen_size(cub3d);
	 
	ft_init_map(cub3d);
	// exit(0);
	init_vars(cub3d);
}

static int	create_window(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		return (0);
	ft_read_textures(cub3d);
	cub3d->image = mlx_new_image(cub3d->mlx_ptr, cub3d->res_x, cub3d->res_y);
	if (!cub3d->image)
		return (0);
	cub3d->img_ptr = mlx_get_data_addr(cub3d->image, &cub3d->bit_pix, \
									&cub3d->size_line, &cub3d->endian);
	if (cub3d->screenshot)
	{
		ft_convert_bmp(cub3d);
		exit(0);
	}
	cub3d->win_ptr
		= mlx_new_window(cub3d->mlx_ptr, cub3d->res_x, cub3d->res_y, "cub3d");
	if (!cub3d->win_ptr)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		flag;

	flag = 0;
	if (argc > 1)
	{
		init_cub3d(&cub3d, argv[1]);
		if (argc == 3 && !ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
			cub3d.screenshot = 1;
		flag = create_window(&cub3d);
		if (!flag)
			exception(TWELVE);
		print_structs(&cub3d);
		mlx_hook(cub3d.win_ptr, 17, 0L, exit_prog, &cub3d);
		mlx_hook(cub3d.win_ptr, 2, (1L << 0), key_press, &cub3d);
		mlx_hook(cub3d.win_ptr, 3, (1L << 1), key_release, &cub3d);
		mlx_loop_hook(cub3d.mlx_ptr, ft_start_game, &cub3d);
		mlx_loop(cub3d.mlx_ptr);
	}
	else
		ft_putstr("Вы не передали аргументы в программу!\n");
	return (0);
}
