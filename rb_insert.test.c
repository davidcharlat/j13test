#include <stdlib.h>
#include <stdio.h>
#include "j13/ex08/ft_btree_rb.h"

void	rb_insert(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *));

typedef	struct	s_list
{
	struct	s_list	*next;
	void			*data;
	int				level;
}					t_list;

#define CUR_NODE_ADD ((t_rb_node*)(cursor->data))

void	btree_apply_infix_test_dcharlat (t_rb_node *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_infix_test_dcharlat (root->left, applyf);
		applyf (root);
		if (root->right)
			btree_apply_infix_test_dcharlat (root->right, applyf);
	}
}

t_list	*ft_create_elem_test_dcharlat (void *datum, int current_level)
{
	t_list	*ptr;
	
	ptr = (t_list*)malloc(sizeof(t_list));
	if (ptr)
	{
		ptr->data = datum;
		ptr->next = NULL;
		ptr->level = current_level;
	}
	return (ptr);	
}

void	ft_list_add_node_test_dcharlat(t_list **begin_list, void *ptr, int current_level)
{
	t_list *temp;
	t_list *addr_next;
	
	temp = ft_create_elem_test_dcharlat (ptr, current_level);
	if (*begin_list)
	{
		addr_next = *begin_list;
		while (addr_next->next)
			addr_next = addr_next->next;
		if (temp)
			addr_next->next = temp;
	}
	else
	{
		if (temp)
			*begin_list = temp;
	}
}

int	cmp_1st_char (void* c1, void* c2)
{
	return (*(char*)c1 - *(char*)c2);
}

int		verify_tree_test_dcharlat (t_rb_node *root)
{
	int		nb = 0;
	t_list	*cursor;
	int		nbnode = 0;
	
	void	count_black (void *nod)
	{
		int count;
		t_rb_node *temp;
		t_rb_node	*node;
	
		node = (t_rb_node*)nod;

		if (!node->left || !node->right)
		{

			count = 0;
			temp = node;
			while (temp->parent)
			{
				count = count + 1 - temp->color;
				temp = temp->parent;
			}
			if (nb == count || nb == 0)
				nb = count;
			else
				nb = -1;
		}
	}
	
	void	count_node_test_dcharlat (void *nod)
	{
		int count;
		t_rb_node *temp;
		t_rb_node	*node;
	
		node = (t_rb_node*)nod;

		if (!node->left || !node->right)
		{

			count = 0;
			temp = node;
			while (temp->parent)
			{
				count = count + 1;
				temp = temp->parent;
			}
			if (nbnode < count)
				nbnode = count;
		}
	}
	t_list	*list_of_node;
	list_of_node = NULL;

	void	verify_order_test_dcharlat (void *nod)
	{
		t_rb_node	*node;
		
		node = (t_rb_node*)nod;
		ft_list_add_node_test_dcharlat (&list_of_node, (void*)(node->data), 3);
	}

	btree_apply_infix_test_dcharlat (root, &verify_order_test_dcharlat);
	cursor = list_of_node;
	while (cursor->next)
	{
	printf ("cmp %s and %s\n", (char*)(cursor->data), (char*)(cursor->next->data));
		if (cmp_1st_char((char*)(cursor->data), (char*)(cursor->next->data)) > 0)
		{
			printf("error\n");
			return -1;
		}
		cursor = cursor->next;
	}
	printf ("OK\n");
	
	btree_apply_infix_test_dcharlat (root, &count_black);
	printf ("\nnumber of black for each leave: %d\n", nb + 1);
	btree_apply_infix_test_dcharlat (root, &count_node_test_dcharlat);
	printf ("max number of node for each leave: %d\n", nbnode + 1);
	if ((nb + 1) < ((nbnode + 1) / 2))
	{
		printf ("Error: rules of rb trees arent't respected\n");
		return (-1);
	}
	printf ("OK\n");
	return nb;
}

void	btree_apply_by_level_test_dcharlat(t_rb_node *root, void (*applyf)(void *item,
							int current_level, int is_first_elem))
{
	t_list	*nodes;
	t_list	*cursor;
	int		prec_level;
	
	prec_level = 0;
	nodes = NULL;
	if (root->left)
		ft_list_add_node_test_dcharlat (&nodes, root->left, 1);
	if (root->right)
		ft_list_add_node_test_dcharlat (&nodes, root->right, 1);
	applyf (root, 0, 1);
	cursor = nodes;	
	while (cursor)
	{
		if (CUR_NODE_ADD->left)
			ft_list_add_node_test_dcharlat (&nodes, CUR_NODE_ADD->left, cursor->level + 1);
		if (CUR_NODE_ADD->right)
			ft_list_add_node_test_dcharlat (&nodes, CUR_NODE_ADD->right, cursor->level + 1);
		applyf (CUR_NODE_ADD, cursor->level, cursor->level - prec_level);
		if (cursor->next)
			prec_level = cursor->level;
		cursor = cursor->next;
	}
	while (nodes)
	{
		cursor = nodes;
		nodes = nodes->next;
		free (cursor);
	}	
}

void	to_applyf(void *item, int current_level, int is_first_elem)
{
	t_rb_node *node;
	
	node = (t_rb_node*)item;	
	
	if (is_first_elem)
		printf ("new level\n");
	printf ("level: %d, value %s color:%d ", current_level, (char*)(node->data), node->color);
	if (node->parent && node->parent->left == node) printf ("parent (left born): %s\n",(char*)(node->parent->data));
	else if (node->parent && node->parent->right == node) printf ("parent (right born): %s\n",(char*)(node->parent->data));
	else if (node->parent) printf ("parent: (error born): %s\n",(char*)(node->parent->data));
	else printf ("parent : NULL\n");
}

int	main ()
{
	char	c[19][9] = {"are", "chief", "hello", "bred", "hello", "elephant", "guy", "yellow", "zaz", "19", "19", "wc", "tree", "star", "BIG", "+", "very bad", "David", "Charlat"};
	t_rb_node	*root;
	int		i;

	i = 0;
	root = NULL;
	while (i < 19) 
	{
printf ("inserting %s\n", c[i]);
	rb_insert(&root, &c[i], &cmp_1st_char);
	i++;
	}
	btree_apply_by_level_test_dcharlat(root, &to_applyf);
	i = verify_tree_test_dcharlat (root);
	if (i>=0)
	{
		printf ("each leave has got the same number of black node, rules of rb trees seems respected, and the tree is ordered\nrb_insert OK\n");
		return (0);
	}
	return (1);
}
