//#include<iostream>
//class Action {
//	int a;
//public:
//	Action(int i = 0) :a(i) {}
//	int val() const { return a; }
//	virtual void f(char ch)const final{ std::cout << val() << ch << "\n"; };
//};
//class Bingo :public Action {
//public:
//	Bingo(int i = 0) :Action(i) {};
//	virtual void f(char* ch) const override{ std::cout << val() << ch << "!\n"; }
//};
//
//int main() {
//	Bingo b;
//	//b.f('@'); invalid
//
//}