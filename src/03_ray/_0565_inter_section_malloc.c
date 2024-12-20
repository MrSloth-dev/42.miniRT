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
	t_inter		*node;
	node = ft_create_inter(value, shape);

	t_interlst	*new;
	new = ft_lstnew(node);
	if (!lst)
		lst = &new;

	t_interlst	*temp;
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
