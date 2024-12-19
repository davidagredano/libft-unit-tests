/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 15:56:08 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *s, int c, size_t n, char *expected)
{
	int	pass;

	pass = 1;
	s = malloc(n);
	if (!s)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}
	ft_memset(s, c, n);
	if (strcmp((char *) s, expected) != 0)
	{
		pass = 0;
		printf("Error: ");
		printf("Expected '%s'", expected);
		printf("instead of '%s'\n", (unsigned char *) s);
	}
	free(s);
	return (pass);
}

void    ft_memset_test(void)
{
	int	pass;
	void	*s;

	pass = 1;
	s = NULL;

	pass = ft_assert(s, 'A', 5, "AAAAA");
	if (pass)
		pass = ft_assert(s, 'c', 2, "cc");
	if (pass)
		pass = ft_assert(s, '5', 9, "555555555");
	if (pass)
		pass = ft_assert(s, ' ', 7, "       ");
	if (pass)
		pass = ft_assert(s, '\0', 3, "\0\0\0");

	ft_print_test_result("ft_memset", pass);
}
