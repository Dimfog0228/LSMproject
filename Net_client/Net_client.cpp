#define _WINSOCK_DEPRECATED_NO_WARNINGS
//Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
#include <iostream>
#include <winsock2.h>
const short port = 10020;

int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
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


    char buffer[256] = { 0, };
    int iLen = strlen(buffer);//buffer 배열에 저장된 문자열의 길이를 계산
    int iSendByte;
    while (1)
    {
        ZeroMemory(buffer, sizeof(buffer));
        //buffer 배열을 256바이트 크기로 초기화하여 모든 요소를 0으로 설정합니다. //memset
        fgets(buffer, 256, stdin);
        //fgets 함수는 C 언어에서 사용자 입력을 표준 입력(stdin)에서 읽어와서 문자열로 저장하는 함수
        if (buffer[0] == '\n') break;
        iLen = strlen(buffer);//buffer 배열에 저장된 문자열의 길이를 계산
        iSendByte = send(sock, buffer, iLen, 0); //send 함수는 송신에 성공하면 송신한 바이트 수를 반환하며, 실패하면 -1을 반환
        printf("%d바이트를 전송했습니다\n", iSendByte);

        char recvbuffer[256] = { 0, }; //다른 곳에서 보낸 걸 받아봄
        int iRecvByte = recv(sock, recvbuffer, 256, 0);
        printf("[받음]%s\n", recvbuffer);
    }
    closesocket(sock);
    // )  윈속 해제    
    WSACleanup();
    std::cout << "Hello World!\n";
}
