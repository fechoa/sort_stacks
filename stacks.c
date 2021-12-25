/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:26:29 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 19:36:08 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_stack_a(t_stack *stack, char *argv[], int argc, int size)
{
	int	i;

	i = 0;
	stack->nums = (int *)malloc(sizeof(int) * size);
	if (stack->nums == NULL)
		return (-1);
	ft_fill_numbers(argc, argv, &stack->nums);
	stack->size = size;
	stack->max_size = size;
	return (1);
}

int	ft_create_stack_b(t_stack *stack, int size)
{
	stack->nums = (int *)malloc(sizeof(int) * size);
	if (stack->nums == NULL)
		return (-1);
	stack->size = 0;
	stack->max_size = size;
	return (1);
}

void	ft_free_stacks(t_stack a, t_stack b, t_stack c)
{
	if (a.nums != NULL)
		free(a.nums);
	if (b.nums != NULL)
		free(b.nums);
	if (c.nums != NULL)
		free(c.nums);
}

bool	ft_copy_stacks(t_stack *from, t_stack *to, int i)
{
	if (to == NULL || from == NULL || from->nums == NULL || from->size == 0)
		return (false);
	to->nums = (int *)malloc(sizeof(int) * from->size);
	if (to->nums == NULL)
		return (false);
	while (++i < from->size)
		to->nums[i] = from->nums[i];
	to->size = from->size;
	to->max_size = from->size;
	return (true);
}
