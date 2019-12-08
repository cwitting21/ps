/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:29:37 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:12:08 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				add_zeroes(char *str)
{
	int				i;
	int				tmp;

	i = -1;
	tmp = str[0];
	while (++i < SIZE)
		str[i] = str[i + 1];
	str[SIZE - 1] = tmp;
}
