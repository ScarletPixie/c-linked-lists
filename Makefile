NAME	=	liblist.a
CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-fsanitize=leak -fsanitize=address -fsanitize=undefined -Wall -Wextra -g
SRCS	=	linked_list_addition.c linked_list_helper.c linked_list_removal.c linked_list_misc.c \
			structs.c utils.c linked_list_addition2.c linked_list_misc2.c linked_list_removal2.c \
			get_data_extra.c get_data.c

OBJS	=	${SRCS:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

debug2:		$(OBJS)
	cc $(CFLAGS) $(OBJS) main2.c -o debug
	$(MAKE) clean
debug:		$(OBJS)
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
