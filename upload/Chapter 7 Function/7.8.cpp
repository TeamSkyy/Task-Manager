//#include <iostream>
//using namespace std;
//const int ArSize = 8;
//int sum_arr(int* begin, int* end);
//int main() {
//	int cookies[ArSize] = { 10,20,30,40,50,60,70,80 };
//	int result;
//	result = sum_arr(cookies, cookies+ArSize);//���õ��ǵ�ַ����������
//	return 0;
//}
//
//int sum_arr(const int* begin, const int *end) {
//	int result=0;
//	const int* pt; //const int* pt����˼���� pt ��һ��ָ�� const int ��ָ�롣
//	//����Ըı�ָ�� pt ����������ָ��ͬ��λ�ã������㲻��ͨ�� pt �޸���ָ���������ֵ��
//	for (pt=begin; pt !=end; pt++) {
//		result += *pt;
//	}
//
//	return result;
//}