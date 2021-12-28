#include "philo.h"

void *check_die_flag(philo_t *philo, t_gen *gen, int i)
{
    if (philo->data->time_to_die + 1 <= time_pass(gen->start_eating) - philo[i].last_lunch)
    {
        philo->data->dead_flag == 1;
        print(&philo[i], 0);
        return (1);
    }
    if (philo[i].all_eaten == gen->time_to_eat)
    {
        philo->all_eaten++;
        if (philo->eaten_times == gen->nbr_philo_must_eat)
        {
            printf("%d all philos have eaten\n", time_pass(gen->start_eating));
            return (1);
        }
    }
    return (0);
}

void ph_dying(void *pass)
{
    philo_t *philo;
    t_gen   *gen;
    int i;

    philo = pass;
    gen = philo[0].data;
    while (1)
    {
        i = 0;
        philo->all_eaten = 0;
        while (i < gen->nbr)
        {
            if (check_die_flag(philo, gen, 1))
                return (NULL);
            i++;
        }
    }
}