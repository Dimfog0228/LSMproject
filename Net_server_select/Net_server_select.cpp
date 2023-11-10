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
	ioctlsocket(sock, FIONBIO, &on); 
	
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

	FD_SET readSet;
	FD_SET sendSet;
	FD_SET execptSet;
	timeval timeout;
	timeout.tv_sec = 1.0f;
	timeout.tv_usec = 0;

	while (1) {
		////select 함수가 이벤트가 발생한 소켓을 식별하는 내부적인 동작에 대해 자세히 설명하겠습니다.

		//커널에 등록된 소켓 확인 :

		//select 함수가 호출되면 커널은 감시 대상 소켓들을 확인하고 해당 소켓들 중에서 이벤트가 발생한 것을 식별합니다.
		//	이벤트 발생 여부 확인 :

		//커널은 각 소켓에 대해 읽기, 쓰기, 예외 상황에 대한 이벤트 여부를 확인합니다.
		//	이때, fd_set에 저장된 비트맵을 통해 소켓의 상태를 효율적으로 확인합니다.
		//	이벤트 발생 소켓 식별 :

		//이벤트가 발생한 소켓을 식별하기 위해 커널은 fd_set 구조체의 내용을 확인합니다.
		//	fd_set은 비트맵 형태로 되어 있으며, 비트의 인덱스는 소켓 디스크립터를 나타냅니다.
		//	따라서 이벤트가 발생한 소켓은 해당 비트가 1로 설정된 인덱스로 식별할 수 있습니다.
		//	이벤트 발생 여부 반환 :

		//select 함수는 이벤트가 발생한 소켓의 수를 반환합니다.
		//	만약 이벤트가 발생한 경우, FD_ISSET 매크로를 사용하여 어떤 소켓에서 이벤트가 발생했는지를 확인할 수 있습니다.
		//	이렇게 커널은 select 함수 호출 시에 등록된 소켓들 중에서 어떤 소켓에서 이벤트가 발생했는지를 효율적으로 식별하고,
		//이 정보를 사용자에게 반환합니다.내부적으로 커널은 비트맵을 사용하여 이벤트 발생 여부를 관리하며, 이를 통해 많은 수의 소켓을 효과적으로 감시할 수 있습니다.
		FD_ZERO(&readSet);
		FD_ZERO(&sendSet);
		FD_ZERO(&execptSet);

		FD_SET(sock, &readSet);

		for (std::list<SOCKET>::iterator iter = userlist.begin(); iter != userlist.end(); iter++) {

			FD_SET(*iter, &readSet);
			FD_SET(*iter, &sendSet);

		}

		ret = select(0, &readSet, &sendSet, NULL, &timeout);
		if (ret == SOCKET_ERROR) break;
		if (ret == 0)
		{
			continue;
		}


		//accept
		if (FD_ISSET(sock, &readSet))
		{
			int addlen = sizeof(clientaddr);
			clientsock = accept(sock, (SOCKADDR*)&clientaddr, &addlen);
			if (clientsock == SOCKET_ERROR)
			{
				int iError = WSAGetLastError();
				if (iError != WSAEWOULDBLOCK)
				{
					break;
				}
			}
			else
			{
				userlist.push_back(clientsock);
				printf("클라이언트 접속 ip=%s, Port:%d\n",
					inet_ntoa(clientaddr.sin_addr),
					ntohs(clientaddr.sin_port));
			}
		}





		//recv or Send
		for (std::list<SOCKET>::iterator iter = userlist.begin();
			iter != userlist.end();
			)
		{
			if (FD_ISSET(*iter, &readSet))
			{
				SOCKET cSock = *iter;
				char buf[256] = { 0, };
				int iRecvByte = recv(cSock, buf, 256, 0);
				if (iRecvByte == SOCKET_ERROR)
				{
					closesocket(*iter);
					iter =userlist.erase(iter);
					continue;
				}
				else
				{
					if (iRecvByte == 0 || iRecvByte == SOCKET_ERROR)
					{
						closesocket(*iter);
						iter = userlist.erase(iter);
						continue;
					}

					printf("[받음]%s\n", buf);
					int iLen = strlen(buf);

					for (std::list<SOCKET>::iterator iterSend = userlist.begin();
						iterSend != userlist.end();
						)
					{
						SOCKET cSock = *iterSend;

						int iSendByte = send(cSock, buf, iLen, 0);
						if (iSendByte == SOCKET_ERROR)
						{
							closesocket(*iterSend);
							iterSend = userlist.erase(iterSend);
							continue;
						}
						iterSend++;
					}
				}
			}

			iter++;
		}
	}

	closesocket(sock);
	// )  윈속 해제


	WSACleanup();
	std::cout << "Hello World!\n";
}
