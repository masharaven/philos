#include "philo.h"

/* The program should take the following arguments: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] */

// int init_struct(char **av, t_gen *gen)
// {
// 	int i;

// 	i = 0;
// 	write(1, "he", 2);
// 	gen->nbr = ft_atoi(av[1]);
// 	gen->time_to_die = ft_atoi(av[2]);
// 	gen->time_to_eat = ft_atoi(av[3]);
// 	gen->time_to_sleep = ft_atoi(av[4]);
// 	if (av[5])
// 		gen->nbr_philo_must_eat = ft_atoi(av[5]);
// 	if (gen->nbr < 0)
// 		return (1);
// 	write(1, "he", 2);
	
// 	return  (0);
// }

void	*init_struct(t_gen *gen, char **argv, int argc)
{
	gen->number_of_philo = ft_atoi(argv[1]);
	gen->time_to_die = ft_atoi(argv[2]);
	gen->time_to_eat = ft_atoi(argv[3]);
	gen->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		gen->nbr_philo_must_eat = ft_atoi(argv[5]);
	else
		gen->nbr_philo_must_eat = -1;
	// write(1, "he2", 3);
	// int i = 1;
	// while(i <= 5)
	// {
		// printf("%d\n", gen->number_of_philo);
		// i++;
	// }	
	return (0);
}

long starting_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}


void pthread_init(t_gen *gen)
{
	pthread_t	*thread;
	philo_t		*philo;
	int			i;

	thread = (pthread_t *)malloc(sizeof(pthread_mutex_t) * (gen->number_of_philo));
	philo = (philo_t *)malloc(sizeof(philo_t) * gen->number_of_philo);
	gen->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * gen->number_of_philo);
	// pthread_mutex_init(&gen->mx, NULL);
	gen->start_eating = starting_time();
	// printf("time %d\n", gen->start_eating);

	table(thread, philo, gen);

	while(i < gen->number_of_philo)
		pthread_mutex_destroy(&gen->mutex[i++]);
	

}

int main(int ac, char **av)
{
	t_gen *gen;
	int i, j = 0;

	i = ac;
	gen = (t_gen *)malloc(sizeof(t_gen));
	if (!gen)
		return (1);
	if (ac != 5 && ac != 6)
		return (1);
	// while (i)

	init_struct(gen, av, ac);
	pthread_init(gen);
	// write(1, "he", 2);
	return (0);

}