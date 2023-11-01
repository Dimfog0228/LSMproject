#include "LinkListClass.h"
/// <summary>
/// ///
/// </summary>


	class_Box::class_Box() {
		next = nullptr;
		prev = nullptr;
		a = 1;
	}
	class_Containner::class_Containner() {
		head = nullptr;
		tail = nullptr;
	};

	void class_Containner::addBox() {
		class_Box* newBox= new class_Box;
		if (head == nullptr) head = newBox;
		if (tail != nullptr) tail->next = newBox;
		newBox->prev = tail;
		tail = newBox;
	}
	void class_Containner::delBox() {
		
		if (tail != nullptr) {
			if (head != tail) {
				tail = tail->prev;
				tail->next = nullptr;
			}
			else {
				tail = nullptr;
				head = nullptr;
			}
		}
	}


