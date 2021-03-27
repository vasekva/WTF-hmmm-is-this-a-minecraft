#include "cub3d.h"

char	*ft_add_spaces(char *str, int add)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	dst = malloc(len + add + 1);
	if (!dst)
		exception(TWENTYONE);
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
	return (dst);
}

int	ft_skiplines(t_cub3d *cub3d, char *line, int i)
{
	while (cub3d->buff[i][0] != '0' && cub3d->buff[i][0] != '1'
		&& cub3d->buff[i][0] != '2')
	{
		if (cub3d->buff[i][0]
			== ' ' && is_map_line(cub3d, cub3d->buff[i]))
			break ;
		i++;
	}
	return (i);
}

void	ft_fill_map(t_cub3d *cub3d, int i, int len, int ind)
{
	int		diff;
	char	*tmp;

	diff = 0;
	tmp = NULL;
	while (cub3d->buff[i])
	{
		len = ft_strlen(cub3d->buff[i]);
		if (len < cub3d->map_w)
		{
			diff = cub3d->map_w - len;
			tmp = ft_add_spaces(cub3d->buff[i], diff);
			cub3d->map[ind]
				= ft_strdup(tmp);
			free(tmp);
		}
		else
		{
			cub3d->map[ind] = ft_strdup(cub3d->buff[i]);
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
	i = ft_skiplines(cub3d, cub3d->buff[i], i);
	j = i;
	len = ft_strlen(cub3d->buff[j]);
	while (cub3d->buff[j])
	{
		if (ft_strlen(cub3d->buff[j]) > len)
			len = ft_strlen(cub3d->buff[j]);
		j++;
	}
	cub3d->map_w = len;
	ft_fill_map(cub3d, i, 0, 0);
}
