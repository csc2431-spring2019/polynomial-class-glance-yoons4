# Start Up Code for Polynomial Class
## Purpose
The goal of this lab is to practice dynamic memory with a simple class.

## Design
This Polynomial class will store the coefficients of a one variable polynomial
in a dynamically created array. This class has two data members:
```
	size_t _degree;
	float* _coefficients;
```
It is straightforward to see what they represent.
For example:
![equation](https://latex.codecogs.com/gif.latex?7x%5E4-2x%5E2&plus;0.5x&plus;2.23)
would be:
``` 
	_degree = 4
	_coefficients => {2.23, 0.5, -2.0, 0.0, 7}
```
Notice that the array size is `_degree + 1`.

## What is given?
You will be provided with the code of the constructors the Sum and ToString methods
the rest of the methods you will implement yourself.
Additionally you will be provided with the unit tests to test your code.

## What is expected?
- Your code ***must*** compile.
- Your grade will be *almost* the percentage of your passed unit tests.
- Your code needs to show good programming practices: indentation, meaningful variable names, identifiers convention (CamelCase for functions, 
camelCase for variables, _camelCase for data members, SNAKE_CASE for constants), header comments, correct file names, etc. Failure to 
code appropriate will result in strong points penalization.
- You will need to provide implementation of the following methods:
  a. Destructor
  b. Copy Assignment operator overload
  c. Subtract
  d. Multiply
  e. Minus
  f. Derive
  g. Evaluate
  h. ToString
  i. Read (returns the `istream` parameter, first reads the degree and then degree + 1 floats for the coefficients)
  j. Write (returns the `ostream` parameter)
- The following methods will count toward extra credit, some code will be provided to guarantee compilation:
  a. Divide
  b. Integrate


