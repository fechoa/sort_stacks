/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 22:51:52 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stack)
{
	if (ft_is_sort_list(*stack) == true)
		return ;
	ft_get_extremes(stack);
	if (stack->nums[0] == stack->extremes.median
		&& stack->nums[1] == stack->extremes.min)
		ft_sa(stack);
	else if (stack->nums[0] == stack->extremes.median)
		ft_rra(stack);
	else if (stack->nums[0] == stack->extremes.max
		&& stack->nums[1] == stack->extremes.min)
		ft_ra(stack);
	else if (stack->nums[0] == stack->extremes.min)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}
