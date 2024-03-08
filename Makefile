NAME	=	liblist.a
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	.

#------------------------------------------------------------------------------#
# singly linked list
L1_PATH	=	./lists_1/
L1_SRCS	=	linked_list_addition.c linked_list_creation.c linked_list_misc.c \
			linked_list_nodes.c linked_list_removal.c linked_list_removal_extra.c \
			linked_list_helper.c

L1_OBJS	=	${addprefix ${L1_PATH}, ${L1_SRCS:.c=.o}}
#------------------------------------------------------------------------------#


# doubly linked list
L2_PATH	=	./lists_2/
L2_SRCS	=	linked_list_addition2.c linked_list_creation2.c linked_list_misc2.c \
			linked_list_nodes2.c linked_list_removal2.c
L2_OBJS	=	${addprefix ${L2_PATH}, ${L2_SRCS:.c=.o}}
#------------------------------------------------------------------------------#


#------------------------------------------------------------------------------#
# other
COMMON	=	structs.c utils.c get_data.c get_data_extra.c
COM_OBJ	=	${COMMON:.c=.o}
#------------------------------------------------------------------------------#


all:		$(NAME)

$(NAME):	$(L1_OBJS) $(L2_OBJS) $(COMMON)
	ar -rc $(NAME) $(L1_OBJS) $(L2_OBJS) $(COMMON)
	ranlib $(NAME)

%.o:		%.c
	cc -I$(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(L1_OBJS) $(L2_OBJS) $(COMMON_OBJ)

fclean: clean
	rm -f $(NAME) debug

mclean: all clean

re: fclean all

#debug:	$(OBJS)
#	cc $(CFLAGS) -g $(OBJS) main2.c -o debug
#	$(MAKE) clean

.PHONY: all clean fclean mclean re
