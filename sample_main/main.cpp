<<<<<<< HEAD
#include <iostream>
#include "Polinomr.h"
#include "List.h"
#include <cstdlib>

void multiplication_of_two_polynomials() {
	std::string a, b;
	
	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� �������:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t������� �����, �� ������� ������ �������� �������" << std::endl;
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

	std::cout << "\t\t������� �������:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t������� �����, �� ������� ������ �������� �������" << std::endl;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);

	polinom result = s / b;
	std::cout << "\t" << a << " / " << b << " = " << result << "\n\n";
}

void menu() {
	std::cout << "\t\t ��������, ��� �� ������ �������: " << std::endl;
	std::cout << "\t\t\t 1) �������� ��� ��������" << std::endl;
	std::cout << "\t\t\t 2) ������� ��� ��������" << std::endl;
	std::cout << "\t\t\t 3) ��������� �������� ���� ���������" << std::endl;
	std::cout << "\t\t\t 4) �������� ������� �� �����" << std::endl;
	std::cout << "\t\t\t 5) �������� ������� �� �����" << std::endl;
	std::cout << "\t\t\t 6) ����� �� ���������" << std::endl;
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
		std::cout << "\t\t\t ������������ ����" << std::endl;
		std::cout << "\t\t\t ���������� ��� ���" << std::endl;
		menu();
	}
	menu();
}

int main() {
	system("color 0D");
	setlocale(LC_ALL, "rus");

	std::cout << "\n";
	std::cout << "\t\t\t===================================================" << std::endl;
	std::cout << "\t\t\t||      ��������� ��� ���������� ���������       ||" << std::endl;
	std::cout << "\t\t\t===================================================" << std::endl;
	std::cout << "\n\n";
	std::cout << "\t��������� ������������, ������ ��� �������������� ��������� ������ ����� ���������" << std::endl;
	std::cout << "\t\t 1. ������� ��� ������������ �������. �������� 1x^2y^2z^3" << std::endl;
	std::cout << "\t\t 2. ����� �������� � ����������� �� ������ ���� ��������. �������� 1x^2y^2z^3+2x^0y^0z^0" << std::endl;
	std::cout << "\t\t 3. ������� ��� ������� �������, ��������� ����^. �������� 2x^0y^0z^0" << std::endl;
	std::cout << "\t\t 4. ���������� ������� ���������� ����������� x->y->z. �������� 2x^0y^0z^0" << std::endl;
	std::cout << "\n\n\n";

	menu();

	return 0;
=======
#include <iostream>
#include "Polinomr.h"
#include "List.h"
#include <cstdlib>

void multiplication_of_two_polynomials() {
	std::string a, b;
	
	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� ��� ��������:\n";
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

	std::cout << "\t\t������� �������:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t������� �����, �� ������� ������ �������� �������" << std::endl;
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

	std::cout << "\t\t������� �������:\n";
	std::cout << "\t\t";
	std::cin >> a;
	std::cout << "\t\t������� �����, �� ������� ������ �������� �������" << std::endl;
	std::cout << "\t\t";
	std::cin >> b;
	std::cout << "\n";
	polinom s(a);

	polinom result = s / b;
	std::cout << "\t" << a << " / " << b << " = " << result << "\n\n";
}

void menu() {
	std::cout << "\t\t ��������, ��� �� ������ �������: " << std::endl;
	std::cout << "\t\t\t 1) �������� ��� ��������" << std::endl;
	std::cout << "\t\t\t 2) ������� ��� ��������" << std::endl;
	std::cout << "\t\t\t 3) ��������� �������� ���� ���������" << std::endl;
	std::cout << "\t\t\t 4) �������� ������� �� �����" << std::endl;
	std::cout << "\t\t\t 5) �������� ������� �� �����" << std::endl;
	std::cout << "\t\t\t 6) ����� �� ���������" << std::endl;
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
		std::cout << "\t\t\t ������������ ����" << std::endl;
		std::cout << "\t\t\t ���������� ��� ���" << std::endl;
		menu();
	}
	menu();
}

int main() {
	system("color 0D");
	setlocale(LC_ALL, "rus");

	std::cout << "\n";
	std::cout << "\t\t\t===================================================" << std::endl;
	std::cout << "\t\t\t||      ��������� ��� ���������� ���������       ||" << std::endl;
	std::cout << "\t\t\t===================================================" << std::endl;
	std::cout << "\n\n";
	std::cout << "\t��������� ������������, ������ ��� �������������� ��������� ������ ����� ���������" << std::endl;
	std::cout << "\t\t 1. ������� ��� ������������ �������. �������� 1x^2y^2z^3" << std::endl;
	std::cout << "\t\t 2. ����� �������� � ����������� �� ������ ���� ��������. �������� 1x^2y^2z^3+2x^0y^0z^0" << std::endl;
	std::cout << "\t\t 3. ������� ��� ������� �������, ��������� ����^. �������� 2x^0y^0z^0" << std::endl;
	std::cout << "\t\t 4. ���������� ������� ���������� ����������� x->y->z. �������� 2x^0y^0z^0" << std::endl;
	std::cout << "\n\n\n";

	menu();

	return 0;
>>>>>>> 0313d6a0bcb831d82a3e6eade187621deaf054e0
}