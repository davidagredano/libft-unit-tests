/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:35:47 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 11:12:39 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_strlen_test(void)
{
	int		len = 5;
	char	*strs[] = {"hello", "world", "a", "", "lkjh  23ew"};
	int		i = 0;
	int		pass = 1;

	while (i < len)
	{
		if (ft_strlen(strs[i]) != strlen(strs[i]))
		{
			pass = 0;
			printf("Error for input %s. ", strs[i]);
			printf("Expected %zu ", strlen(strs[i]));
			printf("instead of %zu\n", ft_strlen(strs[i]));
		}
		i++;
	}
	ft_log_result_test("ft_strlen", pass);
}
