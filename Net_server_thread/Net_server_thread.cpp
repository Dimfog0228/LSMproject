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
	//u_long�� ���� ������ �ַ� ���� ���α׷��ֿ��� Ư�� �Լ� �� API���� �䱸�ϴ� ������ ������ ��ġ�� ����
	ioctlsocket(sock, FIONBIO, &on); //������ non block ���·� ����. 
	//FIONBIO�� ���� ���α׷��ֿ��� ���Ǵ� ����Դϴ�. �� ����� ������ ������ ���(non-blocking mode)�� �����ϱ� ���� ioctlsocket �Ǵ� ������ �Լ��� ����
	//������ ��忡�� ������ I/O �۾��� �Ϸ�� ������ ������� �ʰ� ��� ��ȯ
	//���Ͽ��� �����͸� �аų� �� �� ���ŷ(Blocking) ������ �����ϰ�, �ٸ� �۾��� �����ϴ� ���� ������ ����͸��ϰ� ���� �� ����

	SOCKADDR_IN socketInfo;
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = htonl(INADDR_ANY); //s_addr�� 32��Ʈ ������ ����Ǿ��ִ� ipv4�ּ�
	socketInfo.sin_port = htons(port);

	ret = bind(sock, (SOCKADDR*)&socketInfo, sizeof(socketInfo)); //��ȯ���� ���ε� ���� ���� ������
	if (ret == SOCKET_ERROR) return 1;
	ret = listen(sock, SOMAXCONN); //������ ���� ��� ���·� ���´�
	if (ret == SOCKET_ERROR) return 1;

	SOCKADDR_IN clientaddr;
	SOCKET clientsock; //Ŭ���̾�Ʈ �ּ� ������ ���� ����

	std::clock_t start = std::clock();//���� �ð��� �����ϰų� �۾��� �ҿ�� �ð��� ���
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
			printf("Ŭ���̾�Ʈ �߰��� ip=%s, Port:%d\n",
				inet_ntoa(clientaddr.sin_addr),
				ntohs(clientaddr.sin_port));
		}

		for (std::list<SOCKET>::iterator iter = userlist.begin(); iter != userlist.end(); ) 
		{// ó�� ��Ҹ� ����Ŵ(������ ����)   //������ ����� �ڸ� ����Ŵ(������ ����)

			SOCKET cSock = *iter;
			char buffer[256] = { 0, };
			int iRecvByte = recv(cSock, buffer, 256, 0);

			if (iRecvByte == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK 
				|| iRecvByte == 0) {
				
					iter = userlist.erase(iter);
					continue;
			}

			printf("[����]%s\n", buffer);
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
	// )  ���� ����


	WSACleanup();
	std::cout << "Hello World!\n";
}
