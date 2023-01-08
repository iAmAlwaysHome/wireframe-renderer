#ifndef FDF_H
# define FDF_H

# define WIN_W 1280
# define WIN_H 720
# define CLR_TEXT 0x802020
# define ESCAPE 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6
# define SCAN 1
# define PARALLEL_PRJ 35
# define ISOMETRIC_PRJ 34

# include "../mylibc/mylibc.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

//2D arr are used for z, and clr to utilize x,y
//bpl, ll, endian are set by mlx_get_data_addr()
//x,y quadrant and d_funct, d_x, d_y deltas used by bresenham algo
typedef struct s_map
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		**z;
	int		**color;
	int		x_center;
	int		y_center;
	double	x_rotated;
	double	y_rotated;
	double	z_rotated;
	double	x;
	double	y;
	double	x1;
	double	y1;
	int		d_funct;
	double	d_x;
	double	d_y;
	int		x_quadrant;
	int		y_quadrant;
	int		y_offset;
	int		x_offset;
	double	rot_x_rad;
	double	rot_y_rad;
	double	rot_z_rad;
	int		zoom;
	int		scan;
}	t_map;

//split input fdf map into lines
typedef struct s_inp_map
{
	char				**inpmap_line;
	struct s_inp_map	*next;
}	t_inp_map;

//main.c

void	exit_with_err(char *mssg);
int		destroy_window(t_map *tmap);
void	print_controls(t_map *tmap);
void	print_status(t_map *tmap);

//init_tmap.c

void	init_tmap(t_map *tmap);
void	init_img_addr(t_map *tmap);
void	reset_map_pos(t_map *tmap);
void	isometric_prj(t_map *tmap);
void	parallel_prj(t_map *map);

//parse_inp_map.c, parse_inp_map2.c

//set_inpmap_list and t_map height, width
void	parse_inp_map(char *inp_str, t_map *map);
//traverse and free t_inp_map list after setting t_map z, color arr
void	set_tmap_z_clr_with_inpmap(t_inp_map *inp_map, t_map *tmap);

//str_to_clr.c

//if there is a substr ",0x" in a str calculate hex nbr
//otherwise set color to white 0xffffff
int		str_to_clr(const char *str);

//draw_map.c

//uses mlx_put_image_to_window()
//draw lines between every point with bresenham - mimique chess horse movement
//each point will have vertical and horizontal line
//position_line_points() will increase next point y or x coordinate by 1
//depending on whether vertical or horizontal line is being drawn
//print controls and status of the program
void	draw_map(t_map *tmap);

//position_line_points.c

//x axis = 0, y axis = 1
//sets tmap center and rotated x,y,z (intermediate values)
//rotated x,y,z are then positioned at center, changed by offset
//which results in x,y,x1,y1 later to be used by bresenham to draw lines
void	position_line_points(t_map *tmap, int x, int y, char axis);

//bresenham.c

//set point d_x, d_y, d_funct and color pixel(x,y)
void	bres_start_point(t_map *tmap, int clr);
//color pixel(x,y) and recalculate point d_funct
void	bres_next_point(t_map *tmap, double x, double y, int clr);

//events.c

int		handle_keypress(int key, t_map *tmap);

#endif
