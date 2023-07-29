#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define FILENAME_SOCK "/tmp/Socket"

// typedef struct sockaddr_un {
//     sa_family_t sun_family;               /* AF_UNIX */
//     char        sun_path[108];            /* имя пути */
// }sockaddr_un;
