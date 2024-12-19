/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:29 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 14:21:45 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_isalpha_test(void)
{
	int	pass;
	int	i;

	pass = 1;
	i = -10;
	while (i <= CHAR_MAX + 10)
	{
		if ((ft_isalpha(i) == 0) != (isalpha(i) == 0))
		{
			pass = 0;
			printf("isalpha(%d)=%d ", i, isalpha(i));
			printf("ft_isalpha(%d)=%d\n", i, ft_isalpha(i));
		}
		i++;
	}
	ft_print_test_result("ft_isalpha", pass);
}
