#include "cub3d.h"
#include "libft.h"

int	verif_line(char *str)
{
	char *tab_cpy;

	tab_cpy = str;
	while (*tab_cpy != '\0')
	{
		tab_cpy = skip_spaces(tab_cpy);
		if (*tab_cpy == '1')
			tab_cpy++;
		else
			return (0);
	}
	return (1);
}

int	verif_line_in(char *str)
{
	char *tab_cpy;

	tab_cpy = str;
	tab_cpy = skip_spaces(tab_cpy);
	if (*tab_cpy != '1')
		return (0);
	while (*tab_cpy != '\0')
	{
		if (*tab_cpy == '1' || *tab_cpy == '2' || *tab_cpy == '0' || *tab_cpy == 'N' || *tab_cpy == 'S' ||
		*tab_cpy == 'E' || *tab_cpy == 'W' || *tab_cpy == ' ')
			tab_cpy++;
		else
			return (0);
	}
	tab_cpy--;
	while (*tab_cpy == ' ')
		tab_cpy--;
	if (*tab_cpy != '1')
		return (0);
	return (1);
}

int	verif_space(char **tab, int i)
{
	char *tab_cpy;
	int j;

	j = 0;
	tab_cpy = tab[i];
	while (tab_cpy[j] != '\0')
	{
		if (tab_cpy[j] == ' ')
		{
			if (char_space(tab_cpy[j + 1]) == 0)
				return (0);
			if (ft_strlen(tab[i + 1]) >= ft_strlen(tab[i]))
			{
				if (char_space(tab[i + 1][j]) == 0)
					return (0);
			}
			if (ft_strlen(tab[i - 1]) >= ft_strlen(tab[i]))
			{
				if (char_space(tab[i - 1][j]) == 0)
					return (0);
			}
			if (j > 0 && char_space(tab_cpy[j - 1]) == 0)
					return (0);
		}
		j++;
	}
	return (1);
}

int	verif_floor(char **tab, int i)
{
	char *tab_cpy;
	int j;

	j = 0;
	tab_cpy = tab[i];
	while (tab_cpy[j] != '\0')
	{
		if (tab_cpy[j] == '0')
		{
			if ((char_floor(tab_cpy[j - 1]) == 1) && (char_floor(tab_cpy[j + 1]) == 1) && (char_floor(tab[i + 1][j]) == 1)
			&& (char_floor(tab[i - 1][j]) == 1))
				j++;
			else
			{
				printf("ZERO str = %s x = %d y = %d\n", tab[i - 1], j, i - 1);
				printf("ZERO str = %s x = %d y = %d\n", tab_cpy, j, i);
				printf("ZERO str = %s x = %d y = %d\n", tab[i + 1], j, i + 1);
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int	get_value_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	char_floor(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'S' || c == 'N' || c == 'E' || c == 'W' || c == '\0' || c == '\n')
		return (1);
	return (0);
}

int	char_space(char c)
{
	if (c == ' ' || c == '1' || c == '\0' || c == '\n')
		return (1);
	return (0);
}

int	verif_map(char **tab)
{
	int i;
	int j;

	i = 0;
	j = get_value_map(tab);
	if (verif_line(tab[i]) == 0)
		return (0);
	i++;
	while (tab[i + 1] != NULL && verif_line_in(tab[i]) == 1 && verif_space(tab, i) == 1 && verif_floor(tab, i) == 1)
		i++;
	if (verif_line(tab[i]) == 0 || i != (j - 1))
		return (0);
	return (1);
}
