#include "traceroute.h"

int get_info(t_traceroute *g)
{
	int		n;
	static char	str[126];
	void		*ptr;

	bzero (&g->hints, sizeof (struct addrinfo));
	g->hints.ai_flags = AI_CANONNAME;
	g->hints.ai_family = AF_INET;
	g->hints.ai_socktype = 0;
	if ((n = getaddrinfo(g->addr, NULL, &g->hints, &g->res)) != 0)
	    return 0;
	g->len = g->res->ai_addrlen;
	while (g->res) {
		if (g->res->ai_addr->sa_family == AF_INET)
   		{
			ptr = &((struct sockaddr_in *) g->res->ai_addr)->sin_addr;
        		if (inet_ntop(g->res->ai_family, ptr, str, sizeof(str)) == NULL)
        	    		return (0);
			g->s = g->res->ai_addr;
        		g->ip = str;
			return 1;
    		}
		g->res = g->res->ai_next;
	}
	return 0;
}
