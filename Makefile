NAME	=	liblist.a
CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-fsanitize=leak -fsanitize=address -fsanitize=undefined -Wall -Wextra -g
SRCS	=	lnk_list.c lnk_list_extra.c helpers.c structs.c
OBJS	=	${SRCS:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

debug:		$(OBJS)
	cc $(DFLAGS) $(OBJS) main.c -o debug
	$(MAKE) clean
debug2:		$(OBJS)
	cc $(CFLAGS) -g $(OBJS) main.c -o debug
	$(MAKE) clean

%.o:		%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) debug

mclean: all clean

re: fclean all

.PHONY: all clean fclean mclean re
