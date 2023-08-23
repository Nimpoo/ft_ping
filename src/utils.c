/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:41:22 by sihemayoub        #+#    #+#             */
/*   Updated: 2023/07/27 22:38:57 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"

unsigned short	calcul_checksum(void *icmp_header, int len)
{
	unsigned short	*buf;
	unsigned int	sum;

	buf = icmp_header;
	sum = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char *)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	return ((short)~sum);
}
