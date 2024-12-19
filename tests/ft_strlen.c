/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:35:47 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 14:25:45 by dagredan         ###   ########.fr       */
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
	ft_print_test_result("ft_strlen", pass);
	
}
