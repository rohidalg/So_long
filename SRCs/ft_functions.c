/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:27 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 18:24:42 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_write(unsigned int n)
{
	write(1, "Number of movements: ", 22);
	ft_itoa(n);
	write(1, "\n", 1);
}
