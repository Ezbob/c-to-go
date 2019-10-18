#include <stdio.h>
#include <stdlib.h>
#include "libdill.h"


coroutine void worker(const char *text) {
  while(1) {
    printf("%s\n", text);
    msleep(now() + random() % 500);
  }
}

int main(void) {
    go(worker("Hello!"));
    go(worker("World!"));

    msleep(now() + 5000);

    printf("Hello world\n");
    return 0;
}
