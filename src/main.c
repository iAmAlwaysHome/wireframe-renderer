
#include "../includes/fdf.h"

void	print_controls(t_map *tmap)
{
	int	y;

	y = 0;
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, \
					"CONTROLS:");
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 40, CLR_TEXT, \
					"X/Y/Z: Rotate around x/y/z");
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, \
					"Arrows: Translate");
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, \
					"+/-: Zoom");
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, \
					"I/P: Isometric/Parallel");
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, \
					"S: Scan");
}

void	print_status(t_map *tmap)
{
	int		y;
	char	buf[10];

	y = 150;
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 60, CLR_TEXT, "STATUS:");
	sprintf(buf, "%d", tmap->zoom);
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 40, CLR_TEXT, "zoom: ");
	mlx_string_put(tmap->mlx, tmap->win, 75, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", tmap->rot_x_rad);
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, "x_rot: ");
	mlx_string_put(tmap->mlx, tmap->win, 85, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", tmap->rot_y_rad);
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, "y_rot: ");
	mlx_string_put(tmap->mlx, tmap->win, 75, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", tmap->rot_z_rad);
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, "z_rot: ");
	mlx_string_put(tmap->mlx, tmap->win, 85, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", tmap->x_offset);
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, "x_offset: ");
	mlx_string_put(tmap->mlx, tmap->win, 115, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", tmap->y_offset);
	mlx_string_put(tmap->mlx, tmap->win, 10, y += 20, CLR_TEXT, "y_offset: ");
	mlx_string_put(tmap->mlx, tmap->win, 115, y += 0, CLR_TEXT, buf);
}

int	destroy_window(t_map *tmap)
{
	mlx_destroy_window(tmap->mlx, tmap->win);
	exit(0);
	return (0);
}

void	exit_with_err(char *mssg)
{
	myputendl_fd(mssg, 2);
	exit(1);
}

//mlx_hook registers events(e.g. key presses) from user and then calls arg func
//2 indicates any keypress, 17 indicates pressing the cross in the window UI
//mlx_loop keeps the window opened
int	main(int argc, char **argv)
{
	t_map	*tmap;

	if (argc != 2)
		exit_with_err("Wrong number of arguments. Input 1 argument.");
	tmap = (t_map *)malloc(sizeof(t_map));
	if (!tmap)
		exit_with_err("main() map malloc failed.");
	init_tmap(tmap);
	parse_inp_map(argv[1], tmap);
	draw_map(tmap);
	mlx_hook(tmap->win, 2, 0, handle_keypress, tmap);
	mlx_hook(tmap->win, 17, 0, destroy_window, tmap);
	mlx_loop(tmap->mlx);
	return (0);
}
