/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:57:34 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 11:02:46 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_test(char *desc, char *s, int fd)
{
	//printf("\n%s\n", desc);
	//ft_putendl_fd(s, fd);

	return (true);
}

void	ft_putendl_fd_test(void)
{
	int		pass = 1;

	if (!ft_test("'hello'", "hello", STDOUT_FILENO) ||
		!ft_test("'HELLO'", "HELLO", STDOUT_FILENO) ||
		!ft_test("'heLLo'", "heLLo", STDOUT_FILENO) ||
		!ft_test("'012'", "012", STDOUT_FILENO) ||
		!ft_test("NULL", NULL, STDOUT_FILENO) ||
		!ft_test("''", "", STDOUT_FILENO))
		pass = 0;

	ft_log_result_test("ft_putendl_fd", pass);
}
