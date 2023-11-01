#include <iostream>

int main() {
	class A {
		int a = 10;
	public:
		virtual void prt() {
			std::cout << 0;
		}
	};

	class B : public A {
		int b = 20;
		void prt() {
			std::cout << 1;
		}

	};


	class B Bcl;

	class A* Acl = &Bcl;

	Acl->prt();
}