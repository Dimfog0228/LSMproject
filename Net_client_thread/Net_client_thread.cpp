#define _WINSOCK_DEPRECATED_NO_WARNINGS
//Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
#include <iostream>
#include <winsock2.h>
#include <thread>
const short port = 10020;

SOCKET sock;

void sendwork()
{
    while (1)
    {
        char buffer[256] = { 0, };
        int iLen = strlen(buffer);
        int iSendByte;

        ZeroMemory(buffer, sizeof(char) * 256);

        fgets(buffer, 256, stdin);

        if (buffer[0] == '\n') break;

        iLen = strlen(buffer);
        iSendByte = send(sock, buffer, iLen, 0);

        if (iSendByte == SOCKET_ERROR)
        {  break;  }

        printf("%d바이트를 전송했습니다", iSendByte);

    }
}
 

int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN socketInfo;
    socketInfo.sin_family = AF_INET;
    socketInfo.sin_addr.s_addr = inet_addr("192.168.0.8");
    socketInfo.sin_port = htons(port);
    int ret = connect(sock, (SOCKADDR*)&socketInfo, sizeof(socketInfo));
    //소켓에 연결할 곳의 정보를 넣고, 그 소켓에 연결을 시도
    if (ret == 0)//connect 정상 처리를 받으면
    {
        printf("서버 접속 ip=%s, Port:%d\n",
            inet_ntoa(socketInfo.sin_addr),
            ntohs(socketInfo.sin_port));
    }
    else
    {
        printf("서버 접속 불가 ip=%s, Port:%d\n",
            inet_ntoa(socketInfo.sin_addr),
            ntohs(socketInfo.sin_port));
    }

    std::thread sendthread(sendwork);
    sendthread.detach();

    while (1)
    {
        char recvbuf[256] = { 0, };
        int iRecvByte = recv(sock, recvbuf, 256, 0);
        if (iRecvByte == SOCKET_ERROR)
        {
            break;
        }
        printf("[받음]%s\n", recvbuf);
    }
   


   

    closesocket(sock);
    // )  윈속 해제    
    WSACleanup();
    std::cout << "Hello World!\n";
}
