#include "./minilibx_opengl_20191021/mlx.h"
#include <stdio.h>

int	pixel_draw_2(void *mlx_ptr, void *win_ptr)
{
	int x;
	int y;

	x = 151;
	y = 50;
	while (y <= 350)
	{
		while (x <= 250)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xf8f8ff);
			x++;
		}
		x = 151;
		y++;
	}
	return (0);
}

int	pixel_draw_3(void *mlx_ptr, void *win_ptr)
{
	int x;
	int y;

	x = 251;
	y = 50;
	while (y <= 350)
	{
		while (x <= 350)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
			x++;
		}
		x = 251;
		y++;
	}
	return (0);
}

int	pixel_draw_1(void *mlx_ptr, void *win_ptr)
{
	int x;
	int y;

	x = 50;
	y = 50;
	while (y <= 350)
	{
		while (x <= 150)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x80);
			x++;
		}
		x = 50;
		y++;
	}
	return (0);
}

int	deal_key(int key, void *param)
{
	printf("%d\n", key);
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "TEST");
	pixel_draw_1(mlx_ptr, win_ptr);
	pixel_draw_2(mlx_ptr, win_ptr);
	pixel_draw_3(mlx_ptr, win_ptr);
	mlx_mouse_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
