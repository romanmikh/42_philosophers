#include "philo.h"

int	check_ll(int sign, t_msec *n)
{
	if (!sign && *n == LLONG_MIN)
		return (2);
	if (*n < 0 && *n != LLONG_MIN)
		return (2);
	return (0);
}

int	my_atoll(const char *str, t_msec *n)
{
	int	sign;

	sign = 0;
	*n = 0;
	if (*str == '+')
		str++;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		*n *= 10;
		*n += *str - '0';
		if (check_ll(sign, n))
			return (2);
		str++;
	}
	if (*str == '\0')
		return (0);
	return (1);
}
