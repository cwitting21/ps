/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:13:06 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/08 10:28:49 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort(t_lst **head_a, t_lst **head_b, t_args *args)
{
	leave_3_nbrs_in_a(head_a, head_b, args);
	sort_3_numbers(head_a);
	sort_lists_hard(head_a, head_b, args);
}

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

static void		choose_case(t_stack *s, t_args *args)
{
	if (s->a->size > 5)
	{
		from_a_to_b(args, &s->a, &s->b);
		sort(&s->a, &s->b, args);
	}
	else if (s->a->size == 2)
		sort_2(&s->a);
	else if (s->a->size == 3)
	{
		sort_3_numbers(&s->a);
		clean_one_stack(s->a, s->a->size);
	}
	else if (s->a->size > 3 && s->a->size <= 5)
		sort_5_numbers(&s->a, &s->b, args);
}

int				main(int ac, char **av)
{
	t_stack		s;
	t_args		*args;
	t_lst		*cur;

	null_args(&s);
	args = (t_args*)malloc(sizeof(t_args));
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &s.a)))
			return (case1_local(args, &s.a));
		if (!(init_args(args, s.a->size)) || !(args_to_array(&s.a, args)))
			return (case2_local(args, &s.a));
		if (!list_is_sorted(s.a))
			choose_case(&s, args);
		clean_push_swap(args);
	}
	exit(EXIT_SUCCESS);
}
