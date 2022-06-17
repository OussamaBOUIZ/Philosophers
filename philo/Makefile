NAME = philo 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = CC

FUNCTIONS = philo.c check_get_args.c is_integer.c ft_atoi.c sys_err.c


OBJECTS = $(FUNCTIONS: .c=.o)


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