/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:30:31 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 19:11:40 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

bool	ft_assert_return(char *test_description, const char *s, int c)
{
	bool	pass = 1;

	char *ret_std = strchr(s, c);
	char *ret_mine = ft_strchr(s, c);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_str(ret_std, ret_mine, test_description, pass);

	return (pass);
}

void	ft_strchr_test(void)
{
	int		pass = 1;
	const char	s[] = "The strchr() function returns a pointer to the first occurrence of the character c in the string s.";
	
	if (!ft_assert_return("Looking for 'f'", s, 'f') ||
		!ft_assert_return("Looking for '.'", s, '.') ||
		!ft_assert_return("Looking for '*'", s, '*') ||
		!ft_assert_return("Looking for '\\0'", s, '\0'))
		pass = 0;

	ft_log_result_test("ft_strchr", pass);
}
