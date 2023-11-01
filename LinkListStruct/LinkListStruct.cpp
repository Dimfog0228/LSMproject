//구조체를 넣으면 그 안의 값만을 이용하므로 단순한 구조에 적합하다. 
//구조체는 값 형식, 클래스는 참조 형식이므로 복사, 비교는 구조체가 우위에 있다.
// 디테일(관리) vs 속도(효율)
// 
// 
//c++에서는 구조체도 클래스와 거의 같은 기능들을 사용할 수 있으나, 값만 들었느냐 기능이 들었느냐를 구분해서 쓰는 것이 보기 좋을 듯


#include <iostream> // 이거 만든다고 구조체 안 만든시간까지 합치면 18시간 날림;;;

struct strt_Box{
	int iData;
	strt_Box* head;
	strt_Box* tail;
	strt_Box* next;
	strt_Box* prev;

	//구조체도 생성자, 함수를 가질 수 있다.
	strt_Box() {
		iData = 1, head = this, tail = this, next = nullptr, prev = nullptr;
	}
	/*strt_Box(int iData, strt_Box* head, strt_Box* tail, strt_Box* next, strt_Box* prev) : head(head), tail(tail), next(next), prev(prev) {
		iData = 0, head = this, tail = this, next = nullptr, prev = nullptr;
	}*/

	void addStrt_Box() { //인자값 넣기 싫어~ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
		tail->next = new strt_Box; //마지막 박스의 다음(공간)에 새로운 박스 생성
		tail->next->iData = tail->iData * 2; //새로운 박스의 데이터 초기화(마지막이었던 박스의 2배씩 되도록)
		tail->next->prev = tail; // 마지막 박스 주소 저장;
		tail = tail->next; //마지막 다음에 만든 박스가 마지막 박스
	}

	void addStrt_Box(int value) { //for문 쓰기 귀찮아~ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ

		for (int i = 0; i < value; i++) {
			tail->next = new strt_Box; //마지막 박스의 다음(공간)에 새로운 박스 생성
			tail->next->iData = tail->iData * 2; //새로운 박스의 데이터 초기화(마지막이었던 박스의 2배씩 되도록)
			tail->next->prev = tail; // 마지막 박스 주소 저장;
			tail = tail->next; //마지막 다음에 만든 박스가 마지막 박스
			std::cout << tail->iData <<std::endl;
		}
	}

	void  delStrt_Box() {
		if (tail!=nullptr) {
			tail = tail->prev;
			tail->next = nullptr;
			delete tail->next; //마지막 박스를 해제함
		}
	}

	void  delStrt_Box(int value) {
		for (int i = 0; i < value; i++) {
			if (tail != nullptr) {
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr; //마지막 박스를 해제함
			}
			else i = value;
		}
	}
	
};



int main() {

	strt_Box* strt_Box_A = new strt_Box;

	strt_Box_A->addStrt_Box(2);
	strt_Box_A->delStrt_Box();
	

	std::cout << "EndLine";

}