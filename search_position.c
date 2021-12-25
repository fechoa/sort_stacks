/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 18:36:08 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position_up(t_stack *stack, int min, int max, int i)
{
	while (!(stack->nums[i] >= min && stack->nums[i] <= max))
		i++;
	return (i);
}

int	ft_position_up_two(t_stack *stack, int num1, int num2, int i)
{
	while (stack->nums[i] != num1 && stack->nums[i] != num2)
		i++;
	return (i);
}

int	ft_position_down(t_stack *stack, int min, int max, int i)
{
	int	pos;

	pos = stack->size - 1;
	while (!(stack->nums[pos - i] >= min && stack->nums[pos - i] <= max))
		i++;
	return (i);
}

int	ft_position_down_two(t_stack *stack, int val1, int val2, int i)
{
	int	pos;

	pos = stack->size - 1;
	while (stack->nums[pos - i] != val1 && stack->nums[pos - i] != val2)
		i++;
	return (i);
}
