/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:26:30 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 17:51:50 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert_dest(char *test_description, char *src, size_t size)
{
	char	dst_std[32] = "hello ";
	char	dst_mine[32] = "hello ";
	bool	pass = 1;

	strlcat(dst_std, src, size);
	ft_strlcat(dst_mine, src, size);

	if (strncmp(dst_std, dst_mine, size) != 0) pass = 0;
	//printf("- %s:\n", test_description);
	//ft_log_result_str(dst_std, dst_mine, pass);

	return (pass);
}

static size_t	ft_assert_return(char *test_description, char *src, size_t size)
{
	char	dst_std[32] = "hello ";
	char	dst_mine[32] = "hello ";
	bool	pass = 1;

	size_t ret_std = strlcat(dst_std, src, size);
	size_t ret_mine = ft_strlcat(dst_mine, src, size);

	if (ret_std != ret_mine) pass = 0;
	//printf("- %s:\n", test_description);
	//ft_log_result_nbr(ret_std, ret_mine, pass);

	return (pass);
}

void	ft_strlcat_test(void)
{
	char	*dst_std;
	char	*dst_mine;
	int	pass;

	pass = 1;
	dst_std = NULL;
	dst_mine = NULL;
	
	if (!ft_assert_dest("Dest with simple test", "world", 32) ||
		!ft_assert_return("Return value with simple test", "world", 32) ||
		!ft_assert_dest("Dest with size(9) less than src + dest(12)", "world", 9) ||
		!ft_assert_return("Return value with size(9) less than src + dest(12)", "world", 9) ||
		!ft_assert_dest("Dest with size(3) less than src(6)", "world", 3) ||
		!ft_assert_return("Return value with size(3) less than src(6)", "world", 3) ||
		!ft_assert_dest("Dest with size 0", "world", 0) ||
		!ft_assert_return("Return value with size 0", "world", 0))
		pass = 0;

	ft_log_result_test("ft_strlcat", pass);
}
