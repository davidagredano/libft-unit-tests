/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:18:01 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/29 12:15:09 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static void	ft_log_split_result(const char *s, char c, char **substrs)
{
	size_t	i = 0;

	printf("\nResult for \"%s\" '%c':\n", s, c);
	while (substrs[i] != NULL)
	{
		printf("%zu. %s\n", i, substrs[i]);
		i++;
	}
	printf("%zu. %s\n", i, substrs[i]);
}

static bool	ft_test(char const *s, char c, const char *expect)
{
	bool	pass = 1;
	size_t	i = 0;

	char **substrs = ft_split(s, c);

	if (strcmp(expect, substrs[0]) != 0) pass = 0;
	//ft_log_split_result(s, c, substrs);

	while (substrs[i] != NULL)
	{
		free(substrs[i]);
		i++;
	}
	free(substrs);
	return (pass);
}

void	ft_split_test(void)
{
	int		pass = 1;
	
	if (!ft_test("Hello world", ' ', "Hello") ||
		!ft_test("Hi-bye-hello", '-', "Hi") ||
		!ft_test("Hello", ' ', "Hello") ||
		!ft_test("**hello***students*how**are****you?*", '*', "hello") ||
		!ft_test("This is a super string", ' ', "This"))
		pass = 0;

	ft_log_result_test("ft_split", pass);
}
