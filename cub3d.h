#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
#include "./minilibx_opengl_20191021/mlx.h"
#include <stdio.h>

typedef struct	s_resolution
{
	int x;
	int y;
}				t_resolution;

typedef struct	s_textures
{
	char* no;
	char* so;
	char* we;
	char* ea;
	char* s;
}				t_textures;

typedef struct	s_f
{
	int x;
	int	y;
	int z;
}				t_f;

typedef struct	s_pos
{
	int	x;
	int	y;
	char orientation;
}				t_pos;

typedef struct	s_dir
{
	double x;
	double y;
}				t_dir;

typedef struct	s_info
{
	t_resolution res;
	t_textures text;
	t_f f;
	t_f c;
	t_dir pos;
	t_dir dir;
	t_dir plane;
	t_dir time;
	t_dir raydir;
}				t_info;

int     verif_tab(char **tab);
int		verif_info(char **tab);
char	**get_map(char **tab);
char	*ft_strdup_no_space(const char *s1);
char	*ft_strdup_num(const char *s1);
char	*skip_spaces(char *str);
char	*skip_nbr(char *str);
char	*skip_coma(char *str);
int		char_space(char c);
int		char_floor(char c);
int		check_nbr(char *str);
int		verif_map(char **tab);
t_info	info_init(void);
t_info	get_values(char **tab);
t_dir get_pos(char **map);




#endif
