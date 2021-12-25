/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:24:28 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/02 22:53:22 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_extremes
{
	int	max;
	int	min;
	int	median;
}	t_extremes;
typedef struct s_stack
{
	int			size;
	int			max_size;
	int			*nums;
	t_extremes	extremes;
}	t_stack;
typedef struct s_sort
{
	int	min;
	int	max;
	int	median;
	int	size;
	int	num;
}	t_sort;

int			*ft_error_returns(void);
bool		ft_is_double(int argc, char *argv[]);
bool		ft_is_num(char ch);
bool		ft_is_num_cycle(char *str);
bool		ft_is_valid_num(int argc, char *argv[]);
void		ft_fill_numbers(int argc, char *argv[], int **numbers);
bool		ft_already_sort(size_t size, int **numbers_array);
bool		ft_is_sort_list(t_stack stack);
long long	ft_atoi_new(const char *str);
int			ft_atoi(const char *str);
bool		ft_is_bigger_than_int(int argc, char *argv[]);
int			*ft_fail_args(int argc, char *argv[]);

int			ft_create_stack_a(t_stack *stack, char *argv[], int argc, int size);
int			ft_create_stack_b(t_stack *stack, int size);
bool		ft_copy_stacks(t_stack *from, t_stack *to, int i);
void		ft_free_stacks(t_stack a, t_stack b, t_stack c);

int			ft_sa(t_stack *stack);
int			ft_sb(t_stack *stack);
int			ft_ss(t_stack *a, t_stack *b);
int			ft_pa(t_stack *from, t_stack *to);
int			ft_pb(t_stack *from, t_stack *to);
int			ft_ra(t_stack *stack);
int			ft_rb(t_stack *stack);
int			ft_rr(t_stack *a, t_stack *b);
int			ft_rra(t_stack *stack);
int			ft_rrb(t_stack *stack);
int			ft_rrr(t_stack *a, t_stack *b);

void		ft_sort_3(t_stack *stack);

void		ft_sort_5(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_5_first_action(t_stack *stack_a, t_stack *stack_b);
bool		ft_sort_5_check_end(t_stack *stack, int min, int max);

void		ft_sort(t_stack *a, t_stack *b, t_stack *c, int tmp_size);
t_sort		*ft_create_values(t_stack *stack, int val_sizes);
void		ft_median_push(t_stack *a, t_stack *b, t_sort values);
void		ft_sort_tmp_stack(t_stack *stack);
t_sort		*ft_get_num_values(int stack_size, int val_sizes);
int			ft_position_up(t_stack *stack, int min, int max, int i);
int			ft_position_up_two(t_stack *stack, int num1, int num2, int i);
int			ft_position_down(t_stack *stack, int min, int max, int i);
int			ft_position_down_two(t_stack *stack, int val1, int val2, int i);
void		ft_sorting_proc(t_stack *a, t_sort *values, int i, int j);
void		ft_push_to_a(t_stack *a, t_stack *b);
int			ft_push_to_a_add(t_stack *b, int up, int down);
void		ft_get_extremes(t_stack *stack);
void		ft_swap(int *num1, int *num2);

#endif