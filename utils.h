#ifndef

struct peer {
  char* name;
  char* address;
  int port;
  struct sockaddr_in saddr;
};

struct peers {
  struct peer* peerlist;
  int num_peers;
};

struct peers getpeers();

#endif
