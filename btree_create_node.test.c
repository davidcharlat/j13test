#include <stdlib.h>
#include <stdio.h>
#include "j13/ex00/ft_btree.h"

t_btree	*btree_create_node (void *item);

int		main (void)
{
	void	*ptr;
	t_btree	*node;
	int		*item;
	
	*item = 123;
	printf ("testing btree_create_node\n");
	ptr = (void*)item;
	node = btree_create_node (ptr);
	if (node);
	{
		if (*((int*)(node->item)) != 123)
		{
			printf ("error : node->item isn't equal to the provided parameter; expected 123, received %d", *((int*)(node->item)));
			free (node);
			return (2);
		}
		if (node->left || node->right)
		{
			printf ("error : node->left or node->right isn't NULL; received %p and %p", node->left, node->right);
			free (node);
			return (3);
		}
		printf ("node->item is pointing at %d (expecting 123)\nnode->left and node->right are %p (expecting NULL)\n:OK\n", *((int*)(node->item)), node->left);
		printf ("btree_create_node.c OK\n");
		free (node);
		return (0);
	}
	printf ("error: failed to run btree_create_node (ptr)");
	return (4);
}
