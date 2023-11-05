#pragma once

template<class TMP>
class class_Box {
public:
	TMP data;
	class_Box<TMP>* pNext;
	class_Box<TMP>* pPrev;
	class_Box()
	{
		pNext = nullptr;
		pPrev = nullptr;
	};
};

template<class TMP>
class class_Containner {
public:
	class_Box<TMP>* head = nullptr;
	class_Box<TMP>* tail = nullptr;
public:
	class_Containner();
	~class_Containner();
	class_Box<TMP>* NewBox(TMP data);

	void addFront(class_Box<TMP>* pNewBox);
	void addBack(class_Box<TMP>* pNewBox);
	
	void delFront();
	void delBack();
	void delAll();

	void showFront();
	void showBack();



};