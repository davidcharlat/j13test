#include <stdlib.h>
#include <stdio.h>
#include "j13/ex02/ft_btree.h"

t_btree	*btree_create_node (void *item);
int		btree_level_count(t_btree *root);

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
	char	ref[3] = "hh";
	char	ref2[6] = "yazer";
	char	ref3[2] = "z";
	t_btree	*root;
	int		i;
	int		result[3];


	i = 0;
	root = NULL;
	result[0] = btree_level_count (root);
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
	result[1] = btree_level_count (root->left->left);
	result[2] = btree_level_count (root);
	printf("%d, %d, %d",result[0], result[1], result[2]);
	return (0);
}
