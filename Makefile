NAME	=	liblist.a
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	lnk_list.c lnk_list_extra.c helpers.c structs.c
OBJS	=	${SRCS:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o:		%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

mclean: all clean

re: fclean all

.PHONY: all clean fclean mclean re
