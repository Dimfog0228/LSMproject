// Clang_0.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{	
	int a = 10;
	int b = 20;

	int* ptr;
	int* ptr2;

	ptr = &a;
	ptr2 = &b;


	std::cout << (ptr) << std::endl;
}

