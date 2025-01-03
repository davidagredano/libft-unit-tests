/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/02 16:10:14 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *s1, void *s2, size_t n, char *desc)
{
	int	pass = 1;
	s1 = malloc(n);
	s2 = malloc(n);
	if (!s1 || !s2)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}

	bzero(s1, n);
	ft_bzero(s2, n);

	if (memcmp(s1, s2, n) != 0)
		pass = 0;

	//ft_log_result_str((char *) s1, (char *) s2, desc, pass);

	free(s1);
	free(s2);
	return (pass);
}

static void	ft_test_null(void)
{
	bzero(NULL, 5);
	ft_bzero(NULL, 5);
}

void    ft_bzero_test(void)
{
	int		pass = 1;
	void	*s1;
	void	*s2;

	s1 = NULL;
	s2 = NULL;

	if (!ft_assert(s1, s2, 987325, "987325") ||
		!ft_assert(s1, s2, 42, "42") ||
		!ft_assert(s1, s2, 0, "0"))
		pass = 0;

	//ft_test_null(); // Should segfault

	ft_log_result_test("ft_bzero", pass);
}
