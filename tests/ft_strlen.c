/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:35:47 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/03 15:32:21 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_strlen_test(void)
{
	int		pass = 1;
	char	*strs[] = {"hello", "a", "", "lala lala"/*, NULL*/};
	int		len = 4;
	int		i = 0;

	size_t	ret_std;
	size_t	ret_mine;

	while (i < len)
	{
		ret_std = strlen(strs[i]);
		ret_mine = ft_strlen(strs[i]);
		if (ret_mine != ret_std)
			pass = 0;
		//ft_log_result_nbr(ret_std, ret_mine, strs[i], pass);
		i++;
	}

	ft_log_result_test("ft_strlen", pass);
}
