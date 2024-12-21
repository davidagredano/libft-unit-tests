/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:29 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 11:10:50 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_isdigit_test(void)
{
	int	pass;
	int	i;

	pass = 1;
	i = -10;
	while (i <= CHAR_MAX + 10)
	{
		if ((ft_isdigit(i) == 0) != (isdigit(i) == 0))
		{
			pass = 0;
			printf("isdigit(%d)=%d ", i, isdigit(i));
			printf("ft_isdigit(%d)=%d\n", i, ft_isdigit(i));
		}
		i++;
	}
	ft_log_result_test("ft_isdigit", pass);
}
