/*
** EPITECH PROJECT, 2018
** pushswap
** File description:
** pushswap
*/

#ifndef _PUSH_H_
#define _PUSH_H_

typedef enum macro {
    VAL_NULL = -9999999,
    ERROR = 84,
} macro_t;

int *wap_alloc(int);
void sort_function(int *, int *, int);
void function_sa(int *, int *, int);
void function_sb(int *, int *, int);
void function_sc(int *, int *, int);
void function_pa(int *, int *, int);
void function_pb(int *, int *, int);
void function_ra(int *, int *, int);
void function_rb(int *, int *, int);
void function_rr(int *, int *, int);
void function_rra(int *, int *, int);
void function_rrb(int *, int *, int);
void function_rrr(int *, int *, int);
int limit_list(int *);

#endif
