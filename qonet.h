typedef struct TCPClient {
    int socket;

} TCPClient;

TCPClient OpenTCP(char* dstIP, unsigned short dstPort);