/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:30:15 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/08 16:53:39 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_x_frth(t_printf *ft)
{
	if (ft->flag->zero && !(ft->prec))
	{
		if (!(!(ft->precision) && ft->prec && ft->z))
		{
			ft_insert_sharp(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length, '0');
		}
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length + ft->z, ' ');
		if (!(!(ft->precision) && ft->prec && ft->z))
			ft_insert_sharp(ft);
	}
	if (!(!(ft->precision) && ft->prec && ft->z))
		ft_format_s(ft);
}

void	ft_format_x_thrd(t_printf *ft)
{
	if (ft->precision >= ft->length)
	{
		ft_insert_chr(ft, 0, ft->width -
				ft_max(ft->precision, ft->length), ' ');
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
		ft_format_x_frth(ft);
}

void	ft_format_x_scnd(t_printf *ft)
{
	if (ft->flag->minus)
	{
		if (ft->precision >= ft->length)
		{
			ft_insert_sharp(ft);
			ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
			ft_format_s(ft);
			ft_insert_chr(ft, 0, ft->width - 
					ft_max(ft->precision, ft->length), ' ');
		}
		else
		{
			if (!(!(ft->precision) && ft->prec && ft->z))
			{
				ft_insert_sharp(ft);
				ft_format_s(ft);
			}
			ft_insert_chr(ft, 0, ft->width - ft->length + ft->z, ' ');
		}
	}
	else
		ft_format_x_thrd(ft);
}

void	ft_format_x_frst(t_printf *ft)
{
	if (ft->flag->sharp)
	{
		ft->pn = 2;
		ft->width = (ft->width >= 2) ? (ft->width - ft->pn) : ft->width;
	}
	if (ft->z && ft->flag->sharp)
		ft->width = (ft->width >= 2) ? (ft->width + ft->pn) : ft->width;
	if (ft->width >= ft_max(ft->precision, ft->length))
		ft_format_x_scnd(ft);
	else if (ft->precision >= ft->length)
	{
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (!(!(ft->precision) && ft->prec && ft->z))
		{
			ft_insert_sharp(ft);
			ft_format_s(ft);
		}
	}
}
