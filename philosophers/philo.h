#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft/libft.h"

#define PHT_SIZE 2

typedef struct philo_s{

	int name;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int end_lunch;
	int	eaten_times; //сколько он съел
	long last_lunch; //в милисекундах
	int	all_eaten;
	struct s_gen	*data;
	

}	philo_t;

typedef struct s_gen {
	int nbr;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep; 
	
	int number_of_philo;
	pthread_mutex_t *mutex;
	pthread_mutex_t mx;
	int nbr_philo_must_eat;
	int start_eating;
	struct philo_s	*each_philo;
	int	dead_flag;
	
}	t_gen;





void	init_struct(t_gen *gen, char **argv, int argc);
void	table(pthread_t *thread, philo_t *philo, t_gen *gen);
void	*ph_doing(void *pass);

void *ph_dying(void *pass);
int check_die_flag(philo_t *philo, t_gen *gen, int i);
int print(philo_t *philo, int flag);
int time_pass(long start);

void pthread_init(t_gen *gen);
long starting_time(void);


void thinking(philo_t *philo);
void sleeping(philo_t *philo);
void eating (philo_t *philo);
void waiting(int time);
void check_flag(philo_t *philo, int flag);
int	ft_atoi(const char *g);

#endif