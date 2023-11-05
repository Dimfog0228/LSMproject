#include <iostream>

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	//int& getCents() { return m_cents; }
};

//void operator + (const Cents& c1, const Cents& c2)
//{
//	// cout << c1.m_cents + c2.m_cents << endl;  전역 함수(클래스 외부)이므로 private 멤버를 사용할 수 없다.
//
//	std::cout << c1.getCents() + c2.getCents() << std::endl;
//}

int main()
{
	Cents cents1(5);
	Cents cents2(7);

	std::cout << cents1.getCents() + cents2.getCents() << std::endl;

	//cents1 + cents2;   // 오버로딩한 + 호출
}