NAME	=	downy
CFLAGS	=	-Wall -Wextra -Werror -g -O2
INCLUDE	=	-I includes
CC		=	gcc
MAIN_SRC	=	main.c
SRC_DIR	=	$(addprefix src/, utils.c check.c)
SRCS	=	$(MAIN_SRC) $(SRC_DIR)
OBJS	=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re