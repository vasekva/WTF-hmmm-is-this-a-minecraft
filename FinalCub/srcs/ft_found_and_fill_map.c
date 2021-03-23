#include "cub3d.h"

char	*ft_add_spaces(char *str, int add)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	dst = malloc(len + add + 1);
	dst[len + add] = '\0';
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	while (add)
	{
		dst[i] = ' ';
		add--;
		i++;
	}
	if (str)
		free(str);
	return (dst);
}

int	ft_skiplines(t_cub3d *cub3d, char *line, int i)
{
	while (cub3d->buf.buffer[i][0] != '0' && cub3d->buf.buffer[i][0] != '1'
		&& cub3d->buf.buffer[i][0] != '2')
	{
		if (cub3d->buf.buffer[i][0] == ' ' && is_map_line(cub3d->buf.buffer[i]))
			break ;
		i++;
	}
	return (i);
}

void	ft_fill_map(t_cub3d *cub3d, int i)
{
	int	len;
	int	ind;
	int	diff;

	len = 0;
	ind = 0;
	diff = 0;
	while (cub3d->buf.buffer[i])
	{
		len = ft_strlen(cub3d->buf.buffer[i]);
		if (len < cub3d->map_w)
		{
			diff = cub3d->map_w - len;
			cub3d->map[ind]
				= ft_strdup(ft_add_spaces(cub3d->buf.buffer[i], diff));
		}
		else
		{
			cub3d->map[ind] = ft_strdup(cub3d->buf.buffer[i]);
		}
		i++;
		ind++;
	}
}

void	ft_found_and_fill_map(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	i = ft_skiplines(cub3d, cub3d->buf.buffer[i], i);
	j = i;
	len = ft_strlen(cub3d->buf.buffer[j]);
	while (cub3d->buf.buffer[j])
	{
		if (ft_strlen(cub3d->buf.buffer[j]) > len)
			len = ft_strlen(cub3d->buf.buffer[j]);
		j++;
	}
	cub3d->map_w = len;
	ft_fill_map(cub3d, i);
}
