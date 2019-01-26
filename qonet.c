#include "qonet.h"
#include "qolib.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

TCPClient OpenTCP(char* dstIP, unsigned short dstPort) {
    // Validate VARs
    if(dstPort < 0 || dstPort > 50000) {
        qol_cab("Failed to parse destination port. Port must be less than 50K and more than 0.\r\n");
    }

    // Target
    struct sockaddr_in dst;

    // Local Socket
    //printf("Generating socket...\r\n");
    int sock = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock < 0) {
        qol_cab("Failed to create socket.\r\n");
    } else {
        //printf("Socket Generated!\r\n");
    }

    // Set DST
    struct in_addr ip;
    ip.s_addr = inet_addr(dstIP);
    //printf("IP: %ld\r\n", ip.s_addr);
    dst.sin_family = AF_INET;
    dst.sin_addr = ip;
    dst.sin_port = htons(dstPort);


    // Connect Local Socket
    if(connect(sock, &dst, sizeof(dst)) > 0) {
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
    return write(sock, data, strlen(data));
}

char* RecieveArrayTCP(TCPClient client, int bufferSize) {
    int sock = client.socket;
    char buffer[bufferSize];
    bzero(buffer, bufferSize);
    return read(sock, buffer, bufferSize);
}

void CloseTCP(TCPClient client) {
    int sock = client.socket;
    close(sock);
}

