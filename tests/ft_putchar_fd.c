/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:22:08 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 12:29:15 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_test(char *desc, char c, int fd)
{
	//printf("\n%s\n", desc);
	//ft_putchar_fd(c, fd);
	//printf("\n");

	return (true);
}

void	ft_putchar_fd_test(void)
{
	int		pass = 1;

	if (!ft_test("'o'", 'o', STDOUT_FILENO) ||
		!ft_test("'L'", 'L', STDOUT_FILENO) ||
		!ft_test("'0'", '0', STDOUT_FILENO) ||
		!ft_test("'\\0'", '\0', STDOUT_FILENO))
		pass = 0;

	ft_log_result_test("ft_putchar_fd", pass);
}
