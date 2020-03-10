#include "cub3d.h"
#include "libft.h"

int 	verif_all_for(char **tab, char *str, int nb)
{
	int i;
	char *tab_cpy;

	i = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		verif_double_for(char **tab, char *str, int nb)
{
	int i;
	char *tab_cpy;

	i = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			i++;
			while (tab[i] != NULL)
			{
				tab_cpy = tab[i];
				tab_cpy = skip_spaces(tab_cpy);
				if (ft_strncmp(tab_cpy, str, nb) == 0)
					return (0);
				i++;
			}
			return (1);
		}
		i++;
	}
	return (1);
}

int		verif_all(char **tab)
{
	if (verif_all_for(tab, "S ", 2) == 0)
		return (0);
	if (verif_all_for(tab, "R ", 2) == 0)
		return (0);
	if (verif_all_for(tab, "F ", 2) == 0)
		return (0);
	if (verif_all_for(tab, "C ", 2) == 0)
		return (0);
	if (verif_all_for(tab, "NO ", 3) == 0)
		return (0);
	if (verif_all_for(tab, "SO ", 3) == 0)
		return (0);
	if (verif_all_for(tab, "WE ", 3) == 0)
		return (0);
	if (verif_all_for(tab, "EA ", 3) == 0)
		return (0);
	return (1);
}

int		verif_double(char **tab)
{
	if (verif_double_for(tab, "S ", 2) == 0)
		return (0);
	if (verif_double_for(tab, "R ", 2) == 0)
		return (0);
	if (verif_double_for(tab, "F ", 2) == 0)
		return (0);
	if (verif_double_for(tab, "C ", 2) == 0)
		return (0);
	if (verif_double_for(tab, "NO ", 3) == 0)
		return (0);
	if (verif_double_for(tab, "SO ", 3) == 0)
		return (0);
	if (verif_double_for(tab, "WE ", 3) == 0)
		return (0);
	if (verif_double_for(tab, "EA ", 3) == 0)
		return (0);
	return (1);
}

int     verif_tab(char **tab)
{
	int i;

	i = 0;
	if (verif_all(tab) == 0)
		return (0);
	if (verif_double(tab) == 0)
		return (0);
	if (verif_info(tab) == 0)
		return (0);
	if (verif_map(tab) == 0)
		return (0);
	return (1);
}