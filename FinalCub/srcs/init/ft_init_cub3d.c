#include "cub3d.h"

static void	ft_fill_buff(t_cub3d *cub3d)
{
	int		i;
	int		fd;
	char	*line;
	char	*buff;
	int		cwr;

	i = 0;
	fd = open(cub3d->file_path, O_RDONLY);
	if (read(fd, buff, 0) < 0)
		exception(THIRTYONE);
	if (fd < 0)
	{
		close(fd);
		exception(TWO);
	}
	while (1)
	{
		cwr = get_next_line(fd, &line);
		cub3d->buff[i] = ft_strdup(line);
		free(line);
		if (cwr == 0)
			break ;
		i++;
	}
	close(fd);
}

static void	ft_set_buffer(int fd, t_cub3d *cub3d)
{
	char	*line;
	char	*check;
	int		cwr;
	int		i;

	while (1)
	{
		cwr = get_next_line(fd, &line);
		free(line);
		i++;
		if (cwr == 0)
			break ;
	}
	close(fd);
	cub3d->buff = malloc(sizeof(char *) * (i + 1));
	if (!cub3d->buff)
		exception(THIRTYNINE);
	cub3d->buff[i] = NULL;
	ft_fill_buff(cub3d);
}

static void	ft_init_vars01(t_cub3d *cub3d)
{
	cub3d->mlx = malloc(sizeof(t_mlx));
	if (!cub3d->mlx)
		exception(THIRTYEIGHT);
	cub3d->mlx->p_mlx = NULL;
	cub3d->mlx->p_win = NULL;
	cub3d->mlx->image = NULL;
	cub3d->mlx->p_img = NULL;
	cub3d->mlx->bits_per_pixel = 0;
	cub3d->mlx->line_length = 0;
	cub3d->mlx->endian = 0;
	cub3d->spr_crds = NULL;
	ft_memset(&cub3d->map, 0, sizeof(char **));
	ft_memset(&cub3d->keys, 0, sizeof(t_keys));
	ft_memset(&cub3d->texture, 0, sizeof(t_texture) * 7);
	ft_memset(&cub3d->floor, 0, sizeof(t_floor));
	ft_memset(&cub3d->sprite, 0, sizeof(t_sprite));
}

static int	ft_check_fileformat(char *argument)
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

void	ft_init_cub3d(t_cub3d *cub3d)
{
	int		fd;
	char	*check;

	ft_init_vars01(cub3d);
	if (!ft_check_fileformat(cub3d->file_path))
		exception(ONE);
	fd = open(cub3d->file_path, O_RDONLY);
	if (read(fd, check, 0) < 0)
		exception(THIRTYONE);
	if (fd < 0)
	{
		close(fd);
		exception(TWO);
	}
	ft_set_buffer(fd, cub3d);
	ft_check_params01(cub3d);
	ft_check_file(cub3d);
	ft_read_screen_size(cub3d);
	ft_init_map(cub3d);
	ft_init_vars02(cub3d);
}
