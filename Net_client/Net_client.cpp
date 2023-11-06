#include <WinSock2.h>
#include <iostream>

int main()
{//윈속 초기화
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

                           //IP                   //TCP
    //SOCKET sockTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //SOCKET sockUDP = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0); //STREAM은 TCP, DGRAM은 UDP로 해석
    //SOCKADDR sa; //16바이트 구조체
    SOCKADDR_IN sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(192.168.0.8);
    sa.sin_port;
    int ret = ;

    connect(sock, , sizeof());

    char buf[256] = "KGCA";
    int iLen = strlen(buf);
    int iSendByte;

    while (1) {
        fgets(buf, 256, stdin);
        if (buf[0] == '\n') break;
        int iSendByte = send(sock, buf, iLen, 0);
        printf("%d 전송", iSendByte);
    }

    //해제
    WSACleanup();
    std::cout << "Hello World!\n";
}

