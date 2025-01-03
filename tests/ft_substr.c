/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:48:41 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 11:45:18 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, const char *s, char *expect, unsigned int start, size_t len)
{
	bool	pass = 1;

	char *ret_mine = ft_substr(s, start, len);

	if (ret_mine && strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, desc, pass);

	free(ret_mine);
	return (pass);
}

void	ft_substr_test(void)
{
	int		pass = 1;
	
	if (!ft_assert_return("'Hello word' 3 4", "Hello word", "lo w", 3, 4) ||
		!ft_assert_return("'Hello' 2 2", "Hello", "ll", 2, 2) ||
		!ft_assert_return("'Hello' 3 5", "Hello", "lo", 3, 5) ||
		!ft_assert_return("'Hello' 4 20", "Hello", "o", 4, 20) ||
		!ft_assert_return("'Hello' 5 10", "Hello", "", 5, 10) ||
		!ft_assert_return("'Hello' 6 10", "Hello", "", 5, 10) ||
		!ft_assert_return("'Hello' 0 10", "Hello", "Hello", 0, 10) ||
		!ft_assert_return("'Hello' 2 0", "Hello", "", 2, 0) ||
		!ft_assert_return("'Hello' 0 0", "Hello", "", 0, 0) ||
		!ft_assert_return("'Bye-bye' 4 3", "Bye-bye", "bye", 4, 3) ||
		!ft_assert_return("NULL 2 3", NULL, NULL, 2, 3) ||
		!ft_assert_return("'' 3 2", "", "", 3, 2))
		pass = 0;

	ft_log_result_test("ft_substr", pass);
}
