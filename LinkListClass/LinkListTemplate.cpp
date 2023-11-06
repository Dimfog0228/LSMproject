#include <iostream>
#include "LinkListClass.cpp"

int	a = 10;
//float b = 0.5f;

int main() {

	if (a == 10) {
		class_Containner<int> A;
		A.addBack(A.NewBox(a));
		A.addBack(A.NewBox(20));
		A.addBack(A.NewBox('a')); //10 20 97
		A.showFront();
		A.showBack();
		//A.delAll();
		std::cout << "EndLine";
	}



}