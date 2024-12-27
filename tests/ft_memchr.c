/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:03:02 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 21:01:57 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, char *s, int c, size_t n)
{
	bool	pass = 1;

	void *ret_std = memchr((void *) s, c, n);
	void *ret_mine = ft_memchr((void *) s, c, n);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_str((char *) ret_std, (char *) ret_mine, desc, pass);

	return (pass);
}

void	ft_memchr_test(void)
{
	int		pass = 1;
	char	*s = "The memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.";
	unsigned char	s2[5];
	s2[0] = 0200;
	s2[1] = 0201;
	s2[2] = 0202;
	s2[3] = 0101;
	s2[4] = 0;
	
	if (!ft_assert_return("Looking for 'c' in the initial 100 bytes", s, 'c', 100) ||
		!ft_assert_return("Looking for 'c' in the initial 4 bytes", s, 'c', 4) ||
		!ft_assert_return("Looking for 'e' in the initial 3 bytes", s, 'e', 3) ||
		!ft_assert_return("Looking for '*' in the initial 512 bytes", s, '*', 512) ||
		!ft_assert_return("Looking for 0201 in the initial 3 bytes", (char *) s2, 0201, 3))
		pass = 0;

	ft_log_result_test("ft_memchr", pass);
}
