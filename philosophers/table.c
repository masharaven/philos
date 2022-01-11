#include "philo.h"

int time_pass(long start)
{
	return ((int)(starting_time() - start));
}

int print(philo_t *philo, int flag)
{
	pthread_mutex_lock(&philo->data->mx);
	if (flag == 0)
	{
		printf("%d: philo %d is dead\n", time_pass(philo->data->start_eating), philo->name);
		pthread_mutex_unlock(&philo->data->mx);
		return (1);
	}
	if (philo->data->dead_flag == 1 || philo->data->nbr_philo_must_eat == philo->eaten_times)
	{
		pthread_mutex_unlock(&philo->data->mx);
		return (1);
	}
	check_flag(philo, flag);
	pthread_mutex_unlock(&philo->data->mx);
	return (0);
}

void check_flag(philo_t *philo, int flag)
{
	if (flag == 1)
		printf("%d philo: %d taken a left fork\n", time_pass(philo->data->start_eating), philo->name);
	else if (flag == 2)
		printf("%d philo: %d taken a right fork\n", time_pass(philo->data->start_eating), philo->name);
	else if (flag == 3)
		printf("%d philo: %d is eating\n", time_pass(philo->data->start_eating), philo->name);
	else if (flag == 4)
		printf("%d philo: %d is thinking\n", time_pass(philo->data->start_eating), philo->name);
	else if (flag == 5)
		printf("%d philo: %d is sleeping\n", time_pass(philo->data->start_eating), philo->name);
}



void table(pthread_t *thread, philo_t *philo, t_gen *gen)
{
	int i;

	i = 0;
	while (i < gen->number_of_philo)
	{
		pthread_mutex_init(&gen->mutex[i], NULL);
		philo[i].name = i + 1;
		philo[i].right_fork = &gen->mutex[i];
		philo[i].end_lunch = 0;
		philo[i].eaten_times = 0;
		philo[i].data = gen;
		gen->each_philo = &philo[i];
		if (i != gen->number_of_philo - 1)
			philo[i].left_fork = &gen->mutex[i + 1];
		else
			philo[i].left_fork = &gen->mutex[0];
		pthread_create(&thread[i], NULL, &ph_doing, (void *)(&philo[i]));
		i++;
	}
	usleep(100);
	pthread_create(&thread[i], NULL, &ph_dying, (void *)(philo));
}