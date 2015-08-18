#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int
main()
{
 int fd;
 struct ifreq ifr;

 fd = socket(AF_INET, SOCK_DGRAM, 0);

 ifr.ifr_addr.sa_family = AF_INET; //fetching IPv4 Address

 strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1); //getting IP from device eth0 (ethernet)

 ioctl(fd, SIOCGIFADDR, &ifr);

 close(fd);

 printf("Local IP address is: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr$ // result prints

 return 0;
}
