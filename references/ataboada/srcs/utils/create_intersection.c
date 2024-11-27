/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:46:08 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/13 13:32:42 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Creates (with malloc) a new intersection.
t_intr	*ft_create_intersection(double t, t_shapes *s)
{
	t_intr	*i;

	i = malloc(sizeof(t_intr));
	if (!i)
		return (NULL);
	i->t = t;
	i->object = s;
	return (i);
}

// Adds the intersection to the intersections list in a sorted way. Basically, 
// it adds a t_intr to t_intrs list in a sorted way.
void	ft_add_sorted_intersection(t_intrs **lst, t_shapes *s, double t)
{
	t_intrs	*new;
	t_intrs	*tmp;
	t_intr	*i;

	i = ft_create_intersection(t, s);
	new = ft_lstnew(i);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		if (((t_intr *)tmp->content)->t > t)
		{
			new->next = tmp;
			*lst = new;
		}
		else
		{
			while (tmp->next && ((t_intr *)tmp->next->content)->t < t)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
	}
}

// Frees the intersections list.
void	ft_free_intersections(t_intrs **lst)
{
	t_intrs	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
}
