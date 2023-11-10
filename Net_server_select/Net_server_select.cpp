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

	FD_SET readSet;
	FD_SET sendSet;
	FD_SET execptSet;
	timeval timeout;
	timeout.tv_sec = 1.0f;
	timeout.tv_usec = 0;

	while (1) {
		////select �Լ��� �̺�Ʈ�� �߻��� ������ �ĺ��ϴ� �������� ���ۿ� ���� �ڼ��� �����ϰڽ��ϴ�.

		//Ŀ�ο� ��ϵ� ���� Ȯ�� :

		//select �Լ��� ȣ��Ǹ� Ŀ���� ���� ��� ���ϵ��� Ȯ���ϰ� �ش� ���ϵ� �߿��� �̺�Ʈ�� �߻��� ���� �ĺ��մϴ�.
		//	�̺�Ʈ �߻� ���� Ȯ�� :

		//Ŀ���� �� ���Ͽ� ���� �б�, ����, ���� ��Ȳ�� ���� �̺�Ʈ ���θ� Ȯ���մϴ�.
		//	�̶�, fd_set�� ����� ��Ʈ���� ���� ������ ���¸� ȿ�������� Ȯ���մϴ�.
		//	�̺�Ʈ �߻� ���� �ĺ� :

		//�̺�Ʈ�� �߻��� ������ �ĺ��ϱ� ���� Ŀ���� fd_set ����ü�� ������ Ȯ���մϴ�.
		//	fd_set�� ��Ʈ�� ���·� �Ǿ� ������, ��Ʈ�� �ε����� ���� ��ũ���͸� ��Ÿ���ϴ�.
		//	���� �̺�Ʈ�� �߻��� ������ �ش� ��Ʈ�� 1�� ������ �ε����� �ĺ��� �� �ֽ��ϴ�.
		//	�̺�Ʈ �߻� ���� ��ȯ :

		//select �Լ��� �̺�Ʈ�� �߻��� ������ ���� ��ȯ�մϴ�.
		//	���� �̺�Ʈ�� �߻��� ���, FD_ISSET ��ũ�θ� ����Ͽ� � ���Ͽ��� �̺�Ʈ�� �߻��ߴ����� Ȯ���� �� �ֽ��ϴ�.
		//	�̷��� Ŀ���� select �Լ� ȣ�� �ÿ� ��ϵ� ���ϵ� �߿��� � ���Ͽ��� �̺�Ʈ�� �߻��ߴ����� ȿ�������� �ĺ��ϰ�,
		//�� ������ ����ڿ��� ��ȯ�մϴ�.���������� Ŀ���� ��Ʈ���� ����Ͽ� �̺�Ʈ �߻� ���θ� �����ϸ�, �̸� ���� ���� ���� ������ ȿ�������� ������ �� �ֽ��ϴ�.
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
				printf("Ŭ���̾�Ʈ ���� ip=%s, Port:%d\n",
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

					printf("[����]%s\n", buf);
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
	// )  ���� ����


	WSACleanup();
	std::cout << "Hello World!\n";
}
