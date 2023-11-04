#include "LinkListClass.h"
/// <summary>
/// ///
/// </summary>

	template<class TMP>
	class_Box<TMP>::class_Box() {
		next = nullptr;
		prev = nullptr;
		a = 1;
	}

	template<class TMP>
	class_Containner<TMP>::class_Containner() {
		head = nullptr;
		tail = nullptr;
	};

	template<class TMP>
	void class_Containner<TMP>::addBox() {
		class_Box* newBox= new class_Box;
		if (head == nullptr) head = newBox;
		if (tail != nullptr) tail->next = newBox;
		newBox->prev = tail;
		tail = newBox;
	}

	template<class TMP>
	void class_Containner<TMP>::delBox() {
		
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


