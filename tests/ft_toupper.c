/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:42:08 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 18:01:11 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static size_t	ft_assert_return(char *test_description, int c)
{
	bool	pass = 1;

	size_t ret_std = toupper(c);
	size_t ret_mine = ft_toupper(c);

	if (ret_std != ret_mine) pass = 0;
	//printf("- %s:\n", test_description);
	//ft_log_result_nbr(ret_std, ret_mine, pass);

	return (pass);
}

void	ft_toupper_test(void)
{
	int	pass = 1;
	
	if (!ft_assert_return("Return value passing 'R'", 'R') ||
		!ft_assert_return("Return value passing 'j'", 'j') ||
		!ft_assert_return("Return value passing '\\0'", '\0') ||
		!ft_assert_return("Return value passing 200", 200) ||
		!ft_assert_return("Return value passing 1000", 1000))
		pass = 0;

	ft_log_result_test("ft_toupper", pass);
}
