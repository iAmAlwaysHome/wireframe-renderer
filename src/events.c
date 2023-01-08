
#include "../includes/fdf.h"

static void	zoom(int key, t_map *map)
{
	if (key == ZOOM_IN)
		map->zoom *= 2;
	if (map->zoom <= 1)
		return ;
	if (key == ZOOM_OUT)
		map->zoom /= 2;
	mlx_destroy_image(map->mlx, map->img);
	init_img_addr(map);
	draw_map(map);
}

//parallel_translation
static void	translate_model(int key, t_map *map)
{
	if (key == UP)
		map->y_offset -= 40;
	if (key == DOWN)
		map->y_offset += 40;
	if (key == RIGHT)
		map->x_offset += 40;
	if (key == LEFT)
		map->x_offset -= 40;
	mlx_destroy_image(map->mlx, map->img);
	init_img_addr(map);
	draw_map(map);
}

static void	rotate_model(int key, t_map *map)
{
	if (key == X_KEY)
		map->rot_x_rad += M_PI / 10;
	if (key == Y_KEY)
		map->rot_y_rad += M_PI / 10;
	if (key == Z_KEY)
		map->rot_z_rad += M_PI / 10;
	mlx_destroy_image(map->mlx, map->img);
	init_img_addr(map);
	draw_map(map);
}

static	void	scan(t_map *map)
{
	map->scan += 1;
	if ((int)map->height < map->scan + 2)
		map->scan = -1;
	mlx_destroy_image(map->mlx, map->img);
	init_img_addr(map);
	draw_map(map);
}

int	handle_keypress(int key, t_map *map)
{
	if (key == ESCAPE)
		destroy_window(map);
	else if (key == PARALLEL_PRJ)
		parallel_prj(map);
	else if (key == ISOMETRIC_PRJ)
		isometric_prj(map);
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, map);
	else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		translate_model(key, map);
	else if (key == X_KEY || key == Y_KEY || key == Z_KEY)
		rotate_model(key, map);
	else if (key == SCAN)
		scan(map);
	return (0);
}
