/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:38:25 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/28 17:20:02 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static void	ft_del_content(void *content)
{
	if (content == NULL)
		return ;
	free(content);
}

static void	ft_replace_content(void *content)
{
	char *str_content = (char *) content;
	while (*str_content != 0)
	{
		*str_content = '*';
		str_content++;
	}
}

static void	*ft_replace_content2(void *content)
{
	void	*new_content;

	new_content = strdup("New mapped list content.");
	if (new_content == NULL)
		return (NULL);
	return (new_content);
}

static bool	ft_test(void *s1, void *s2, void *s3, bool log)
{
	bool	pass = 1;

	//ft_lstnew (1) + log list + ft_lstsize (3) + ft_lstlast (4)
	if (log)
		printf("\nTrying to create a node with ft_lstnew...\n");
	t_list *begin = ft_lstnew(strdup(s1));
	if (memcmp(s1, begin->content, strlen(s1) + 1)) pass = 0;
	if (begin->next != NULL) pass = 0;
	if (log)
	{
		ft_log_list_contents(begin);
		printf("List size: %d\n", ft_lstsize(begin));
		printf("Last node content: %s\n", (char *) ft_lstlast(begin)->content);
	}

	//ft_lstadd_front (2) + log list + ft_lstsize (3) + ft_lstlast (4)
	if (log)
		printf("\nTrying to add a node to the list with ft_lstadd_front...\n");
	ft_lstadd_front(&begin, ft_lstnew(strdup(s2)));
	if (memcmp(s2, begin->content, strlen(s2) + 1)) pass = 0;
	if (begin->next == NULL) pass = 0;
	if (log)
	{
		ft_log_list_contents(begin);
		printf("List size: %d\n", ft_lstsize(begin));
		printf("Last node content: %s\n", (char *) ft_lstlast(begin)->content);
	}

	//ft_lstadd_back (5) + log list + ft_lstsize (3) + ft_lstlast (4)
	if (log)
		printf("\nTrying to add a node to the list with ft_lstadd_front...\n");
	ft_lstadd_back(&begin, ft_lstnew(strdup(s3)));
	if (log)
	{
		ft_log_list_contents(begin);
		printf("List size: %d\n", ft_lstsize(begin));
		printf("Last node content: %s\n", (char *) ft_lstlast(begin)->content);
	}

	//ft_lstmap (9) + log list + ft_lstsize (3) + ft_lstlast (4)
	if (log)
		printf("\nTrying to use lstmap to create a new list...\n");
	t_list *begin2 = ft_lstmap(begin, &ft_replace_content2, &ft_del_content);
	if (log)
	{
		ft_log_list_contents(begin2);
		printf("List size: %d\n", ft_lstsize(begin2));
		printf("Last node content: %s\n", (char *) ft_lstlast(begin2)->content);
	}

	//ft_lstiter (8) + log list + ft_lstsize (3) + ft_lstlast (4)
	if (log)
		printf("\nTrying to use lstiter in the first list...\n");
	ft_lstiter(begin, &ft_replace_content);
	if (log)
	{
		ft_log_list_contents(begin);
		printf("List size: %d\n", ft_lstsize(begin));
		printf("Last node content: %s\n", (char *) ft_lstlast(begin)->content);
	}

	//ft_lstdelone (6) + log list + ft_lstsize (3) + ft_lstlast (4)
	t_list *tmp = begin->next;
	if (log)
		printf("\nTrying to delete the first node...\n");
	ft_lstdelone(begin, &ft_del_content);
	begin = tmp;
	if (log)
	{
		ft_log_list_contents(begin);
		printf("List size: %d\n", ft_lstsize(begin));
		printf("Last node content: %s\n", (char *) ft_lstlast(begin)->content);
	}

	//ft_lstclear (7) + log list + ft_lstsize (3) + ft_lstlast (4) 
	if (log)
		printf("\nTrying to clear the lists...\n");
	ft_lstclear(&begin, &ft_del_content);
	ft_lstclear(&begin2, &ft_del_content);
	if (log)
	{
		ft_log_list_contents(begin);
		printf("List size: %d\n", ft_lstsize(begin));
		ft_log_list_contents(begin2);
		printf("List size: %d\n", ft_lstsize(begin2));
	}
	
	return (pass);
}

void	ft_bonus_test(void)
{
	int		pass = 1;
	
	if (!ft_test("Hi", "New head", "Back addition", false)/* ||
		!ft_test("000", "Adding head", "Append string", false) ||
		!ft_test("bye", "Hello head", "Hello tail", false)*/)
		pass = 0;

	ft_log_result_test("Parte bonus", pass);
}
