#include "polynomial.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cfloat>

using std::istream;
using std::ostream;
using std::string;
using std::stringstream;
using std::fixed;
using std::setprecision;
using std::showpos;

Polynomial::Polynomial(size_t degree) : _degree(degree){
	_coefficients = new float[_degree + 1];
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = 0.0;
	}
}
Polynomial::Polynomial(size_t degree, const float* coefficients): _degree(degree){
	_coefficients = new float[_degree + 1];
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = coefficients[i];
	}
}
Polynomial::Polynomial(const Polynomial& polynomial): _degree(polynomial._degree){
	_coefficients = new float[_degree + 1];
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = polynomial._coefficients[i];
	}
}
Polynomial::~Polynomial(){
	// DO THIS FIRST TO PREVENT MEMORY LEAKS!
    for (size_t i = 0; i < _degree + 1; i++){
        delete [] _coefficients[i];
    }
    delete [] _coefficients;
    
}
const Polynomial Polynomial::Sum(const Polynomial& rhs)const{
    Polynomial sumValue(*this);
    for (size_t i = 0; i < _degree + 1; i++)
    {
        sumValue._coefficients[i] += rhs._coefficients[i];
    }
    return sumValue;
}
const Polynomial Polynomial::Subtract(const Polynomial& rhs)const{
    Polynomial subtractedValue(*this);
    for (size_t i = 0; i < _degree + 1; i++)
    {
        minusValue._coefficients[i] -= rhs._coefficients[i];
    }
    return subtractedValue;
}
const Polynomial Polynomial::Minus()const{
	Polynomial retVal(*this);
	for (size_t i = 0; i < _degree + 1; i++) {
		retVal._coefficients[i] *= -1;
	}
	return retVal;
}
const Polynomial Polynomial::Multiply(const Polynomial& rhs)const{
    Polynomial multipliedValue(*this);
    int z = 0; //The variable represents results by the multiplication of two polynomials.
    float coefficientNumber[z]; //The variable for representing only coefficient on each variable.
    int degreeNumber[z]; //The variable for representing only degree on each variable.
    for (size_t i = 0; i < _degree + 1; i++){
        for(size_t j = 0; j < rhs._degree + 1; j++){
            coefficientNumber[z] = multipliedValue._coefficients[i] * rhs._coefficients[j];
            degreeNumber[z] = i + j;
            z++;
        }
    }
    
    //This for function is to simplify the multiplied results from two polynomials.
    for(int a = 0; a < z; a++){
        for(int b = a+1; b < z; b++){
            //If two variables' degrees are same each other, add the coefficients together.
            if(degreeNumber[a] == degreeNumber[b]){
                coefficientNumber[a] += coefficients[b];
                //Delete both variable's coefficient and degrees to show coefficient is already added to the first variable's coefficient.
                delete [] coefficient[b];
                delete [] degreeNumber[b];
                z--;
            }
            //If two variables' degrees are different, then stay same.
            else{
                coefficientNumber[a] += 0;
            }
        }
    }
    
    //This function is going to return values to multipliedValue._coefficients[i].
    for(int a = 0; a < z; a++){
        int degrees = degreeNumber[a];
        multipliedValue._coefficients[degrees] = coefficientNumber[a];
    }
    return multipliedValue;
}
const Polynomial Polynomial::Divide(const Polynomial& rhs)const{
    Polynomial dividedValue(*this);
    
    int y = 0;
    int z = _degree - rhs._degree;
    while(z >= 0){
        rhs._coefficients[z] = rhs._coefficients[z+2];
        for(size_t i = _degree - y; i >= rhs._degree - y; i--){
            dividedValue._coefficients[i] -= rhs._coefficients[i];
        }
        z--;
        y++;
    }
    return dividedValue;
}
const Polynomial Polynomial::Derive()const{
    Polynomial derivingValue(*this);
    for (size_t i = 0; i < _degree + 1; i++){
        i -= 1;
        if (i < 0){
            delete [] derivingValue._coefficients[i];
        }
        else{
            derivingValue._coefficients[i] *= i;
        }
    }
    return derivingValue;
}
float Polynomial::Evaluate(float x)const{
    float resultAnswer = 0;
    for(size_t i = 0; i < _degree + 1; i++){
        resultAnswer += ((x^i)*_coefficients[i]);
    }
    return resultAnswer;
}
float Polynomial::Integrate(float start, float end)const{
    float resultStart = 0;
    float resultEnd = 0;
    
    //For lower point for function
    for (size_t i = 0; i < _degree + 1; i++){
        i += 1;
        _coefficients[i] /= i;
        resultStart += ((start^i)* _coefficients[i]);
    }
    
    //For higher point for function
    for (size_t i = 0; i < _degree + 1; i++){
        i += 1;
        _coefficients[i] /= i;
        resultEnd += ((end^i)* _coefficients[i]);
    }
    float totalResult = resultEnd - resultStart;
    return totalResult;
}
const Polynomial& Polynomial::operator=(const Polynomial& rhs){
	if (&rhs == this){
		return *this;
	}
	if (_degree != rhs._degree){
		if (_coefficients){
			delete[] _coefficients;
		}
		_degree = rhs._degree;
		_coefficients = new float[_degree + 1];
	}
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = rhs._coefficients[i];
	}
	return *this;
}
bool Polynomial::Equals(const Polynomial& rhs)const{
	if (_degree != rhs._degree){
		return false;
	}
	for (size_t i=0; i < _degree; i++){
		if (abs(_coefficients[i] - rhs._coefficients[i]) > 0.0001){
			return false;
		}
	}
	return true;
}
string Polynomial::ToString()const{
	stringstream ss;
	for (size_t i = _degree; i > 0; i--) {
		ss << showpos << fixed << setprecision(2) << _coefficients[i] << "x^" << i << " ";
	}
	ss << showpos << fixed << setprecision(2) << _coefficients[0];
	return ss.str();
}
ostream& Polynomial::Write(ostream& output)const{
	output << _degree << " ";
	for (size_t i = 0; i < _degree + 1; i++) {
		output << _coefficients[i] << " ";
	}
	return output;
}
istream& Polynomial::Read(istream& input){
	size_t degree;
	input >> degree;
	if (input.fail()){
		return input;
	}
	float* coefficients = new float[degree + 1];
	for (size_t i = 0; i < degree + 1; i++) {
		input >> coefficients[i];
		if (input.fail()){
			delete[] coefficients;
			return input;
		}
	}

	if (degree != _degree){
		if (_coefficients){
			delete[] _coefficients;
		}
		_degree = degree;
		_coefficients = coefficients;
	}else{
		for (size_t i = 0; i < _degree + 1; i++) {
			_coefficients[i] = coefficients[i];
		}
		delete[] coefficients;
	}
	return input;
}
