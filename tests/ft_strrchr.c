/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:30:31 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 10:12:24 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *test_description, const char *s, int c)
{
	bool	pass = 1;

	char *ret_std = strrchr(s, c);
	char *ret_mine = ft_strrchr(s, c);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_str(ret_std, ret_mine, test_description, pass);

	return (pass);
}

void	ft_strrchr_test(void)
{
	int		pass = 1;
	const char	s[] = "The strchr() function returns a pointer to the first occurrence of the character c in the string s.";
	
	if (!ft_assert_return("Looking for 'f'", s, 'f') ||
		!ft_assert_return("Looking for 'r'", s, 'r') ||
		!ft_assert_return("Looking for '*'", s, '*') ||
		!ft_assert_return("Looking for 'h' + 256", s, 'h' + 256) ||
		//!ft_assert_return("Looking for 'a' in NULL", NULL, 'a') || //segfault
		!ft_assert_return("Looking for '\\0'", s, '\0'))
		pass = 0;

	ft_log_result_test("ft_strrchr", pass);
}
