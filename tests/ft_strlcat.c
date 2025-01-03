/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:26:30 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 10:58:37 by dagredan         ###   ########.fr       */
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

static void	ft_test_segfault(void)
{
	char	dst[10];
	strlcpy(dst, "hi", 10);

	//printf("dst precat:  %s\n", dst);

	//strlcat(dst, " world", 10); // WORKS
	//ft_strlcat(dst, " world", 10); // WORKS

	//strlcat(NULL, "HELLO", 10); // segfault
	//ft_strlcat(NULL, "HELLO", 10); // segfault

	//strlcat(NULL, "HELLO", 0); // WORKS
	//ft_strlcat(NULL, "HELLO", 0); // WORKS

	//strlcat(dst, NULL, 10); // segfault
	//ft_strlcat(dst, NULL, 10); // segfault

	//strlcat(dst, NULL, 0); // segfault
	//ft_strlcat(dst, NULL, 0); // segfault

	//strlcat(NULL, NULL, 10); // segfault
	//ft_strlcat(NULL, NULL, 10); // segfault

	//strlcat(NULL, NULL, 0); // segfault
	//ft_strlcat(NULL, NULL, 0); // segfault

	//printf("dst postcat: %s\n", dst);
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

	ft_test_segfault();

	ft_log_result_test("ft_strlcat", pass);
}
