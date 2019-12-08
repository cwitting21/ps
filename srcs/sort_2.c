/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:46 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/08 06:36:33 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			sort_2(t_lst **head)
{
	if ((*head)->value > (*head)->next->value)
	{
		swap(head);
		ft_printf("sa\n");
	}
	clean_one_stack(*head, (*head)->size);
}
