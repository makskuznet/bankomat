// OOP_Dz_1_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Bankomat
{
	unsigned int number;
	unsigned int sum;
	unsigned int max_sum;
	unsigned int min_sum;
public:
	Bankomat(): number(0), sum(0), max_sum(0), min_sum(0)
	{}
	Bankomat(int number_p, int sum_p, int max_sum_p, int min_sum_p)
	{
		number=number_p;
		sum=sum_p;
		max_sum=max_sum_p;
		min_sum=min_sum_p;
	}
	int GetNumber()
	{
		return number;
	}
	int GetSum()
	{
		return sum;
	}
	int GetMaxSum()
	{
		return max_sum;
	}
	int GetMinSum()
	{
		return min_sum;
	}
	void LoadMoney(Bankomat &Terminal, int load_sum)
	{
		Terminal.sum+=load_sum;
	}
	void TakeMoney(Bankomat &Terminal, int take_sum)
	{
		if ((take_sum<Terminal.min_sum) || (take_sum>Terminal.max_sum) || (take_sum>Terminal.sum))
			puts("������� ������������ �����");
		else
			Terminal.sum-=take_sum;
	}
	void toString(Bankomat &Terminal)
	{
		cout<<"\n����� � ���������: ";
		int thous=sum/1000;
		switch (thous)
		{
			case 0: break;
			case 1: cout<<"���� ������ ";  break;
			case 2: cout<<"��� ������ ";  break;
			case 3: cout<<"��� ������ "; break;
			case 4: cout<<"������ ������ "; break;
			case 5: cout<<"���� ����� "; break;
			case 6: cout<<"����� ����� "; break;
			case 7: cout<<"���� ����� "; break;
			case 8: cout<<"������ ����� "; break;
			case 9: cout<<"������ ����� "; break;
			case 10: cout<<"������ ����� "; break;
		}
		int hundr = (sum%1000)/100;
		switch (hundr)
		{
			case 0: break;
			case 1: cout<<"��� "; break;
			case 2: cout<<"������ "; break;
			case 3: cout<<"������ "; break;
			case 4: cout<<"��������� "; break;
			case 5: cout<<"������� "; break;
			case 6: cout<<"�������� "; break;
			case 7: cout<<"������� "; break;
			case 8: cout<<"��������� "; break;
			case 9: cout<<"��������� "; break;
		}
		int ten = (sum%100)/10;
		int flag = 0;
		switch (ten)
		{
			case 0: break;
			case 1: flag=1; break;
			case 2: cout<<"�������� "; break;
			case 3: cout<<"�������� "; break;
			case 4: cout<<"����� "; break;
			case 5: cout<<"��������� "; break;
			case 6: cout<<"���������� "; break;
			case 7: cout<<"��������� "; break;
			case 8: cout<<"����������� "; break;
			case 9: cout<<"��������� "; break;
		}
		int unit=sum%10;
		if (flag==1)
			switch (unit)
		{
			case 0: break;
			case 1: cout<<"����������� "; break;
			case 2: cout<<"���������� "; break;
			case 3: cout<<"���������� "; break;
			case 4: cout<<"������������ "; break;
			case 5: cout<<"���������� "; break;
			case 6: cout<<"����������� "; break;
			case 7: cout<<"���������� "; break;
			case 8: cout<<"������������ "; break;
			case 9: cout<<"������������ "; break;
		}
		else
			switch (unit)
		{
			case 0: break;
			case 1: cout<<"���� "; break;
			case 2: cout<<"��� "; break;
			case 3: cout<<"��� "; break;
			case 4: cout<<"������ "; break;
			case 5: cout<<"���� "; break;
			case 6: cout<<"����� "; break;
			case 7: cout<<"���� "; break;
			case 8: cout<<"������ "; break;
			case 9: cout<<"������ "; break;
		}
		cout<<"������";
	}
};


class Money
{
	int rub_10;
	int rub_50;
	int rub_100;
	int rub_500;
	int rub_1000;
public:
	Money(Bankomat Terminal)
	{
		unsigned int buf_sum = Terminal.GetSum();
		rub_1000 = buf_sum / 1000;
		buf_sum = buf_sum - 1000 * rub_1000;
		rub_500 = buf_sum / 500;
		buf_sum = buf_sum - 500 * rub_500;
		rub_100 = buf_sum / 100;
		buf_sum = buf_sum - 100 * rub_100;
		rub_50 = buf_sum / 50;
		buf_sum = buf_sum - 50 * rub_50;
		rub_10 = buf_sum / 10;
		buf_sum = buf_sum - 10 * rub_10;
	}
	void Change_Cash(Bankomat Terminal)
	{
		double buf_sum = Terminal.GetSum();
		rub_1000 = buf_sum / 1000;
		buf_sum = buf_sum - 1000 * rub_1000;
		rub_500 = buf_sum / 500;
		buf_sum = buf_sum - 500 * rub_500;
		rub_100 = buf_sum / 100;
		buf_sum = buf_sum - 100 * rub_100;
		rub_50 = buf_sum / 50;
		buf_sum = buf_sum - 50 * rub_50;
		rub_10 = buf_sum / 10;
		buf_sum = buf_sum - 10 * rub_10;
	}

	int Get_rub_10()
	{
		return rub_10;
	}
	int Get_rub_50()
	{
		return rub_50;
	}
	int Get_rub_100()
	{
		return rub_100;
	}
	int Get_rub_500()
	{
		return rub_500;
	}
	int Get_rub_1000()
	{
		return rub_1000;
	}
};


class Application
{
public:
	void Run()
	{
	unsigned int number;
	unsigned int sum;
	unsigned int max_sum;
	unsigned int min_sum;
	unsigned int take_sum, load_sum;
	cout << "������� 1, ����� ������ ������ ��� 0, ����� �����: ";
	char flag2,flag3;
	cin>>flag2;
	switch (flag2)
	{
		case '0': break;
		case '1':
			cout << "������� ������ � ��������� ���������:\n" << "�����: ";
			cin >> number;
			cout << "������� ����� �����: ";
			cin >> sum;
			cout << "����������� ����� ��� ������: ";
			cin >> min_sum;
			cout << "������������ ����� ��� ������: ";
			cin >> max_sum;
			Bankomat Terminal1(number, sum, max_sum, min_sum);
			Money cash(Terminal1);
			cout << "\n\n������ � ��������� ���������:\n" << "�����: " << Terminal1.GetNumber() << "\n����� � ���������: " << Terminal1.GetSum() << "\n���. ����� ��� ������: " << Terminal1.GetMinSum() << "\n����. ����� ��� ������: " << Terminal1.GetMaxSum();
			cout << "\n\n�������� �������� � ����������:\n0 - ����� �� ����\n1 - ����� ������\n2 - �������� ������\n3 - ������� ����� ��������\n����: ";
			cin>>flag3;
			while (flag3 != '0')
			{
				switch (flag3)
				{
				case '1':
					cout << "\n\n������� �����, ������� ������ �����: ";
					cin >> take_sum;
					Terminal1.TakeMoney(Terminal1,take_sum);
					cash.Change_Cash(Terminal1);
					break;
				case '2':
					cout << "\n\n������� �����, ������� ������ ��������: ";
					cin >> load_sum;
					Terminal1.LoadMoney(Terminal1, load_sum);
					cash.Change_Cash(Terminal1);
					break;
				case '3':
					Terminal1.toString(Terminal1);
					break;
				}
				cout << "\n\n�������� �������� � ����������:\n0 - ����� �� ����\n1 - ����� ������\n2 - �������� ������\n3 - ������� ����� ��������\n����: ";
				cin>>flag3;
			}
	}
	}
};




void main()
{
	setlocale(0, "russian");
	Application app;
	app.Run();
	cout << "\n\n������� ����� ������� ��� ���������� ������ ���������...";
	getch();
}

