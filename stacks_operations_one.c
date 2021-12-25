/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 21:19:36 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	if (stack == NULL || stack->nums == NULL)
		return (-1);
	if (stack->size <= 1)
		return (0);
	tmp = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = tmp;
	write(1, "sa\n", 3);
	return (0);
}

int	ft_sb(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->nums == NULL)
		return (-1);
	if (stack->size <= 1)
		return (0);
	tmp = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = tmp;
	write(1, "sb\n", 3);
	return (0);
}

int	ft_ss(t_stack *a, t_stack *b)
{
	if (ft_sa(a) < 0 || ft_sa(b) < 0)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}

int	ft_pa(t_stack *from, t_stack *to)
{
	int	i;

	if (!from || !to || !from->nums || !to->nums)
		return (-1);
	if (from->size == 0)
		return (0);
	if (to->size > 0)
	{
		i = to->size - 1;
		while (i >= 0)
		{
			to->nums[i + 1] = to->nums[i];
			i--;
		}
	}
	to->nums[0] = from->nums[0];
	to->size++;
	from->size--;
	i = -1;
	while (++i < from->size)
		from->nums[i] = from->nums[i + 1];
	write(1, "pa\n", 3);
	return (0);
}

int	ft_pb(t_stack *from, t_stack *to)
{
	int	i;

	if (!from || !to || !from->nums || !to->nums)
		return (-1);
	if (from->size == 0)
		return (0);
	if (to->size > 0)
	{
		i = to->size - 1;
		while (i >= 0)
		{
			to->nums[i + 1] = to->nums[i];
			i--;
		}
	}
	to->nums[0] = from->nums[0];
	to->size++;
	from->size--;
	i = -1;
	while (++i < from->size)
		from->nums[i] = from->nums[i + 1];
	write(1, "pb\n", 3);
	return (0);
}
