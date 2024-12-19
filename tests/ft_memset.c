/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 16:36:57 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *s1, void *s2, int c, size_t n)
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
	memset(s1, c, n);
	ft_memset(s2, c, n);
	if (strncmp((char *) s1, (char *) s2, n) != 0)
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

void    ft_memset_test(void)
{
	int	pass;
	void	*s1;
	void	*s2;

	pass = 1;
	s1 = NULL;
	s2 = NULL;

	if (!ft_assert(s1, s2, 'A', 5))
		pass = 0;
	if (!ft_assert(s1, s2, 'R', 2))
		pass = 0;
	if (!ft_assert(s1, s2, '5', 9))
		pass = 0;
	if (!ft_assert(s1, s2, ' ', 7))
		pass = 0;
	if (!ft_assert(s1, s2, '\0', 3))
		pass = 0;

	ft_print_test_result("ft_memset", pass);
}
