/*
 * Fraction.h
 *
 *  Created on: Jul 5, 2014
 *      Author: Mike
 */


#include <queue>
#include <string>
#include <iostream>

#ifndef FRACTION_H_
#define FRACTION_H_



class Fraction {
public:

	Fraction();
	Fraction(long);
	Fraction(long, long);
	Fraction(const std::string&);
	Fraction(const char*);

	long getNumerator() const;
	void setNumerator(long);
	long getDenominator() const;
	void setDenominator(long); // throw execption string("Division by zero")

	static std::queue<std::string> Tokenize(const std::string& infixExpression);
	static Fraction evaluateInfix(std::queue<std::string>& infixQueue);

	static int precedence(std::string);
	static long gcd(long, long);

	Fraction& operator+=(const Fraction& rhs);
	Fraction& operator-=(const Fraction& rhs);
	Fraction& operator*=(const Fraction& rhs);
	Fraction& operator/=(const Fraction& rhs);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	std::string operator()();

private:
	long numerator;
	long denominator;
	void normalize();
};

Fraction operator+(const Fraction& rhs);
Fraction operator-(const Fraction& rhs);

Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

bool operator==(const Fraction& lhs, const Fraction& rhs);
bool operator<(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);
bool operator<=(const Fraction& lhs, const Fraction& rhs);
bool operator>(const Fraction& lhs, const Fraction& rhs);
bool operator>=(const Fraction& lhs, const Fraction& rhs);

std::istream& operator>>(std::istream&, Fraction& rhs);
std::ostream& operator<<(std::ostream&, const Fraction& rhs);



#endif /* FRACTION_H_ */
