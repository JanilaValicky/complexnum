#include <iostream>
#include <Windows.h>
#include <cmath>
#include "complexlib.h"

using namespace std;

const int numberlenght = 10, complexlenght = 2 * numberlenght + 3;
const double pi = 3.14159265358979323846, eps = 0.0001;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = 0, number = 0, p = 0;
	char testMenu[23];
	char z[23];
	char test[23];
	double a, b;
	bool inputIsCoppect = true;
	bool complexNumberIsEntered = false;
	complex currentComlexNumber;
	complex z1;
	complex z2;

	for (;;)
	{
		// 1) для незакрывающегося меню ничего существенного не поменялось
		for (; (menu > 11 || menu < 1);)
		{
			while (!complexNumberIsEntered)
			{
				cout << "Введите основное число" << endl;
				currentComlexNumber = complex::readConsole();
				complexNumberIsEntered = true;
				break;
			}

			/* 3) изменена проверка на корректность введенного номера операции:
			 * сначала данные с консоли записываются в переменную testMenu (это массив символов),
			 * потом этот массив проверяется на корректность,
			 * и если ввод оказался корректным, то этот массив переводится в тип int,
			 * если неверным, то ввод запрашивается еще раз
			 */
			cout << "Выберите операцию:\n1.Перевод в тригонометрическую форму.\n2.Перевод в показательную форму.\n3.Возведение в степень.\n4.Извлечение корня.\n5.Сложение.\n6.Вычитание.\n7.Умножение.\n8.Деление.\n9.Ввести число\n10.Вывести результат\n11.Выход\n";
			cin >> testMenu;
			cin.ignore(cin.rdbuf()->in_avail());
			if (strlen(testMenu) > 2)
			{
				menu = -1;
				cout << "Некорректный ввод" << endl;
				continue;
			}
			for (int i = 0; i < strlen(testMenu); i++)
			{
				if (!isdigit(testMenu[i]))
				{
					menu = -1;
					cout << "Некорректный ввод" << endl;
					continue;
				}
			}
			menu = atoi(testMenu);
		}
		if (menu < 5)
		{
			z1 = currentComlexNumber;
			switch (menu)
			{
			case 1:
			{
				z1.trigform(z1);
				break;
			}
			case 2:
			{
				z1.pokazform(z1);
				break;
			}
			case 3:
			{
				for (int i = 0; p < 1; i++)
				{
					if (i > 0)
					{
						cout << "Неверный ввод\n";
					}
					cout << "Введите степень: ";
					cout << "Введите степень: ";
					cin >> p;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				currentComlexNumber = z1.power(z1, p);
				break;
			}
			case 4:
			{
				for (int i = 0; p < 1; i++)
				{
					if (i > 0)
					{
						cout << "Неверный ввод\n";
					}
					cout << "Введите степень: ";
					cin >> p;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				z1.root(z1, p);
				break;
			}
			}
		}
		else if (menu > 4 && menu < 12)
		{
			if (menu < 10)
			{
				z1 = currentComlexNumber;
				cout << "Введите втАрое комплексное число\n";
				z2 = complex::readConsole();
				switch (menu)
				{
				case 5:
				{
					currentComlexNumber = z1.addition(z1, z1);
					//currentComlexNumber = z1.addition(z1, z2);
					break;
				}
				case 6:
				{
					currentComlexNumber = z1.substractoin(z1, z2);
					break;
				}
				case 7:
				{
					currentComlexNumber = z1.multiplication(z1, z2);
					break;
				}
				case 8:
				{
					currentComlexNumber = z1.division(z1, z2);
					break;
				}
				}
			}
			else if (menu > 8 && menu < 10)
			{
				switch (menu)
				{
				case 9:   
				{
					cout << "Введите основное число" << endl;
					currentComlexNumber = complex::readConsole();
				}
				case 10:   
				{
					cout << "Результат:  ";
					//complex::zoutput(currentComlexNumber.a, currentComlexNumber.b);
				}
				default:
					break;
				}

			}
			else
			{
				return 0;
			}
		}
		menu = 0;
		p = 0;
	}
}


