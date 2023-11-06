#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)

int main() {

	WSADATA wsadata; //윈속 초기화에 필요한 값들을 가진 구조체
	WSAStartup(MAKEWORD(2, 2), &wsadata); //윈속 초기화(버전,상태 설정), 솔직히 워드 받아와서 버전값 넣는거 빼고 뭔지 모르겠음..ALPPHANOH?


	//**** WSADATA 내용
	/*printf("%#x\n", wsadata.wHighVersion);
	printf("%#x\n", wsadata.wVersion);
	printf("%s\n", wsadata.szDescription);
	printf("%s\n", wsadata.szSystemStatus);
	printf("%d\n", wsadata.iMaxSockets);
	printf("%d\n", wsadata.iMaxUdpDg);   
	*/


	//**** 리틀 엔디안 / 빅 엔디안 변환
	//unsigned int idata = 256;
	//unsigned short sdata = 17;
	//printf("host:%#x   network:%#x\n", idata, htonl(idata)); // host to network Int(4바이트)
	//printf("host:%#x   network:%#x\n", sdata,htons(sdata)); // host to network short(2바이트)      

	//**** IPv4변환 
	//inet_addr; //문자열 주소 표현(10진)을 4바이트 표현(32비트)으로 변환
	//inet_ntoa; //4바이트 주소를 문자열 주소(아스키) 표현으로 변환

	IN_ADDR addr;
	addr.s_addr = htonl(12 << 24 | 34 << 16 | 56 << 8 | 78); //비트 연산자를 이용하여 메모리를 밀어내고, 비트 or 연산자를 이용하여 32비트 주소를 채움. ||는 논리 연산
	//빅 엔디안 4바이트 
	printf("%s\n", inet_ntoa(addr)); //네트워크 주소를 아스키 문자로 변환 //00001100 00100010 00111000 01001110 --->  12.34.56.78
	
	u_int naddr = inet_addr("111.111.11.0");//111.111.11.0을 32비트로 변환
	u_int haddr = ntohl(naddr); //32비트로 변환한 것을 network to host Int로 변환
	//printf("%d", haddr);전체 이어진 비트가 나오므로 큰 수가 출력됨
	printf("%d.%d.%d.%d\n", haddr >> 24, (u_char)(haddr >> 16), (u_char)(haddr >> 8), (u_char)haddr);

	/*inet_addr은 다소 낡은 방법으로 간주되며 
	주소 해상도에 대해 더 유연하고 더 나은 오류 처리를 제공하는 
	inet_pton(IPv4 / IPv6 주소 변환)과 같은 더 현대적인 함수나 getaddrinfo와 같은 라이브러리를 사용하는 것이 권장됩니다.*/

	WSACleanup();

}