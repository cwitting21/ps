/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_final.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:28:59 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/08 10:50:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		clean_read_cmd(t_lst **head_a, t_lst **head_b, t_args *args)
{
	if (*head_a && (*head_a)->size)
		clean_one_stack(*head_a, (*head_a)->size);
	if (*head_b && (*head_b)->size)
		clean_one_stack(*head_b, (*head_b)->size);
	if (args)
	{
		if (args->arr)
		{
			free(args->arr);
			args->arr = NULL;
		}
		free(args);
		args = NULL;
	}
}

void		clean_checker(t_lst *h_a, t_lst *h_b, t_args *args)
{
	if (args)
	{
		if (args->arr)
		{
			free(args->arr);
			args->arr = NULL;
		}
		free(args);
		args = NULL;
	}
	if (h_a && h_a->size)
		clean_one_stack(h_a, h_a->size);
	if (h_b && h_b->size)
		clean_one_stack(h_b, h_b->size);
}

void		clean_push_swap(t_args *args)
{
	if (args)
	{
		if (args->arr)
		{
			free(args->arr);
			args->arr = NULL;
		}
		free(args);
		args = NULL;
	}
}
