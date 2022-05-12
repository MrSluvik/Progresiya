//2. Створити абстрактний базовий клас “Прогресія” з віртуальною функцією – обчислення суми прогресії.
//Створити похідні класи: “Арифметична прогресія” і “Геометрична прогресія”.
//Кожний клас має два поля типу double: перший член прогресії і постійна різниця(для арифметичної) і постійне відношення(для геометричної).
//Визначити функцію обчислення суми, де параметром є кількість елементів прогресії.
#include <iostream>
#include<windows.h>
using namespace std;

class Progression
{
protected:
	virtual double Sum(int n) = 0; //віртуальною функцією – обчислення суми прогресії.   де параметром є кількість елементів прогресії
};

class ArifmeticProgression :public Progression
{
private:
	double a1;// перший член прогресії
	double d;//постійна різниця
public:
	ArifmeticProgression(double a1,double d) {//конструтор
		this->a1 = a1;
		this->d = d;
	}

	double Sum(int n) override {//переоприділення функції суми прогресії
		return ((2 * a1 + (n - 1) * d) / 2) * n;
	}
	
	~ArifmeticProgression(){}//дестркутор
};

class GeometricProgression:public Progression
{
private:
	double b1; //перший член прогресії
	double q;//постійне відношення
public:

	GeometricProgression(double b1, double q){//конструтор
		this->b1 = b1;
		this->q = q;
	}

	double Sum(int n) override {//переоприділення функції суми прогресії
		return (b1*(1-pow(q,n)))/(1-q);
	}

	~GeometricProgression(){}//дестркутор
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ArifmeticProgression A(2.5 , 2.5);//створюєм обєк класу ареф.прогресії
	GeometricProgression B(4.5 , 3.5);//створюєм обєк класу геоме.прогресії
	int n = 0;
	cout << "Введіть кількість елементів прогресії" << endl;
	cin >> n;
	cout << "Сума арифметичної прогресії = " << A.Sum(n) << endl;
	cout << "Сума геометричної прогресії = " << B.Sum(n) << endl;
}


