/*
 * Fraction.cpp
 *
 *  Created on: Jul 5, 2014
 *      Author: Mike
 */

#include <queue>
#include <stack>
#include <string>
#include <stdio.h>
#include <sstream>
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
	std::cout  << "const string& ctor: " << expression << std::endl;
	std::queue<std::string> tokens = Tokenize(expression);

	Fraction result = evaluateInfix(tokens);

	setNumerator(result.getNumerator());
	setDenominator(result.getDenominator());

}

//-----------------------------------------------------------------

Fraction::Fraction(const char* expression) {
	std::cout << "const char* ctor: " << expression << std::endl;
	std::string infix(expression);
	std::cout << "string infix: " << infix << std::endl;

	std::queue<std::string> tokens = Tokenize(infix);

	Fraction result = evaluateInfix(tokens);

	setNumerator(result.getNumerator());
	setDenominator(result.getDenominator());
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

	std::cout << "infix: " << infixExpression << std::endl;

	std::istringstream exs(infixExpression);

	while (exs.good()) {

		std::string toks;
		exs >> toks;
		std::cout << "tok: " << toks << std::endl;

		std::istringstream tok(toks);

		char loneOp = tok.peek();

		if (loneOp == '+' || loneOp == '-') {
			char operation;
			tok >> operation;
			std::string s;
			s += operation;
			std::cout << "lone op: " << s << std::endl;
			tokens.push(s);
			continue;
		}

		while (tok.good()) {
			long operand;
			tok >> operand;

			if (!tok.fail()) {
				std::cout << "was long: " << operand << std::endl;
				std::ostringstream out;
				out << operand;
				tokens.push(out.str());
			} else {
				std::cout << "long failed: ";
				tok.clear();
				char operation;
				tok >> operation;
				std::string s;
				s += operation;
				std::cout << s << std::endl;
				tokens.push(s);
			}
		}
	}

	return tokens;
}

//-----------------------------------------------------------------

Fraction Fraction::evaluateInfix(std::queue<std::string>& infixQueue) {

	std::stack<Fraction> operands;
	std::stack<std::string> operators;

	while (!infixQueue.empty()) {
		std::string token = infixQueue.front();
		infixQueue.pop();
		std::cout << "Next Token: " << token << std::endl;

		long num = 0;
		std::istringstream testNumber(token);
		testNumber >> num;

		if (!testNumber.fail()) {
			std::cout << "it's a number" << std::endl;
			operands.push(Fraction(num));

		} else if (token == "+" || token == "-" || token == "*"
				|| token == "/") {
			std::cout << "it's an operator" << std::endl;

			while (!operators.empty()
					&& precedence(operators.top()) > precedence(token)) {
				evaluate(operands, operators);
				std::cout << "top operand = " << operands.top() << std::endl;
			}
			operators.push(token);

		} else if (token == "(") {
			std::cout << "it's an open parenthesis" << std::endl;
			operators.push(token);

		} else if (token == ")") {
			std::cout << "it's a close parenthesis" << std::endl;
			while (!operators.empty() && operators.top() != "(") {
				evaluate(operands, operators);
				std::cout << "top operand = " << operands.top() << std::endl;
			}

			if (operators.empty()) {
				std::cout << " paranthesis missing error" << std::endl;
			} else {
				std::cout << " pop a ( " << std::endl;
				operators.pop();
			}
		}

	}

	std::cout << "done with queue" << std::endl;

	std::cout << "op stack: " << !operators.empty() << std::endl;
	while (!operators.empty()) {
		evaluate(operands, operators);
		std::cout << "top operand = " << operands.top() << std::endl;
	}

	return operands.top();

}

//-----------------------------------------------------------------

void Fraction::evaluate(std::stack<Fraction>& operands,
		std::stack<std::string>& operators) {

	std::cout << "fractions: " << std::endl;
	for (auto dump = operands; !dump.empty(); dump.pop()) {
		std::cout << dump.top();
	}

	std::cout << "operators: " << std::endl;
	for (auto dump = operators; !dump.empty(); dump.pop()) {
		std::cout << dump.top() << std::endl;;
	}

	Fraction two = operands.top();
	operands.pop();
	Fraction one = operands.top();
	operands.pop();
	std::string op = operators.top();
	operators.pop();

	std::cout << "op: " << op << std::endl;

	if (op == "+") {
		std::cout << one << " + " << two << " = " << (one + two) << std::endl;
		operands.push(one + two);
	} else if (op == "-") {
		std::cout << two;
		std::cout << " - " << one;
		std::cout << " = " << std::endl;
		std::cout << (one - two) << std::endl;
		operands.push(one - two);
	} else if (op == "*") {
		std::cout << one << " * " << two << " = " << (one * two) << std::endl;
		operands.push(one * two);
	} else if (op == "/") {
		std::cout << one << " / " << two << " = " << (one / two) << std::endl;
		operands.push(one / two);
	} else {
		std::cout << "error should not get here" << std::endl;
	}
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
	if (this->getNumerator() == 0) {
		this->setNumerator(0);
		this->setDenominator(1);
		return;
	}
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
	std::cout << "Enter Fraction: ";
	std::string s;
	std::getline(in, s);

	Fraction f(s);

	rhs.setNumerator(f.getNumerator());
	rhs.setDenominator(f.getDenominator());

	return in;
}

//-----------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const Fraction& rhs) {
	out << rhs.getNumerator() << "/" << rhs.getDenominator() << std::endl;
	return out;
}

//-----------------------------------------------------------------
