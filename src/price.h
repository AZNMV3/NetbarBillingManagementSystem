/* admin.h */
#ifndef PRICE_H
#define PRICE_H

/* Head Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEFAULT_PRICE 2.5
#define RATE_FILE_POSITION	"./data/rate.txt"
#define MONTH_STAT_FILE_POSITION	"./data/month_stat.txt"

extern void price_add_core(int time_left_interval, int time_right_interval, float price);
extern float price_read(int time_sec);
extern void price_del_core(int time_left_interval);

extern void statistics_print_out_an_user(char id[]);
extern float statistics_between(int time_left_year, int time_left_month, int time_left_day, int time_right_year, int time_right_month, int time_right_day, int * count);
extern void statistics_print_out_an_month(void);
#endif