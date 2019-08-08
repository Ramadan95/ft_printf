/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di_frst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:00:38 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/08 18:14:09 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_di_sxth(t_printf *ft)
{
	;
}

void	ft_format_di_ffth(t_printf *ft)
{
	;
}

void	ft_format_di_frth(t_printf *ft)
{
	;
}

void	ft_format_di_thrd(t_printf *ft)
{
	if (ft->width > ft_max(ft->precision, ft->length))
	{
		if (ft->flag->minus)
		{
			if (ft->precision >= ft->length)
			{
				ft_insert_di(ft);
				ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
				ft_format_s(ft);
				ft_insert_chr(ft, 0, ft->width - ft->precision -
						(ft->flag->plus || ft->flag->space || ft->pn), ' ');
			}
			else
			{
				ft_insert_di(ft);
				if (!(!(ft->precision) && ft->prec && ft->z))
					ft_format_s(ft);
				ft_insert_chr(ft, 0, ft->width - ft->length -
						(ft->flag->plus || ft->flag->space || ft->pn), ' ');
			}
		}
		else
		{
			if (ft->precision >= ft->length)
			{
				ft_insert_chr(ft, 0, ft->width - ft->precision -
						(ft->flag->plus || ft->flag->space || ft->pn), ' ');
				ft_insert_di(ft);
				ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
				ft_format_s(ft);
			}
			else
			{
				if (ft->flag->zero || !(ft->pn))
					ft_insert_di(ft);
				if (!(!(ft->precision) && ft->prec && ft->z))
					ft_format_s(ft);
								
				// if ((ft->pn && ft->flag->zero) ||
				// 		(ft->flag->plus && !(ft->pn) && ft->flag->zero)
				// 		|| (ft->flag->space && !(ft->pn) && ft->flag->zero))
				// 	ft_insert_di(ft);
				// {
				// 	if (ft->z || !(ft->flag->zero))
				// 	{
				// 		ft_insert_chr(ft, 0, ft->width - ft->length -
				// 				(ft->flag->plus || ft->flag->space ||
				// 				ft->pn) + ft->z, ' ');
				// 		if (ft->pn)
				// 			ft_insert_chr(ft, 0, 1, '-');
				// 		else if (ft->flag->plus)
				// 			ft_insert_chr(ft, 0, 1, '+');
				// 	}
				// 	else if (!(ft->prec))
				// 		ft_insert_chr(ft, 0, ft->width - ft->length -
				// 				(ft->flag->plus || ft->flag->space ||
				// 				ft->pn) + ft->z, '0');
				// 	else
				// 		ft_insert_chr(ft, 0, ft->width - ft->length -
				// 				(ft->flag->plus || ft->flag->space ||
				// 				ft->pn) + ft->z, ' ');
				// 	if (!(!(ft->precision) && ft->prec && ft->z))
				// 		ft_format_s(ft);
				// }
			}
		}
	}
	else if (ft->precision >= ft->length)
	{
		ft_insert_di(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		ft_insert_di(ft);
		if (!(!(ft->precision) && ft->prec && ft->z))
			ft_format_s(ft);
	}
}
