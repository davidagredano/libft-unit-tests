/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 11:09:50 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *s1, void *s2, size_t n)
{
	int	pass;

	pass = 1;
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
	{
		pass = 0;
		printf("Error: ");
		printf("Expected '%s' ", (char *) s1);
		printf("instead of '%s'\n", (char *) s2);
	}
	free(s1);
	free(s2);
	return (pass);
}

void    ft_bzero_test(void)
{
	int	pass;
	void	*s1;
	void	*s2;

	pass = 1;
	s1 = NULL;
	s2 = NULL;

	if (!ft_assert(s1, s2, 987325))
		pass = 0;
	if (!ft_assert(s1, s2, 42))
		pass = 0;

	ft_log_result_test("ft_bzero", pass);
}
