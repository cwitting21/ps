/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:42:58 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/08 10:28:41 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		case1_local(t_args *args, t_lst **h)
{
	if (*h && (*h)->size)
		clean_one_stack(*h, (*h)->size);
	if (args)
	{
		free(args);
		args = NULL;
	}
	return (ft_error());
}

static int		case2_local(t_args *args, t_lst **h)
{
	if (*h && (*h)->size)
		clean_one_stack(*h, (*h)->size);
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
	return (ft_error());
}

int				main(int ac, char **av)
{
	t_stack		s;
	t_args		*args;
	int			ret;

	null_args(&s);
	ret = 1;
	args = (t_args*)malloc(sizeof(t_args));
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &s.a)))
			return (case1_local(args, &s.a));
		if (!(init_args(args, s.a->size)) || !(args_to_array(&s.a, args)))
			return (case2_local(args, &s.a));
		ret = read_commands(&s.a, &s.b, args);
		if ((stack_is_sorted(&s.a, &s.b) || s.a->size == 1)
		&& ret != 0)
			ft_printf("OK\n");
		else if (!stack_is_sorted(&s.a, &s.b) && ret != 0)
			ft_printf("KO\n");
		clean_checker(s.a, s.b, args);
	}
	exit(EXIT_SUCCESS);
}
