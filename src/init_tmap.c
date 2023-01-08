

#include "../includes/fdf.h"

void	init_tmap(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W, WIN_H, "Fdf");
	map->height = 0;
	map->width = 0;
	map->d_x = 0;
	map->d_y = 0;
	map->y_offset = 0;
	map->x_offset = 0;
	map->zoom = 16;
	map->rot_x_rad = 0.8;
	map->rot_y_rad = 0;
	map->rot_z_rad = 0.8;
	map->scan = -1;
	map->img = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, \
								&map->line_len, &map->endian);
	if (!map->mlx || !map->win || !map->img)
		exit_with_err("init_tmap() mlx initialization error");
}

void	init_img_addr(t_map *map)
{
	map->img = mlx_new_image(map->mlx, WIN_W, WIN_H);
	if (!map->img)
		exit_with_err("init_img_addr() mlx initialization error");
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, \
								&map->line_len, &map->endian);
}

void	reset_map_pos(t_map *map)
{
	map->y_offset = 0;
	map->x_offset = 0;
	map->rot_x_rad = 0.8;
	map->rot_y_rad = 0;
	map->rot_z_rad = 0.8;
	map->scan = -1;
	map->img = mlx_new_image(map->mlx, WIN_W, WIN_H);
	if (!map->img)
		exit_with_err("reset_map_pos() mlx initialization error");
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, \
								&map->line_len, &map->endian);
}

void	parallel_prj(t_map *tmap)
{
	tmap->rot_x_rad = 0;
	tmap->rot_y_rad = 0;
	tmap->rot_z_rad = 0;
	mlx_destroy_image(tmap->mlx, tmap->img);
	init_img_addr(tmap);
	draw_map(tmap);
}

void	isometric_prj(t_map *tmap)
{
	mlx_destroy_image(tmap->mlx, tmap->img);
	reset_map_pos(tmap);
	draw_map(tmap);
}
