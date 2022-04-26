<<<<<<< HEAD
#include <gtest.h>
#include "List.h"

TEST(node, can_create_default_node) {
	ASSERT_NO_THROW(node<int> a);
}

TEST(node, can_create_node_with_data) {
	ASSERT_NO_THROW(node<int> a(10));
}

TEST(node, can_create_node_with_copy_constructor) {
	node<int> a(100);
	ASSERT_NO_THROW(node<int> b(a));
}

/*
TEST(node, can_create_node_with_data_and_pointer_for_second_node) {
	node<int> a(200);
	ASSERT_NO_THROW(node<int> b(200, &a));
}
*/

TEST(node, comparison_operators_works_right) {
	node<int> a(200);
	node<int> b(200);
	node<int> c(400);
	EXPECT_EQ(1, a == b);
	EXPECT_EQ(1, a < c);
	EXPECT_EQ(0, a > c);
	EXPECT_EQ(1, a >= b);
}

TEST(List, can_create_default_list) {
	ASSERT_NO_THROW(List<int> a);
}

TEST(List, can_create_list_with_element) {
	ASSERT_NO_THROW(List<int> a(100));
}

TEST(List, can_create_list_with_node) {
	node<int> b(200);
	ASSERT_NO_THROW(List<int> a(&b));
}

TEST(List, can_create_list_with_copy_constructor) {
	List<int> a(400);
	ASSERT_NO_THROW(List<int> b(a));
}

TEST(List, can_create_list_with_copy_assignment) {
	List<int> a(4000);
	ASSERT_NO_THROW(List<int> b = a);
}

TEST(List, can_create_list_with_Rvalue_reference_list) {
	List<int> c(List<int>(4000));
	EXPECT_EQ(c.read_first(), 4000);
	ASSERT_NO_THROW(List<int> b(List<int> (4000)));
}

TEST(List, copy_assignment_operator_with_Rvalue_reference_is_right) {
	List<int> d = List<int>(10);
	EXPECT_EQ(d.read_first(), 10);
	ASSERT_NO_THROW(List<int> c = List<int> (10));
}

TEST(List, can_get_size) {
	List<int> d = List<int>(10);
	ASSERT_NO_THROW(d.size());
	EXPECT_EQ(d.size(), 1);
}

TEST(List, can_check_for_emptiness) {
	List<double> a;
	List<double> c(2000);

	ASSERT_NO_THROW(a.empty());
	EXPECT_EQ(a.empty(), true);
	EXPECT_EQ(c.empty(), false);
}

TEST(List, can_push_back_data) {
	List<double> a;
	
	List<double> b(2000);
	b.push_back(-890);
	b.push_back(123.4);
	List<double>::iterator it = b.begin();
	it++; it++;

	ASSERT_NO_THROW(a.push_back(-189));
	EXPECT_EQ(123.4, *it);
}

TEST(List, can_push_back_node) {
	List<double> a;
	node<double> q(123);
	node<double> s(-567);
	a.push_back(&q);
	a.push_back(&s);

	List<double>::iterator it = a.begin();
	it++; 

	ASSERT_NO_THROW(a.push_back(&q));
	EXPECT_EQ(0, 567 + *it);

}

TEST(List, can_delete_an_element_by_data) {
	List<double> a;

	node<double> q(123);
	node<double> s(-567);
	a.push_back(&q);
	a.push_back(&s);

	EXPECT_EQ(a.size(), 2);
	ASSERT_NO_THROW(a.delElem(-567));
	EXPECT_EQ(a.size(), 1);
}

TEST(List, can_pop_front_element) {
	List<int> a;
	node<int> q(123);
	node<int> s(-567);
	a.push_back(&q);
	a.push_back(&s);
	a.push_back(234);

	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(a.read_first(), 123);
	ASSERT_NO_THROW(a.pop_front());
	EXPECT_EQ(a.size(), 2);
	EXPECT_EQ(a.read_first(), -567);
}

TEST(List, can_pop_back_element) {
	List<int> a;
	node<int> q(123);
	node<int> s(-567);
	a.push_back(&q);
	a.push_back(&s);
	a.push_back(234);

	List<int>::iterator it = a.begin();
	it++; it++;

	EXPECT_EQ(a.size(), 3);
	ASSERT_NO_THROW(a.pop_back());
	EXPECT_EQ(a.size(), 2);
}

TEST(List, can_sort) {
	List<int> a;
	node<int> q(123);
	node<int> s(-567);
	a.push_back(&q);
	a.push_back(&s);
	a.push_back(234);
	a.push_back(6);
	a.push_back(-567);
	a.push_back(67);

	ASSERT_NO_THROW(a.sort());
	//a.show();
=======
#include <gtest.h>
#include "List.h"

TEST(node, can_create_default_node) {
	ASSERT_NO_THROW(node<int> a);
}

TEST(node, can_create_node_with_data) {
	ASSERT_NO_THROW(node<int> a(10));
}

TEST(node, can_create_node_with_copy_constructor) {
	node<int> a(100);
	ASSERT_NO_THROW(node<int> b(a));
}

/*
TEST(node, can_create_node_with_data_and_pointer_for_second_node) {
	node<int> a(200);
	ASSERT_NO_THROW(node<int> b(200, &a));
}
*/

TEST(node, comparison_operators_works_right) {
	node<int> a(200);
	node<int> b(200);
	node<int> c(400);
	EXPECT_EQ(1, a == b);
	EXPECT_EQ(1, a < c);
	EXPECT_EQ(0, a > c);
	EXPECT_EQ(1, a >= b);
}

TEST(List, can_create_default_list) {
	ASSERT_NO_THROW(List<int> a);
}

TEST(List, can_create_list_with_element) {
	ASSERT_NO_THROW(List<int> a(100));
}

TEST(List, can_create_list_with_node) {
	node<int> b(200);
	ASSERT_NO_THROW(List<int> a(&b));
}

TEST(List, can_create_list_with_copy_constructor) {
	List<int> a(400);
	ASSERT_NO_THROW(List<int> b(a));
}

TEST(List, can_create_list_with_copy_assignment) {
	List<int> a(4000);
	ASSERT_NO_THROW(List<int> b = a);
}

TEST(List, can_create_list_with_Rvalue_reference_list) {
	List<int> c(List<int>(4000));
	EXPECT_EQ(c.read_first(), 4000);
	ASSERT_NO_THROW(List<int> b(List<int> (4000)));
}

TEST(List, copy_assignment_operator_with_Rvalue_reference_is_right) {
	List<int> d = List<int>(10);
	EXPECT_EQ(d.read_first(), 10);
	ASSERT_NO_THROW(List<int> c = List<int> (10));
}

TEST(List, can_get_size) {
	List<int> d = List<int>(10);
	ASSERT_NO_THROW(d.size());
	EXPECT_EQ(d.size(), 1);
}

TEST(List, can_check_for_emptiness) {
	List<double> a;
	List<double> c(2000);

	ASSERT_NO_THROW(a.empty());
	EXPECT_EQ(a.empty(), true);
	EXPECT_EQ(c.empty(), false);
}

TEST(List, can_push_back_data) {
	List<double> a;
	
	List<double> b(2000);
	b.push_back(-890);
	b.push_back(123.4);
	List<double>::iterator it = b.begin();
	it++; it++;

	ASSERT_NO_THROW(a.push_back(-189));
	EXPECT_EQ(123.4, *it);
}

TEST(List, can_push_back_node) {
	List<double> a;
	node<double> q(123);
	node<double> s(-567);
	a.push_back(&q);
	a.push_back(&s);

	List<double>::iterator it = a.begin();
	it++; 

	ASSERT_NO_THROW(a.push_back(&q));
	EXPECT_EQ(0, 567 + *it);

}

TEST(List, can_delete_an_element_by_data) {
	List<double> a;

	node<double> q(123);
	node<double> s(-567);
	a.push_back(&q);
	a.push_back(&s);

	EXPECT_EQ(a.size(), 2);
	ASSERT_NO_THROW(a.delElem(-567));
	EXPECT_EQ(a.size(), 1);
}

TEST(List, can_pop_front_element) {
	List<int> a;
	node<int> q(123);
	node<int> s(-567);
	a.push_back(&q);
	a.push_back(&s);
	a.push_back(234);

	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(a.read_first(), 123);
	ASSERT_NO_THROW(a.pop_front());
	EXPECT_EQ(a.size(), 2);
	EXPECT_EQ(a.read_first(), -567);
}

TEST(List, can_pop_back_element) {
	List<int> a;
	node<int> q(123);
	node<int> s(-567);
	a.push_back(&q);
	a.push_back(&s);
	a.push_back(234);

	List<int>::iterator it = a.begin();
	it++; it++;

	EXPECT_EQ(a.size(), 3);
	ASSERT_NO_THROW(a.pop_back());
	EXPECT_EQ(a.size(), 2);
}

TEST(List, can_sort) {
	List<int> a;
	node<int> q(123);
	node<int> s(-567);
	a.push_back(&q);
	a.push_back(&s);
	a.push_back(234);
	a.push_back(6);
	a.push_back(-567);
	a.push_back(67);

	ASSERT_NO_THROW(a.sort());
	//a.show();
>>>>>>> 0313d6a0bcb831d82a3e6eade187621deaf054e0
}