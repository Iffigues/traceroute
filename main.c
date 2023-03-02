#include "traceroute.h"

int need_help(int argc, char **argv) {
	if (argc == 1)
		return (1);
	while(*argv)
		if (!ft_strcmp(*argv++, "--help"))
			return (1);
	return (0);
}

void ft_run(t_traceroute g) {
	open_socket(&g);	
}

int ft_start(char *b) {
	t_traceroute g = get_info(b);
	if (g.err) {
		if (g.err == 2)
			freeaddrinfo(g.res);
		return 1;
	}
	ft_run(g);
	freeaddrinfo(g.res); 
	return 0;
}

int main(int argc, char **argv) {
	if (need_help(argc, argv)) {
		help();
		return 0;
	}
	if (argc == 2) {
		ft_start(argv[1]);
	}
	return (0);
}
