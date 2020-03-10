#include "cub3d.h"
#include "libft.h"

int 	verif_info_resolution(char **tab, char *str, int nb)
{
	int i;
	int verif;
	char *tab_cpy;

	i = 0;
	verif = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			tab_cpy++;
			tab_cpy = skip_spaces(tab_cpy);
			verif = check_nbr(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			verif = verif + check_nbr(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			if (*tab_cpy == '\0' && verif == 2)
				return (1);
		}
		i++;
	}
	return (0);
}

int		verif_info_color(char **tab, char *str, int nb)
{
	int i;
	int verif;
	char *tab_cpy;

	i = 0;
	verif = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			tab_cpy++;
			tab_cpy = skip_spaces(tab_cpy);
			while (*tab_cpy != '\0')
			{
				verif = verif + check_nbr(tab_cpy);
				tab_cpy = skip_nbr(tab_cpy);
				tab_cpy = skip_coma(tab_cpy);
				if (check_nbr(tab_cpy) != 1 && *tab_cpy != '\0')
					return (0);
			}
			if (*tab_cpy == '\0' && verif == 3)
				return (1);
		}
		i++;
	}
	return (0);
}

int 	verif_info_path(char **tab, char *str, int nb)
{
	int i;
	int verif;
	char *tab_cpy;

	i = 0;
	verif = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			tab_cpy++;
			if (ft_strlen(str) == 3)
				tab_cpy++;
			tab_cpy = skip_spaces(tab_cpy);
			while (*tab_cpy != ' ' && *tab_cpy != '\0')
				tab_cpy++;
			tab_cpy = skip_spaces(tab_cpy);
			if (*tab_cpy == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	verif_info(char **tab)
{
	if (verif_info_resolution(tab, "R ", 2) == 0)
		return (0);
	if (verif_info_path(tab, "S ", 2) == 0)
		return (0);
	if (verif_info_color(tab, "F ", 2) == 0)
		return (0);
	if (verif_info_color(tab, "C ", 2) == 0)
		return (0);
	if (verif_info_path(tab, "NO ", 3) == 0)
		return (0);
	if (verif_info_path(tab, "SO ", 3) == 0)
		return (0);
	if (verif_info_path(tab, "WE ", 3) == 0)
		return (0);
	if (verif_info_path(tab, "EA ", 3) == 0)
		return (0);
	return (1);
}