 
#include "mylibc.h"

int	myatoi(const char *str)
{
	int				num;
	size_t			i;
	int				sign;

	sign = 1;
	num = 0;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (myisdigit(str[i]))
	{
		if (num == 214748364 && str[i] == '8' && sign == -1)
			return (-2147483648);
		num = 10 * num + (str[i++] - '0');
	}
	return (num * sign);
}
