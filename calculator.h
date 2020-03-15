/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/15 18:50:25 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CALCULATOR_H
# define CALCULATOR_H
# define ERROR1 "Please give me a valid age (years)?\n"
# define ERROR2 "Please give me a valid argument (hours x.x)?\n"
# include "./libft/libft.h"
# include <math.h>
# define RESET		"\033[0m"
# define BLUE    	"\033[34m"
# define BOLDRED	"\033[1m\033[31m"
# define BOLDGREEN	"\033[1m\033[32m"
# define BOLDWHITE	"\033[1m\033[37m"
# define BOLDYELLOW  "\033[1m\033[33m"

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
	int    months;
	int		years;
}				t_period;

int		main(void);
void	print_result(t_time *time, int period);
void    read_input(t_time *time);
#endif