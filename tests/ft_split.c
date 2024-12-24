/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:18:01 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/24 19:08:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"


static bool	ft_log_test(char const *s, char c)
{
	bool	pass = 1;
	size_t	i;

	char **ret_mine = ft_split(s, c);

	//if (strcmp(expect, ret_mine) != 0) pass = 0;
	//ft_log_result_str(expect, ret_mine, s, pass);

	/*
	printf("\nResult for '%s':\n", s);
	i = 0;
	while (ret_mine[i] != NULL)
	{
		printf("%zu. %s\n", i, ret_mine[i]);
		i++;
	}
	printf("%zu. (NULL)\n", i);
	*/

	i = 0;
	while (ret_mine[i] != NULL)
	{
		free(ret_mine[i]);
		i++;
	}
	free(ret_mine);
	return (pass);
}

void	ft_split_test(void)
{
	int		pass = 1;
	
	if (!ft_log_test("Hello world", ' ') ||
		!ft_log_test("Hi-bye-hello", '-') ||
		!ft_log_test("Hello", ' ') ||
		!ft_log_test("This is a super string", ' '))
		pass = 0;

	ft_log_result_test("ft_split", pass);
}
