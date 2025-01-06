/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_065_lstadd_sort_inter_malloc.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:17:48 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:18:54 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_inter	*ft_create_inter(double value, t_shapes *shape)
{
	t_inter	*temp;

	temp = malloc(sizeof(t_inter));
	if (!temp)
		return (NULL);
	temp->shape = shape;
	temp->value = value;
	return (temp);
}

static void	ft_put_intersection_on_lst(t_interlst *new,
				t_interlst **lst, double value)
{
	t_interlst	*temp;

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

// we didn't implement reflection and refraction,
// so, we dont save negative values for intersection
void	ft_lstadd_sort_inter(t_interlst **lst, double value, t_shapes *shape)
{
	t_inter		*node;
	t_interlst	*new;

	if ((value < 0)
		|| (lst && *lst
			&& value > ((t_inter *)(*lst)->cont)->value))
		return ;
	node = ft_create_inter(value, shape);
	new = ft_lstnew(node);
	if (!lst)
		lst = &new;
	if (!*lst)
		*lst = new;
	else
		ft_put_intersection_on_lst(new, lst, value);
}
