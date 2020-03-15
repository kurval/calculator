#include "calculator.h"
#include <math.h>
#include <stdlib.h>

static void init_struct(t_time *time)
{
    time->hours = 0;
    time->age = 0;
    time->period = (t_period*)malloc(sizeof(t_period));
    time->period->hours = 0.0;
    time->period->days = 0;
    time->period->years = 0;
}

static void count_hours(t_time *time, int days)
{
    time->period->hours = time->hours * (double)days;
}

static void count_days(t_time *time)
{
    if (time->period->hours >= (double)24)
    {
        time->period->days = time->period->hours / (double)24;
        time->period->hours = fmod(time->period->hours, (double)24);
    }
}

static void count_years(t_time *time)
{
    if (time->period->hours >= 8760)
    {
        time->period->years = time->period->hours / (double)8760;
        time->period->hours = fmod(time->period->hours, (double)8760);
    }
}

static void calc_time(t_time *time, int days)
{
    
    count_hours(time, days);
    if (days > 365)
        count_years(time);
    count_days(time);
}

int main(void)
{
	char	*line;
    t_time  time;

    init_struct(&time);
    ft_printf("How old are you (years)?\n");
    get_next_line(0, &line);
    time.age = ft_atoi(line);
    time.age = 80 - time.age;
    free(line);
    ft_printf("How much time do you spend on your phone daily (hours x.x)?\n");
    get_next_line(0, &line);
    time.hours = atof(line);
    free(line);
    ft_printf("You spend:\n");
    calc_time(&time, 7);
    ft_printf("weekly: %d days %.1f hours\n", time.period->days, time.period->hours);
    calc_time(&time, 30);
    ft_printf("monthly: %d days %.1f hours\n", time.period->days, time.period->hours);
    calc_time(&time, 365);
    ft_printf("yearly: %d days %.1f hours\n", time.period->days, time.period->hours);
    calc_time(&time, (365 * time.age));
    ft_printf("rest of your life: %d years %d days %.1f hours on your phone\n", time.period->years, time.period->days, time.period->hours);
    ft_printf("*life expectancy 80\n");
    free(time.period);
    return (0);
}