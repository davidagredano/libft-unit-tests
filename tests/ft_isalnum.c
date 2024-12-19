/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:29 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 11:46:28 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_isalnum_test(void)
{
	int	pass;
	int	i;

	pass = 1;
	i = -10;
	while (i <= CHAR_MAX + 10)
	{
		if ((ft_isalnum(i) == 0) != (isalnum(i) == 0))
		{
			pass = 0;
			printf("isalnum(%d)=%d ", i, isalnum(i));
			printf("ft_isalnum(%d)=%d\n", i, ft_isalnum(i));
		}
		i++;
	}
	printf("ft_isalnum: ");
	if (pass)
		printf("OK\n");
	else
		printf("KO\n");
}
