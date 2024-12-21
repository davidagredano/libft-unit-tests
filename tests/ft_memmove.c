/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 13:09:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert_dest(void *src, size_t n);
static int	ft_test_overlapping(char *prev_ptr);

void	ft_memmove_test(void)
{
	int	pass;

	pass = 1;

	if (!ft_assert_dest((void *) "hello", 5)) pass = 0;
	if (!ft_assert_dest((void *) "hello world", 11)) pass = 0;
	if (!ft_assert_dest((void *) "hello world", 2)) pass = 0;
	if (!ft_assert_dest((void *) "hello world", 20)) pass = 0;
	if (!ft_assert_dest((void *) "hello world", 0)) pass = 0;
	if (!ft_test_overlapping("src")) pass = 0;
	if (!ft_test_overlapping("dest")) pass = 0;
	if (!ft_test_overlapping("same")) pass = 0;

	ft_log_result_test("ft_memmove", pass);
}

static int	ft_assert_dest(void *src, size_t n)
{
	char	dest_std[32] = "";
	char	dest_mine[32] = "";
	int		pass = 1;

	memmove(dest_std, src, n);
	ft_memmove(dest_mine, src, n);

	if (memcmp(dest_std, dest_mine, n) != 0)
		pass = 0;

	/*
	printf("Assert dest - ");
	ft_log_result_str((char *) dest_std, (char *) dest_mine, pass);
	*/

	return (pass);
}

static int	ft_test_overlapping(char *prev_ptr)
{
	char	src_std[16] = "hello world";
	char	src_mine[16] = "hello world";
	int		pass = 1;

	if (prev_ptr == "src")
	{
		memmove(&src_std[6], src_std, 5);
		ft_memmove(&src_mine[6], src_mine, 5);
	}
	else if (prev_ptr == "dest")
	{
		memmove(src_std, &src_std[6], 5);
		ft_memmove(src_mine, &src_std[6], 5);
	}
	else if (prev_ptr == "same")
	{
		memmove(src_std, src_std, 5);
		ft_memmove(src_mine, src_std, 5);
	}

	if (memcmp(src_std, src_mine, 5) != 0)
		pass = 0;

	/*
	printf("Assert dest (overlapping) - ");
	ft_log_result_str((char *) src_std, (char *) src_mine, pass);
	*/
}
