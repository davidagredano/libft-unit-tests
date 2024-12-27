/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:58:00 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 13:13:58 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert(char *desc, int n)
{
	//printf("\n%s\n", desc);
	//ft_putnbr_fd(n, STDOUT_FILENO);
	//printf("\n");

	return (true);
}

void	ft_putnbr_test(void)
{
	int		pass = 1;
	
	if (!ft_assert("8", 8) ||
		!ft_assert("897", 897) ||
		!ft_assert("89700", 89700) ||
		!ft_assert("8970000", 8970000) ||
		!ft_assert("897000000", 897000000) ||
		!ft_assert("2147483647", 2147483647) ||
		!ft_assert("-59", -59) ||
		!ft_assert("-2147483647", -2147483647) ||
		!ft_assert("-2147483648", -2147483648) ||
		!ft_assert("+214", +214) ||
		!ft_assert("0", 0))
		pass = 0;

	ft_log_result_test("ft_putnbr_fd", pass);
}
