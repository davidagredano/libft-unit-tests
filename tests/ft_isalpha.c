/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:29 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 10:55:26 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_isalpha_test(void)
{
	int	pass;
	int	i;

	pass = 1;
	i = 0;
	while (i <= CHAR_MAX)
	{
		if ((ft_isalpha(i) == 0) != (isalpha(i) == 0))
		{
			pass = 0;
			printf("isalpha(%d)=%d ", i, isalpha(i));
			printf("ft_isalpha(%d)=%d\n", i, ft_isalpha(i));
		}
		i++;
	}
	printf("ft_isalpha: ");
	if (pass)
		printf("OK\n");
	else
		printf("KO\n");
}
