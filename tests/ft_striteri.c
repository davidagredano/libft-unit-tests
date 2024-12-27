/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:19:13 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 11:47:58 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_toupper_iteri(unsigned int i, char *c)
{
	if (islower(*c) != 0) 
		*c = *c - 32;
}

static bool	ft_assert(char *desc, char *s, char *expect)
{
	bool	pass = 1;
	char	*ret_mine;

	ret_mine = strdup(s);
	if (!ret_mine)
		return (NULL);
	ft_striteri(ret_mine, &ft_toupper_iteri);

	if (strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, desc, pass);

	free(ret_mine);
	return (pass);
}

void	ft_striteri_test(void)
{
	int		pass = 1;
	
	if (!ft_assert("'hello'", "hello", "HELLO") ||
		!ft_assert("'HELLO'", "HELLO", "HELLO") ||
		!ft_assert("'heLLo'", "heLLo", "HELLO") ||
		!ft_assert("'000'", "000", "000"))
		pass = 0;

	ft_log_result_test("ft_striteri", pass);
}
