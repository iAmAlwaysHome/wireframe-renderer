

#include "../includes/fdf.h"

//calculate hex nbr from 2/4 digit hex abbrevation
//see bitwise operators for c
static int	bit_shimyabbrev(unsigned long nbr, int nbr_len)
{
	int	last_digit;
	int	shift;

	shift = 0;
	last_digit = nbr % 16;
	if (nbr_len == 4)
		while (shift++ < 2)
			nbr = nbr << 4 | last_digit;
	if (nbr_len == 2)
		while (shift++ < 4)
			nbr = nbr << 4 | last_digit;
	return ((int)(nbr));
}

//ex fdf values: 10; 3,0xff; 19,0xff00; 61,0x802020
//if nbr is hex abbrev bit_shift it
//if there was no clr value set it to white 0xffffff
static int	get_clr_hex(unsigned long nbr, int nbr_len)
{
	if (nbr_len == 0 && nbr == 0)
		return ((int)(0xffffff));
	if (nbr_len == 2 || nbr_len == 4)
		return (bit_shimyabbrev(nbr, nbr_len));
	if (nbr_len == 6)
		return ((int)(nbr));
	return (0);
}

static int	ishex(int c)
{
	return (myisdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'));
}

//if there is a substr ",0x" in a str calculate hex nbr
int	str_to_clr(const char *str)
{
	unsigned long	nbr;
	int				i;
	int				nbr_len;

	nbr = 0x0;
	i = 0;
	nbr_len = 0;
	while (str[i] != ',' && str[i])
		i++;
	if (mystrnstr(&str[i], ",0x", mystrlen(",0x")))
	{
		i += 3;
		while (ishex(str[i]))
		{
			if (myisdigit(str[i]))
				nbr = nbr * 16 + str[i] - '0';
			if ('a' <= str[i] && str[i] <= 'f')
				nbr = nbr * 16 + str[i] - 'a' + 10;
			if ('A' <= str[i] && str[i] <= 'F')
				nbr = nbr * 16 + str[i] - 'A' + 10;
			nbr_len++;
			i++;
		}
	}
	return (get_clr_hex(nbr, nbr_len));
}
