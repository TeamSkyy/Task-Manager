#pragma once
typedef unsigned long UL;

class stack {

private:
	UL top; //ջ������
	enum{MAX=12};
	UL items[MAX];
public:
	stack();
	bool isEmpty()const;
	bool isFull()const;
	bool push(const UL& ref);
	bool pop(UL& ref);
};