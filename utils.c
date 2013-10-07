#include <arpa/inet.h>

#include <netinet/in.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"


struct peers getpeers() {
  FILE* addressbook = fopen("addressbook", "r");
  char buffer[75];
  struct peers peers; 
  int peerlist_size = 10;
  
  peers.peerlist = malloc(peerlist_size*sizeof(struct peer));
  peers.num_peers = 0;
  
  int i;
  for (i=0; fgets(buffer, 50, addressbook) != NULL; i++) {
    peers.peerlist[i].name = malloc(25);
    peers.peerlist[i].address = malloc(25);

    sscanf("%s%s%d", peers.peerlist[i].name, 
	   peers.peerlist[i].address, peers.peerlist[i].port);
  
    peers.peerlist[i].saddr.sin_family = AF_INET;
    peers.peerlist[i].saddr.sin_port = htons(peers.peerlist[i].port);
    peers.peerlist[i].saddr.sin_addr.s_addr = 
      inet_addr(peers.peerlist[i].address);

    if (peers.num_peers == peerlist_size) {
      peerlist_size = 2*peerlist_size;
      peers.peerlist = realloc(peers.peerlist, peerlist_size*sizeof(currpeer));
    }
    
    peers.num_peers++;
  }
  fclose(addressbook);

  return peers;
}
