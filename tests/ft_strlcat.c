/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:26:30 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/29 14:30:02 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_test(char *desc, char *dst, char *src, size_t size)
{
	char	dst_std[32];
	char	dst_mine[32];
	int	pass = 1;

	memset(dst_std, 0, 32);
	strlcpy(dst_std, dst, 32);
	memset(dst_mine, 0, 32);
	strlcpy(dst_mine, dst, 32);

	size_t ret_std = strlcat(dst_std, src, size);
	size_t ret_mine = ft_strlcat(dst_mine, src, size);

	if (strcmp(dst_std, dst_mine) != 0) pass = 0;
	//ft_log_result_str(dst_std, dst_mine, desc, pass);
	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_nbr(ret_std, ret_mine, desc, pass);

	return (pass);
}

void	ft_strlcat_test(void)
{
	char	*dst_std;
	char	*dst_mine;
	int	pass;

	pass = 1;
	
	if (!ft_test("'H' 'ello' 0", "H", "hello", 0) ||
		!ft_test("'hello ' 'world' 32", "hello ", "world", 32) ||
		!ft_test("'hi ' 'world' 5 (size < src + dest)", "hi ", "world", 5) ||
		!ft_test("'hello ' 'bye' 3 (size < src)", "hello ", "bye", 3) ||
		!ft_test("'hello ' 'bye' 5 (size == src)", "hello ", "bye", 5) ||
		!ft_test("'hi ' 'bye' 0", "hi ", "bye", 0))
		pass = 0;

	ft_log_result_test("ft_strlcat", pass);
}
