//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//union once4all {
//    int int_val;
//    long long_val;
//    double double_val;
//}; //�����壬ֻ����һ�����ݣ��ڴ�Ϊ����һ����������
//
//struct widget {
//    char brand[20];
//    int type;
//    union id {             //����Ƕ��
//        long id_num;
//        char id_cahr[20];
//    }id_val;//ʵ��
//};
//
//int main()
//{
//    once4all pail;
//    pail.int_val = 15;
//    cout << pail.int_val << endl;
//    pail.double_val = 1.38;
//    cout << pail.double_val;
//
//    
//
//    widget prize;
//    prize.type = 20;
//    if (prize.type == 1) {
//        cin >> prize.id_val.id_num;
//    }
//    else {
//        cin >> prize.id_val.id_cahr;      //����������������ֱ��prize.id_val
//    };
//
//    return 0;
//}
//
//
