#include <iostream>

//  1.	Создать структуру Rectangle, описывающую прямоугольник.Написать функцию для определения попадания произвольной точки в данный прямоугольник.
//  Точка также должна описываться отдельной структурой Point.Прямоугольник состоит из двух точек.

struct Point
{
	int x;
	int y;
};

struct Rectangle
{
	Point upLeft;
	Point downRight;
};

void IsPointBelongRectangle(Rectangle a, Point b)
{
	if (b.x >= a.upLeft.x && b.x <= a.downRight.x && b.y >= a.upLeft.y && b.y <= a.downRight.y)
		std::cout << "The point belongs to rectangle." << std::endl;
	else
		std::cout << "The point does not belongs to rectangle." << std::endl;
}

/*  Реализовать структуру Fraction, которая представляет собой пользовательский тип данных для работы с обыкновенными дробями :
  Обязательные поля : числитель и знаменатель(целочисленные).Реализовать следующие функции : показ дроби на экран консоли, 
  показ неправильной дроби как смешанной, показ обыкновенной дроби как десятичной, возврат значения типа double на основании 
  значений числителя и знаменателя дроби, сокращение дроби, сравнение дробей, сложение, вычитание, умножение, деление дробей*/

struct Fraction
{
	int numerator;
	int denominator;
};

void ShowSimpleFraction(Fraction a)
{
	if (a.numerator < a.denominator)
		std::cout << a.numerator << "/" << a.denominator << std::endl;
	else
		std::cout << "Fraction is not simple" << std::endl;
}
void ShowMixedFraction(Fraction a)
{
	if (a.numerator >= a.denominator)
		std::cout << a.numerator / a.denominator << " and " << a.numerator % a.denominator << "/" << a.denominator << std::endl;
	else
		std::cout << "Fraction is simple, can not be displayes as mixed fraction" << std::endl;
}
void ShowFraction(Fraction a)
{
	std::cout << a.numerator << "/" << a.denominator;
}

void ShowDecimalFraction(Fraction a)
{
	std::cout << (double)a.numerator / a.denominator << std::endl;
}

void Show(Fraction a)
{
	if (a.numerator < a.denominator && a.numerator > 0)
		std::cout << a.numerator << "/" << a.denominator << std::endl;
	else if (a.numerator > a.denominator || a.numerator < 0 && a.numerator * (-1) > a.denominator)
		std::cout << a.numerator / a.denominator << " and " << abs(a.numerator) % a.denominator << "/"
		<< a.denominator << std::endl;
}

int GreatestCommonDivisor(Fraction a)
{
	while (a.denominator > 0)
	{
		a.numerator = abs(a.numerator)% a.denominator;
		std::swap(a.numerator, a.denominator);
	}
	return abs(a.numerator);
}

void FractionReduction(Fraction a)
{
	if (a.denominator == 0)
		std::cout << "Cannot be divided by zero" << std::endl;
	if (a.numerator == 0)
		std::cout << "Fraction after reduction is zero" << std::endl;
	int gcd = GreatestCommonDivisor(a);
	Fraction(c);
	c.numerator = a.numerator / gcd;
	c.denominator = a.denominator / gcd;
	std::cout << "Fraction after reduction is ";
	Show(c);
}

void ComparisonFraction(Fraction a, Fraction b)
{
	if ((double)a.numerator / a.denominator > (double)b.numerator / b.denominator) {
		ShowFraction(a);
		std::cout << " > ";
		ShowFraction(b);
		std::cout << std::endl;
	}
	else if ((double)b.numerator / b.denominator > (double)a.numerator / a.denominator) {
		ShowFraction(a);
		std::cout << " < ";
		ShowFraction(b);
		std::cout << std::endl;
	}
	else
		std::cout << "Fractions are equal" << std::endl;
}
 
void FractionSum(Fraction a, Fraction b)
{
	int newDenominator = a.denominator * b.denominator;
	int newANumerator = a.numerator * b.denominator;
	int newBNumerator = b.numerator * a.denominator;
	
	Fraction c;
	c.numerator = newANumerator + newBNumerator;
	c.denominator = newDenominator;

	int gcd = GreatestCommonDivisor(c);
	Fraction(d);
	d.numerator = c.numerator / gcd;
	d.denominator = c.denominator / gcd;
	std::cout << "Sum of two fractions is ";
	Show(d);
}

void FractionSubtruction(Fraction a, Fraction b)
{
	int newDenominator = a.denominator * b.denominator;
	int newANumerator = a.numerator * b.denominator;
	int newBNumerator = b.numerator * a.denominator;

	Fraction c;
	c.numerator = newANumerator - newBNumerator;
	c.denominator = newDenominator;

	int gcd = GreatestCommonDivisor(c);
	Fraction(d);
	d.numerator = c.numerator / gcd;
	d.denominator = c.denominator / gcd;
	std::cout << "Subtraction of two fractions is ";
	Show(d);
}

void FractionMultiplication(Fraction a, Fraction b)
{
	Fraction c;
	c.numerator = a.numerator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	int gcd = GreatestCommonDivisor(c);
	Fraction(d);
	d.numerator = c.numerator / gcd;
	d.denominator = c.denominator / gcd;
	std::cout << "Multiplication of two fractions is ";
	Show(d);
}

void FractionDivision(Fraction a, Fraction b)
{
	Fraction c;
	c.numerator = a.numerator * b.denominator;
	c.denominator = a.denominator * b.numerator;
	int gcd = GreatestCommonDivisor(c);
	Fraction(d);
	d.numerator = c.numerator / gcd;
	d.denominator = c.denominator / gcd;
	std::cout << "Division of two fractions is ";
	Show(d);
}

int main()
{
	Point A;
	std::cout << "Enter coordinate x for point A " << std::endl;
	std::cin >> A.x;
	std::cout << "Enter coordinate y for point A " << std::endl;
	std::cin >> A.y;

	Rectangle a;
	std::cout << "Enter coordinate x for upper left point of rectangle " << std::endl;
	std::cin >> a.upLeft.x;
	std::cout << "Enter coordinate y for upper left point of rectangle " << std::endl;
	std::cin >> a.upLeft.y;
	std::cout << "Enter coordinate x for bottom right point of rectangle " << std::endl;
	std::cin >> a.downRight.x;
	std::cout << "Enter coordinate y for bottom right point of rectangle " << std::endl;
	std::cin >> a.downRight.y;

	IsPointBelongRectangle(a, A);

	Fraction c;
	std::cout << "Enter numerator of fraction" << std::endl;
	std::cin >> c.numerator;
	std::cout << "Enter denumerator of fraction" << std::endl;
	std::cin >> c.denominator;

	ShowSimpleFraction(c);
	std::cout << std::endl;

	Fraction b;
	std::cout << "Enter numerator of fraction" << std::endl;
	std::cin >> b.numerator;
	std::cout << "Enter denumerator of fraction" << std::endl;
	std::cin >> b.denominator;

	ShowMixedFraction(b);
	ShowDecimalFraction(b);
	FractionReduction(b);

	ComparisonFraction(c, b);
	FractionSum(c, b);
	FractionSubtruction(c, b);
	FractionMultiplication(c, b);
	FractionDivision(c, b);

}
