#include <stdlib.h>
#include <stdio.h>
#include "j13/ex02/ft_btree.h"

t_btree	*btree_create_node (void *item);
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));


void applyprint (void* item)
{
	printf ("%d ", *(int*)item);
}

int		main (void)
{
	t_btree	*node[8];
	int		nb[8];
	int		i;
	t_btree	*root;
	
	i = 0;
	while (i < 8)
	{
	nb[i] = ((6 - i) * (1 + i)) / 2; //valeurs : 3, 5, 6, 6, 5, 3, 0, -4
	node[i] = btree_create_node ((void*)&nb[i]);
	i++;
	}
	/*  arbre left<  right >=
				3
			0		5
	      -4      3    6
		              5 6 
	*/
	root = node[0];
	root->right = node[1];
	root->right->right = node[2];
	root->right->right->right = node[3];
	root->right->right->left = node[4];
	root->right->left = node[5];
	root->left = node[6];
	root->left->left = node[7];
	
	btree_apply_infix(root, applyprint);
	return (0);
}
