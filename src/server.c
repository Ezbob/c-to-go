#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include "libdill/libdill.h"


coroutine void dialogue(int sock) {
  char inbuf[512], outbuf[512] = "OK";

  ssize_t receivedsize = mrecv(sock, inbuf, sizeof(inbuf), -1);
  if (receivedsize < 0) goto cleanup;

  inbuf[receivedsize] = '\0';
  printf("Received: '%s'\n", inbuf);

  int rc = msend(sock, outbuf, sizeof(outbuf), -1);
  if (rc != 0) goto cleanup;
cleanup:
  rc = hclose(sock); // closes the socket
  assert(rc == 0);
}


int main(int argc, char **argv) {

    int port = 5555;
    if (argc > 1) port = atoi(argv[1]); 

    struct ipaddr addr;

    int cip = ipaddr_local(&addr, NULL, port, 0);

    if (cip < 0) {
      perror("Can't open listening socket");
      return 1;
    }

    int clisten = tcp_listen(&addr, 10);
    assert(clisten >= 0);


    int cclose, csocket; // c for "code"
    while (1) {
      csocket = tcp_accept(clisten, NULL, -1);
      assert(csocket >= 0);
    
      printf("New connection!!\n");

      csocket = suffix_attach(csocket, "\r\n", 2);
      assert(csocket >= 0);

      int code = go(dialogue(csocket));
      if (code < 0) goto cleanup;
    }

cleanup:
    cclose = hclose(csocket);
    assert(cclose == 0);

    return 0;
}
