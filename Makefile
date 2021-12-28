
NAME = philo.a

NAME_PHILO = philo

SRC = do_it.c dying.c init.c philo_test.c table.c

HEADER = philo.h

RM = rm -rf 

CC = gcc -g 

CFLAGS = -Wall -Werror -Wextra -I.

OBJS= $(SRC:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJS)
		make -C libft
		ar rcs $(NAME) $(OBJS)
		gcc -g -Wall -Werror -Wextra push_swap.c push_swap.a includes/libft/libft.a -o $(NAME_PHILO)

clean:
		$(RM) $(OBJS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_PHILO)

re: fclean all

.PHONY: all clean re fclean