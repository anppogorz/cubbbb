#include "cub3d.h"
#include "libft.h"

t_resolution get_value_resolution(char **tab, char *str, int nb)
{
	int i;
	t_resolution res;
	char *tab_cpy;

	res.x = 0;
	res.y = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			tab_cpy++;
			res.x = ft_atoi(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			res.y = ft_atoi(tab_cpy);
			return (res);
		}
		i++;
	}
	return (res);
}

t_f	get_value_color_f(char **tab, char *str, int nb)
{
	int i;
	t_f f;
	char *tab_cpy;

	i = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab[i], str, nb) == 0)
		{
			tab_cpy = tab[i];
			tab_cpy++;
			f.x = ft_atoi(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			f.y = ft_atoi(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			f.z = ft_atoi(tab_cpy);
			return (f);
		}
		i++;
	}
	return (f);
}

t_f	get_value_color(char **tab, char *str, int nb)
{
	int i;
	t_f f;
	char *tab_cpy;

	i = 0;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			tab_cpy++;
			f.x = ft_atoi(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			f.y = ft_atoi(tab_cpy);
			tab_cpy = skip_spaces(tab_cpy);
			tab_cpy = skip_nbr(tab_cpy);
			f.z = ft_atoi(tab_cpy);
			return (f);
		}
		i++;
	}
	return (f);
}

char	*get_value_path(char **tab, char *str, int nb)
{
	int i;
	char *value;
	char *tab_cpy;

	i = 0;
	value = NULL;
	while (tab[i] != NULL)
	{
		tab_cpy = tab[i];
		tab_cpy = skip_spaces(tab_cpy);
		if (ft_strncmp(tab_cpy, str, nb) == 0)
		{
			if (ft_strlen(str) == 3)
				tab_cpy++;
			tab_cpy++;
			tab_cpy = skip_spaces(tab_cpy);
			value = ft_strdup(tab_cpy);
			return (value);
		}
		i++;
	}
	return (value);
}

t_info		get_values(char **tab)
{
	t_info info;


	info.res = get_value_resolution(tab, "R ", 2);
	info.text.ea = get_value_path(tab, "EA ", 2);
	info.text.we = get_value_path(tab, "WE ", 2);
	info.text.so = get_value_path(tab, "SO ", 2);
	info.text.no = get_value_path(tab, "NO ", 2);
	info.text.s = get_value_path(tab, "S ", 2);
	info.f = get_value_color(tab, "F ", 2);
	info.c = get_value_color(tab, "C ", 2);
	return (info);
}
