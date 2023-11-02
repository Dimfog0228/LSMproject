// Clang_0.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{	

    int a = 1; //컴파일 과정에서 &a, &b....등 변수들의 메모리 주소가 할당됨
    std::cout << a << std::endl;
    a = 2;
    std::cout << a << std::endl;
    a = 3;
    std::cout << a << std::endl;
    int b = 4;
    int c = 5;
    int* d = nullptr;
    d = &a;     std::cout << *d << std::endl;
    d = &b;     std::cout << *d << std::endl;
    d = &c;     std::cout << *d << std::endl;
    std::cout << &d << std::endl; //d의 주소
    std::cout << d << std::endl; //d의 값(주소)
    std::cout << *d << std::endl; //d의 값(주소)의 값


    int num[5];
    num[0] = 1; num[1] = 3; num[2] = 5; num[3] = 7; num[4] = 9;
    //int num[] = { 1, 3, 5, 7, 9 }; 과 같음
    // 포인터 변수 선언(동일한 데이터형의 변수의 주소를 저장한다.)
    int* ptr0 = &num[0];
    int* ptr1 = &num[1];
    int* ptr2 = &num[2];
    int* ptr3 = &num[3];
    int* ptr4 = &num[4];
    int* ptr5 = num + 0;// &num[0]
    int* ptr6 = num + 1;// &num[1]
    int* ptr7 = num + 2;// &num[2]
    int* ptr8 = num + 3;// &num[3]
    int* ptr9 = num + 4;// &num[4]
    //int ptr10 = *(num + 0);// num[0]
    //int ptr11 = *(num + 1);// num[1]
    //int ptr12 = *(num + 2);// num[2]
    //int ptr13 = *(num + 3);// num[3]
    //int ptr14 = *(num + 4);// num[4]
}

