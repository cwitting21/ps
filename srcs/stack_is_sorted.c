/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:44:33 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:47:38 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			stack_is_sorted(t_lst **head_a, t_lst **head_b)
{
	t_lst	*end_a;

	end_a = (*head_a)->next;
	if (!((*head_a)->value < (*head_a)->next->value
		&& (*head_a)->value < (*head_a)->prev->value))
		return (0);
	while (end_a->next && end_a->next != (*head_a))
	{
		if (!(end_a->value > end_a->prev->value
			&& end_a->value < end_a->next->value))
			return (0);
		end_a = end_a->next;
	}
	if (!(end_a->value > end_a->prev->value
		&& end_a->value > (*head_a)->value) || (*head_b))
		return (0);
	return (1);
}
