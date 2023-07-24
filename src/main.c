/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 01:33:13 by sihemayoub        #+#    #+#             */
/*   Updated: 2023/07/24 15:57:06 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"

void	lezgo(t_ping *ping)
{
	unsigned char buffer[IP_MAXPACKET];

	while (1)
	{
		ping->data_size = recvfrom(ping->sockfd, buffer, IP_MAXPACKET, 0, (struct sockaddr *)&ping->sender_addr, &ping->sender_addr_len);
		if (ping->data_size < 0)
		{
			write(2, "[ERROR]: Fail to recvfrom\n", 26);
			exit(EXIT_FAILURE);
		}
		ping->ip_header = (struct ip *)buffer;
		ping->ip_header_length = ping->ip_header->ip_hl * 4;
		ping->icmp_header = (struct icmphdr *)(buffer + ping->ip_header_length);
		if (ping->ip_header->ip_p == IPPROTO_ICMP)
		{
			if (ping->icmp_header->type == ICMP_ECHO)
			{
				printf("PROUTE");
			}
		}
	}
}

void	setup(t_ping *ping)
{
	ping->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->sockfd < 0)
	{
		write(2, "[ERROR]: Fail to create a socket\n", 33);
		exit(EXIT_FAILURE);
	}
	ping->sender_addr_len = sizeof(ping->sender_addr);
	ping->ip_header = NULL;
	ping->ip_header_length = 0;
	ping->data_size = 0;
	ping->icmp_header = NULL;
}

int	main(void)
{
	t_ping	ping;
	setup(&ping);
	lezgo(&ping);

	return (0);
}
