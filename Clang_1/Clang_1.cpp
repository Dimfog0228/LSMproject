#include <iostream>

int stack[5];
int nowWhere=0;

void putin(int num) {
	for (int i = 0; i < num; i++) {
		if (nowWhere < 5) {
			stack[nowWhere] = nowWhere + 1;
			if(nowWhere<4)nowWhere++;
		}
		else { std::cout << "breakOver"; break; }
	}
}

void takeout(int num) {
	for (int i = 0; i < num; i++) {
		if (nowWhere >= 0) {
			std::cout << stack[nowWhere];
			stack[nowWhere] = NULL;
			if(nowWhere>0)nowWhere--;
		}
		else { std::cout << "breakUnder"; break; }
	}
}

int main() {

	putin(5);
	takeout(5);



}
