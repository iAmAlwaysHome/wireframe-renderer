

#include "../includes/fdf.h"

static t_inp_map	*new_inpmap_node(char **line)
{
	t_inp_map	*tmp;

	tmp = (t_inp_map *)malloc(sizeof(t_inp_map));
	if (!tmp)
		exit_with_err("new_inpmap_node() malloc error\n");
	tmp->inpmap_line = line;
	tmp->next = NULL;
	return (tmp);
}

//x correponds to fdf map z/clr value column
static int	set_tmap_width(char **line)
{
	int	x;

	x = 0;
	while (line[x])
		x++;
	return (x);
}

static void	set_tmap_height_width(char **line, t_map *tmap)
{
	if (tmap->height == 0)
		tmap->width = set_tmap_width(line);
	(tmap->height)++;
}

//while get_next_line() set_inpmap_list and t_map height, width
static void	read_fdf_map(int fd, t_inp_map *inp_map, t_map *tmap)
{
	t_inp_map	*tmp;
	char		*read_line;

	tmp = inp_map;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		tmp->inpmap_line = mysplit(read_line, ' ');
		free(read_line);
		set_tmap_height_width(tmp->inpmap_line, tmap);
		tmp->next = new_inpmap_node(NULL);
		tmp = tmp->next;
	}
}

void	parse_inp_map(char *inp_str, t_map *tmap)
{
	int				fd;
	t_inp_map		*inp_map;

	inp_map = (t_inp_map *)malloc(sizeof(t_inp_map));
	if (!inp_map)
		exit_with_err("parse_inp_map() malloc error\n");
	fd = open(inp_str, O_RDONLY, 0);
	if (fd < 0 || fd > 1024)
	{
		close(fd);
		exit_with_err("File descriptor error");
	}
	read_fdf_map(fd, inp_map, tmap);
	set_tmap_z_clr_with_inpmap(inp_map, tmap);
	close(fd);
}
