#define _WINSOCK_DEPRECATED_NO_WARNINGS
//Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
#include <WinSock2.h>
#include <iostream>
#pragma comment(lib,"ws2_32")
const short port = 10020;

int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN socketInfo;
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = inet_addr("192.168.0.8"); //s_addr은 32비트 정수로 저장되어있는 ipv4주소
	socketInfo.sin_port = htons(port);

	int ret = bind(sock, (SOCKADDR*)&socketInfo, sizeof(socketInfo)); //반환값은 바인딩 성공 여부 정수값
	ret = listen(sock, SOMAXCONN); //소켓을 수신 대기 상태로 놓는다

	SOCKADDR_IN clientaddr;
	SOCKET clientsock; //클라이언트 주소 정보를 가진 소켓

	printf("wake up server\n");

	while (1) {
		
		int addrlen = sizeof(clientaddr);
		clientsock = accept(sock, (SOCKADDR*)&clientaddr, &addrlen);
		printf("connect detected : ip:%s, port:%d\n",
			inet_ntoa(clientaddr.sin_addr),//네트워크 비트 >> 아스키 비트
			ntohs(clientaddr.sin_port)); //네트워크 비트 >> 호스트 비트(short)
		while (1) {

			char buffer[256] = { 0, };//이 코드는 256바이트 크기의 문자 배열을 만들고, 배열의 모든 요소를 0으로 초기화하여 널 종료 문자열('\0')로 만든 것입니다.
			//이 배열은 문자열을 저장하거나 다루는 데 사용될 수 있으며, 초기화로 인해 문자열이 비어 있습니다.

			int iRecvByte = recv(clientsock, buffer, 256, 0);
			//소켓으로부터 데이터를 읽어오는 함수로, 주어진 소켓 (clientsock)에서 최대 256바이트의 데이터를 읽어 buffer 배열에 저장하도록 시도

			if (iRecvByte == 0) break; // 정상종료
			if (iRecvByte == SOCKET_ERROR) break;// 비정상 종료
			printf("수신: %s\n", buffer);


		}

		closesocket(clientsock);
		printf("클라이언트 접속해제 ip=%s, Port:%d\n",
			inet_ntoa(clientaddr.sin_addr),
			ntohs(clientaddr.sin_port));

	}

	closesocket(sock);
	// )  윈속 해제


	WSACleanup();
	std::cout << "Hello World!\n";
}

