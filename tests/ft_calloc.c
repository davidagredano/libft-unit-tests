/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:29:58 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/23 17:13:31 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, size_t nmemb, size_t size)
{
	bool	pass = 1;

	void *ret_std = calloc(nmemb, size);
	void *ret_mine = ft_calloc(nmemb, size);

	if ((memcmp(ret_std, ret_mine, nmemb * size)) != 0) pass = 0;
	//ft_log_result_str((char *) ret_std, (char *) ret_mine, desc, pass);
	//printf("std=%p mine=%p\n", ret_std, ret_mine);
	//Max size_t: 18446744073709551615

	free(ret_std);
	free(ret_mine);
	return (pass);
}

void	ft_calloc_test(void)
{
	int		pass = 1;
	
	if (!ft_assert_return("10 sizeof(char)", 10, sizeof(char)) ||
		!ft_assert_return("0 4", 0, 4) ||
		!ft_assert_return("20 0", 20, 0) ||
		//!ft_assert_return("100000000 100", 100000000, 100) ||
		!ft_assert_return("0 0", 0, 0))
		pass = 0;

	ft_log_result_test("ft_calloc", pass);
}
