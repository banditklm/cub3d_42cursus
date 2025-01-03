#include "cub.h"

t_coll	*ft_collnew(void *value)
{
	t_coll	*node;

	node = malloc(sizeof(t_coll));
	if (!node)
		return (NULL);
	node->ptr = value;
	node->next = NULL;
	return (node);
}

void	ft_colladd_back(t_coll **lst, t_coll *new)
{
	t_coll	*current;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	ft_collclear(t_coll **lst)
{
	t_coll	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (*lst)
		{
			free((*lst)->ptr);
			free(*lst);
		}
		*lst = tmp;
	}
	lst = NULL;
}

void	*c_malloc(size_t size, int flag)
{
	static t_coll	*head;
	t_coll			*tmp;
	void			*ptr;

	if (flag == 1)
	{
		ptr = malloc(size);
		if (!ptr)
			return (ft_collclear(&head), NULL);
		tmp = ft_collnew(ptr);
		if (!tmp)
			return (ft_collclear(&head), free(ptr), NULL);
		ft_colladd_back(&head, tmp);
		return (ptr);
	}
	else if (flag == 0)
		ft_collclear(&head);
	return (NULL);
}