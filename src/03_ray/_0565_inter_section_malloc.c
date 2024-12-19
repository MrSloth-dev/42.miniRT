#include "ft_printf/libft/libft.h"
#include "minirt.h"

t_inter	*ft_create_inter(double value, t_shapes *shape)
{
	t_inter	*temp;

	temp = malloc(sizeof(t_inter));
	if (!temp)
		return (NULL);
	temp->shape = shape;
	temp->value= value;
	return (temp);
}

void	ft_lstadd_sort_inter(t_interlst **lst, double value, t_shapes *shape)
{
	t_interlst	*temp;
	t_interlst	*new;
	t_inter		*node;

	node = ft_create_inter(value, shape);
	new = ft_lstnew(node);
	if (!lst)
		lst = &new;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		if (((t_inter *)temp->cont)->value > value)
		{
			new->next = temp;
			*lst = new;
		}
		else
		{
			while (temp->next && (((t_inter *)temp->next->cont)->value < value))
				temp = temp->next;
			new->next = temp->next;
			temp->next = new;
		}
	}
}

void	ft_inter_to_list(t_interlst **lst, t_inter *inter)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = ft_lstnew(inter);
	else
		ft_lstadd_back(lst, ft_lstnew(inter));
}
