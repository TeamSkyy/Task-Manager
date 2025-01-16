#include "Queue.h"
#include <iostream>
#include <cmath>  // ���� fabs ����

bool newcustomer(double m);
const int MIN_PER_HOUR = 60;

int main()
{
    using namespace std;
    int qs;
    cout << "Please enter the max size of the queue: ";
    cin >> qs;//������д�С
    Queue queue1(qs), queue2(qs);
    int testHours = 100;
    long cycleTime = testHours * MIN_PER_HOUR;//�ܵĲ���ʱ�䣨���ӣ�
    int customer_per_hour = 60;
    double avg_wait_time = 0.0;

    do {
        Customer temp_customer;
        int turnaways = 0;//���ܾ�����
        int waitTime1 = 0, waitTime2 = 0;//���еȴ�ʱ��
        int customer_number = 0;//��ӵĿ�������
        int line_wait = 0;//�����ܵȴ�ʱ��
        int customer_served = 0;//�ѷ���Ŀ�������
        int sum_line = 0;//�ۼƶ����ܳ���
        double min_per_cus = double(MIN_PER_HOUR) / customer_per_hour;

        // ģ��ѭ��
        for (int cycle = 0; cycle < cycleTime; cycle++)
        {
            if (newcustomer(min_per_cus)) {
                if (queue1.isFull()&&queue2.isFull()) {
                    turnaways++;
                }
                if(queue1.currentSize()<queue2.currentSize())
                {
                    customer_number++;
                    temp_customer.set(cycle);//���˵���ʱ��
                    queue1.enqueue(temp_customer);//�������
                }
                else {
                    customer_number++;
                    temp_customer.set(cycle);//���˵���ʱ��
                    queue2.enqueue(temp_customer);//�������
                }
            }
            if (waitTime1 <= 0 && !queue1.isEmpty()) {
                queue1.dequeue(temp_customer);
                waitTime1 = temp_customer.pTime();//���Ӻ�����ȴ�ʱ���ɿ��˵Ĵ���ʱ��
                line_wait += cycle - temp_customer.aTime();
                customer_served++;
            }
            if (waitTime1 > 0) {
                waitTime1--;
            }

            if (waitTime2 <= 0 && !queue2.isEmpty()) {
                queue2.dequeue(temp_customer);
                waitTime2 = temp_customer.pTime();//���Ӻ�����ȴ�ʱ���ɿ��˵Ĵ���ʱ��
                line_wait += cycle - temp_customer.aTime();
                customer_served++;
            }
            if (waitTime2 > 0) {
                waitTime2--;
            }
            sum_line += queue1.currentSize() + queue2.currentSize();
        }

        if (customer_served > 0) {
            avg_wait_time = double(line_wait) / customer_served;
        }
        else {
            avg_wait_time = 0;  // ��ֹ����0����
        }

        // ���� customer_per_hour�������ӵ������
        cout << "��ǰÿСʱ�ͻ�: " << customer_per_hour << ", ƽ���ȴ�ʱ��: " << avg_wait_time << endl;

        if (avg_wait_time > 1.0) {
            if (avg_wait_time - 1.0 > 0.5) {
                customer_per_hour -= 5;  // ���������0.5�������󲽷�
            }
            else {
                customer_per_hour--;  // ���С������С����
            }
        }
        else {
            if (1.0 - avg_wait_time > 0.5) {
                customer_per_hour += 5;
            }
            else {
                customer_per_hour++;
            }
        }

    } while (fabs(avg_wait_time - 1.0) > 0.05);  // �ſ��ж�����

    std::cout << "ÿСʱӦ���� " << customer_per_hour << " ���ͻ������ܱ�֤ƽ���ȴ�ʱ��Ϊ1���ӡ�" << endl;
}

bool newcustomer(double m) {
    // ʹ�����������
    std::random_device rd;               // ����豸��������������
    std::mt19937 gen(rd());              // Mersenne Twister ����
    std::uniform_real_distribution<> dis(0.0, 1.0);  // ���� [0.0, 1.0) ֮������������

    return dis(gen) < (1.0 / m);  // �������ɸ��ʣ����ӿͻ����ɵ������
}
