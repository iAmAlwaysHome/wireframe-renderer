
#include "../includes/fdf.h"

static double	get_abs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

//calculates next point x,y and calls bres_next_point()
static void	draw_line(t_map *map, int color)
{
	double	x_delta;
	double	y_delta;

	x_delta = 0;
	y_delta = 0;
	while (0 < (int)(map->d_x - get_abs(x_delta))
		|| 0 < (int)(map->d_y - get_abs(y_delta)))
	{
		if (map->d_x < map->d_y)
		{
			if (0 <= map->d_funct)
				x_delta += map->x_quadrant;
			y_delta += map->y_quadrant;
		}
		else
		{
			if (0 <= map->d_funct)
				y_delta += map->y_quadrant;
			x_delta += map->x_quadrant;
		}
		bres_next_point(map, map->x + x_delta, map->y + y_delta, color);
	}
}

static void	draw_horiz_line(t_map *tmap, int x, int y)
{
	position_line_points(tmap, x, y, 'x');
	bres_start_point(tmap, tmap->color[y][x]);
	if (x < tmap->width - 1)
		draw_line(tmap, tmap->color[y][x]);
}

static void	draw_vert_line(t_map *tmap, int x, int y)
{
	if (tmap->scan == y)
		return ;
	position_line_points(tmap, x, y, 'y');
	bres_start_point(tmap, tmap->color[y][x]);
	if (y < tmap->height - 1)
		draw_line(tmap, tmap->color[y][x]);
}

//draw lines between every point with bresenham - mimique chess horse movement
//each point will have vertical and horizontal line
//position_line_points() will increase next point y or x coordinate by 1
//depending on whether vertical or horizontal line is being drawn
//print controls and status of the program
void	draw_map(t_map *tmap)
{
	int	x;
	int	y;

	y = 0;
	while (y < tmap->height && (tmap->scan == -1 || y <= tmap->scan))
	{
		x = 0;
		while (x < tmap->width)
		{
			draw_horiz_line(tmap, x, y);
			draw_vert_line(tmap, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tmap->mlx, tmap->win, tmap->img, 0, 0);
	print_controls(tmap);
	print_status(tmap);
}
