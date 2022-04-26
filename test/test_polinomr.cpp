<<<<<<< HEAD
#include <gtest.h>
#include "Polinomr.h"

TEST(Monom, can_create_default_monom) {
	ASSERT_NO_THROW(Monom a);
}

TEST(Monom, can_create_with_coeff_and_row) {
	ASSERT_NO_THROW(Monom b(169412, 222));
}

TEST(Monom, can_create_monom_with_copy_constructor) {
	Monom a(100, 222);
	ASSERT_NO_THROW(Monom b(a));
}

TEST(Monom, can_create_with_copy_assignment) {
	Monom a(100, 222);
	ASSERT_NO_THROW(Monom b = a);
}

TEST(Monom, can_sum_two_monom_with_equal_row) {
	Monom a(-2, 456);
	Monom b(90, 456);
	ASSERT_NO_THROW(a + b);
}

TEST(Monom, cant_sum_two_monom_with_different_row) {
	Monom a(-2,456);
	Monom b(90, 123);
	ASSERT_ANY_THROW(a + b);
}

TEST(Monom, can_substract_two_monom_with_equal_row) {
	Monom a(-2, 123);
	Monom b(90, 123);
	ASSERT_NO_THROW(a - b);
}

TEST(Monom, cant_substract_two_monom_with_different_row) {
	Monom a(-2, 123);
	Monom b(90, 400);
	ASSERT_ANY_THROW(a - b);
}

TEST(Monom, can_multiply_two_monom) {
	Monom a(-2, 456);
	Monom b(90, 123);
	ASSERT_NO_THROW(a * b);
}

TEST(Monom, can_multiply_a_monomial_by_an_Rvalue_int_number) {
	Monom a(3, 100);
	int b = 4;
	ASSERT_NO_THROW(a * b);
}

TEST(Monom, can_multiply_a_monomial_by_an_Lvalue_int_number) {
	Monom a(3, 100);
	ASSERT_NO_THROW(a * 4);
}

TEST(Monom, can_multiply_an_Lvalue_int_number_by_a_monomial) {
	Monom a(3, 100);
	int b = 4;
	ASSERT_NO_THROW(b * a);
}

TEST(Monom, can_multiply_an_Rvalue_int_number_by_a_monomial) {
	Monom a(3, 100);
	ASSERT_NO_THROW(4 * a);
}

TEST(Monom, can_multiply_a_monomial_by_an_Lvalue_double_number) {
	Monom a(3, 100);
	double b = 4.0;
	ASSERT_NO_THROW(a * b);
}

TEST(Monom, can_multiply_a_monomial_by_an_Rvalue_double_number) {
	Monom a(3, 100);
	ASSERT_NO_THROW(a * 4.0);
}

TEST(Monom, can_multiply_an_Lvalue_double_number_by_a_monomial) {
	Monom a(3, 100);
	double b = 4.0;
	ASSERT_NO_THROW(b * a);
}

TEST(Monom, can_multiply_an_Rvalue_double_number_by_a_monomial) {
	Monom a(3, 100);
	ASSERT_NO_THROW(4.0 * a);
}
TEST(Monom, can_divide_a_monomial_by_an_Rvalue_number) {
	Monom a(16, 100);
	ASSERT_NO_THROW(a / 20);
}


TEST(polinom, can_create_default_polinom) {
	ASSERT_NO_THROW(polinom a);
}

TEST(polinom, can_create_polinom_with_monom) {
	Monom a(100, 222);
	ASSERT_NO_THROW(polinom b(a));
}

TEST(polinom, can_create_polinom_with_Rvalue_monom) {
	ASSERT_NO_THROW(polinom a(Monom(-4, 123)));
}

TEST(polinom, can_create_polinom_with_copy_constructor) {
	Monom a(100, 222);
	polinom b(a);
	ASSERT_NO_THROW(polinom c(b));
}

TEST(polinom, can_create_polinom_with_move_constructor) {
	ASSERT_NO_THROW(polinom c(polinom(1, 400)));
}

TEST(polinom, can_push_back_with_data) {
	List<int> a;
	a.push_back(20);
	a.push_back(400);
	a.push_back(300);
	a.push_back(500);
	List<int>::iterator it = a.begin();
	it++;
	it++;
	ASSERT_NO_THROW(a.push_back(20));
	EXPECT_EQ(a.size(), 5);
	EXPECT_EQ(*it, 300);
}

TEST(Polinom, can_create_polinom_with_coeff_and_row) {
	ASSERT_NO_THROW(polinom a(3400, 234));
}

TEST(Polinom, can_insert_element) {
	polinom a;
	ASSERT_NO_THROW(a.insert(Monom(1000,213)));
	EXPECT_EQ(1, a.size());
}

TEST(Polinom, can_sum_two_polinom) {
	polinom a(100, 340);
	polinom b(1234, 456);
	
	ASSERT_NO_THROW(a + b);
}

TEST(Polinom, can_sum_two_Lvalue_polinom) {
	ASSERT_NO_THROW(polinom (100, 340) + polinom (1234, 456));
}

TEST(Polinom, can_substract_two_polinom) {
	polinom a(100, 340);
	polinom b(1234, 456);
	ASSERT_NO_THROW(polinom (100, 340)- polinom (1234, 456));
}

TEST(Polinom, can_multiply_two_polinom) {
	polinom a(100, 340);
	polinom b(1234, 456);
	ASSERT_NO_THROW(4 * b);
}


TEST(Polinom, can_multiply_a_number_by_a_polynomial) {
	polinom a(100, 340);

	ASSERT_NO_THROW(4.986736 * a);
=======
#include <gtest.h>
#include "Polinomr.h"

TEST(Monom, can_create_default_monom) {
	ASSERT_NO_THROW(Monom a);
}

TEST(Monom, can_create_with_coeff_and_row) {
	ASSERT_NO_THROW(Monom b(169412, 222));
}

TEST(Monom, can_create_monom_with_copy_constructor) {
	Monom a(100, 222);
	ASSERT_NO_THROW(Monom b(a));
}

TEST(Monom, can_create_with_copy_assignment) {
	Monom a(100, 222);
	ASSERT_NO_THROW(Monom b = a);
}

TEST(Monom, can_sum_two_monom_with_equal_row) {
	Monom a(-2, 456);
	Monom b(90, 456);
	ASSERT_NO_THROW(a + b);
}

TEST(Monom, cant_sum_two_monom_with_different_row) {
	Monom a(-2,456);
	Monom b(90, 123);
	ASSERT_ANY_THROW(a + b);
}

TEST(Monom, can_substract_two_monom_with_equal_row) {
	Monom a(-2, 123);
	Monom b(90, 123);
	ASSERT_NO_THROW(a - b);
}

TEST(Monom, cant_substract_two_monom_with_different_row) {
	Monom a(-2, 123);
	Monom b(90, 400);
	ASSERT_ANY_THROW(a - b);
}

TEST(Monom, can_multiply_two_monom) {
	Monom a(-2, 456);
	Monom b(90, 123);
	ASSERT_NO_THROW(a * b);
}

TEST(Monom, can_multiply_a_monomial_by_an_Rvalue_int_number) {
	Monom a(3, 100);
	int b = 4;
	ASSERT_NO_THROW(a * b);
}

TEST(Monom, can_multiply_a_monomial_by_an_Lvalue_int_number) {
	Monom a(3, 100);
	ASSERT_NO_THROW(a * 4);
}

TEST(Monom, can_multiply_an_Lvalue_int_number_by_a_monomial) {
	Monom a(3, 100);
	int b = 4;
	ASSERT_NO_THROW(b * a);
}

TEST(Monom, can_multiply_an_Rvalue_int_number_by_a_monomial) {
	Monom a(3, 100);
	ASSERT_NO_THROW(4 * a);
}

TEST(Monom, can_multiply_a_monomial_by_an_Lvalue_double_number) {
	Monom a(3, 100);
	double b = 4.0;
	ASSERT_NO_THROW(a * b);
}

TEST(Monom, can_multiply_a_monomial_by_an_Rvalue_double_number) {
	Monom a(3, 100);
	ASSERT_NO_THROW(a * 4.0);
}

TEST(Monom, can_multiply_an_Lvalue_double_number_by_a_monomial) {
	Monom a(3, 100);
	double b = 4.0;
	ASSERT_NO_THROW(b * a);
}

TEST(Monom, can_multiply_an_Rvalue_double_number_by_a_monomial) {
	Monom a(3, 100);
	ASSERT_NO_THROW(4.0 * a);
}
TEST(Monom, can_divide_a_monomial_by_an_Rvalue_number) {
	Monom a(16, 100);
	ASSERT_NO_THROW(a / 20);
}


TEST(polinom, can_create_default_polinom) {
	ASSERT_NO_THROW(polinom a);
}

TEST(polinom, can_create_polinom_with_monom) {
	Monom a(100, 222);
	ASSERT_NO_THROW(polinom b(a));
}

TEST(polinom, can_create_polinom_with_Rvalue_monom) {
	ASSERT_NO_THROW(polinom a(Monom(-4, 123)));
}

TEST(polinom, can_create_polinom_with_copy_constructor) {
	Monom a(100, 222);
	polinom b(a);
	ASSERT_NO_THROW(polinom c(b));
}

TEST(polinom, can_create_polinom_with_move_constructor) {
	ASSERT_NO_THROW(polinom c(polinom(1, 400)));
}

TEST(polinom, can_push_back_with_data) {
	List<int> a;
	a.push_back(20);
	a.push_back(400);
	a.push_back(300);
	a.push_back(500);
	List<int>::iterator it = a.begin();
	it++;
	it++;
	ASSERT_NO_THROW(a.push_back(20));
	EXPECT_EQ(a.size(), 5);
	EXPECT_EQ(*it, 300);
}

TEST(Polinom, can_create_polinom_with_coeff_and_row) {
	ASSERT_NO_THROW(polinom a(3400, 234));
}

TEST(Polinom, can_insert_element) {
	polinom a;
	ASSERT_NO_THROW(a.insert(Monom(1000,213)));
	EXPECT_EQ(1, a.size());
}

TEST(Polinom, can_sum_two_polinom) {
	polinom a(100, 340);
	polinom b(1234, 456);
	
	ASSERT_NO_THROW(a + b);
}

TEST(Polinom, can_sum_two_Lvalue_polinom) {
	ASSERT_NO_THROW(polinom (100, 340) + polinom (1234, 456));
}

TEST(Polinom, can_substract_two_polinom) {
	polinom a(100, 340);
	polinom b(1234, 456);
	ASSERT_NO_THROW(polinom (100, 340)- polinom (1234, 456));
}

TEST(Polinom, can_multiply_two_polinom) {
	polinom a(100, 340);
	polinom b(1234, 456);
	ASSERT_NO_THROW(4 * b);
}


TEST(Polinom, can_multiply_a_number_by_a_polynomial) {
	polinom a(100, 340);

	ASSERT_NO_THROW(4.986736 * a);
>>>>>>> 0313d6a0bcb831d82a3e6eade187621deaf054e0
}