#include "philo.h"

void waiting(int time)
{
    long i;

    i = starting_time();
    while (starting_time() - i < time)
        usleep(50);
}

void eating (philo_t *philo)
{
    if (philo->data->dead_flag)
        return ;
    if (print(philo, 3))
        return ;
    waiting((int)philo->data->time_to_eat);
    philo->eaten_times++;
}

void sleeping(philo_t *philo)
{
    if (philo->data->dead_flag)
        return ;
    if (print(philo, 5))
        return ;
    waiting((int)philo->data->time_to_sleep);
}

void thinking(philo_t *philo)
{
    if (philo->data->dead_flag)
        return ;
    if (print(philo, 4))
        return ;
}

void *ph_doing(void *pass)
{
	philo_t *philo;

	// (void)pass;
    philo = pass;
	if (philo->name % 2 == 0)
		waiting(philo->data->time_to_eat);
	while (philo->data->dead_flag != 1 && philo->eaten_times != philo->data->nbr_philo_must_eat)
	{
		pthread_mutex_lock(philo->left_fork);
		if (print(philo, 1))
			return (NULL);
		pthread_mutex_lock(philo->right_fork);
		if (print(philo, 2))
			return (NULL);
		eating(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}