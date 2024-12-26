/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:58:38 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/26 20:06:41 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert(char *desc, const char *s1, const char *s2, char *expect)
{
	bool	pass = 1;

	char *ret_mine = ft_strjoin(s1, s2);

	if (strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, desc, pass);

	free(ret_mine);
	return (pass);
}

void	ft_strjoin_test(void)
{
	int		pass = 1;
	
	if (!ft_assert("'Hi' ' bye'", "Hi", " bye", "Hi bye") ||
		!ft_assert("'Hello' ' world!'", "Hello", " world!", "Hello world!") ||
		!ft_assert("'**+*Hi*++' '+*'", "**+*Hi*++", "+*", "**+*Hi*+++*") ||
		!ft_assert("'David' ''", "David", "", "David") ||
		!ft_assert("'' ''", "", "", "") ||
		!ft_assert("'' 'hi'", "", "hi", "hi"))
		pass = 0;

	ft_log_result_test("ft_strjoin", pass);
}
