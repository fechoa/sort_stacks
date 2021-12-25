/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:50:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/02 22:52:58 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_stack		c;

	c.nums = ft_fail_args(argc, argv);
	if (c.nums == NULL)
		return (1);
	c.max_size = argc - 1;
	c.size = 0;
	ft_sort_tmp_stack(&c);
	if (!ft_create_stack_a(&a, argv, argc, (argc - 1))
		|| !ft_create_stack_b(&b, (argc - 1)))
		return (1);
	if (argc - 1 <= 3)
		ft_sort_3(&a);
	else if (argc - 1 <= 5)
		ft_sort_5(&a, &b);
	else if (argc - 1 <= 100)
		ft_sort(&a, &b, &c, 40);
	else if (argc - 1 <= 300)
		ft_sort(&a, &b, &c, 60);
	else
		ft_sort(&a, &b, &c, 80);
	ft_free_stacks(a, b, c);
	return (0);
}
