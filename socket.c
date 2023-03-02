#include "traceroute.h"

int open_socket(t_traceroute *g)
{
	int size;

	size = 84;
	if ((g->socket = socket(g->s->sa_family, SOCK_RAW, IPPROTO_ICMP)) < 0)
		return 1;
	if (setsockopt(g->socket, SOL_SOCKET, SO_RCVBUF, &size, sizeof (size)) < 0)
		return 1;
	int on = 1;
	if (setsockopt(g->socket, SOL_SOCKET, SO_TIMESTAMP, &on, (int)sizeof(on)) != 0)
		printf("\nSetting socket options to TIMESTAMP failed!\n");
	if (setsockopt(g->socket, IPPROTO_IP, IP_RECVTTL, &on, (int)sizeof(on)) != 0)
		printf("\nSetting socket options to RECVTTL failed!\n");

	struct timeval tv_out;
	tv_out.tv_sec = 1;
	tv_out.tv_usec = 0;
	setsockopt(g->socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof tv_out);
	return 0;
}


int setSocks(t_traceroute *g) {
	  if (setsockopt(g->socket, IPPROTO_IP, IP_TTL, &g->ttl, (int)sizeof(g->ttl)) != 0)
    		return 1;
	  return 0;
} 
