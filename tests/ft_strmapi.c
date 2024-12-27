/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:18:41 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 11:11:50 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static char	ft_toupper_map(unsigned int i, char c)
{
	return (islower(c) != 0 ? c - 32 : c);
}

static bool	ft_assert(char *desc, char const *s, char *expect)
{
	bool	pass = 1;

	char *ret_mine = ft_strmapi(s, &ft_toupper_map);

	if (strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, desc, pass);

	free(ret_mine);
	return (pass);
}

void	ft_strmapi_test(void)
{
	int		pass = 1;
	
	if (!ft_assert("'hello'", "hello", "HELLO") ||
		!ft_assert("'HELLO'", "HELLO", "HELLO") ||
		!ft_assert("'heLLo'", "heLLo", "HELLO") ||
		!ft_assert("'000'", "000", "000"))
		pass = 0;

	ft_log_result_test("ft_strmapi", pass);
}
