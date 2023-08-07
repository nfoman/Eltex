#include"server.h"
#include <arpa/inet.h>
#include <errno.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

  


int main(){
    struct sockaddr_in serv;
    struct ip_mreqn multi;
    char bufik[100];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    int fd;
    multi.imr_multiaddr.s_addr=(inet_addr("224.0.0.1"));
    multi.imr_address.s_addr=INADDR_ANY;
    multi.imr_ifindex=0;

    
    fd=socket(AF_INET,SOCK_DGRAM,0);
    if (fd == -1) {
        perror("error in socket()");
        exit(EXIT_FAILURE);
    }
    inet_pton(AF_INET, "224.0.0.1", &(serv.sin_addr));
    multi.imr_multiaddr.s_addr=(inet_addr("224.0.0.1"));
    multi.imr_address.s_addr=INADDR_ANY;
    multi.imr_ifindex=0;
    setsockopt(fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&multi,sizeof(struct ip_mreqn));
    int ret =bind(fd,(const struct sockaddr*)&serv,sizeof(serv));
    if (ret == -1) {
        perror("error in bind()");
        exit(EXIT_FAILURE);
    }
    socklen_t size=sizeof(serv);


    recvfrom(fd,bufik,100,0,(struct sockaddr*)&serv,&size);
    printf("%s\n", bufik);
   
    


}