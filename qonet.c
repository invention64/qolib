#include "qonet.h"
#include "qolib.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

IP4 GenerateIPv4(char* dstIP, unsigned short dstPort) {
    // Validate VARs
    if(dstPort < 0 || dstPort > 50000) {
        qol_cab("Failed to parse destination port. Port must be less than 50K and more than 0.\r\n");
    }

    // Target
    struct sockaddr_in dst;

    // Set DST
    struct in_addr ip;
    ip.s_addr = inet_addr(dstIP);
    //printf("IP: %ld\r\n", ip.s_addr);
    dst.sin_family = AF_INET;
    dst.sin_addr = ip;
    dst.sin_port = htons(dstPort);

    IP4 target;
    target.dst = dst;
    return target;
}

TCPClient OpenTCP(IP4 target) {
    // Local Socket
    //printf("Generating socket...\r\n");
    int sock = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock < 0) {
        qol_cab("Failed to create socket.\r\n");
    } else {
        //printf("Socket Generated!\r\n");
    }

    // Connect Local Socket
    if(connect(sock, &target.dst, sizeof(target.dst)) > 0) {
        error("Failed to connect..........");
    } else {
        //printf("Connected!\r\n");
        TCPClient client;
        client.socket = sock;
        return client;
    }
}

int SendArrayTCP(TCPClient client, char* data) {
    int sock = client.socket;
    return send(sock, data, strlen(data), 0);
}

char* RecieveArrayTCP(TCPClient client, int bufferSize) {
    int sock = client.socket;
    char buffer[bufferSize];
    bzero(buffer, bufferSize);
    return recv(sock, buffer, bufferSize, 0);
}

void CloseTCP(TCPClient client) {
    int sock = client.socket;
    close(sock);
}

UDPClient OpenUDP() {    
    // Local Socket
    //printf("Generating socket...\r\n");
    int sock = socket(AF_INET, SOCK_DGRAM, 0); 
    
    if (sock < 0) {
        qol_cab("Failed to create socket.\r\n");
    } else {
        //printf("Socket Generated!\r\n");
    }

    //printf("Connected!\r\n");
    UDPClient client;
    client.socket = sock;
    return client;
}

int SendArrayUDP(UDPClient client, IP4 target, char* data) {
    int sock = client.socket;
    return sendto(sock, data, strlen(data), 0, &target.dst, sizeof(target.dst));
}

char* RecieveArrayUDP(UDPClient client, IP4 target, int bufferSize) {
    int sock = client.socket;
    char buffer[bufferSize];
    bzero(buffer, bufferSize);
    return recvfrom(sock, buffer, bufferSize, 0, &target.dst, sizeof(target.dst));
}

void CloseUDP(UDPClient client) {
    int sock = client.socket;
    close(sock);
}