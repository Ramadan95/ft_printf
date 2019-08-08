/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:12:08 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/07 18:10:06 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_s_scnd(t_printf *ft)
{
	while (((ft->value->s)[ft->k] != '\0') &&
			(ft->k < ft->length))
	{
		ft_insert_chr(ft, 0, 1, (ft->value->s)[ft->k]);
		(ft->k)++;
	}
}

void	ft_format_s_frst(t_printf *ft)
{
	if (ft->width > ft->length)
	{
		if (ft->flag->minus)
		{
			ft_format_s_scnd(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		}
		else
		{
			ft_insert_chr(ft, 0, ft->width - ft->length,
					ft->flag->zero ? '0' : ' ');
			ft_format_s_scnd(ft);
		}
	}
	else
		ft_format_s_scnd(ft);
}
