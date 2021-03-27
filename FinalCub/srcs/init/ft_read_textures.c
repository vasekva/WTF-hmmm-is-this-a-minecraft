#include "cub3d.h"

static void	assign_path_tex(t_cub3d *cub3d, char *line, int ind)
{
	int	i;

	i = 0;
	while (line[i]
		&& (line[i] == 'N' || line[i] == 'O' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E' || line[i] == 'A'
			|| line[i] == 'F' || line[i] == 'C'))
		i++;
	if (line[i] != ' ')
		exception(TWENTYNINE);
	while (line[i] == ' ')
		i++;
	if (line[i] >= '0' && line[i] <= '9')
	{
		ft_parse_color(line, ind, cub3d);
		cub3d->texture[ind].texture = 0;
	}
	else
	{
		cub3d->texture[ind].path_texture = ft_strtrim(&line[i], " ");
		cub3d->texture[ind].texture = 1;
	}
}

static void	assign_tex(t_cub3d *cub3d, char *line, int i)
{
	assign_path_tex(cub3d, line, i);
	if (cub3d->texture[i].texture == 1)
	{
		cub3d->texture[i].image
			= mlx_xpm_file_to_image(cub3d->mlx->p_mlx,
				cub3d->texture[i].path_texture, &cub3d->texture[i].width,
				&cub3d->texture[i].height);
		if (!cub3d->texture[i].image)
			exception(THIRTEEN);
		cub3d->texture[i].ptr_texture
			= mlx_get_data_addr(cub3d->texture[i].image,
				&cub3d->texture[i].bits_per_pixel,
				&cub3d->texture[i].line_length, &cub3d->texture[i].endian);
		if (!cub3d->texture[i].ptr_texture)
			exception(FOURTEEN);
	}
}

void	ft_read_textures(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->buff[i])
	{
		if (cub3d->buff[i][0] == 'S' && cub3d->buff[i][1] == 'O')
			assign_tex(cub3d, cub3d->buff[i], 0);
		if (cub3d->buff[i][0] == 'N' && cub3d->buff[i][1] == 'O')
			assign_tex(cub3d, cub3d->buff[i], 1);
		if (cub3d->buff[i][0] == 'E' && cub3d->buff[i][1] == 'A')
			assign_tex(cub3d, cub3d->buff[i], 2);
		if (cub3d->buff[i][0] == 'W' && cub3d->buff[i][1] == 'E')
			assign_tex(cub3d, cub3d->buff[i], 3);
		if (cub3d->buff[i][0] == 'F' && cub3d->buff[i][1] == ' ')
			assign_tex(cub3d, cub3d->buff[i], 4);
		if (cub3d->buff[i][0] == 'C' && cub3d->buff[i][1] == ' ')
			assign_tex(cub3d, cub3d->buff[i], 5);
		if (cub3d->buff[i][0] == 'S' && cub3d->buff[i][1] == ' ')
			assign_tex(cub3d, cub3d->buff[i], 6);
		i++;
	}
}
