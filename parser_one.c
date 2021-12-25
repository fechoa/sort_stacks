/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:44 by a1111             #+#    #+#             */
/*   Updated: 2021/11/02 22:54:12 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_error_returns(void)
{
	write(2, "Error\n", 6);
	return (NULL);
}

bool	ft_is_double(int argc, char *argv[])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (++i < (size_t)(argc - 1))
	{
		j = i;
		while (++j < (size_t)argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (true);
		}
	}
	return (false);
}

bool	ft_is_num(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (true);
	return (false);
}

bool	ft_is_num_cycle(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_num(str[i]) == false)
			return (false);
		i++;
	}	
	return (true);
}

bool	ft_is_valid_num(int argc, char *argv[])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (++i < (size_t)argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-')
				continue ;
			if (ft_is_num(argv[i][j]) == false)
				return (false);
		}
		if (j == 0)
			return (false);
	}
	return (true);
}
