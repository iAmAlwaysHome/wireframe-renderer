 

#include "mylibc.h"

static	char	*read_until_nl(int fd, char *str)
{
	char	*buffer;
	int		read_output;

	buffer = malloc((100000 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_output = 1;
	while (!gnl_strchr(str, '\n') && read_output)
	{
		read_output = read(fd, buffer, 100000);
		if (read_output == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_output] = '\0';
		str = gnl_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static	char	*chars_before_nl(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static	char	*chars_after_nl(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (gnl_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || 100000 < 1)
		return (NULL);
	str = read_until_nl(fd, str);
	if (!str)
		return (NULL);
	line = chars_before_nl(str);
	str = chars_after_nl(str);
	return (line);
}
