NAME		=	liblist.a
DEBUG_NAME	=	liblist_debug.a
CFLAGS		=	-Wall -Wextra -Werror
DEBUG_FLAGS	=	-Wall -Wextra -ggdb3
INCLUDE		=	./include

#------------------------------------------------------------------------------#
# singly linked list
L1_PATH	=	./lists_1/
L1_SRCS	=	linked_list_addition.c linked_list_creation.c linked_list_misc.c \
			linked_list_nodes.c linked_list_removal.c linked_list_removal_extra.c

L1_OBJS	=	${addprefix ${L1_PATH}, ${L1_SRCS:.c=.o}}

#------------------------------------------------------------------------------#


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

OBJS		=	$(L1_OBJS) $(L2_OBJS) $(COMMON_OBJS)
DEBUG_OBJS	=	${OBJS:.o=_debug.o}

all:	$(NAME)

debug:	$(DEBUG_NAME)

mclean:	all clean

dclean:	debug debug_clean

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DEBUG_NAME):	$(DEBUG_OBJS)
	ar -rc $(DEBUG_NAME) $(DEBUG_OBJS)
	ranlib $(DEBUG_NAME)

%.o:	%.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c $< -o $@

%_debug.o:	%.c
	$(CC) -I$(INCLUDE) $(DEBUG_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

debug_clean:
	rm -f $(DEBUG_OBJS)

fclean: clean debug_clean
	rm -f $(NAME) $(DEBUG_NAME)

re: fclean all

.PHONY: all clean debug_clean fclean mclean re
