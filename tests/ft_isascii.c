/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:29 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 11:45:57 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_isascii_test(void)
{
	int	pass;
	int	i;

	pass = 1;
	i = -10;
	while (i <= CHAR_MAX + 10)
	{
		if ((ft_isascii(i) == 0) != (isascii(i) == 0))
		{
			printf("isascii(%d)=%d ", i, isascii(i));
			printf("ft_isascii(%d)=%d\n", i, ft_isascii(i));
			pass = 0;
		}
		i++;
	}
	printf("ft_isascii: ");
	if (pass)
		printf("OK\n");
	else
		printf("KO\n");
}
