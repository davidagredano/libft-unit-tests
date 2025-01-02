/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:28:57 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/02 22:52:31 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_assert_return(char *desc, const char *s)
{
	bool	pass = 1;

	char *ret_std = strdup(s);
	char *ret_mine = ft_strdup(s);

	if (strcmp(ret_std, ret_mine) != 0 || ret_std == ret_mine) pass = 0;
	//ft_log_result_str(ret_std, ret_mine, desc, pass);
	//printf("Mem std=%p mine=%p\n", ret_std, ret_mine);

	free(ret_std);
	free(ret_mine);
	return (pass);
}

void	ft_strdup_test(void)
{
	int		pass = 1;
	
	if (!ft_assert_return("'Hello word'", "Hello world") ||
		!ft_assert_return("'Bye'", "Bye") ||
		//!ft_assert_return("NULL", NULL) || //segmentation fault
		!ft_assert_return("''", ""))
		pass = 0;

	ft_log_result_test("ft_strdup", pass);
}
