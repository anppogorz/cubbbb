#include "libft.h"
#include "cub3d.h"

char	*ft_strdup_no_space(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	while (s1[j] == ' ')
		j++;
	while (s1[i + j] != '\0')
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2 == 0)
		return (NULL);
	i = 0;
	while (s1[i + j] != '\0')
	{
		s2[i] = s1[i + j];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*skip_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	*skip_nbr(char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

char	*skip_coma(char *str)
{
	if (*str == ',')
		str++;
	return (str);
}

int		check_nbr(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}