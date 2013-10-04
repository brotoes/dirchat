#include "dirchat.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <err.h>
#include <errno.h>

int main(int argc, char * argv[]) {
	struct sockaddr peer_addr;
	int sid;

	if (argc != 2) {
		err(1, "Incorrect Argument Counts\n");
	}

	

	sid = socket(AF_INET, SOCK_STREAM, 0);
	if (sid == -1) {
		err(1, "Socket creation failed\n");
	}
	if (bind(sid, &peer_addr, sizeof(struct sockaddr) == -1)) {
		err(1, "Bind failed\n");
	}
	return 0;
}
