//#include <iostream>
//using namespace std;
//void swapr(int& a, int& b);
//void swapp(int* a, int* b);
//void swapv(int a, int b);
//int main() {
//	int wallet1 = 100, wallet2 = 350;
//	cout << "wallet1: " << wallet1 << " wallet2: " << wallet2 << endl;
//	swapr(wallet1, wallet2);
//	cout << "wallet1: " << wallet1 << " wallet2: " << wallet2 << endl;
//	swapp(&wallet1, &wallet2);
//	cout << "wallet1: " << wallet1 << " wallet2: " << wallet2<<endl;
//	swapv(wallet1, wallet2);
//	cout << "wallet1: " << wallet1 << " wallet2: " << wallet2<< endl;
//	return 0;
//}
////�����ô���
//void swapr(int& a, int& b) {
//	int temp;;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
////��ָ�봫��
//void swapp(int* a, int* b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
////��ֵ����
//void swapv(int a, int b) {
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//	//������ֵ
//}