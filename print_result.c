/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 14:58:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/15 19:33:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

void    print_result(t_time *time, int period)
{
    char *days;
    char *hours;
    char *months;
    char *years;

    days = (time->period->days > 1) ? ft_strdup("days") :  ft_strdup("day ");
    hours = (time->period->hours > 1) ? ft_strdup("hours") : ft_strdup("hour ");
    months = (time->period->months > 1) ? ft_strdup("months") : ft_strdup("month ");
    years = (time->period->years > 1) ? ft_strdup("years") : ft_strdup("year ");     
    if (period == 1)
        ft_printf(BOLDWHITE "%22d %s %4.1f %-5s per week\n" RESET, time->period->days, days, time->period->hours, hours);
    else if (period == 2)
        ft_printf(BOLDWHITE "%22d %s %4.1f %-5s per month\n" RESET, time->period->days, days, time->period->hours, hours);
    else if (period == 3)
        ft_printf(BOLDWHITE "%12d %s %2d %s %4.1f %-5s per year\n" RESET, time->period->months, months, time->period->days, days, time->period->hours, hours);
    else if (period == 4)
        ft_printf(BOLDWHITE "%3d %s %2d %s %2d %s %4.1f %-5s till the end of your life\n" RESET, time->period->years, years, time->period->months, months, time->period->days, days, time->period->hours, hours);
    free(hours);
    free(days);
    free(months);
    free(years);
}