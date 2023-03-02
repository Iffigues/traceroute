NAME=traceroute
SRC=main.c help.c util.c addr.c socket.c
OBJ=$(SRC:.c=.o)
CC=gcc -fsanitize=address
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)
%.o:%.c
	$(CC) -c $< 
clean:
	rm -f *.o
fclean:clean
	rm -f $(NAME)
re:fclean all
.PHONY:all clean fclean re
