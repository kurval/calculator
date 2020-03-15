/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 14:58:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/15 15:04:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

static void error_check(char **line, int err)
{
    int ret;

    ret = 0;
    while(!ft_atoi_err((*line)) || (err == 2 && ft_atoi((*line)) > 24) ||
    (err == 1 && ft_atoi((*line)) > 80))
    {
        free((*line));
        if (err == 1)
            ft_printf(BOLDRED ERROR1 RESET);
        else
            ft_printf(BOLDRED ERROR2 RESET);
        ret = get_next_line(0, line);
        if (ret == 0 || ret == -1)
            exit(0);
    }
}

void        read_input(t_time *time)
{
    char	*line;
    int     ret;

    ft_printf(BOLDGREEN "How old are you (years)?\n" RESET);
    ret = get_next_line(0, &line);
    if (ret == 0 || ret == -1)
        exit(0);
    error_check(&line, 1);
    time->age = ft_atoi(line);
    time->age = 80 - time->age;
    free(line);
    ft_printf(BOLDGREEN "How much time do you spend on your phone daily (hours x.x)?\n" RESET);
    ret = get_next_line(0, &line);
    if (ret == 0 || ret == -1)
        exit(0);
    error_check(&line, 2);
    time->hours = atof(line);
    free(line);
}