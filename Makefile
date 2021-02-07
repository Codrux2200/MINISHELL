SRC     =      ./lib/my/my_put_nbr.c	\
                ./lib/my/my_putstr.c	\
				./lib/my/my_strlen.c 	\
				./lib/my/my_getnbr.c   \
				./lib/my/dir.c 					\
				./lib/my/ls.c 					\
				./lib/my/my_putstr_err.c 					\
				./lib/my/path_finder.c 					\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME2	= 	./lib/my/my.h

all:	compil_lib compil_my

compil_lib:	$(OBJ)
		ar rc $(NAME) $(OBJ)

compil_my:
		cp $(NAME2) ./include
		gcc -o mysh main.c libmy.a
		

clean:
		rm -f $(OBJ)

fclean:	clean
		rm libmy.a
		rm include/my.h
		rm mysh

re: fclean all

