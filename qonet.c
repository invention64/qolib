#include "qonet.h"
#include <sys/socket.h>
#include <netinet/in.h>

TCPClient OpenTCP(char* dstIP, unsigned short dstPort) {
    // Validate VARs
    if(dstPort < 0 || dstPort > 50000) {
        throw runtime_error("dstPort must be greater than 0 and less than 50,000!");
        return;
    }

    // Target
    struct sockaddr_in dst;

    // Local Socket
    printf("Generating socket...\r\n");
    int sock = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock < 0) {
        error("ERROR opening socket");
    } else {
        printf("Socket Generated!\r\n");
    }

    // Set DST
    struct in_addr ip;
    ip.s_addr = inet_addr(dstIP);
    printf("IP: %ld\r\n", ip.s_addr);
    dst.sin_family = AF_INET;
    dst.sin_addr = ip;
    dst.sin_port = htons(dstPort);


    // Connect Local Socket
    if(connect(sock, &dst, sizeof(dst)) > 0) {
        error("Failed to connect..........");
    } else {
        printf("Connected!\r\n");
    }
}