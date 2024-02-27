NAME	=	liblist.a
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	linked_list_addition.c linked_list_helper.c linked_list_removal.c linked_list_misc.c \
			structs.c utils.c linked_list_addition2.c linked_list_misc2.c linked_list_removal2.c \
			get_data_extra.c get_data.c

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
	rm -f $(NAME) debug

mclean: all clean

re: fclean all

.PHONY: all clean fclean mclean re
