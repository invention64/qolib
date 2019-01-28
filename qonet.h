#ifndef _qonet_h
#define _qonet_h
#include <netinet/in.h>

typedef struct IP4 {
    struct sockaddr_in dst;
} IP4;

typedef struct TCPClient {
    int socket;
} TCPClient;

typedef struct UDPClient {
    int socket;
} UDPClient;

// General
IP4 GenerateIPv4(char* dstIP, unsigned short dstPort);

// TCP
TCPClient OpenTCP(IP4 target);
int SendArrayTCP(TCPClient client, char* data);
char* RecieveArrayTCP(TCPClient client, int bufferSize);
void CloseTCP(TCPClient client);

// UDP
UDPClient OpenUDP();
int SendArrayUDP(UDPClient client, IP4 target, char* data);
char* RecieveArrayUDP(UDPClient client, IP4 target, int bufferSize);
void CloseUDP(UDPClient client);

#endif
