NAME	=	liblist.a
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	./include

#------------------------------------------------------------------------------#
# singly linked list
L1_PATH	=	./lists_1/
L1_SRCS	=	linked_list_addition.c linked_list_creation.c linked_list_misc.c \
			linked_list_nodes.c linked_list_removal.c linked_list_removal_extra.c

L1_OBJS	=	${addprefix ${L1_PATH}, ${L1_SRCS:.c=.o}}

#------------------------------------------------------------------------------#


# doubly linked list
L2_PATH	=	./lists_2/
L2_SRCS	=	linked_list_addition2.c linked_list_creation2.c linked_list_misc2.c \
			linked_list_nodes2.c linked_list_removal2.c linked_list_removal_extra2.c

L2_OBJS	=	${addprefix ${L2_PATH}, ${L2_SRCS:.c=.o}}

#------------------------------------------------------------------------------#


#------------------------------------------------------------------------------#
# other
COMMON_SRCS	=	utils.c
COMMON_OBJS	=	${COMMON_SRCS:.c=.o}
#------------------------------------------------------------------------------#


OBJS	= $(L1_OBJS) $(L2_OBJS) $(COMMON_OBJS)



all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o:		%.c
	cc -I$(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) debug

mclean: all clean

re: fclean all

#debug:	$(NAME)
#	cc -g -L. -o debug main2.c $(NAME)
#	$(MAKE) clean

.PHONY: all clean fclean mclean re
