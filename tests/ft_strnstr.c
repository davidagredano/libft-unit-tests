/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:28:57 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/22 11:14:00 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, char *big, char *little, size_t len)
{
	bool	pass = 1;

	char *ret_std = strnstr(big, little, len);
	char *ret_mine = ft_strnstr(big, little, len);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_str(ret_std, ret_mine, desc, pass);

	return (pass);
}

void	ft_strnstr_test(void)
{
	int		pass = 1;
	char	s[] = "The strnstr() function.";
	
	if (!ft_assert_return("'strnstr' 50", s, "strnstr", 50) ||
		!ft_assert_return("'The' 200", s, "The", 200) ||
		!ft_assert_return("'he' 4", s, "he", 4) ||
		!ft_assert_return("'he' 3", s, "he", 3) ||
		!ft_assert_return("'he' 2", s, "he", 2) ||
		!ft_assert_return("'libft' 200", s, "libft", 200) ||
		!ft_assert_return("'strnstr' 0", s, "strnstr", 0) ||
		!ft_assert_return("'strnstr' in '' 100", "", "strnstr", 100) ||
		!ft_assert_return("'' 100", s, "", 100) ||
		!ft_assert_return("'' in '' 100", "", "", 100) ||
		!ft_assert_return("'' in '' 0", "", "", 0) ||
		!ft_assert_return("'' 100", s, "", 100))
		pass = 0;

	ft_log_result_test("ft_strnstr", pass);
}
