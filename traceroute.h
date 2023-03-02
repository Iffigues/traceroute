#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include <netinet/ip_icmp.h>
# include <sys/time.h>
# include <strings.h>

typedef struct	s_traceroute
{
	int	ttl;
	int	ttlTotaux;
	int	socket;
	int 	err;
	size_t	len;
	int	bridge;
	struct sockaddr *s;
	struct	addrinfo hints;
	struct	addrinfo *res;
	char	*addr;
	char	*ip;
}		t_traceroute;



void		help();
int		ft_strcmp(const char *s1, const char *s2);
t_traceroute get_info(char *addr);
int setSocks(t_traceroute *g);
int open_socket(t_traceroute *g);
#endif
