#include "cub3d.h"
#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "./minilibx_opengl_20191021/mlx.h"

char    **malloc_tab(int ret, char *line, char **tab)
{
    int i;
    int fd;

    i = 0;
    fd = open("map.cub", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) == 1)
    {
    	if (ft_strncmp(line, "", 1) != 0)
    		i++;
        free(line);
    }
    if (!(tab = (char **)malloc(sizeof(char*) * (i + 1))))
        return (NULL);
    tab[i] = NULL;
    close(fd);
    return (tab);
}

char    **tab(void)
{
    char *line;
    char **tab;
    int i;
    int fd;
    int ret;

    tab = malloc_tab(ret, line, tab);
    fd = open("map.cub", O_RDONLY);
    i = 0;
    while ((ret = get_next_line(fd, &line)) == 1)
    {
    	if (ft_strncmp(line, "", 1) != 0)
		{
			tab[i] = ft_strdup(line);
			i++;
		}
        free(line);
    }
    return (tab);
}

t_info    	parsing(char **tab)
{
	t_info info;

    if (verif_tab(tab) == 0)
	{
    	printf("ERROR");
    	return (info);
	}
    return (get_values(tab));
}

char	**get_map(char **tab)
{
	int i;

	i = 0;
	while (ft_atoi(tab[i]) == 0)
		tab++;
	return (tab);
}

int main(void)
{
	t_info 	info;
	char 	**tab;
	void	*mlx_ptr;
	void	*win_ptr;
	double 	cameraX;
	double perpwalldist;
	int i;
	int hit;
	int side ;
	t_resolution step;
	t_resolution map;
	t_dir sidedist;
	t_dir deltadist;

	i = 0;
    info = parsing(tab());
	tab = get_map(tab());
	info.pos = get_pos(map);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, info.res.x, info.res.y, "Cub3d");
	while (i < info.res.y)
	{
		cameraX = (2 * i) / (double)info.res.y - 1;
		info.raydir.y = info.dir.x + (info.plane.x * cameraX);
		info.raydir.x = info.dir.y + info.plane.y
	}
	deltadist.y = (1 / info.raydir.y);
	deltadist.x = (1 / info.raydir.x);
	if (info.raydir.y < 0)
	{
		step.x = 1;
		sidedist.y = ()
	}
	mlx_loop(mlx_ptr);
    /*printf("%d\n", info.res.x);
	printf("%d\n", info.res.y);
	printf("%s\n", info.text.ea);
	printf("%s\n", info.text.no);
	printf("%s\n", info.text.so);
	printf("%s\n", info.text.we);
	printf("%s\n", info.text.s);
	printf("%d\n", info.f.x);
	printf("%d\n", info.c.x);*/

    return (0);
}
// free info.text
// afficher messages d'erreurs

/*int	display(t_info info, char **map)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, info.res.x, info.res.y, "TEST");
	mlx_loop(mlx_ptr);
}*/