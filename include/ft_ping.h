/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:45:45 by sihemayoub        #+#    #+#             */
/*   Updated: 2023/07/26 03:43:21 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/socket.h>

# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <netinet/in.h>

# include <arpa/inet.h>

# define MAXSIZE_PACKET 4096

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

typedef struct s_ping {
	int					sockfd;
	struct sockaddr_in	dest_addr;
	const char			*address;
	struct icmp			*icmp_header;
	unsigned char		packet[IP_MAXPACKET];
}t_ping;

void    request(t_ping *ping);

#endif
