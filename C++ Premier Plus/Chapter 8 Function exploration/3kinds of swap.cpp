//#include <iostream>
//using namespace std;
//struct job {
//	char name;
//	int num;
//	double price;
//};
//
//template<typename any>
//void swap(any& a, any& b);  //��ʽʵ����
//
//template <>
//void swap(job& j1, job& j2); //��ʽ���廯
//
//template void swap<char>(char& a, char& b); //��ʽʵ����
//
//
//int main() {
//
//	return 0;
//}
//
////��ʽʵ����
//template<typename any>
//void swap(any& a, any& b) {
//	any temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
////��ʽ���廯
//template < > 
//void swap(job &j1, job &j2) {
//	char temp;
//	temp=j1.name;
//	j1.name = j2.name;
//	j2.name = temp;
//	
//	double temp2;
//	temp2 = j1.price;
//	j1.price = j2.price;
//	j2.price = temp2;
//}
//
//template void swap<char>(char& a, char& b);