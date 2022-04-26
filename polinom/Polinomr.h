<<<<<<< HEAD
#ifndef _POLINOM_
#define _POLINOM_

#include "List.h"
#include <iostream>
#include <string>

class Monom {
protected:
	friend class polinom;
	friend class List<Monom>;
	friend class List<Monom>::iterator;

	double coeff;
	int row;
public:
	Monom();
	Monom(const Monom& m_monom);
	Monom(const double m_coeff,const int m_row);

	bool operator==(const Monom& m_monom);
	bool operator==(const Monom& m_monom) const;
	bool operator<(const Monom& m_monom);
	bool operator<(const Monom& m_monom) const;
	bool operator>(const Monom& m_monom);
	bool operator>(const Monom& m_monom) const;
	bool operator>=(const Monom& m_monom);
	bool operator>=(const Monom& m_monom) const;
	
	friend Monom operator+(const Monom& m_first, const Monom& m_second); 
	friend Monom operator-(const Monom& m_first, const Monom& m_second);
	friend Monom operator*(const Monom& m_first, const Monom& m_second);
	friend Monom operator*(const Monom& m_first, const double& second);
	friend Monom operator*(const Monom& m_first, const int& second);
	friend Monom operator*(const double& first, const Monom& m_second);
	friend Monom operator*(const int& first, const Monom& m_second);

	Monom& operator/(const double& a);
	Monom& operator+=(const Monom& m_monom);

	friend std::ostream& operator<<(std::ostream& out, Monom& m_monom) {
		out << m_monom.coeff << "x^" << m_monom.row / 100 << "y^" << m_monom.row % 100 / 10 << "z^" << m_monom.row % 10;
		out << " + ";
		return out;
	}
};

class polinom :public List<Monom> {
private:
	node<Monom>* last;
	void cleaning();
public:
	polinom();
	polinom(const Monom& m_monom);
	polinom(Monom&& m_monom);
	polinom(const polinom& m_polinom);
	polinom(double m_coeff, int m_row);
	polinom(std::string& str);

	void insert(const Monom& m_monom);
	void insert(Monom&& m_monom);

	friend polinom operator+(const polinom& m_first, const polinom& m_second);
	friend polinom operator-(const polinom& m_first, const polinom& m_second);
	friend polinom operator*(const polinom& m_first, const polinom& m_second);
	friend polinom operator*(const int& first, const polinom& m_second);
	friend polinom operator*(const double& first, const polinom& m_second);
	friend polinom operator*(const polinom& m_second, const int& second);
	friend polinom operator*(const polinom& m_second, const double& second);
	friend polinom operator/(const polinom& m_first, const int& second);
	friend polinom operator/(const polinom& m_first, const double& second);

	friend std::ostream& operator<<(std::ostream& out, const polinom& m_polinom){
		polinom::iterator it = m_polinom.begin();

		for (it; it != m_polinom.end(); it++) {
			out << *it;
		}
		out << 0;
	
		return out;
	}
};
#endif // !_POLINOM_

=======
#ifndef _POLINOM_
#define _POLINOM_

#include "List.h"
#include <iostream>
#include <string>

class Monom {
protected:
	friend class polinom;
	friend class List<Monom>;
	friend class List<Monom>::iterator;

	double coeff;
	int row;
public:
	Monom();
	Monom(const Monom& m_monom);
	Monom(const double m_coeff,const int m_row);

	bool operator==(const Monom& m_monom);
	bool operator==(const Monom& m_monom) const;
	bool operator<(const Monom& m_monom);
	bool operator<(const Monom& m_monom) const;
	bool operator>(const Monom& m_monom);
	bool operator>(const Monom& m_monom) const;
	bool operator>=(const Monom& m_monom);
	bool operator>=(const Monom& m_monom) const;
	
	friend Monom operator+(const Monom& m_first, const Monom& m_second); 
	friend Monom operator-(const Monom& m_first, const Monom& m_second);
	friend Monom operator*(const Monom& m_first, const Monom& m_second);
	friend Monom operator*(const Monom& m_first, const double& second);
	friend Monom operator*(const Monom& m_first, const int& second);
	friend Monom operator*(const double& first, const Monom& m_second);
	friend Monom operator*(const int& first, const Monom& m_second);

	Monom& operator/(const double& a);
	Monom& operator+=(const Monom& m_monom);

	friend std::ostream& operator<<(std::ostream& out, Monom& m_monom) {
		out << m_monom.coeff << "x^" << m_monom.row / 100 << "y^" << m_monom.row % 100 / 10 << "z^" << m_monom.row % 10;
		out << " + ";
		return out;
	}
};

class polinom :public List<Monom> {
private:
	node<Monom>* last;
	void cleaning();
public:
	polinom();
	polinom(const Monom& m_monom);
	polinom(Monom&& m_monom);
	polinom(const polinom& m_polinom);
	polinom(double m_coeff, int m_row);
	polinom(std::string& str);

	void insert(const Monom& m_monom);
	void insert(Monom&& m_monom);

	friend polinom operator+(const polinom& m_first, const polinom& m_second);
	friend polinom operator-(const polinom& m_first, const polinom& m_second);
	friend polinom operator*(const polinom& m_first, const polinom& m_second);
	friend polinom operator*(const int& first, const polinom& m_second);
	friend polinom operator*(const double& first, const polinom& m_second);
	friend polinom operator*(const polinom& m_second, const int& second);
	friend polinom operator*(const polinom& m_second, const double& second);
	friend polinom operator/(const polinom& m_first, const int& second);
	friend polinom operator/(const polinom& m_first, const double& second);

	friend std::ostream& operator<<(std::ostream& out, const polinom& m_polinom){
		polinom::iterator it = m_polinom.begin();

		for (it; it != m_polinom.end(); it++) {
			out << *it;
		}
		out << 0;
	
		return out;
	}
};
#endif // !_POLINOM_

>>>>>>> 0313d6a0bcb831d82a3e6eade187621deaf054e0
