/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:40:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:44:42 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_size(char **tab)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (tab[i])
	{
		size++;
		i++;
	}
	return (size);
}
