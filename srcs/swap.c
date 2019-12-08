/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:44:36 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/08 06:21:25 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			swap(t_lst **head)
{
	int		tmp;

	if (*head)
	{
		if ((*head)->size > 1)
		{
			tmp = (*head)->value;
			(*head)->value = (*head)->next->value;
			(*head)->next->value = tmp;
			return (1);
		}
	}
	return (0);
}
