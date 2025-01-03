/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 15:30:46 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *s1, void *s2, int c, size_t n, char *desc)
{
	int	pass = 1;
	s1 = malloc(n);
	s2 = malloc(n);
	if (!s1 || !s2)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}

	void *ret_std = memset(s1, c, n);
	void *ret_mine = ft_memset(s2, c, n);

	if (memcmp(s1, s2, n) != 0)
		pass = 0;

	//ft_log_result_str((char *) ret_std, (char *) ret_mine, desc, pass);

	free(s1);
	free(s2);
	return (pass);
}

static void	ft_test_null(void *s1, void *s2, int pass)
{
	memset(s1, 'A', 5);
	ft_memset(s2, 'A', 5);
}

void    ft_memset_test(void)
{
	int		pass = 1;
	void	*s1;
	void	*s2;

	s1 = NULL;
	s2 = NULL;

	if (!ft_assert(s1, s2, 'A', 5, "'A' 5") ||
		!ft_assert(s1, s2, 'R', 2, "'R' 2") ||
		!ft_assert(s1, s2, '5', 9, "'5' 9") ||
		!ft_assert(s1, s2, ' ', 7, "' ' 7") ||
		!ft_assert(s1, s2, '\0', 3, "'\\0' 3") ||
		!ft_assert(s1, s2, '\0', 0, "'\\0' 0"))
		pass = 0;

	//ft_test_null(s1, s2, pass); // should segfault

	ft_log_result_test("ft_memset", pass);
}
