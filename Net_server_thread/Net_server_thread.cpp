#define _WINSOCK_DEPRECATED_NO_WARNINGS
//Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
#include <WinSock2.h>
#include <iostream>
#include <list>
#pragma comment(lib,"ws2_32")
const short port = 10020;
int time = 0;

std::list<SOCKET> userlist;

int main()
{
	WSADATA wsadata;
	int ret = 0;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret != 0) return 1;

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	u_long on = TRUE;
	//u_long이 사용된 이유는 주로 소켓 프로그래밍에서 특정 함수 및 API에서 요구하는 데이터 형식의 일치성 때문
	ioctlsocket(sock, FIONBIO, &on); //소켓을 non block 상태로 만듦. 
	//FIONBIO는 소켓 프로그래밍에서 사용되는 상수입니다. 이 상수는 소켓을 비차단 모드(non-blocking mode)로 설정하기 위해 ioctlsocket 또는 유사한 함수에 전달
	//비차단 모드에서 소켓은 I/O 작업이 완료될 때까지 대기하지 않고 즉시 반환
	//소켓에서 데이터를 읽거나 쓸 때 블로킹(Blocking) 동작을 방지하고, 다른 작업을 수행하는 동안 소켓을 모니터링하고 싶을 때 유용

	SOCKADDR_IN socketInfo;
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = htonl(INADDR_ANY); //s_addr은 32비트 정수로 저장되어있는 ipv4주소
	socketInfo.sin_port = htons(port);

	ret = bind(sock, (SOCKADDR*)&socketInfo, sizeof(socketInfo)); //반환값은 바인딩 성공 여부 정수값
	if (ret == SOCKET_ERROR) return 1;
	ret = listen(sock, SOMAXCONN); //소켓을 수신 대기 상태로 놓는다
	if (ret == SOCKET_ERROR) return 1;

	SOCKADDR_IN clientaddr;
	SOCKET clientsock; //클라이언트 주소 정보를 가진 소켓

	std::clock_t start = std::clock();//실행 시간을 측정하거나 작업에 소요된 시간을 계산
	printf("wake up server\n");

	while (1) {

		int addrlen = sizeof(clientaddr);
		clientsock = accept(sock, (SOCKADDR*)&clientaddr, &addrlen);

		if (clientsock == SOCKET_ERROR) {

			int Error = WSAGetLastError();
			if (Error != WSAEWOULDBLOCK)break;

		}
		else {
			userlist.push_back(clientsock);
			printf("클라이언트 추가됨 ip=%s, Port:%d\n",
				inet_ntoa(clientaddr.sin_addr),
				ntohs(clientaddr.sin_port));
		}

		for (std::list<SOCKET>::iterator iter = userlist.begin(); iter != userlist.end(); ) 
		{// 처음 요소를 가리킴(내용이 있음)   //마지막 요소의 뒤를 가리킴(내용이 없음)

			SOCKET cSock = *iter;
			char buffer[256] = { 0, };
			int iRecvByte = recv(cSock, buffer, 256, 0);

			if (iRecvByte == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK 
				|| iRecvByte == 0) {
				
					iter = userlist.erase(iter);
					continue;
			}

			printf("[받음]%s\n", buffer);
			int iLen = strlen(buffer);

			for (std::list<SOCKET>::iterator iterSend = userlist.begin();
				iterSend != userlist.end();
				iterSend++)
			{
				SOCKET cSock = *iterSend;

				int iSendByte = send(cSock, buffer, iLen, 0);
				if (iSendByte == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK)
				{break;}
			}

			iter++;
		}
	}

	closesocket(sock);
	// )  윈속 해제


	WSACleanup();
	std::cout << "Hello World!\n";
}
