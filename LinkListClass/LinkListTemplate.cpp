#include <iostream>
#include "LinkListClass.cpp"

int	a = 10;
//float b = 0.5f;

int main() {

	if (a == 10) {
		class_Containner<int> A;
		A.addBack(A.NewBox(a));
		A.addBack(A.NewBox(20));
		A.addBack(A.NewBox('a'));
		A.delBack();
		A.delFront();
		std::cout << "EndLine";
	}



}