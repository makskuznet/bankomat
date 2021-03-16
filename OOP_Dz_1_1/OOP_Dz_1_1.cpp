// OOP_Dz_1_1.cpp: определяет точку входа для консольного приложения.
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
			puts("Введена некорректная сумма");
		else
			Terminal.sum-=take_sum;
	}
	void toString(Bankomat &Terminal)
	{
		cout<<"\nСумма в банкомате: ";
		int thous=sum/1000;
		switch (thous)
		{
			case 0: break;
			case 1: cout<<"Одна тысяча ";  break;
			case 2: cout<<"Две тысячи ";  break;
			case 3: cout<<"Три тысячи "; break;
			case 4: cout<<"Четыре тысячи "; break;
			case 5: cout<<"Пять тысяч "; break;
			case 6: cout<<"Шесть тысяч "; break;
			case 7: cout<<"Семь тысяч "; break;
			case 8: cout<<"Восемь тысяч "; break;
			case 9: cout<<"Девять тысяч "; break;
			case 10: cout<<"Десять тысяч "; break;
		}
		int hundr = (sum%1000)/100;
		switch (hundr)
		{
			case 0: break;
			case 1: cout<<"сто "; break;
			case 2: cout<<"двести "; break;
			case 3: cout<<"триста "; break;
			case 4: cout<<"четыреста "; break;
			case 5: cout<<"пятьсот "; break;
			case 6: cout<<"шестьсот "; break;
			case 7: cout<<"семьсот "; break;
			case 8: cout<<"восемьсот "; break;
			case 9: cout<<"девятьсот "; break;
		}
		int ten = (sum%100)/10;
		int flag = 0;
		switch (ten)
		{
			case 0: break;
			case 1: flag=1; break;
			case 2: cout<<"двадцать "; break;
			case 3: cout<<"тридцать "; break;
			case 4: cout<<"сорок "; break;
			case 5: cout<<"пятьдесят "; break;
			case 6: cout<<"шестьдесят "; break;
			case 7: cout<<"семьдесят "; break;
			case 8: cout<<"восемьдесят "; break;
			case 9: cout<<"девяносто "; break;
		}
		int unit=sum%10;
		if (flag==1)
			switch (unit)
		{
			case 0: break;
			case 1: cout<<"одиннадцать "; break;
			case 2: cout<<"двенадцать "; break;
			case 3: cout<<"тринадцать "; break;
			case 4: cout<<"четырнадцать "; break;
			case 5: cout<<"пятнадцать "; break;
			case 6: cout<<"шестнадцать "; break;
			case 7: cout<<"семнадцать "; break;
			case 8: cout<<"восемнадцать "; break;
			case 9: cout<<"девятнадцать "; break;
		}
		else
			switch (unit)
		{
			case 0: break;
			case 1: cout<<"один "; break;
			case 2: cout<<"два "; break;
			case 3: cout<<"три "; break;
			case 4: cout<<"четыре "; break;
			case 5: cout<<"пять "; break;
			case 6: cout<<"шесть "; break;
			case 7: cout<<"семь "; break;
			case 8: cout<<"восемь "; break;
			case 9: cout<<"девять "; break;
		}
		cout<<"рублей";
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
	cout << "Введите 1, чтобы начать работу или 0, чтобы выйти: ";
	char flag2,flag3;
	cin>>flag2;
	switch (flag2)
	{
		case '0': break;
		case '1':
			cout << "Введите данные о состоянии банкомата:\n" << "Номер: ";
			cin >> number;
			cout << "Текущая сумма денег: ";
			cin >> sum;
			cout << "Минимальная сумма для снятия: ";
			cin >> min_sum;
			cout << "Максимальная сумма для снятия: ";
			cin >> max_sum;
			Bankomat Terminal1(number, sum, max_sum, min_sum);
			Money cash(Terminal1);
			cout << "\n\nДанные о состоянии банкомата:\n" << "Номер: " << Terminal1.GetNumber() << "\nСумма в банкомате: " << Terminal1.GetSum() << "\nМин. сумма для снятия: " << Terminal1.GetMinSum() << "\nМакс. сумма для снятия: " << Terminal1.GetMaxSum();
			cout << "\n\nВыберите действие с банкоматом:\n0 - выйти из меню\n1 - снять деньги\n2 - положить деньги\n3 - вывести сумму прописью\nВвод: ";
			cin>>flag3;
			while (flag3 != '0')
			{
				switch (flag3)
				{
				case '1':
					cout << "\n\nВведите сумму, которую хотите снять: ";
					cin >> take_sum;
					Terminal1.TakeMoney(Terminal1,take_sum);
					cash.Change_Cash(Terminal1);
					break;
				case '2':
					cout << "\n\nВведите сумму, которую хотите положить: ";
					cin >> load_sum;
					Terminal1.LoadMoney(Terminal1, load_sum);
					cash.Change_Cash(Terminal1);
					break;
				case '3':
					Terminal1.toString(Terminal1);
					break;
				}
				cout << "\n\nВыберите действие с банкоматом:\n0 - выйти из меню\n1 - снять деньги\n2 - положить деньги\n3 - вывести сумму прописью\nВвод: ";
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
	cout << "\n\nНажмите любую клавишу для завершения работы программы...";
	getch();
}

