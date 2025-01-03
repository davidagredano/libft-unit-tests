/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:26:30 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 10:32:36 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_dest(char *desc, char *src, size_t size)
{
	bool	pass = 1;

	char	*dst_std = malloc(100);
	char	*dst_mine = malloc(100);
	if (!dst_std || !dst_mine)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}

	strlcpy(dst_std, src, size);
	ft_strlcpy(dst_mine, src, size);

	if (strcmp(dst_std, dst_mine) != 0) pass = 0;
	//ft_log_result_str(dst_std, dst_mine, desc, pass);

	free(dst_std);
	free(dst_mine);
	return (pass);
}

static bool	ft_assert_return(char *desc, char *src, size_t size)
{
	int	pass = 1;

	char	*dst_std = malloc(100);
	char	*dst_mine = malloc(100);
	if (!dst_std || !dst_mine)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}

	size_t	ret_std = strlcpy(dst_std, src, size);
	size_t	ret_mine = ft_strlcpy(dst_mine, src, size);

	if (ret_std != ret_mine) pass = 0;
	//ft_log_result_nbr(ret_std, ret_mine, desc, pass);

	free(dst_std);
	free(dst_mine);
	return (pass);
}

static void	ft_test_segfault(void)
{
	char	dst[10];

	//strlcpy(NULL, "HELLO", 10); // segfault
	//ft_strlcpy(NULL, "HELLO", 10); // segfault

	//strlcpy(NULL, "HELLO", 0); // WORKS
	//ft_strlcpy(NULL, "HELLO", 0); // WORKS
	
	//strlcpy(dst, NULL, 10); // segfault
	//ft_strlcpy(dst, NULL, 10); // segfault
	
	//strlcpy(dst, NULL, 0); // segfault
	//ft_strlcpy(dst, NULL, 0); // segfault

	//strlcpy(NULL, NULL, 10); // segfault
	//ft_strlcpy(NULL, NULL, 10); // segfault

	//strlcpy(NULL, NULL, 0); // segfault
	//ft_strlcpy(NULL, NULL, 0); // segfault
}

void	ft_strlcpy_test(void)
{
	int	pass = 1;
	
	if (!ft_assert_dest("hello 6", "hello", 6))
		pass = 0;
	if (!ft_assert_dest("hello 2", "hello", 2))
		pass = 0;
	if (!ft_assert_dest("hello 12", "hello", 12))
		pass = 0;
	//if (!ft_assert_dest("hello 0", "hello", 0))
	//	pass = 0;
	if (!ft_assert_dest("'' 10", "", 10))
		pass = 0;
	if (!ft_assert_return("hello 6", "hello", 6))
		pass = 0;
	if (!ft_assert_return("hello 2", "hello", 2))
		pass = 0;
	if (!ft_assert_return("hello 12", "hello", 12))
		pass = 0;
	if (!ft_assert_return("hello 0", "hello", 0))
		pass = 0;
	if (!ft_assert_return("'' 10", "", 10))
		pass = 0;

	ft_test_segfault();

	ft_log_result_test("ft_strlcpy", pass);
}
