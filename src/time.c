#include "philo.h"

t_msec	philo_get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

void	u_wait(t_msec waiting_time)
{
	t_msec	t;

	t = philo_get_time();
	while (waiting_time - t > 5)
	{
		usleep(1000 * (waiting_time - t - 5));
		t = philo_get_time();
	}
	while (waiting_time > t)
		t = philo_get_time();
}
