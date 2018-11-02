#include <stdlib.h>
#include <stdio.h>
#include "j13/ex02/ft_btree.h"

t_btree	*btree_create_node (void *item);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
							int current_level, int is_first_elem));


void	to_applyf(void *item, int current_level, int is_first_elem)
{
	if (is_first_elem)
		printf ("new level\n");
	printf ("level: %d, value %s\n", current_level, (char*)item);
}

void	btree_insert_data(t_btree **root, void *item, int(*cmpf)(void*, void*))
{
	t_btree *next;
	t_btree *parent;
	
	next = *root;
	while (next)
	{
		parent = next;
		if (cmpf (item, next->item) < 0)
			next = next->left;
		else
			next = next->right;
	}
	if (!*root)
		*root = btree_create_node (item);
	else
	{
		if (cmpf (item, parent->item) < 0)
			parent->left = btree_create_node (item);
		else
			parent->right = btree_create_node (item);
	}
	
}

int	cmp_1st_char (void* c1, void* c2)
{
	return (*(char*)c1 - *(char*)c2);
}

int		main (void)
{
	char	c[13][9] = {"hello", "guy", "hi", "how", "are", "you", "handsome", "yellow", "zaz", "zz", "x", "wx", "tre"};
	t_btree	*root;
	int		i;


	i = 0;
	root = NULL;
	while (i < 13)
	{
	btree_insert_data(&root, &c[i], cmp_1st_char);
	i++;
	}
	/*  tree  left<  right >=
		   hello
	   guy		hi
	 are		  how
	 				you
	 		handsome    yellow
	 			    x	     zaz
	 			  wx	     	zz
	 			tre
	*/
	btree_apply_by_level(root, to_applyf);
	return (0);
}
