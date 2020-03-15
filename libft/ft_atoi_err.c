/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:29:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/15 16:11:37 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		starting_point(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static	int		check_sign(const char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			return (0);
		*i += 1;
	}
	if (!str[*i])
		return (0);
	return (1);
}

int				ft_atoi_err(const char *str)
{
	int		i;
	int		dot;

	dot = 0;
	i = starting_point(str);
	if (!check_sign(str, &i) || str[i] == '.')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && !dot))
		{
			if (str[i] == '.')
				dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (1);
}
