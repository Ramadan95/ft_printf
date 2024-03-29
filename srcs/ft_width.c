/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:05:03 by mfahey            #+#    #+#             */
/*   Updated: 2019/07/26 19:35:23 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_iswidth(t_printf *ft)
{
	if ((ft->fmt)[ft->i] == '*')
	{
		ft->width = va_arg(ft->ap, int);
		(ft->i)++;
	}
	else if (ft_isdigit((ft->fmt)[ft->i]))
	{
		ft->width = (int)ft_atoll(ft->fmt + ft->i);
		while (ft_isdigit((ft->fmt)[ft->i]))
			(ft->i)++;
	}
}
