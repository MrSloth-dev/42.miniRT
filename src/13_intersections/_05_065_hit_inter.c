/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_065_hit_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:18:24 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
the hit pointer, will be always the slowest positive value,
because the list is ordered.
*/
t_inter	*ft_hit_inter(t_interlst **lst)
{
	t_interlst	*head;

	head = *lst;
	while (head)
	{
		if (((t_inter *)head->cont)->value > 0)
		{
			return ((t_inter *)head->cont);
		}
		head = head->next;
	}
	return (NULL);
}
