/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:33:14 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/26 19:54:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert(char *desc, const char *s1, char *expect, char const *set)
{
	bool	pass = 1;

	char *ret_mine = ft_strtrim(s1, set);

	if (strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, desc, pass);

	free(ret_mine);
	return (pass);
}

void	ft_strtrim_test(void)
{
	int		pass = 1;
	
	if (!ft_assert("'  Hi' ' '", "  Hi", "Hi", " ") ||
		!ft_assert("'Hi---' '-'", "Hi---", "Hi", "-") ||
		!ft_assert("'**+*Hi*+*++' '+*'", "**+*Hi*+*++", "Hi", "+*") ||
		!ft_assert("'..--::+::--..' '-:.'", "..--::+::--..", "+", "-:.") ||
		!ft_assert("'..--::+::--..' '-.'", "..--::+::--..", "::+::", "-.") ||
		!ft_assert("'Hi' ''", "Hi", "Hi", "") ||
		!ft_assert("'' '-+'", "", "", "-+") ||
		!ft_assert("'0000' '0'", "0000", "", "0") ||
		!ft_assert("'Hi' 'hdsgfg'", "Hi", "Hi", "hdsgfg"))
		pass = 0;

	ft_log_result_test("ft_strtrim", pass);
}
