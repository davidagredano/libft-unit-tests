/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:29 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 12:06:00 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_isprint_test(void)
{
	int	pass;
	int	i;

	pass = 1;
	i = -10;
	while (i <= CHAR_MAX + 10)
	{
		if ((ft_isprint(i) == 0) != (isprint(i) == 0))
		{
			printf("isprint(%d)=%d ", i, isprint(i));
			printf("ft_isprint(%d)=%d\n", i, ft_isprint(i));
			pass = 0;
		}
		i++;
	}
	printf("ft_isprint: ");
	if (pass)
		printf("OK\n");
	else
		printf("KO\n");
}
