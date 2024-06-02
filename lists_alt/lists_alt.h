#ifndef LIST_ALT_H
#define LIST_ALT_H

enum lst_types
{
	DEFAULT,
};

typedef struct node_s
{
	void			*data;
	struct node_s	*next;
	struct node_s	*prev;
}	node_t;


typedef struct
{
	node_t		*list;
	size_t		size;
	void		(*del_node)(void *);
	lst_types	 type;
}	list_t;

//	TODO: IMPLEMENT ALL FOLLOWING FUNCTIONS

//	creation
list_t	new_list(lst_types type, void (*del_node)(void *));
list_t	lst_append(list_t *list, void *data);
list_t	lst_prepend(list_t *list, void *data);
list_t	lst_insert_at(list_t *list, void *data, size_t index);
list_t	lst_insert_next(list_t *list, void *data, node_t *ref_node);
list_t	lst_insert_prev(list_t *list, void *data, node_t *ref_node);
list_t	lst_insert_if(list_t *list, void *data, bool (*func)(void *));

list_t	lst_append_node(list_t *list, node_t *new_node);
list_t	lst_prepend_node(list_t *list, node_t *new_node);
list_t	lst_insert_node_at(list_t *list, node_t *new_node, size_t index);
list_t	lst_insert_node_next(list_t *list, node_t *ref_node, node_t *new_node);
list_t	lst_insert_node_prev(list_t *list, node_t *ref_node, node_t *new_node);
list_t	lst_insert_node_if(list_t *list, node_t *new_node, bool (*func)(void *));


//	deletion
int		lst_remove_at(list_t *list, size_t index);
int		lst_remove_node(list_t *list, node_t *node);
int		lst_remove_if(list_t *list, bool (*func)(void *));	

void	lst_pop_at(list_t *list, size_t index);
void	lst_pop_node(list_t *list, node_t *node);

void	lst_destroy(list_t *list);

#endif
