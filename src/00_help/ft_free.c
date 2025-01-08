/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		split[i] = ft_free(split[i]);
		i++;
	}
	split = ft_free(split);
	return (NULL);
}

void	ft_free_objects(t_objects *list)
{
	t_objects	*temp;
	t_list		*cur;

	cur = list;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		temp->cont = ft_free(temp->cont);
		temp = ft_free(temp);
	}
	cur = ft_free(cur);
}

void	ft_free_canvas(t_canvas *canvas)
{
	ft_free_objects(canvas->objects);
	canvas->objects = NULL;
	ft_free(canvas->mlx);
	ft_free(canvas->gnl_rest);
}
