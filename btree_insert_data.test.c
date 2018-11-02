#include <stdlib.h>
#include <stdio.h>
#include "j13/ex02/ft_btree.h"

t_btree	*btree_create_node (void *item);
void	btree_insert_data(t_btree **root, void *item, int(*cmpf)(void*, void*));

int	cmpnb (void* nb1, void* nb2)
{
	return (*(int*)nb1 - *(int*)nb2);
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
	printf ("%d ", *(int*)item);
}

int		main (void)
{
	int		nb[8];
	int		i;
	t_btree	*root;

	root = NULL;
	i = 0;
	while (i < 8)
	{
	nb[i] = ((6 - i) * (1 + i)) / 2; //valeurs : 3, 5, 6, 6, 5, 3, 0, -4
	btree_insert_data(&root, &nb[i], cmpnb);
	i++;
	}
	/*  arbre left<  right >=
				3
			0		5
	      -4      3    6
		              5 6 
	*/
	btree_apply_infix(root, applyprint);
	return (0);
}
