#pragma once
#include<iostream>
class Stonewt {
public:
	enum Format { stn, int_pnd, float_pnd }; // ״̬ö��
private:
	enum { Lbs_per_stn = 14 };
	Format status;
	int stone;
	double	pds_left;
	double pounds;
public:
	//���캯��
	Stonewt();
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	~Stonewt();
	//����״̬
	void set_status(Format newStat);
	//����
	Stonewt operator+(const Stonewt& st) const;
	Stonewt operator-(const Stonewt& st) const;
	Stonewt operator*(const Stonewt& st) const;
	//�������
	friend std::ostream& operator<<(std::ostream& os, Stonewt st);
	friend std::istream& operator>>(std::istream& is, Stonewt& st);
	//��ϵ�ж�
	bool operator==(const Stonewt& s) const;
	bool operator!=(const Stonewt& s) const;
	bool operator<(const Stonewt& s) const;
	bool operator<=(const Stonewt& s) const;
	bool operator>(const Stonewt& s) const;
	bool operator>=(const Stonewt& s) const;
};