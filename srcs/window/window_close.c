/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:42:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 16:35:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "config.h"

int	window_close(t_config *game);

int	window_close(t_config *game)
{
	(void)game;
	// destroy game();
	exit(0);
}