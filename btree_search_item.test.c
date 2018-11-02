#include <stdlib.h>
#include <stdio.h>
#include "j13/ex02/ft_btree.h"

t_btree	*btree_create_node (void *item);
void	*btree_search_item(t_btree *root,
						 void *data_ref, int (*cmpf)(void *, void *));

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

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_infix (root->left, applyf);
		applyf (root->item);
		if (root->right)
			btree_apply_infix (root->right, applyf);
	}
}

void applyprint (void* item)
{
	printf ("%s", (char*)item);
}

int		main (void)
{
	char	c[8][9] = {"hello", "guy", "hi", "how", "are", "you", "handsome", "yellow"};
	char	ref[3] = "hh";
	char	ref2[6] = "yazer";
	char	ref3[2] = "z";
	t_btree	*root;
	int	i;

	i = 0;
	root = NULL;
	while (i < 8)
	{
	btree_insert_data(&root, &c[i], cmp_1st_char);
	i++;
	}
	/*  arbre left<  right >=
		   hello
	   guy		hi
	 are		  how
	 				you
	 		handsome  yellow
	*/
	applyprint (btree_search_item (root, ref, cmp_1st_char));
	printf(" ");
	applyprint (btree_search_item (root, ref2, cmp_1st_char));
	printf(" ");
	printf("%d",(int)(btree_search_item (root, ref3, cmp_1st_char)));
	return (0);
}
