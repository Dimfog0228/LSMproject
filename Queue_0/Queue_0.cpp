#include <iostream>
#include <windows.h>
//#include <stdlib.h>
#define MAX 30

int nowin = 0;
int nowout = 0;
int occup = 0;

struct Ques {
	int facnum;
	char name;
};
Ques WP[MAX];
void give() {
	
	//std::cin >> WP[nowin].facnum;
	//std::cout << nowin+1 << "번째 작업 입력" << std::endl;
	WP[nowin].facnum+=nowin+1;
	WP[nowin].name = 65 + rand() % 26;
	nowin=++nowin%MAX;
	++occup;
	
};

void take() {

	std::cout << nowout+1 <<"번째 작업 출력" << WP[nowout].facnum << " - " << WP[nowout].name << std::endl;
	nowout=++nowout%MAX;
	--occup;
};

int main() {
	
	srand(time(NULL));

	for (int i = 1; i <= MAX; i++) {
		give();

	}
	for (int i = MAX; i > 0; i--) {
		take();
	}
	
	
	
	



	return 0;
}