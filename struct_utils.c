#include "cub3d.h"

char		*ft_strdup_num(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	while (s1[i + j] == '0')
		j++;
	while (s1[i + j] >= '0' && s1[i + j] <= '9')
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i + j] >= '0' && s1[i + j] <= '9')
	{
		s2[i] = s1[i + j];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	get_orientation(char **tab)
{
	int i;
	char *tab_cpy;

	i = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		while (*tab_cpy != 'N' && *tab_cpy != 'S' && *tab_cpy != 'E' && *tab_cpy != 'W' && *tab_cpy != '\0')
			tab_cpy++;
		if (*tab_cpy == 'N' || *tab_cpy == 'S' || *tab_cpy == 'E' || *tab_cpy == 'W')
			return (*tab_cpy);
		i++;
	}
	return ((char)0);
}

t_pos get_pos(char **map)
{
	t_pos pos;

	pos.x = 0;
	pos.y = 0;
	pos.orientation = get_orientation(map);
	while (map[pos.y] != NULL)
	{
		while (map[pos.y][pos.x] != pos.orientation && map[pos.y][pos.x] != '\0')
			pos.x++;
		if (map[pos.y][pos.x] == pos.orientation)
			return (pos);
		pos.x = 0;
		pos.y++;
	}
	return (pos);
}