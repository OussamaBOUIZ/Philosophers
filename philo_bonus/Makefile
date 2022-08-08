NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
FTH = -fsanitize=thread
FS = -fsanitize=address
FUNCTIONS = main.c  check_get_args.c init_proc.c return_mess.c return_mess_2.c \
			sys_err.c check_range.c ft_atoi.c utils.c is_integer.c \
			setup_routines.c time.c proc_utils.c
OBJECTS = $(FUNCTIONS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	echo PHILO_BONUS CREATED

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)
	echo PHILO_BONUS DELETED

re : fclean all
