/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:46:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/13 13:31:37 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Checks if the list already contains the specified shape.
bool	ft_lst_contains(t_list *lst, t_shapes *shape)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->content == shape)
			return (true);
		temp = temp->next;
	}
	return (false);
}

// Removes the specified shape from the list.
void	ft_lst_remove(t_list **lst, t_shapes *shape)
{
	t_list	*temp;
	t_list	*prev;

	temp = *lst;
	prev = NULL;
	while (temp != NULL)
	{
		if (temp->content == shape)
		{
			if (prev == NULL)
				*lst = temp->next;
			else
				prev->next = temp->next;
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

// Returns the last element of the list.
t_list	*ft_lst_last(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// Frees the memory allocated for the list.
void	ft_free_lst(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
