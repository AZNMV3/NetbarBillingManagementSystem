/* admin.h */
#ifndef PRICE_H
#define PRICE_H

/* Head Files */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define DEFAULT_PRICE 2.5

extern void price_add(void);
extern void price_add_core(int time_left_interval, int time_right_interval, float price);
extern float price_read(int time_sec);
extern void price_del_core(int time_left_interval);
extern void price_set(void);

#endif