/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 01:33:13 by sihemayoub        #+#    #+#             */
/*   Updated: 2023/07/26 03:43:27 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"

void	lezgo(t_ping *ping)
{
	inet_pton(AF_INET, ping->address, &(ping->dest_addr.sin_addr));
	while (1)
	{
		request(ping);
		write(1, "Request Send !", 14);
	}
}

void	setup(t_ping *ping, const char *address)
{
	ping->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->sockfd < 0)
	{
		write(2, "[ERROR]: Fail to create a socket\n", 33);
		exit(EXIT_FAILURE);
	}
	ping->address = address;
	ping->dest_addr.sin_family = AF_INET;

	ping->icmp_header = (struct icmp *)ping->packet;
	// * ICMP HEADER : 8 OCTETS
	ping->icmp_header->icmp_type = ICMP_ECHO;				// ? type = 8 BITS
	ping->icmp_header->icmp_hun.ih_idseq.icd_id = getpid();	// ? code = 16 BITS
	ping->icmp_header->icmp_hun.ih_idseq.icd_seq = 1;		// ? seq = 16 BITS
	ping->icmp_header->icmp_code = 0;						// ? code = 8 BITS
	ping->icmp_header->icmp_cksum = 0;						// ? checksum = 16 BITS
	ping->icmp_header->icmp_cksum = calcul_checksum();
}

int	main(int ac, char **av)
{
	t_ping	ping;

	if (ac > 1)
	{
		write(2, "Bad usage: ./ft_ping some_existing_adress\n", 42);
		return (1);
	}
	setup(&ping, av[1]);
	lezgo(&ping);

	return (0);
}
