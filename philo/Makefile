NAME = philo 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
FTH = -fsanitize=thread
FS = -fsanitize=address
FUNCTIONS = main.c  check_range.c check_get_args.c init_philos.c  is_integer.c ft_atoi.c sys_err.c\
			time.c set_up_routines.c utils.c 



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
