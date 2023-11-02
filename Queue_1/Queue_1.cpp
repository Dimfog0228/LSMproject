/// 구조체 Queue
#include <iostream>
#define MAX 10

struct energyCapsule {
	
	char type = 'A';
	int regen = 1;
	float time = 0.0f;

};

energyCapsule* energyBox[MAX];
int remain = 0;
int consuming = 0;
int charging = 0;

void recharge(int repeat) {
	for(int i=0;i<repeat;i++)
	{
		energyCapsule* newCapsule = new energyCapsule;
		if (remain < MAX) {
			
			newCapsule->type = 65 + charging;
			newCapsule->regen = charging + 1;
			newCapsule->time = 0.5f*(10-charging);
		
			energyBox[charging] = newCapsule;//이동 세그멘틱;

			std::cout << energyBox[charging] << "충전됨" << std::endl;
			charging = charging + 1 % MAX;
			remain++;
		}
		else { 
			std::cout << "Full";
			delete newCapsule;
			newCapsule = nullptr;
			break;
		}
		newCapsule = new energyCapsule;
		delete newCapsule;
		
	}
};
//박스 내용을 출력하려면 연산자 오버로드 해야될듯.
void consume(int repeat) {
	for (int i = 0; i < repeat; i++) {
		if (remain > 0) {
			std::cout << energyBox[consuming] << "소모됨" << std::endl;

			delete energyBox[consuming];
			energyBox[consuming] = nullptr;

			remain--;
			consuming = consuming+1 % MAX;
		}
		else {
			std::cout << "Empty";
			break;
		}
	}
};

void throwEbox() {
	std::cout << "Energy in the HOLE!";
	remain	= 0;
	charging = 0;
	consuming = 0;
	for (int i = 0; i < MAX; i++) {
		int a = 0;
		if (energyBox[a] != nullptr) {
			delete energyBox[a];
			energyBox[a] = nullptr;
		}
		++a;
	}
	
};

void checkEbox() {

};


int main()
{
	recharge(1);
	consume(1);

}
