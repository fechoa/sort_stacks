/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:11:15 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/02 18:43:56 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_to_a_add(t_stack *b, int up, int down)
{
	int	check;

	check = 666;
	if (up <= down)
	{
		if (b->nums[up] == b->extremes.min)
			check--;
		while (up-- > 0)
			ft_rb(b);
		return (check);
	}
	if (b->nums[b->size - 1 - down] == b->extremes.min)
		check--;
	while (down-- >= 0)
		ft_rrb(b);
	return (check);
}

void	ft_push_to_a(t_stack *a, t_stack *b)
{
	int	up;
	int	down;
	int	check;

	while (b->size > 0)
	{
		ft_get_extremes(b);
		up = ft_position_up_two(b, b->extremes.min, b->extremes.max, 0);
		down = ft_position_down_two(b, b->extremes.min, b->extremes.max, 0);
		check = ft_push_to_a_add(b, up, down);
		ft_pa(b, a);
		if (check != 666)
			ft_ra(a);
	}
}

void	ft_sorting_proc(t_stack *a, t_sort *values, int i, int j)
{
	if (i > 0)
	{
		while (a->nums[j] != values[i - 1].max)
			j++;
		if (j <= a->size / 2)
			while (j-- >= 0)
				ft_ra(a);
		else
			while (j++ < a->size - 1)
				ft_rra(a);
	}
}

void	ft_median_push(t_stack *a, t_stack *b, t_sort values)
{
	int	up;
	int	down;

	while (b->size < values.size)
	{
		up = ft_position_up(a, values.min, values.max, 0);
		down = ft_position_down(a, values.min, values.max, 0);
		if (up <= down)
			while (up-- > 0)
				ft_ra(a);
		else
			while (down-- >= 0)
				ft_rra(a);
		ft_pb(a, b);
		if (b->nums[0] > values.median)
			ft_rb(b);
	}
}

void	ft_sort_tmp_stack(t_stack *stack)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (*stack).max_size)
	{
		j = i;
		while (++j < (*stack).max_size)
			if ((*stack).nums[i] > (*stack).nums[j])
				ft_swap(&((*stack).nums[i]), &((*stack).nums[j]));
	}
}
