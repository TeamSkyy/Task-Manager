#include <iostream>
using namespace std;

int main() {

	return 0;
}

template <typename t1,typename t2>
void fun1(t1 x, t2 y) {
	typedef decltype(x + y) xytype;
	xytype xpy = x + y;
	xytype arr[10];
	xytype& rxy = arr[2];
	int xx = 66;
	decltype(xx) m; //m��int����
	decltype((xx)) n=m; //n��int����������
}

template <typename t1,typename t2>  //C++11 ���÷�������
auto special(t1 var1, t2 var2)->decltype(var1+var2) {
	return var1 + var2;
}