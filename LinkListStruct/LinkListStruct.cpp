//����ü�� ������ �� ���� ������ �̿��ϹǷ� �ܼ��� ������ �����ϴ�. 
//����ü�� �� ����, Ŭ������ ���� �����̹Ƿ� ����, �񱳴� ����ü�� ������ �ִ�.
// ������(����) vs �ӵ�(ȿ��)
// 
// 
//c++������ ����ü�� Ŭ������ ���� ���� ��ɵ��� ����� �� ������, ���� ������� ����� ������ĸ� �����ؼ� ���� ���� ���� ���� ��


#include <iostream> // �̰� ����ٰ� ����ü �� ����ð����� ��ġ�� 18�ð� ����;;;

struct strt_Box{
	int iData;
	strt_Box* head;
	strt_Box* tail;
	strt_Box* next;
	strt_Box* prev;

	//����ü�� ������, �Լ��� ���� �� �ִ�.
	strt_Box() {
		iData = 1, head = this, tail = this, next = nullptr, prev = nullptr;
	}
	/*strt_Box(int iData, strt_Box* head, strt_Box* tail, strt_Box* next, strt_Box* prev) : head(head), tail(tail), next(next), prev(prev) {
		iData = 0, head = this, tail = this, next = nullptr, prev = nullptr;
	}*/

	void addStrt_Box() { //���ڰ� �ֱ� �Ⱦ�~��������������������������
		tail->next = new strt_Box; //������ �ڽ��� ����(����)�� ���ο� �ڽ� ����
		tail->next->iData = tail->iData * 2; //���ο� �ڽ��� ������ �ʱ�ȭ(�������̾��� �ڽ��� 2�辿 �ǵ���)
		tail->next->prev = tail; // ������ �ڽ� �ּ� ����;
		tail = tail->next; //������ ������ ���� �ڽ��� ������ �ڽ�
	}

	void addStrt_Box(int value) { //for�� ���� ������~����������������������������������������������������������������������������������

		for (int i = 0; i < value; i++) {
			tail->next = new strt_Box; //������ �ڽ��� ����(����)�� ���ο� �ڽ� ����
			tail->next->iData = tail->iData * 2; //���ο� �ڽ��� ������ �ʱ�ȭ(�������̾��� �ڽ��� 2�辿 �ǵ���)
			tail->next->prev = tail; // ������ �ڽ� �ּ� ����;
			tail = tail->next; //������ ������ ���� �ڽ��� ������ �ڽ�
			std::cout << tail->iData <<std::endl;
		}
	}

	void  delStrt_Box() {
		if (tail!=nullptr) {
			tail = tail->prev;
			tail->next = nullptr;
			delete tail->next; //������ �ڽ��� ������
		}
	}

	void  delStrt_Box(int value) {
		for (int i = 0; i < value; i++) {
			if (tail != nullptr) {
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr; //������ �ڽ��� ������
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