/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:20:58 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/03 15:12:01 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_end_room(t_base *info)
{
	if (info->end && !(check_room(info, info->end)))
		return (0);
	else
		ft_strdel(&info->end);
	return (1);
}

int		get_tube(t_base *info, char	*line)
{
	int		i;
	int		j;

	ft_printf("--- IN TUBE ---\n");
	if (info->end && !get_end_room(info))
		return (0);
	if ((i = check_tube(info, ft_str_nword(line, 0, '-'))) == -1)
		return (0);
	if ((j = check_tube(info, ft_str_nword(line, 1, '-'))) == -1)
		return (0);
	if ((!IMX) && (!create_matrix(info)))
		return (0);
	ft_printf("++++++++|%d|++|%d|++++++++\n", i, j);
	if (IMX && !(set_matrix(info, i, j)))
		return (0);
	i = 0;
	ft_printf("PRINT IPAPA\n");/*
	while (i < 2)
	{
		j = 0;
		while (j < IMSZ)
		{
			ft_printf("|");
			ft_printf(RED"%d"C_DEFAULT, IPAPA[i][j++]);
		}
		ft_printf("\n");
		i++;
	}*/
	ft_printf("END GET TUBE\n");
	//info->papa = ft_memalloc((info->a + 1) * sizeof(int), -1);
	/*while (i < IMSZ)
	{
		j = 0;
		while (j < IMSZ)
		{
			if (IMX[i][j] == 1)
			{
				ft_printf("|");
				ft_printf(RED"%d"C_DEFAULT, IMX[i][j++]);
			}
			else
				ft_printf("|%d", IMX[i][j++]);
		}
		ft_printf("\n");
		i++;
	}*/
	return (1);
}

int		check_tube(t_base *info, char *tocheck)
{
	t_list	*tempo;
	int		index;

	tempo = ILH;
	index = 0;
	ft_printf("--- IN CHECK TUBE ---\n");
	ft_printf("TUBE == %s|\n", tocheck);
	while (ILC->name || ILN != NULL)
	{
		ft_printf("NAME content ==== %s|\n", ILC->name);
		ft_printf("NAME index ==== %d|\n", ILC->index);
		ft_printf("FOURMI ==== %d|\n", ILC->ant);
		if (ft_strstr(ILC->name, tocheck))
		{
			index = ILC->index;
			ILH = tempo;
			return (index);
		}
		if (ILN != NULL)
			ILH = ILN;
		else
			break ;
	}
	ILH = tempo;
	return(-1);
}