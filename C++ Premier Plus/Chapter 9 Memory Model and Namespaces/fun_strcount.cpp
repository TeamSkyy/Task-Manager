#include <iostream>
using namespace std;
void strcount(const char* str) {
	int count=0;
	static int total=0; //һ��ʼ�ͳ�ʼ��Ϊ0���ڴ�ʼ�մ��ڣ�ֱ���������
	while (*str++) {
		count++;
		
	}
	total += count;
	cout << "you have " << count << endl;
	cout << "total character is : " << total << endl;
}