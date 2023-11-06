#include "LinkListClass.h"
#include <iostream>
	template<class TMP>
	class_Containner<TMP>::class_Containner() {
		head = nullptr;
		tail = nullptr;
	};

	template<class TMP>
	class_Containner<TMP>::~class_Containner() {
		void delAll();
		std::cout << "컨테이너 해제" << std::endl;
	};

	template<class TMP>
	class_Box<TMP>* class_Containner<TMP>::NewBox(TMP data) {
		class_Box<TMP>* pNewBox = new class_Box<TMP>;
		pNewBox->data = data;
		return pNewBox;
	};


	template<class TMP>
	void class_Containner<TMP>::addFront(class_Box<TMP>* pNewBox) {
		class_Box<TMP>* newBox = pNewBox;
		if (tail == nullptr) tail = newBox;
		if (head != nullptr) head->pPrev = newBox;
		newBox->pNext = head;
		head = newBox;
	};

	template<class TMP>
	void class_Containner<TMP>::addBack(class_Box<TMP>* pNewBox) {
		class_Box<TMP>* newBox = pNewBox;
		if (head == nullptr) head = newBox;
		if (tail != nullptr) tail->pNext = newBox;
		newBox->pPrev = tail;
		tail = newBox;
	}

	template<class TMP>
	void class_Containner<TMP>::delFront() {
		if (head != nullptr) {
			if (head != tail) {
				class_Box<TMP>* temp = head;
				head = head->pNext;
				head->pPrev = nullptr;
				delete temp;
				temp = nullptr;
			}
			else {
				delete head;
				tail = nullptr;
				head = nullptr;
			}
		}
	}

	template<class TMP>
	void class_Containner<TMP>::delBack() {
		if (tail != nullptr) {
			if (head != tail) {
				class_Box<TMP>* temp = tail;
				tail = tail->pPrev;
				tail->pNext = nullptr;
				delete temp;
				temp = nullptr;
			}
			else {
				delete tail;
				head = nullptr;
				tail = nullptr;
			}
		}
	}


	template<class TMP>
	void class_Containner<TMP>::delAll() {

		class_Box<TMP>* Box = head;
		while (Box != nullptr)
		{
			class_Box<TMP>* temp = Box;
			Box = Box -> pNext;
			delete temp;
		}

		head = nullptr;
		tail = nullptr;
	
	};

	template<class TMP>

	void class_Containner<TMP>::showFront() {
		for (class_Box<TMP>* Box = head; Box != nullptr; Box = Box->pNext)
		{
			std::cout << Box->data << std::endl;
		}
	};

	template<class TMP>
	void class_Containner<TMP>::showBack() {
		for (class_Box<TMP>* Box = tail; Box != nullptr; Box = Box->pPrev)
		{
			std::cout << Box->data << std::endl;
		}
	};
