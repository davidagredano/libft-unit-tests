/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:38:25 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/27 20:20:07 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_test(void *content, size_t len)
{
	bool	pass = 1;

	t_list *begin = ft_lstnew(strdup(content));
	if (memcmp(content, begin->content, strlen(content) + 1)) pass = 0;
	if (begin->next != NULL) pass = 0;

	//printf("\n'%s'\n", content);
	//ft_log_list_contents(begin);

	free(begin->content);
	free(begin);
	return (pass);
}

void	ft_bonus_test(void)
{
	int		pass = 1;
	
	if (!ft_test("Hi", 3) ||
		!ft_test("000", 4) ||
		!ft_test("bye", 4))
		pass = 0;

	ft_log_result_test("Parte bonus", pass);
}
