/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:38:25 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/28 09:38:46 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static bool	ft_test(void *s1, void *s2)
{
	bool	pass = 1;

	//ft_lstnew (1)
	t_list *begin = ft_lstnew(strdup(s1));
	if (memcmp(s1, begin->content, strlen(s1) + 1)) pass = 0;
	if (begin->next != NULL) pass = 0;

	//ft_lstadd_front (2)
	t_list *new = ft_lstnew(strdup(s2));
	ft_lstadd_front(&begin, new);
	if (memcmp(s2, begin->content, strlen(s2) + 1)) pass = 0;
	if (begin->next == NULL) pass = 0;

	//log list
	ft_log_list_contents(begin);

	//ft_lstsize (3)
	printf("List size: %d\n", ft_lstsize(begin));
	
	//free the list 
	t_list	*next = begin;
	while (next)
	{
		next = begin->next;
		free(begin->content);
		free(begin);
		begin = next;
	}
	return (pass);
}

void	ft_bonus_test(void)
{
	int		pass = 1;
	
	if (!ft_test("Hi", "New head") ||
		!ft_test("000", "Adding head") ||
		!ft_test("bye", "Hello head"))
		pass = 0;

	ft_log_result_test("Parte bonus", pass);
}
