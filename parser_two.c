/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 22:54:49 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_numbers(int argc, char *argv[], int **numbers)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 1;
	size = (size_t) argc;
	while (size-- > 1)
		(*numbers)[i++] = ft_atoi(argv[j++]);
}

bool	ft_already_sort(size_t size, int **numbers_array)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if ((*numbers_array)[i] > (*numbers_array)[i + 1])
			return (false);
	}
	free(*numbers_array);
	*numbers_array = NULL;
	return (true);
}

bool	ft_is_sort_list(t_stack stack)
{
	size_t	i;

	i = -1;
	while (++i < (size_t)(stack.size - 1))
		if (stack.nums[i] > stack.nums[i + 1])
			return (false);
	return (true);
}

bool	ft_is_bigger_than_int(int argc, char *argv[])
{
	long long int	check_num;
	int				i;
	long long int	min;
	long long int	max;

	min = -2147483648;
	max = 2147483647;
	i = 1;
	check_num = 0;
	while (i < argc)
	{
		if (ft_atoi_new(argv[i]) > max || ft_atoi_new(argv[i]) < min)
			return (true);
		i++;
	}
	return (false);
}

int	*ft_fail_args(int argc, char *argv[])
{
	int	*numbers;

	numbers = NULL;
	if (argc < 3)
	{
		if (argc == 1)
			return (numbers);
		if (ft_is_num_cycle(argv[1]) == false)
			return (ft_error_returns());
		return (numbers);
	}	
	if (ft_is_valid_num(argc, argv) == false || ft_is_double(argc, argv) == true
		|| ft_is_bigger_than_int(argc, argv) == true)
		return (ft_error_returns());
	else
	{
		numbers = (int *)malloc(sizeof(int) * (argc - 1));
		if (numbers == NULL)
			return (numbers);
		ft_fill_numbers(argc, argv, &numbers);
		if (ft_already_sort((size_t)(argc - 2), &numbers) == true)
			return (numbers);
	}
	return (numbers);
}
