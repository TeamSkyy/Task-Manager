#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>

using namespace std;
int main()
{
    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    vector<double> a2(4);
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    array<double, 4> a3 = { 3.14,2.72,1.62,1.41 };
    array<double, 4> a4;
    a4 = a3;

    cout << "a1[1]: " << a1[1] << " at "<<&a1[1]<<endl;
    cout << "a2[1]" << a2[1] << " at " << &a2[1] << endl;
    cout << "a3[1]" << a3[1] << " at " << &a3[1] << endl;
    cout << "a4[1]" << a4[1] << " at " << &a4[1] << endl;
    //Array�Ǿ�̬���飬����array�ͱ�׼���鶼����ջ���棬�ڴ��ַ��ӽ�

    a1[-2] = 20.2;//�൱��*(a1-2)=20.2����ǰ�ƶ�2��double����16λ
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl; 
    /*
        * a2[-2] = 5;
        a3[-2] = 2.5; //still allowed
    */
    
    //����ʹ�÷���at()�������ִ���
    a2.at(1) = 2.4;
    /*
    �����ű�ʾ���ͳ�Ա����at()�Ĳ�����ڣ�ʹ��at()ʱ������������
    �䲶��Ƿ�������������Ĭ�Ͻ��жϡ����ֶ�����Ĵ���������ʱ��
    ����
    */
    return 0;
}


