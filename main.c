#include "traceroute.h"

int need_help(int argc, char **argv) {
	if (argc == 1)
		return (1);
	while(*argv)
		if (!ft_strcmp(*argv++, "--help"))
			return (1);
	return (0);
}

int ft_start(char *b) {
	t_traceroute g;
	g.addr = "google.com";
	get_info(&g);
	printf("%s\n", g.ip);
	return 0;
}

int main(int argc, char **argv) {
	ft_start("google.com");	
	if (need_help(argc, argv)) {
		help();
		return 0;
	}
	return (0);
}
