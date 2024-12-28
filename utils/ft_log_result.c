/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:16:43 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/28 11:19:34 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_log_result_test(const char *test_name, bool pass)
{
	printf("%s:\t%s\n", test_name, pass ? "\e[32mOK\e[0m" : "\e[31mKO\e[0m");
}

void	ft_log_result_str(char *expected, char *result, char *desc, bool pass)
{
	printf("\n%s %s\n", pass ? "\e[32mPASS\e[0m" : "\e[31mERROR\e[0m", desc);
	printf("- Exected '%s' got '%s'\n", expected, result);
}

void	ft_log_result_nbr(size_t expected, size_t result, char *desc, bool pass)
{
	printf("%s %s\n", pass ? "\e[32mPASS\e[0m" : "\e[31mERROR\e[0m", desc);
	printf("- Exected %zu got %zu\n", expected, result);
}

void	ft_log_result_int(int expected, int result, char *desc, bool pass)
{
	printf("%s %s\n", pass ? "\e[32mPASS\e[0m" : "\e[31mERROR\e[0m", desc);
	printf("- Exected %d got %d\n", expected, result);
}

void	ft_log_list_contents(t_list *begin)
{
	size_t	i;

	printf("\n");
	i = 0;
	printf("List begin pointer: %p\n", begin);
	while (begin != NULL)
	{
		printf("Node %zu (%p) ", i, begin);
		printf("->content=%s / ", (char *) begin->content);
		printf("->next=%p\n", begin->next);
		begin = begin->next;
		i++;
	}
}
