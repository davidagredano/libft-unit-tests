/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:03:21 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/23 12:13:34 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, const char *s1, const char *s2, size_t n)
{
	bool	pass = 1;

	int ret_std = strncmp(s1, s2, n);
	int ret_mine = ft_strncmp(s1, s2, n);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_int(ret_std, ret_mine, desc, pass);

	return (pass);
}

void	ft_strncmp_test(void)
{
	int		pass = 1;
	char str[2];
	str[0] = 0201;
	str[1] = 0;
	
	if (!ft_assert_return("ABC ABC 4", "ABC", "ABC", 4) ||
		!ft_assert_return("ABC AB 4", "ABC", "AB", 4) ||
		!ft_assert_return("ABA ABZ 4", "ABA", "ABZ", 4) ||
		!ft_assert_return("ABJ ABC 4", "ABJ", "ABC", 4) ||
		!ft_assert_return("0201 \"A\" 1", (const char *) str, "A", 4) ||
		!ft_assert_return("ABC AB 3", "ABC", "AB", 3) ||
		!ft_assert_return("ABC AB 2", "ABC", "AB", 2) ||
		!ft_assert_return("ABC DEF 0", "ABC", "DEF", 0))
		pass = 0;

	ft_log_result_test("ft_strncmp", pass);
}
