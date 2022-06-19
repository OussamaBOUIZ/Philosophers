NAME = philo 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc

FUNCTIONS = main.c  init_philos check_get_args.c is_integer.c ft_atoi.c sys_err.c\



OBJECTS = $(FUNCTIONS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	echo PHILO CREATED

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)
	echo PHILO DELETED

re : fclean all
