//#include <iostream>
//using namespace std;
//char* buildstr(char str, int n);
//int main() {
//	int times;
//	char ch;
//	cout << "please enter the letter: ";
//	cin >> ch;
//	cout << "pleae enter how many times you want to repeat: ";
//	cin >> times;
//	char *str=buildstr(ch, times);
//	cout << str << endl;
//	delete[]str; //ֻ��ɾ�����ڴ�ռ䣬û��ɾ��ָ��
//
//	return 0;
//}
//
//char* buildstr(char str, int n) {
//	char* arr = new char[n+1]; //����һ��'\n'
//	arr[n] = '\0';
//	while (n-->0) { //����n�жϣ��ж�������������n--
//		arr[n] = str; //��ʱ���ֵ�Ѿ���n-1��
//	}
//	return arr;
//}