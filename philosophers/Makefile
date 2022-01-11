
NAME = philo.a

NAME_PHILO = philo

SRC = do_it.c dying.c philo_test.c table.c

HEADER = philo.h

RM = rm -rf 

CC = gcc -g 

CFLAGS = -Wall -Werror -Wextra -I.

OBJS= $(SRC:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJS)
		make -C libft
		ar rcs $(NAME) $(OBJS)
		gcc -g -Wall -Werror -Wextra philo.a libft/libft.a philo_test.c -o $(NAME_PHILO)

clean:
		$(RM) $(OBJS)
		make fclean -C libft

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_PHILO)

re: fclean all

.PHONY: all clean re fclean