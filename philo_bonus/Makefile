NAME = philo 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
FTH = -fsanitize=thread
FS = -fsanitize=address
FUNCTIONS = main.c 
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
