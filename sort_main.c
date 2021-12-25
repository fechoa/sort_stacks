/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:11:15 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/02 22:54:26 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b, t_stack *c, int tmp_size)
{
	t_sort	*values;
	int		i;

	values = ft_create_values(c, tmp_size);
	if (values == NULL)
		return ;
	i = 0;
	while (i < values[0].num)
	{
		ft_median_push(a, b, values[i]);
		ft_sorting_proc(a, values, i, 0);
		ft_push_to_a(a, b);
		while (a->nums[0] > values[i].min && a->nums[0] <= values[i].max)
			ft_ra(a);
		i++;
	}
	free(values);
}

t_sort	*ft_create_values(t_stack *stack, int val_sizes)
{
	t_sort	*values;
	int		i;

	values = ft_get_num_values(stack->max_size, val_sizes);
	if (values == NULL)
		return (NULL);
	i = 0;
	while (i < values[0].num)
	{
		values[i].min = stack->nums[i * val_sizes];
		values[i].max = stack->nums[i * val_sizes + values[i].size - 1];
		values[i].median = stack->nums[i * val_sizes + (values[i].size / 2)];
		i++;
	}
	return (values);
}

t_sort	*ft_get_num_values(int stack_size, int val_sizes)
{
	t_sort	*values;
	int		numbers;
	int		i;

	numbers = stack_size / val_sizes;
	if (stack_size % val_sizes > 0)
		numbers++;
	values = malloc(sizeof(t_sort) * numbers);
	if (values == NULL)
		return (NULL);
	i = 0;
	while (i < numbers)
	{
		values[i].num = numbers;
		if (i < numbers - 1 || stack_size % val_sizes == 0)
			values[i].size = val_sizes;
		else
			values[i].size = stack_size % val_sizes;
		i++;
	}
	return (values);
}

void	ft_get_extremes(t_stack *stack)
{
	t_stack	add_stack;
	int		i;
	int		j;

	if (ft_copy_stacks(stack, &add_stack, -1) == false)
		return ;
	i = -1;
	while (++i < add_stack.max_size)
	{
		j = i;
		while (++j < add_stack.max_size)
		{
			if (add_stack.nums[i] > add_stack.nums[j])
				ft_swap(&(add_stack.nums[i]), &(add_stack.nums[j]));
		}
	}
	stack->extremes.min = add_stack.nums[0];
	stack->extremes.max = add_stack.nums[add_stack.max_size - 1];
	stack->extremes.median = add_stack.nums[(add_stack.max_size) / 2];
	free(add_stack.nums);
}

void	ft_swap(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
