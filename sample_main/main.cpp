#include <iostream>
#include "Polinomr.h"
#include "List.h"
#include <cstdlib>

void multiplication_of_two_polynomials() {
	std::string a, b;
	
	std::cout << "\t\tВведите два полинома:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);
	polinom q(b);
	
	polinom result = s + q;
	std::cout << "\t\t" << result << "\n\n";
}

void addition_of_two_polynomials() {
	std::string a, b;

	std::cout << "\t\tВведите два полинома:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);
	polinom q(b);

	polinom result = s + q;
	std::cout << "\t\t" << a << " + " << b << " = " << result << "\n\n";
}

void difference_of_two_polynomials() {
	std::string a, b;

	std::cout << "\t\tВведите два полинома:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);
	polinom q(b);

	polinom result = s - q;
	std::cout << "\t\t" << a << " - " << b << " = " << result << "\n\n";
}

void product_of_two_polynomials() {
	std::string a, b;

	std::cout << "\t\tВведите два полинома:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);
	polinom q(b);

	polinom result = s * q;
	std::cout << "\t\t" << a << " * " << b << " = " << result << "\n\n";
}

void multiply_by_number() {
	std::string a;
	double b;

	std::cout << "\t\tВведите полином:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\tВведите число, на которое хотите умножить полином" << std::endl;
	std::cout << "\t\t";
    std::cin >> b;
	std::cout << "\n";
	polinom s(a);

	polinom result = s * b;
	std::cout << "\t" << a << " * " << b << " = " << result << "\n\n";
}

void divide_by_number() {
	std::string a;
	double b;

	std::cout << "\t\tВведите полином:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\tВведите число, на которое хотите поделить полином" << std::endl;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);

	polinom result = s / b;
	std::cout << "\t" << a << " / " << b << " = " << result << "\n\n";
}

void menu() {
	std::cout << "\t\t Выберите, что Вы хотите сделать: " << std::endl;
	std::cout << "\t\t\t 1) Умножить два полинома" << std::endl;
	std::cout << "\t\t\t 2) Сложить два полинома" << std::endl;
	std::cout << "\t\t\t 3) Посчитать разность двух полниомов" << std::endl;
	std::cout << "\t\t\t 4) Умножить полином на число" << std::endl;
	std::cout << "\t\t\t 5) Поделить полином на число" << std::endl;
	std::cout << "\t\t\t 6) Выйти из программы" << std::endl;
	std::cout << "\n";
	std::cout << "\t\t";
	unsigned int a;
	std::cin >> a;

	switch (a) {
	case 1:
		product_of_two_polynomials();
		break;
	case 2:
		addition_of_two_polynomials();
		break;
	case 3:
		difference_of_two_polynomials();
		break;
	case 4:
		multiply_by_number();
		break;
	case 5:
		divide_by_number();
	case 6:
		break;
	case 7:
		std::cout << "\t\t\t Некорректный ввод" << std::endl;
		std::cout << "\t\t\t Попробуйте еще раз" << std::endl;
		menu();
	}
	menu();
}

int main() {
	system("color 0D");
	setlocale(LC_ALL, "rus");

	std::cout << "\n";
	std::cout << "\t\t\t===================================================" << std::endl;
	std::cout << "\t\t\t||      Программа для вычисления полиномов       ||" << std::endl;
	std::cout << "\t\t\t===================================================" << std::endl;
	std::cout << "\n\n";
	std::cout << "\tУважаемый пользователь, просим Вас придерживаться следующих правил ввода полиномов" << std::endl;
	std::cout << "\t\t 1. Вводите все коэффициенты мономов. Например 1x^2y^2z^3" << std::endl;
	std::cout << "\t\t 2. Между мономами и операторами не должно быть пробелов. Например 1x^2y^2z^3+2x^0y^0z^0" << std::endl;
	std::cout << "\t\t 3. Вводите все степени мономов, используя знак^. Например 2x^0y^0z^0" << std::endl;
	std::cout << "\t\t 4. Соблюдайте порядок следования неизвестных x->y->z. Например 2x^0y^0z^0" << std::endl;
	std::cout << "\n\n\n";

	menu();

	return 0;
}
