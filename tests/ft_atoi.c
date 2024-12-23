/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:14:22 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/23 12:14:45 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, const char *nptr)
{
	bool	pass = 1;

	int ret_std = atoi(nptr);
	int ret_mine = ft_atoi(nptr);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_int(ret_std, ret_mine, desc, pass);

	return (pass);
}

void	ft_atoi_test(void)
{
	int		pass = 1;
	
	if (!ft_assert_return("'123'", "123") ||
		!ft_assert_return("'    123'", "    123") ||
		!ft_assert_return("'+123'", "+123") ||
		!ft_assert_return("'-123'", "-123") ||
		!ft_assert_return("'123abc'", "123abc") ||
		!ft_assert_return("'0'", "0") ||
		!ft_assert_return("'-0'", "-0") ||
		!ft_assert_return("'000123'", "000123") ||
		!ft_assert_return("'+000123'", "+000123") ||
		!ft_assert_return("'2147483647'", "2147483647") ||
		!ft_assert_return("'-2147483648'", "-2147483648") ||
		!ft_assert_return("'2147483648'", "2147483648") ||
		!ft_assert_return("'-2147483649'", "-2147483649") ||
		!ft_assert_return("'-'", "-") ||
		!ft_assert_return("'+'", "+") ||
		!ft_assert_return("'123 45'", "123 45") ||
		!ft_assert_return("'123abc 55'", "123abc 55") ||
		!ft_assert_return("'   +123 45'", "   +123 45") ||
		!ft_assert_return("'abc123'", "abc123") ||
		!ft_assert_return("'+abc123'", "+abc123") ||
		!ft_assert_return("'-abc123'", "-abc123") ||
		!ft_assert_return("'   - 123'", "   - 123") ||
		!ft_assert_return("'--123'", "--123") ||
		!ft_assert_return("'++123'", "++123") ||
		!ft_assert_return("'+-123'", "+-123") ||
		!ft_assert_return("'1 2 3'", "1 2 3") ||
		!ft_assert_return("'4000000000'", "4000000000") ||
		!ft_assert_return("''", ""))
		pass = 0;

	ft_log_result_test("ft_atoi", pass);
}
