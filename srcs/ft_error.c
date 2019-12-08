/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:17:49 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/08 06:36:59 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ft_error_and_free(t_lst *head, t_args *args)
{
	write(1, "Error\n", 6);
	if (head)
		clean_one_stack(head, head->size);
	if (args || (*args).arr)
	{
		if (args->arr)
			free(args->arr);
		if (args)
			free(args);
		args = NULL;
	}
	return (0);
}

int				ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
