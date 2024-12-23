/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:26:30 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/23 17:26:15 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_dest(char *dst_std, char *dst_mine, char *src, size_t size)
{
	bool	pass;

	pass = 1;
	dst_std = malloc(100);
	dst_mine = malloc(100);
	if (!dst_std || !dst_mine)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}
	strlcpy(dst_std, src, size);
	ft_strlcpy(dst_mine, src, size);
	if (strcmp(dst_std, dst_mine) != 0)
	{
		printf("Error:\t");
		printf("Exected '%s' got '%s'\n", dst_std, dst_mine);
		pass = 0;
	}
	else
	{
		printf("Pass:\t");
		printf("Exected '%s' got '%s'\n", dst_std, dst_mine);
	}
	free(dst_std);
	free(dst_mine);
	return (pass);
}

static bool	ft_assert_return(char *dst_std, char *dst_mine, char *src, size_t size)
{
	size_t	ret_val_std;
	size_t	ret_val_mine;
	int	pass;

	pass = 1;
	dst_std = malloc(100);
	dst_mine = malloc(100);
	if (!dst_std || !dst_mine)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}
	ret_val_std = strlcpy(dst_std, src, size);
	ret_val_mine = ft_strlcpy(dst_mine, src, size);
	if (ret_val_std != ret_val_mine)
	{
		printf("Error:\t");
		printf("Exected '%zu' got '%zu'\n", ret_val_std, ret_val_mine);
		pass = 0;
	}
	else
	{
		printf("Pass:\t");
		printf("Exected '%zu' got '%zu'\n", ret_val_std, ret_val_mine);
	}
	free(dst_std);
	free(dst_mine);
	return (pass);
}

void	ft_strlcpy_test(void)
{
	char	*dst_std;
	char	*dst_mine;
	int	pass;

	pass = 1;
	dst_std = NULL;
	dst_mine = NULL;
	
	if (!ft_assert_dest(dst_std, dst_mine, "hello", 6))
		pass = 0;
	if (!ft_assert_dest(dst_std, dst_mine, "hello", 2))
		pass = 0;
	if (!ft_assert_dest(dst_std, dst_mine, "hello", 12))
		pass = 0;
	if (!ft_assert_return(dst_std, dst_mine, "hello", 0))
		pass = 0;
	if (!ft_assert_dest(dst_std, dst_mine, "", 10))
		pass = 0;
	if (!ft_assert_return(dst_std, dst_mine, "hello", 6))
		pass = 0;
	if (!ft_assert_return(dst_std, dst_mine, "hello", 2))
		pass = 0;
	if (!ft_assert_return(dst_std, dst_mine, "hello", 12))
		pass = 0;
	if (!ft_assert_return(dst_std, dst_mine, "hello", 0))
		pass = 0;
	if (!ft_assert_return(dst_std, dst_mine, "", 10))
		pass = 0;

	ft_log_result_test("ft_strlcpy", pass);
}
