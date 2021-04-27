#include "./include/mlx.h"
#include "./include/mlxgl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROW			11
#define COL			15
#define TILE_SIZE	32
#define WIDTH		COL * TILE_SIZE
#define HEIGHT		ROW * TILE_SIZE
// 실제 코드에서는 화면크기 -> 맵의 가로 세로 길이로 나눠서 사각형 크기 구하기 과정으로 이루어짐

#define KEY_ESC			53
#define KEY_EVENT_PRESS	2
#define KEY_EVENT_EXIT	17

#define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	int			map[ROW][COL];
	t_img		img;
}				t_game;

int		key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int		exit_button(void)
{
	exit(0);
}
// 해당 위치(x,y)에 1픽셀 크기만큼 그리기
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_game *game, int x, int y, int color)
{
	int dx;
	int dy;

	dy = 0;
	while (dy < TILE_SIZE)
	{
		dx = 0;
		while (dx < TILE_SIZE)
		{
			my_mlx_pixel_put(&game->img, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_squares(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < ROW)
	{
		x = 0;
		while (x < COL)
		{
			if (game->map[y][x] == 1)
				draw_square(game, TILE_SIZE * x, TILE_SIZE * y, 0x0000FF);
			else
				draw_square(game, TILE_SIZE * x, TILE_SIZE * y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;
	char	*dst;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		dst = &game->img.addr[TO_COORD(x1, y1)];
		*(unsigned int *)dst = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COL)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, COL * TILE_SIZE - 1, 0, COL * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROW)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROW * TILE_SIZE - 1, WIDTH, ROW * TILE_SIZE - 1);
}

int		draw_loop(t_game *game)
{
	draw_squares(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int		main(void)
{
	int map[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "2D_MAP");
	memcpy(game.map, map, sizeof(int) * ROW * COL);
	game.img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bpp, &game.img.line_length, &game.img.endian);
	mlx_hook(game.win, KEY_EVENT_PRESS, 0, key_press, &game);
	mlx_hook(game.win, KEY_EVENT_EXIT, 0, exit_button, &game);
	draw_loop(&game);
	// mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}