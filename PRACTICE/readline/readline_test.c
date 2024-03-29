/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:19:00 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/19 13:59:38 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h> //readline 

#include <readline/history.h>
#include <stdlib.h>

int	main(void)
{
	char	*rd_ret;
	int		i;

	i = 0;
	while (++i < 4)
	{
		rd_ret = readline(">>>>>");
		add_history(rd_ret);
		printf("%s\n", rd_ret);
		free(rd_ret);
		printf("%d\n", rl_on_new_line());
	}
	clear_history();
	return (0);
}
