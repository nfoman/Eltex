#include"server.h"
#define SIZE 200




int main(){
    
    struct sockaddr_in serv;
    int fd;
    int flag = 1;
    serv.sin_family = AF_INET;
    serv.sin_port=htons(PORTIK);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    fd=socket(AF_INET,SOCK_RAW,IPPROTO_UDP);
    if(fd==-1){
        perror("socket");
        return 1;
    }
    if (setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &flag, sizeof(flag)) == -1) {
        perror("setsockopt");
        return 1;
    }
    struct udphdr *ptr;
    struct iphdr *iphead;
    socklen_t len =sizeof(struct sockaddr_in);
    char bufik[100];
    char *packet =malloc(SIZE); 
    iphead=(struct iphdr *)packet;
    iphead->version=4;
    iphead->ihl = 5;
    iphead->tos=0;
    iphead->tot_len=0;
    iphead->id=htonl(54321);
    iphead->frag_off=0; 
    iphead->ttl=255;
    iphead->protocol=IPPROTO_UDP;
    iphead->check=0;
    iphead->saddr=htonl(INADDR_ANY);
    iphead->daddr=serv.sin_addr.s_addr;
    
  

    ptr = (struct udphdr *)(packet+sizeof(struct iphdr)); 
    ptr->source=htons(7654);
    ptr->check=0;
    ptr->dest=htons(PORTIK);

    strcpy(bufik,"hello");
    memmove(packet+28,bufik,strlen(bufik));




    
    ptr->len = htons(strlen(bufik)  + sizeof(struct udphdr));
    if(sendto(fd, packet, SIZE, 0, (struct sockaddr *)&serv, sizeof(serv))==-1){
        perror("sendto error()");
        exit(EXIT_FAILURE);
    }
    printf("send\n");
    while (1)
    {   
        // printf("%s\n",bufik); 
        int check = recvfrom(fd, packet, SIZE, 0,(struct sockaddr *)&serv, &len);	
        if(check<0){
            perror("recv");
            exit(EXIT_FAILURE);
        }  
        iphead=(struct iphdr *)(packet);
		ptr = (struct udphdr *)(packet + 20);   
        // printf("%d\n",htons(ptr->source)); 
        if (htons(ptr->dest) == 7654){
            // memmove(str,packet+70,15);
           
            printf("message: %s\n\n", packet+sizeof(struct iphdr)+sizeof(struct udphdr));
        }
    }
    
   
  
       
   

    


}