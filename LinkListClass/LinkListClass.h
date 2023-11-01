#pragma once

class class_Box {
public:
	int a;
	class_Box* next;
	class_Box* prev;
	class_Box();
};

class class_Containner {
public:
	class_Box* head;
	class_Box* tail;
public:
	class_Containner();
	void addBox();
	void delBox();
};