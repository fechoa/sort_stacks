/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 22:50:48 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_sort_5_check_end(t_stack *stack, int min, int max)
{
	if (stack->nums[stack->size - 1] == min
		|| stack->nums[stack->size - 1] == max)
		return (true);
	return (false);
}

void	ft_sort_5_first_action(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sort_5_check_end(stack_a, stack_a->extremes.min,
			stack_a->extremes.max) == true)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (ft_sort_5_check_end(stack_a, stack_a->extremes.min,
			stack_a->extremes.max) == true)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while (stack_b->size < 2)
	{
		if (stack_a->nums[0] == stack_a->extremes.min
			|| stack_a->nums[0] == stack_a->extremes.max)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	ft_get_extremes(stack_a);
	ft_sort_5_first_action(stack_a, stack_b);
	ft_sort_3(stack_a);
	while (stack_b->size > 0)
	{
		ft_pa(stack_b, stack_a);
		if (stack_a->nums[0] > stack_a->nums[1])
			ft_ra(stack_a);
	}
}
