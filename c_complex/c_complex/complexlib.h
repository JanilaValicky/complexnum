#ifndef complexlib_h
#define complexlib_h
class complex
{
private:
	double r, argz;
	complex zaddition(double, double, double, double);
	complex zsubstractoin(double, double, double, double);
	complex zmultiplication(double, double, double, double);
	complex zdivision(double, double, double, double);
	void ztrigform(double, double, double, double);
	void zpokazform(double, double, double, double);
	complex zpower(double, double, double, double, int);
	void zroot(double, double, double, double, int);
	double zarg(double, double);
public:
	char z[23];
	double a, b;
	complex();
	complex(char* z, double a, double b);
	complex addition(complex, complex);
	complex substractoin(complex, complex);
	complex multiplication(complex, complex);
	complex division(complex, complex);
	void trigform(complex);
	void pokazform(complex);
	complex power(complex, int);
	void root(complex, int);

	static void zoutput(double, double);

	bool inputIsCorrect(char* z);
	static complex readConsole(); // 2) Была создана функция readConsole и методы  был вынесен из конструктора, так что теперь ввод и логика разделены
	void zinput(char*);
	void zanalysis(char*, double&, double&);
};
#endif
