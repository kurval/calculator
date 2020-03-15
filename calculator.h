/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/15 12:54:22 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H
# include "./libft/libft.h"

typedef struct	s_time
{
	double				hours;
    int					age;
	struct	s_period	*period;
}				t_time;

typedef struct	s_period
{
	double  hours;
    int     days;
	int		years;
}				t_period;

int	main(void);
#endif