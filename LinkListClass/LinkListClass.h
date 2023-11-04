#pragma once

template<class TMP>
class class_Box {
public:
	TMP a;
	class_Box<TMP>* next;
	class_Box<TMP>* prev;
	class_Box();
};

template<class TMP>
class class_Containner {
public:
	class_Box<TMP>* head;
	class_Box<TMP>* tail;
public:
	class_Containner();
	void addBox();
	void delBox();
};