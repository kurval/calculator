#include "calculator.h"

static void init_struct(t_time *time)
{
    time->hours = 0;
    time->age = 0;
    time->period = (t_period*)malloc(sizeof(t_period));
    time->period->hours = 0.0;
    time->period->days = 0;
    time->period->months = 0;
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

static void count_months(t_time *time)
{
    if (time->period->hours >= 720)
    {
        time->period->months = time->period->hours / (double)720;
        time->period->hours = fmod(time->period->hours, (double)720);
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

static void calc_time(t_time *time, int days, int period)
{
    
    count_hours(time, days);
    if (days > 365)
        count_years(time);
    count_months(time);
    count_days(time);
    print_result(time, period);
}

int main(void)
{
    t_time  time;

    init_struct(&time);
    read_input(&time);
    ft_printf(BOLDYELLOW "You spend time on your phone:\n" RESET);
    calc_time(&time, 7, 1);
    calc_time(&time, 30, 2);
    calc_time(&time, 365, 3);
    calc_time(&time, (365 * time.age), 4);
    ft_printf(BLUE "*life expectancy 80\n" RESET);
    free(time.period);
    return (0);
}