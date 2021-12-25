/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 21:19:15 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack == NULL || stack->nums == NULL)
		return (-1);
	if (stack->size <= 1)
		return (0);
	i = 0;
	tmp = stack->nums[i];
	while (i < stack->size - 1)
	{
		stack->nums[i] = stack->nums[i + 1];
		i++;
	}
	stack->nums[i] = tmp;
	write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack == NULL || stack->nums == NULL)
		return (-1);
	if (stack->size <= 1)
		return (0);
	i = 0;
	tmp = stack->nums[i];
	while (i < stack->size - 1)
	{
		stack->nums[i] = stack->nums[i + 1];
		i++;
	}
	stack->nums[i] = tmp;
	write(1, "rb\n", 3);
	return (0);
}

int	ft_rr(t_stack *a, t_stack *b)
{
	if (ft_ra(a) < 0 || ft_rb(b) < 0)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}

int	ft_rra(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack == NULL || stack->nums == NULL)
		return (-1);
	if (stack->size <= 1)
		return (0);
	i = stack->size - 1;
	tmp = stack->nums[i];
	while (i > 0)
	{
		stack->nums[i] = stack->nums[i - 1];
		i--;
	}
	stack->nums[i] = tmp;
	write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack == NULL || stack->nums == NULL)
		return (-1);
	if (stack->size <= 1)
		return (0);
	i = stack->size - 1;
	tmp = stack->nums[i];
	while (i > 0)
	{
		stack->nums[i] = stack->nums[i - 1];
		i--;
	}
	stack->nums[i] = tmp;
	write(1, "rrb\n", 4);
	return (0);
}
