/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:18:41 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 10:26:44 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert(char *desc, int n, char *expect)
{
	bool	pass = 1;

	char *ret_mine = ft_itoa(n);

	if (strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, desc, pass);

	free(ret_mine);
	return (pass);
}

void	ft_itoa_test(void)
{
	int		pass = 1;
	
	if (!ft_assert("8", 8, "8") ||
		!ft_assert("59", 59, "59") ||
		!ft_assert("897", 897, "897") ||
		!ft_assert("8970", 8970, "8970") ||
		!ft_assert("89700", 89700, "89700") ||
		!ft_assert("897000", 897000, "897000") ||
		!ft_assert("8970000", 8970000, "8970000") ||
		!ft_assert("89700000", 89700000, "89700000") ||
		!ft_assert("897000000", 897000000, "897000000") ||
		!ft_assert("2147483647", 2147483647, "2147483647") ||
		!ft_assert("-59", -59, "-59") ||
		!ft_assert("-2147483648", -2147483648, "-2147483648") ||
		!ft_assert("+214", +214, "214") ||
		!ft_assert("0", 0, "0"))
		pass = 0;

	ft_log_result_test("ft_itoa", pass);
}
