
#include "../includes/fdf.h"

static void	free_inpmap_lines(char **line, t_map *tmap)
{
	int	i;

	i = 0;
	while (i < tmap->width)
		free (line[i++]);
	free (line);
}

//x correponds to fdf map z/clr value column, y - to row
//to achieve the visual result asked by fdf.pdf z has to be lessened 
static void	set_tmap_z_clr(char **line, t_map *tmap, int y)
{
	int	x;

	tmap->z[y] = (int *)malloc(sizeof(int) * (tmap->width));
	if (!tmap->z)
		exit_with_err("set_tmap_z_clr() z malloc failed");
	tmap->color[y] = (int *)malloc(sizeof(int) * (tmap->width));
	if (!tmap->color)
		exit_with_err("set_tmap_z_clr() clr malloc failed");
	x = 0;
	while (line[x])
	{
		tmap->z[y][x] = myatoi(line[x]);
		tmap->color[y][x] = str_to_clr(line[x]);
		x++;
	}
}

//traverse t_inp_map list set t_map z, clr arr and free line
//y correponds to fdf map z/clr value row
void	set_tmap_z_clr_with_inpmap(t_inp_map *inp_map, t_map *tmap)
{
	t_inp_map	*temp;
	t_inp_map	*temp2;
	int			y;

	tmap->z = (int **)malloc(sizeof(int *) * tmap->height);
	if (!tmap->z)
		exit_with_err("set_tmap_z_clr_with_inpmap() z malloc failed");
	tmap->color = (int **)malloc(sizeof(int *) * tmap->height);
	if (!tmap->color)
		exit_with_err("set_tmap_z_clr_with_inpmap() clr malloc failed");
	temp = inp_map;
	y = 0;
	while (temp->next)
	{
		temp2 = temp->next;
		set_tmap_z_clr(temp->inpmap_line, tmap, y);
		free_inpmap_lines(temp->inpmap_line, tmap);
		y++;
		free(temp);
		temp = temp2;
	}
	free(temp2);
}
