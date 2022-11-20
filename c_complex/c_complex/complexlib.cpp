#include <iostream>
#include <cmath>
#include "complexlib.h"
using namespace std;
const int numberlenght = 10, complexlenght = 2 * numberlenght + 3;
const double pi = 3.14159265358979323846, eps = 0.0001;
void complex::zinput(char* z)
{
	for (int k = 0; k != 1;)
	{
		cout << "Введите комплексное число в алгебраической форме:"; // получаем строку и проверяем её на корректность. Проверяем каждый символ. Если символ не число, пробел или точка, то ввод некорректный
		cin.getline(z, complexlenght);
		cin.ignore(cin.rdbuf()->in_avail());
		if (!inputIsCorrect(z))
		{
			cout << "Некорректный ввод" << endl;
			continue;
		}
		int n = strlen(z);
		for (int i = 0, j = 0, ic = 0, signc = 0, numberc = 0; i < n; i++)
		{
			if ((z[i] > 47 && z[i] < 58) || (z[i] == 46))
			{
				numberc++;
				j++;
			}
			else
			{
				if (z[i] == 45 && i == 0)
				{
					j++;
				}
				else
				{
					if ((z[i] == 43 || z[i] == 45) && i != 0)
					{
						signc++;
						j++;
					}
					else
					{
						if (z[i] == 105)
						{
							ic++;
						}
					}
					j++;
				}
			}
			if (ic > 1 || signc > 1)
			{
				j--;
			}
			if (i == n && numberc == 0 && z[i] != 105)
			{
				j--;
			}
			if (j == strlen(z))
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << "Некорректный ввод\n";
		}
	}
}
complex complex::readConsole()
{
	char z[23];  // чтение числа из консоли
	double a, b;
	complex complexNumber;
	a = 0;
	b = 0;
	z[0] = '0';
	complexNumber.zinput(z);
	complexNumber.zanalysis(z, a, b);
	complex resultComplexNumber(z, a, b);
	return resultComplexNumber;
}
bool complex::inputIsCorrect(char* z)
{
	int length = strlen(z);

	// проверка на пустоту
	if (strlen(z) == 0)
		return false;

	// проверка на содержание неверных символов
	for (int i = 0; i < length; i++)
	{
		switch (z[i])
		{
		case 'i':
			continue;
			break;
		case '+':
			continue;
			break;
		case '-':
			continue;
			break;
		case '.':
			continue;
			break;
		default:
		{
			if (!isdigit(z[i]))
				return false;
			break;
		}
		}
	}

	// если 1 символ
	if (length == 1)
	{
		if (!isdigit(z[0]) && z[0] != 'i')
			return false;
	}

	// проверка на наличие более одного "i", более одного "+" и более 2 "-"
	int numberOfI = 0, numberOfPluses = 0, numberOfMinuses = 0;
	for (int i = 0; i < length; i++)
	{
		if (z[i] == 'i')
			numberOfI++;
		else if (z[i] == '+')
			numberOfPluses++;
		else if (z[i] == '-')
			numberOfMinuses++;
		if (numberOfI > 1)
			return false;
		if (numberOfPluses > 1)
			return false;
		if (numberOfMinuses > 2)
			return false;
	}

	// если первый символ "+"
	if (z[0] == '+')
		return false;

	// последний символ не "+" и не "-"
	if (z[length - 1] == '+' || z[length - 1] == '-')
		return false;

	for (int i = 1; i < length; i++)
	{
		if ((z[i] == '-' || z[i] == '+') && (z[i - 1] == '-' || z[i - 1] == '+'))
			return false;
	}

	if (numberOfI == 1 && z[length - 1] != 'i')
		return false;

	if (numberOfI == 0 && (numberOfPluses == 1 || numberOfMinuses == 2))
		return false;

	if (numberOfMinuses == 1 && z[0] != '-' && z[length - 1] != 'i')
		return false;


	return true;
}

void complex::zanalysis(char* z, double& a, double& b) 
{
	char* temp = new char[numberlenght]; // Преобразуем строку в комплексное число. С промощью цикла перебираем все символы в строке. Когда встречаем +/-, то получаем a, когда получаем знак i, то получаем значение b 
	int n = strlen(z);
	for (int i = 0, j = 0; i < n; i++)
	{
		temp[j] = z[i];
		if ((z[i] < 48 || z[i] > 57) && (z[i] != 46)) // 48 - "0", 57 - "9",  46 - ".", 105 - "i", 43 - "+", 45 - "-"
		{
			if (z[i] == 45 && j == 0)
			{
				j++;
			}
			else
			{
				if (z[i] == 105)
				{
					if (i > 0 && z[i - 1] == 45)
					{
						b = -1;
						j = 0;
					}
					else
					{
						if ((i > 0 && z[i - 1] == 43) || (z[i] == 105 && i == 0))
						{
							b = 1;
							j = 0;
						}
						else
						{
							temp[j] = '\0';
							b = strtod(temp, NULL);
							j = 0;
						}
					}
				}
				else
				{
					temp[j] = '\0';
					a = strtod(temp, NULL);
					j = 1;
					temp[0] = z[i];
				}
			}
		}
		else
		{
			if (i == n - 1)
			{
				temp[j + 1] = '\0';
				a = strtod(temp, NULL);
			}
			else
			{
				j++;
			}
		}
	}
}

complex complex::zaddition(double a1, double b1, double a2, double b2)
{
	double a = a1 + a2, b = b1 + b2;
	complex c(z, a, b);
	return c;
	//zoutput(a, b);
}
complex complex::zsubstractoin(double a1, double b1, double a2, double b2)
{
	double a = a1 - a2, b = b1 - b2;
	complex c(z, a, b);
	return c;
	//zoutput(a, b);
}
complex complex::zmultiplication(double a1, double b1, double a2, double b2)
{
	double a = a1 * a2 - b1 * b2, b = a1 * b2 + a2 * b1;
	complex c(z, a, b);
	return c;
	//zoutput(a, b);
}
complex complex::zdivision(double a1, double b1, double a2, double b2)
{
	double zt = a2 * a2 + b2 * b2, a = (a1 * a2 + b1 * b2) / zt, b = (a2 * b1 - a1 * b2) / zt;
	complex c(z, a, b);
	return c;
	//zoutput(a, b);
}
void complex::zoutput(double a, double b)
{
	if (abs(a - 0) < eps)
	{
		if (abs(b - 0) < eps)
		{
			cout << '0';
		}
		else
		{
			if (abs(b - 1) < eps)
			{
				cout << "i";
			}
			else
			{
				if (abs(b + 1) < eps)
				{
					cout << "-i";
				}
				else
				{
					cout << b << "i";
				}
			}
		}
	}
	else
	{
		cout << a;
		if (b > eps)
		{
			if (abs(b - 1) < eps) {
				cout << "+i";
			}
			else
			{
				cout << "+" << b << "i";
			}
		}
		else
		{
			if (b < 0)
			{
				if (b == -1)
				{
					cout << "-i";
				}
				else
				{
					cout << b << "i";
				}
			}
		}
	}
	cout << endl;
}
void complex::ztrigform(double r, double argz, double a, double b)
{
	if (a == 0 && b == 0)
	{
		cout << "Комплексное число, равное нулю, нельзя перевести в тригонометрическую форму.\n";
	}
	else
	{
		cout << "Тригонометрическая форма комплексного числа: z = " << r << "(cos(" << argz << ")+isin(" << argz << "))\n";
	}
}
void complex::zpokazform(double, double, double, double)
{
	if (a == 0 && b == 0)
	{
		cout << "Комплексное число, равное нулю, нельзя перевести в показательную форму.\n";
	}
	else
	{
		cout << "Показательная форма комплексного числа: z = " << r << "e^(" << argz << "i)\n";
	}
}
complex complex::zpower(double r, double argz, double a1, double b1, int p)
{
	double a, b;
	if (a1 == 0)
	{
		b = pow(b1, p) * pow(-1, p / 2);
		if (p % 2 == 0)
		{
			complex c(z, b, 0);
			return c;
			//zoutput(b, 0);
		}
		else
		{
			complex c(z, 0, b);
			return c;
			//zoutput(0, b);
		}
	}
	else
	{
		if (b1 == 0)
		{
			a = pow(a1, p);
			complex c(z, a, 0);
			return c;
			//zoutput(a, 0);
		}
		else
		{
			a = pow(r, p) * cos(p * argz);
			b = pow(r, p) * sin(p * argz);
			complex c(z, a, b);
			return c;
			//zoutput(a, b);
		}
	}
}

void complex::zroot(double r, double argz, double a1, double b1, int p)
{
	double a = 0, b = 0;
	if (a1 == 0 && b1 == 0)
	{
		cout << "z = 0\n";
	}
	else
	{
		for (int i = 0; i < p; i++)
		{
			double newarg = (argz + 2 * pi * i) / p, newr = pow(r, 1.0 / p);
			cos(newarg);
			a = newr * cos(newarg);
			b = newr * sin(newarg);
			cout << "z" << i << " = ";
			zoutput(a, b);
			ztrigform(newr, newarg, a, b);
		}
	}
}
double complex::zarg(double a, double b)
{
	if (a > 0)
	{
		if (b == 0)
		{
			return 0;
		}
		else
		{
			return atan(b / a);
		}
	}
	else
	{
		if (a < 0)
		{
			if (b > 0)
			{
				return pi + atan(b / a);
			}
			else
			{
				if (b < 0)
				{
					return atan(b / a) - pi;
				}
				else
				{
					return pi;
				}
			}
		}
		else
		{
			if (b > 0)
			{
				return pi / 2;
			}
			else
			{
				if (b < 0)
				{
					return -pi / 2;
				}
				else
				{
					return 0;
				}
			}
		}
	}
}
complex::complex() {  }
complex::complex(char* z, double a, double b)
{
	this->a = a;
	this->b = b;
	for (int i = 0; i < 23; i++)
	{
		this->z[i] = z[i];
	}
	r = sqrt(a * a + b * b);
	argz = zarg(a, b);
}
complex complex::addition(complex z1, complex z2)
{
	return zaddition(z1.a, z1.b, z2.a, z2.b);
}
complex complex::substractoin(complex z1, complex z2)
{
	return zsubstractoin(z1.a, z1.b, z2.a, z2.b);
}
complex complex::multiplication(complex z1, complex z2)
{
	return zmultiplication(z1.a, z1.b, z2.a, z2.b);
}
complex complex::division(complex z1, complex z2)
{
	return zdivision(z1.a, z1.b, z2.a, z2.b);
}
void complex::trigform(complex z)
{
	ztrigform(z.r, z.argz, z.a, z.b);
}
void complex::pokazform(complex z)
{
	zpokazform(z.r, z.argz, z.a, z.b);
}
complex complex::power(complex z, int p)
{
	return zpower(z.r, z.argz, z.a, z.b, p);
}
void complex::root(complex z, int p)
{
	zroot(z.r, z.argz, z.a, z.b, p);
}