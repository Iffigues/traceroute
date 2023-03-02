#include "traceroute.h"
#include <stdlib.h>

t_traceroute get_info(char *addr)
{
	int		n;
	static char	str[126];
	void		*ptr;
	t_traceroute	g;

	g.err = 0;
	g.ttl = 0;
	g.addr = addr;
	bzero (&g.hints, sizeof (struct addrinfo));
	g.hints.ai_flags = AI_CANONNAME;
	g.hints.ai_family = AF_INET;
	g.hints.ai_socktype = 0;
	if ((n = getaddrinfo(g.addr, NULL, &g.hints, &g.res)) != 0)	{
	     	g.err = 1;
		return g;
	}
	g.len = g.res->ai_addrlen;
	while (g.res) {
		if (g.res->ai_addr->sa_family == AF_INET)
   		{
			ptr = &((struct sockaddr_in *) g.res->ai_addr)->sin_addr;
        		if (inet_ntop(g.res->ai_family, ptr, str, sizeof(str)) == NULL) {
				g.err = 2;
				return (g);
			}
			g.s = g.res->ai_addr;
        		g.ip = str;
			return g;
    		}
		g.res = g.res->ai_next;
	}
	return g;
}
