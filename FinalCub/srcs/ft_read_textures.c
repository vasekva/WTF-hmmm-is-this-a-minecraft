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
		cub3d->tex[ind].texture = 0;
	}
	else
	{
		cub3d->tex[ind].tex_path = ft_strtrim(&line[i], " ");
		cub3d->tex[ind].texture = 1;
	}
}

static void	assign_tex(t_cub3d *cub, char *line, int i)
{
	assign_path_tex(cub, line, i);
	if (cub->tex[i].texture == 1)
	{
		cub->tex[i].image
			= mlx_xpm_file_to_image(cub->mlx_ptr, cub->tex[i].tex_path,
				&cub->tex[i].width, &cub->tex[i].height);
		if (!cub->tex[i].image)
			exception(THIRTEEN);
		cub->tex[i].tex_ptr
			= mlx_get_data_addr(cub->tex[i].image,
				&cub->tex[i].bit_pix, &cub->tex[i].size_line,
				&cub->tex[i].endian);
		if (!cub->tex[i].tex_ptr)
			exception(FOURTEEN);
	}
}

void	ft_read_textures(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->buf.buffer[i])
	{
		if (cub3d->buf.buffer[i][0] == 'S' && cub3d->buf.buffer[i][1] == 'O')
			assign_tex(cub3d, cub3d->buf.buffer[i], 0);
		if (cub3d->buf.buffer[i][0] == 'N' && cub3d->buf.buffer[i][1] == 'O')
			assign_tex(cub3d, cub3d->buf.buffer[i], 1);
		if (cub3d->buf.buffer[i][0] == 'E' && cub3d->buf.buffer[i][1] == 'A')
			assign_tex(cub3d, cub3d->buf.buffer[i], 2);
		if (cub3d->buf.buffer[i][0] == 'W' && cub3d->buf.buffer[i][1] == 'E')
			assign_tex(cub3d, cub3d->buf.buffer[i], 3);
		if (cub3d->buf.buffer[i][0] == 'F' && cub3d->buf.buffer[i][1] == ' ')
			assign_tex(cub3d, cub3d->buf.buffer[i], 4);
		if (cub3d->buf.buffer[i][0] == 'C' && cub3d->buf.buffer[i][1] == ' ')
			assign_tex(cub3d, cub3d->buf.buffer[i], 5);
		if (cub3d->buf.buffer[i][0] == 'S' && cub3d->buf.buffer[i][1] == ' ')
			assign_tex(cub3d, cub3d->buf.buffer[i], 6);
		i++;
	}
}
