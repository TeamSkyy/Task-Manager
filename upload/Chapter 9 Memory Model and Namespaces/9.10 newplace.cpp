//#include <iostream>
//#include <new>
//using namespace std;
//const int BUF = 512;
//const int N = 5;
//char buffer[BUF];//������
//
//int main() {
//	double* pd1, * pd2;
//	int i;
//	cout << "Calling new and placement new: \n";
//	pd1 = new double[N];
//	pd2 = new(buffer) double[N];
//	for (i = 0; i < N; i++) {
//		pd2[i] = pd1[i] = 100 + 20.0 * i;
//	}
//	cout << "Memory addresses:\n" << " heap: " << pd1 << " static: "
//		<< &buffer << endl;
//	
//	for (i = 0; i < N; i++) {
//		cout << pd1[i] << " at " << &pd1[i] <<
//			" " << pd2[i] << " at " << &pd2[i] << endl;
//	}
//
//	cout << "Calling new and placement new a second time: \n";
//	double* pd3, * pd4;
//	pd3 = new double[N];
//	pd4 = new(buffer)double[N];
//	for (i = 0; i < N; i++) {
//		pd3[i] = pd4[i] = 100 + 40.0 * i;
//	}
//
//	for (i = 0; i < N; i++) {
//		cout << pd3[i] << " at " << &pd3[i] <<
//			" " << pd4[i] << " at " << &pd4[i] << endl;
//	}
//
//	cout << "Calling new and placement new a third time: \n";
//	delete[]pd1;
//	pd1 = new double[N];
//	pd2 = new(buffer+N*sizeof(double)) double[N];
//	for (i = 0; i < N; i++) {
//		pd2[i] = pd1[i] = 100 + 60.0 * i;
//	}
//
//
//	for (i = 0; i < N; i++) {
//		cout << pd1[i] << " at " << &pd1[i] <<
//			" " << pd2[i] << " at " << &pd2[i] << endl; //�ڶ��ε�ֵ��������ǰ���ڴ�����
//	}
//	delete[]pd1;
//	delete[]pd3;
//	//buffer�Ǿ�̬�ռ䣬����Ҫ�ͷſռ䣬delete���ͷſռ䲻��ɾ��ָ��
//
//	return 0;
//}