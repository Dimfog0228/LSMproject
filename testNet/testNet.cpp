#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)

int main() {

	WSADATA wsadata; //���� �ʱ�ȭ�� �ʿ��� ������ ���� ����ü
	WSAStartup(MAKEWORD(2, 2), &wsadata); //���� �ʱ�ȭ(����,���� ����), ������ ���� �޾ƿͼ� ������ �ִ°� ���� ���� �𸣰���..ALPPHANOH?


	//**** WSADATA ����
	/*printf("%#x\n", wsadata.wHighVersion);
	printf("%#x\n", wsadata.wVersion);
	printf("%s\n", wsadata.szDescription);
	printf("%s\n", wsadata.szSystemStatus);
	printf("%d\n", wsadata.iMaxSockets);
	printf("%d\n", wsadata.iMaxUdpDg);   
	*/


	//**** ��Ʋ ����� / �� ����� ��ȯ
	//unsigned int idata = 256;
	//unsigned short sdata = 17;
	//printf("host:%#x   network:%#x\n", idata, htonl(idata)); // host to network Int(4����Ʈ)
	//printf("host:%#x   network:%#x\n", sdata,htons(sdata)); // host to network short(2����Ʈ)      

	//**** IPv4��ȯ 
	//inet_addr; //���ڿ� �ּ� ǥ��(10��)�� 4����Ʈ ǥ��(32��Ʈ)���� ��ȯ
	//inet_ntoa; //4����Ʈ �ּҸ� ���ڿ� �ּ�(�ƽ�Ű) ǥ������ ��ȯ

	IN_ADDR addr;
	addr.s_addr = htonl(12 << 24 | 34 << 16 | 56 << 8 | 78); //��Ʈ �����ڸ� �̿��Ͽ� �޸𸮸� �о��, ��Ʈ or �����ڸ� �̿��Ͽ� 32��Ʈ �ּҸ� ä��. ||�� �� ����
	//�� ����� 4����Ʈ 
	printf("%s\n", inet_ntoa(addr)); //��Ʈ��ũ �ּҸ� �ƽ�Ű ���ڷ� ��ȯ //00001100 00100010 00111000 01001110 --->  12.34.56.78
	
	u_int naddr = inet_addr("111.111.11.0");//111.111.11.0�� 32��Ʈ�� ��ȯ
	u_int haddr = ntohl(naddr); //32��Ʈ�� ��ȯ�� ���� network to host Int�� ��ȯ
	//printf("%d", haddr);��ü �̾��� ��Ʈ�� �����Ƿ� ū ���� ��µ�
	printf("%d.%d.%d.%d\n", haddr >> 24, (u_char)(haddr >> 16), (u_char)(haddr >> 8), (u_char)haddr);

	/*inet_addr�� �ټ� ���� ������� ���ֵǸ� 
	�ּ� �ػ󵵿� ���� �� �����ϰ� �� ���� ���� ó���� �����ϴ� 
	inet_pton(IPv4 / IPv6 �ּ� ��ȯ)�� ���� �� �������� �Լ��� getaddrinfo�� ���� ���̺귯���� ����ϴ� ���� ����˴ϴ�.*/

	WSACleanup();

}