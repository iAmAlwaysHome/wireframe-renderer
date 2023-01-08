

#include "../includes/fdf.h"

static void	set_rot_z(t_map *tmap, double x, double y)
{
	tmap->x_rotated = x * cos(tmap->rot_z_rad) - y * sin(tmap->rot_z_rad);
	tmap->y_rotated = x * sin(tmap->rot_z_rad) + y * cos(tmap->rot_z_rad);
}

static void	set_rot_x(t_map *tmap, double y, int z)
{
	tmap->y_rotated = y * cos(tmap->rot_x_rad) - z * sin(tmap->rot_x_rad);
	tmap->z_rotated = -y * sin(tmap->rot_x_rad) + z * cos(tmap->rot_x_rad);
}

static void	set_rot_y(t_map *tmap, double x, double z)
{
	tmap->x_rotated = x * cos(tmap->rot_y_rad) + z * sin(tmap->rot_y_rad);
	tmap->z_rotated = -x * sin(tmap->rot_y_rad) + z * cos(tmap->rot_y_rad);
}

static void	position_next_point(t_map *tmap, int x, int y)
{
	if (tmap->width <= x || tmap->height <= y)
		return ;
	tmap->x_center = x - (tmap->width / 2);
	tmap->y_center = y - (tmap->height / 2);
	set_rot_z(tmap, tmap->x_center, tmap->y_center);
	set_rot_x(tmap, tmap->y_rotated, tmap->z[y][x]);
	set_rot_y(tmap, tmap->x_rotated, tmap->z_rotated);
	tmap->x1 = tmap->x_rotated;
	tmap->y1 = tmap->y_rotated;
	tmap->x1 = tmap->x1 * tmap->zoom + (WIN_W / 2) + tmap->x_offset;
	tmap->y1 = tmap->y1 * tmap->zoom + (WIN_H / 2) + tmap->y_offset;
}

//sets tmap center and rotated x,y,z (intermediate values)
//rotated x,y,z are then positioned at center, changed by offset
//which results in x,y,x1,y1 later to be used by bresenham to draw lines
void	position_line_points(t_map *tmap, int x, int y, char axis)
{
	tmap->x_center = x - (tmap->width / 2);
	tmap->y_center = y - (tmap->height / 2);
	set_rot_z(tmap, tmap->x_center, tmap->y_center);
	set_rot_x(tmap, tmap->y_rotated, tmap->z[y][x]);
	set_rot_y(tmap, tmap->x_rotated, tmap->z_rotated);
	tmap->x = tmap->x_rotated;
	tmap->y = tmap->y_rotated;
	tmap->x = tmap->x * tmap->zoom + (WIN_W / 2) + tmap->x_offset;
	tmap->y = tmap->y * tmap->zoom + (WIN_H / 2) + tmap->y_offset;
	if (axis == 'x')
		position_next_point(tmap, x + 1, y);
	if (axis == 'y')
		position_next_point(tmap, x, y + 1);
}
