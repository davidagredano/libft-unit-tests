/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 11:12:11 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *dest_std, void *dest_mine, void *src, size_t n)
{
	int	pass;

	pass = 1;
	dest_std = malloc(n);
	dest_mine = malloc(n);
	if (!dest_std || !dest_mine)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}
	memcpy(dest_std, src, n);
	ft_memcpy(dest_mine, src, n);
	if (memcmp(dest_std, dest_mine, n) != 0)
	{
		pass = 0;
		printf("Error: ");
		printf("Expected '%s' ", (char *) dest_std);
		printf("instead of '%s'\n", (char *) dest_mine);
	}
	free(dest_std);
	free(dest_mine);
	return (pass);
}

void    ft_memcpy_test(void)
{
	int	pass;
	void	*dest_std;
	void	*dest_mine;

	pass = 1;
	dest_std = NULL;
	dest_mine = NULL;

	if (!ft_assert(dest_std, dest_mine, (void *) "hello", 5))
		pass = 0;
	if (!ft_assert(dest_std, dest_mine, (void *) "hello world", 11))
		pass = 0;
	if (!ft_assert(dest_std, dest_mine, (void *) "hello world", 2))
		pass = 0;
	if (!ft_assert(dest_std, dest_mine, (void *) "hello world", 20))
		pass = 0;

	ft_log_result_test("ft_memcpy", pass);
}
