/*
 * Fraction.cpp
 *
 *  Created on: Jul 5, 2014
 *      Author: Mike
 */

#include <queue>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Fraction.h"

Fraction::Fraction() :
		numerator(0), denominator(1) {

}

//-----------------------------------------------------------------

Fraction::Fraction(long num) :
		numerator(num), denominator(1) {

}

//-----------------------------------------------------------------

Fraction::Fraction(long num, long denum) :
		numerator(num) {
	setDenominator(denum);
	normalize();
}

//-----------------------------------------------------------------

Fraction::Fraction(const std::string& expression) {
	std::cout << expression << std::endl;
	std::queue<std::string> tokens = Tokenize(expression);

	while (!tokens.empty()) {
		std::cout << tokens.back() << std::endl;
		tokens.pop();
	}

}

//-----------------------------------------------------------------

Fraction::Fraction(const char* expression) {
	std::cout << "const char* ctor: " << expression << std::endl;
	std::string infix(expression);
	std::cout << "string infix: " << infix << std::endl;

	std::queue<std::string> tokens = Tokenize(infix);

	evaluateInfix(tokens);


}

//-----------------------------------------------------------------

long Fraction::getNumerator() const {
	return numerator;
}

//-----------------------------------------------------------------

void Fraction::setNumerator(long num) {
	numerator = num;
}

//-----------------------------------------------------------------

long Fraction::getDenominator() const {
	return denominator;
}

//-----------------------------------------------------------------

void Fraction::setDenominator(long denum) {
	// throw execption string("Division by zero")
	if (denum == 0) {
		std::cout << ("Division by zero");
	} else if (denum < 0) {
		numerator = -numerator;
		denominator = -denum;
	} else {
		denominator = denum;
	}
}

//-----------------------------------------------------------------

std::queue<std::string> Fraction::Tokenize(const std::string& infixExpression) {
	std::queue<std::string> tokens;

	std::cout << "infix: " <<  infixExpression << std::endl;

	for (auto c : infixExpression) {
		std::string s;
		s += c;
		tokens.push(s);
	}

	return tokens;
}

//-----------------------------------------------------------------

Fraction Fraction::evaluateInfix(std::queue<std::string>& infixQueue) {



}

//-----------------------------------------------------------------

int Fraction::precedence(std::string op) {
	if (op == "*" || op == "/")
		return 2;
	if (op == "+" || op == "-")
		return 1;
	if (op == "(")
		return 0;
	return -1;
}

//-----------------------------------------------------------------

long Fraction::gcd(long one, long two) {

// remove negative signs
	if (one < 0) {
		one = -one;
	}
	if (two < 0) {
		two = -two;
	}

	if (one == two) { // if they are equal then they are already the common divisor
		return one;
	} else if (one < two) { // swap, because you need the large number as var one.
		long temp = two;
		two = one;
		one = temp;
	}

	long remainder = one % two;

	if (remainder == 0) { // if remainder is zero, you are done.
		return two;
	} else {
		return gcd(two, remainder); // if remainder is not zero, then recurse.
	}
}

//-----------------------------------------------------------------

void Fraction::normalize() {
	long common = Fraction::gcd(this->getNumerator(), this->getDenominator());
	this->setNumerator(this->getNumerator() / common);
	this->setDenominator(this->getDenominator() / common);
}

//-----------------------------------------------------------------

Fraction& Fraction::operator+=(const Fraction& rhs) {
	long a = this->getNumerator();
	long b = this->getDenominator();
	long c = rhs.getNumerator();
	long d = rhs.getDenominator();

	this->setNumerator(a * d + b * c);
	this->setDenominator(b * d);
	normalize();
	return *this;
}

//-----------------------------------------------------------------

Fraction& Fraction::operator-=(const Fraction& rhs) {
	long a = this->getNumerator();
	long b = this->getDenominator();
	long c = rhs.getNumerator();
	long d = rhs.getDenominator();

	this->setNumerator(a * d - b * c);
	this->setDenominator(b * d);
	normalize();
	return *this;
}

//-----------------------------------------------------------------

Fraction& Fraction::operator*=(const Fraction& rhs) {
	long a = this->getNumerator();
	long b = this->getDenominator();
	long c = rhs.getNumerator();
	long d = rhs.getDenominator();

	this->setNumerator(a * c);
	this->setDenominator(b * d);
	normalize();
	return *this;
}

//-----------------------------------------------------------------

Fraction& Fraction::operator/=(const Fraction& rhs) {
	long a = this->getNumerator();
	long b = this->getDenominator();
	long c = rhs.getNumerator();
	long d = rhs.getDenominator();

	this->setNumerator(a * d);
	this->setDenominator(b * c);
	normalize();
	return *this;
}

//-----------------------------------------------------------------

Fraction& Fraction::operator++() {
	long a = this->getNumerator();
	long b = this->getDenominator();

	this->setNumerator(a + b);
	return *this;
}

//-----------------------------------------------------------------

Fraction Fraction::operator++(int) {
	long a = this->getNumerator();
	long b = this->getDenominator();

	Fraction temp(a, b);
	++(*this);
	return temp;
}

//-----------------------------------------------------------------

Fraction& Fraction::operator--() {
	long a = this->getNumerator();
	long b = this->getDenominator();

	this->setNumerator(a - b);
	return *this;
}

//-----------------------------------------------------------------

Fraction Fraction::operator--(int) {
	long a = this->getNumerator();
	long b = this->getDenominator();

	Fraction temp(a, b);
	--(*this);
	return temp;
}

//-----------------------------------------------------------------

std::string Fraction::operator()() {
	std::string s = this->getNumerator() + "/" + this->getDenominator();
	return s;
}

//-----------------------------------------------------------------

Fraction operator+(const Fraction& rhs) {
	Fraction positive(rhs.getNumerator(), rhs.getDenominator());
	return positive;
}

//-----------------------------------------------------------------

Fraction operator-(const Fraction& rhs) {
	Fraction negative(-rhs.getNumerator(), rhs.getDenominator());
	return negative;
}

//-----------------------------------------------------------------

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	Fraction temp(lhs);
	temp += rhs;
	return temp;
}

//-----------------------------------------------------------------

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	Fraction temp(lhs);
	temp -= rhs;
	return temp;
}

//-----------------------------------------------------------------

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	Fraction temp(lhs);
	temp *= rhs;
	return temp;
}

//-----------------------------------------------------------------

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	Fraction temp(lhs);
	temp /= rhs;
	return temp;
}

//-----------------------------------------------------------------

bool operator==(const Fraction& lhs, const Fraction& rhs) {
	long a = lhs.getNumerator();
	long b = lhs.getDenominator();
	long c = rhs.getNumerator();
	long d = rhs.getDenominator();

	return (a * d) == (b * c);
}

//-----------------------------------------------------------------

bool operator<(const Fraction& lhs, const Fraction& rhs) {
	long a = lhs.getNumerator();
	long b = lhs.getDenominator();
	long c = rhs.getNumerator();
	long d = rhs.getDenominator();

	return (a * d) < (b * c);
}

//-----------------------------------------------------------------

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
	return !(lhs == rhs);
}

//-----------------------------------------------------------------

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
	return (lhs < rhs || lhs == rhs);
}

//-----------------------------------------------------------------

bool operator>(const Fraction& lhs, const Fraction& rhs) {
	return !(lhs < rhs);
}

//-----------------------------------------------------------------

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
	return (lhs > rhs || lhs == rhs);
}

//-----------------------------------------------------------------

std::istream& operator>>(std::istream& in, Fraction& rhs) {

	return in;
}

//-----------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const Fraction& rhs) {
	out << rhs.getNumerator() << "/" << rhs.getDenominator() << std::endl;
	return out;
}

//-----------------------------------------------------------------
