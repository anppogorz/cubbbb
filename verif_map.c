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
	tab_cpy = skip_spaces(tab_cpy);
	while (tab_cpy[j] != '\0')
	{
		if (tab_cpy[j] == 'X')
		{
			if ((tab_cpy[j - 1] == '1' || tab_cpy[j - 1] == ' ') && (tab_cpy[j + 1] == '1' || tab_cpy[j + 1] == ' ')
			&& (tab[i + 1][j] == '1' || tab[i + 1][j] == ' ') && (tab[i - 1][j] == '1' || tab[i - 1][j] == ' '))
				j++;
			else
				return (0);
		}
		j++;
	}
	return (1);
}

int	value_map(char **tab)
{
	int i;

	i = 0;
	while (ft_atoi(tab[i]) == 0)
		i++;
	return (i);
}

int	verif_map(char **tab)
{
	int i;
	int j;

	i = 0;
	j = value_map(tab);
	while (tab[i] != NULL)
		i++;
	i--;
	if (verif_line(tab[i]) == 0)
		return (0);
	i--;
	while (verif_line_in(tab[i]) == 1 && verif_space(tab, i) == 1)
		i--;
	i++;
	if (verif_line(tab[i]) == 0 || i != j)
		return (0);
	return (1);
}