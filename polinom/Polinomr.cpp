#include "Polinomr.h"

Monom::Monom()
	: coeff(0)
	, row(0) {}

Monom::Monom(const Monom& m_monom) // почему без const не работает
	: coeff(m_monom.coeff)
	, row(m_monom.row) {}

Monom::Monom(const double m_coeff, const int m_row) // ¬ы€снить почему при таком объ€влении была ошибка Monom::Monom(double m_coeff, int m_row)
	: coeff(m_coeff)
{
	if (m_row <= 999) {
		row = m_row;
	}
	else {
		throw std::exception();
	}
}

bool Monom::operator==(const Monom& m_monom) {
	return(row == m_monom.row);
}

bool Monom::operator==(const Monom& m_monom) const {
	return const_cast<Monom&>(*this) == const_cast<Monom&>(m_monom);
}

bool Monom::operator<(const Monom& m_monom) {
	return(row < m_monom.row);
}

bool Monom::operator<(const Monom& m_monom) const{
	return const_cast<Monom&>(*this) < const_cast<Monom&>(m_monom);
}

bool Monom::operator>(const Monom& m_monom) {
	return(row > m_monom.row);
}

bool Monom::operator>(const Monom& m_monom) const {
	return const_cast<Monom&>(*this) > const_cast<Monom&>(m_monom);
}

bool Monom::operator>=(const Monom& m_monom) {
	return (row >= m_monom.row);
}

bool Monom::operator>=(const Monom& m_monom) const {
	return (const_cast<Monom&>(*this) >= const_cast<Monom&>(m_monom));
}

Monom operator+(const Monom& m_first, const Monom& m_second) {
	if (m_first.row == m_second.row) {
		return Monom(m_first.coeff + m_second.coeff, m_first.row);
	}
	else {
		throw std::exception();
	}
}

Monom operator-(const Monom& m_first, const Monom& m_second) {
	return (m_first + (-1) * m_second);
}


Monom operator*(const Monom& m_first, const Monom& m_second) {
	return Monom(m_first.coeff * m_second.coeff, m_first.row + m_second.row);
}

Monom operator*(const Monom& m_first, const double& second) {
	return Monom(m_first.coeff * second, m_first.row);
}

Monom operator*(const Monom& m_first, const int& second) {
	return Monom(m_first.coeff * second, m_first.row);
}

Monom operator*(const double& first, const Monom& m_second) {
	return Monom(m_second.coeff * first, m_second.row);
}

Monom operator*(const int& first, const Monom& m_second) {
	return Monom(m_second.coeff * first, m_second.row);
}


Monom& Monom::operator/(const double& a) {
	coeff /= a;
	return *this;
}

Monom& Monom::operator+=(const Monom& m_monom) {
	if (row == m_monom.row) {
		coeff += m_monom.coeff;
		if (!coeff) {
			row = 0;
		}
	}
	else {
		throw std::exception();
	}

	return *this;
}

polinom::polinom()
	: List()
	, last(nullptr)

{}

polinom::polinom(const Monom& m_monom)
	: List(m_monom)
	, last(first) {}

polinom::polinom(Monom&& m_monom)
	: List(m_monom)
	, last(first) {}

polinom::polinom(const polinom& m_polinom) {
	first = last = nullptr;
	node<Monom>* curr = m_polinom.first;
	while (curr != nullptr) {
		push_back(curr->data);
		curr = curr->next;
	}
}


polinom::polinom(double m_coeff, int m_row) {
	Monom a(m_coeff, m_row);
	first = new node<Monom>(a);
	last = first;
}

polinom::polinom(std::string& str)
	:polinom()
{
	for (int i = 0; i < str.size(); i++) {
     	double coeff = 0; 
    	int row = 0;
		bool f = 1;
		if (str[i] == '-' || str[i] == '+') {
			if (str[i] == '-') {
				f = 0;
			}
			i++;
		}
		

		while (str[i] >= '0' && str[i] <= '9') {
			coeff = coeff*10+ (str[i]- 48);
			i++;
		}
		if (!f) {
			coeff *= -1;
		}

		if (str[i] == 'x') {
			i++;
			if (str[i] == '^') {
				i++;
				if (str[i] >= '0' && str[i] <= '9') {
					row += (str[i] - 48) * 100;
					i++;
				}
				else {
					throw std::exception();
				}
			}
			else {
				throw std::exception();
			}
		}
		if (str[i] == 'y') {
			i++;
			if (str[i] == '^') {
				i++;
				if (str[i] >= '0' && str[i] <= '9') {
					row += (str[i] - 48) * 10;
					i++;
				}
				else {
					throw std::exception();
				}
			}
			else {
				throw std::exception();
			}
		}
		else {
			throw std::exception();
		}
		if (str[i] == 'z') {
			i++;
			if (str[i] == '^') {
				i++;
				if (str[i] >= '0' && str[i] <= '9') {
					row += (str[i] - 48);
				}
				else {
					throw std::exception();
				}
			}
			else {
				throw std::exception();
			}
		}
		else {
			throw std::exception();
		}

		insert(Monom(coeff,row));
	}
}

void polinom::cleaning() {
	while (first->data.coeff == 0) {
		pop_front();
	}
	
	node<Monom>* prev = first;
	node<Monom>* curr = ((prev->next == nullptr) ? nullptr : prev->next);

	while (curr != nullptr) {
		if (curr->data.coeff == 0) {
			node<Monom>* temp = curr;
			curr = curr->next;
			prev->next = curr;

			Size--;
			delete temp;
		}
		else {
			curr = curr->next;
			prev = prev->next;
		}
	}
}

polinom operator+(const polinom& m_first, const polinom& m_second) {
	List<Monom>::iterator it_1 = m_first.begin();
	List<Monom>::iterator it_2 = m_second.begin();

	polinom result;

	while (it_1 != m_first.end() && it_2 != m_second.end()) {
		if (*it_1 > *it_2) {
			result.push_back(*it_1);
			it_1++;
		}
		else if (*it_1 < *it_2) {
			result.push_back(*it_2);
			it_2++;
		}
		else {
			result.push_back(*it_1 + *it_2);
			it_1++;
			it_2++;
		}
	}

	if (it_1 == m_first.end() && it_2 != m_second.end()) {
		result.push_back(*it_2);
	}
	else if (it_2 == m_second.end() && it_1 != m_first.end()) {
		result.push_back(*it_1);
	}

	result.cleaning();

	return result;
}

polinom operator-(const polinom& m_first, const polinom& m_second) {
	return (m_first + (-1) * m_second);
}

polinom operator*(const polinom& m_first, const polinom& m_second) {
	polinom result;

	for (List<Monom>::iterator itf = m_first.begin(); itf != m_first.end(); itf++) {
		for (List<Monom>::iterator its = m_second.begin(); its != m_second.end(); its++) {
			result.insert((*itf) * (*its));
		}
	}
	return result;
}

polinom operator*(const int& first, const polinom& m_second) {
	return static_cast<double>(first)*m_second;
}

polinom operator*(const double& first, const polinom& m_second) {
	polinom result;

	List<Monom>::iterator it = m_second.begin();
	for (it; it != m_second.end(); it++) {
		result.push_back(first * (*it));
	}

	return result;
}

polinom operator*(const polinom& m_second, const int& second) {
	return (second * m_second);
}

polinom operator*(const polinom& m_second, const double& second) {
	return (second * m_second);
}

polinom operator/(const polinom& m_first, const int& second) {
	return (m_first / static_cast<double>(second));
}

polinom operator/(const polinom& m_first, const double& second) {
	polinom result;
	for (List<Monom>::iterator it = m_first.begin(); it != m_first.end(); it++) {
		result.push_back((*it) / second);
	}

	return result;
	
}
void polinom::insert(const Monom& m_data) {
	if (first == nullptr) {
		first = last = new node<Monom>(m_data);
		Size++;
	}
	else {
		if (m_data > first->data) {
			push_front(m_data);
		}
		else if (m_data == first->data)
			first->data += m_data;
		else {
			node<Monom>* curr = first->next;
			node<Monom>* prev = first;

			while (curr != nullptr && m_data < curr->data) {
				curr = curr->next;
				prev = prev->next;
			}
			if (curr == nullptr) {
				last = prev->next = new node<Monom>(m_data);
				Size++;
			}
			else if (m_data == curr->data) {
				curr->data += m_data;
			}
			else {
				node<Monom>* new_node = new node<Monom>(m_data);
				new_node->next = curr;
				prev->next = new_node;
				Size++;
			}
		}
	}
}

void polinom::insert(Monom&& m_data) {
	if (first == nullptr) {
		first = last = new node<Monom>(m_data);
		Size++;
	}
	else {
		if (m_data > first->data) {
			push_front(m_data);
		}
		else if (m_data == first->data)
			first->data += m_data;
		else {
			node<Monom>* curr = first->next;
			node<Monom>* prev = first;

			while (curr != nullptr && m_data < curr->data) {
				curr = curr->next;
				prev = prev->next;
			}
			if (curr == nullptr) {
				last = prev->next = new node<Monom>(m_data);
				Size++;
			}
			else if (m_data == curr->data) {
				curr->data += m_data;
			}
			else {
				node<Monom>* new_node = new node<Monom>(m_data);
				new_node->next = curr;
				prev->next = new_node;
				Size++;
			}
		}
	}
}