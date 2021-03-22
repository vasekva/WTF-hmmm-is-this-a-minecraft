#include "cub3d.h"

static void	check_format(t_cub3d *cub, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		exception(FIFTEEN);
}

static void	assign_rgb(int temp, char **rgb)
{
	if (temp < 0)
		temp = 0;
	if (temp > 255)
		temp = 255;
	*rgb = ft_itoa_base(temp, "0123456789ABCDEF");
	if (temp < 16)
		*rgb = ft_strjoin("0", *rgb, 0);
}

static void	check_byte(t_cub3d *cub3d, char *line, int count)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == ',')
	{
		if (count == 0)
			exception(SIXTEEN);
		else if (count == 1)
			exception(SEVENTEEN);
		else if (count == 2)
			exception(EIGHTEEN);
	}
	while (line[i] && line[i] != ',')
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (count == 0)
				exception(NINETEEN);
			else if (count == 1)
				exception(TWENTY);
			else if (count == 2)
				exception(TWENTYONE);
		}
		i++;
	}
}

void	assign_color(t_cub3d *cub3d, char *line, int ind)
{
	int		i;
	int		count;
	char	*rgb[3];
	char	*color;
	int		temp;

	check_format(cub3d, line);
	i = 0;
	count = 0;
	while (count < 3)
	{
		temp = ft_atoi(&line[i]);
		assign_rgb(temp, &rgb[count]);
		check_byte(cub3d, &line[i], count);
		while (line[i] && line[i] != ',')
			i++;
		i++;
		count++;
	}
	color = ft_strjoin(rgb[0], rgb[1], 2);
	color = ft_strjoin(color, rgb[2], 2);
	cub3d->tex[ind].col = ft_atoi_base(color, "0123456789ABCDEF");
	ft_strdel(&color);
}
