#include<iostream>
#include"Matrix.h"
#include"MatrixIO.h"
#include<complex>
#include<cmath>
#include<vector>

int main()
{
	//1
	
	std::cout << "The size of char: " << sizeof(char) << std::endl;
	std::cout << "The size of short: " << sizeof(short) << std::endl;
	std::cout << "The size of int: " << sizeof(int) << std::endl;
	std::cout << "The size of long: " << sizeof(long) << std::endl;
	std::cout << "The size of float: " << sizeof(float) << std::endl;
	std::cout << "The size of double: " << sizeof(double) << std::endl;
	std::cout << "The size of int*: " << sizeof(int*) << std::endl;
	std::cout << "The size of double*: " << sizeof(double*) << std::endl << std::endl;
	
	//2
	
	Numeric_lib::Matrix<int> a (10);
	Numeric_lib::Matrix<int> b (100);
	Numeric_lib::Matrix<double> c (10);
	Numeric_lib::Matrix<int, 2> d (10, 10);
	Numeric_lib::Matrix<int, 3> e (10, 10, 10);
	
	std::cout <<"The size of 'a' matrix: "<< sizeof(a) << std::endl;
	std::cout <<"The size of 'b' matrix: "<< sizeof(b) << std::endl;
	std::cout <<"The size of 'c' matrix: "<< sizeof(c) << std::endl;
	std::cout <<"The size of 'd' matrix: "<< sizeof(d) << std::endl;
	std::cout <<"The size of 'e' matrix: "<< sizeof(e) << std::endl << std::endl;
	
	//3
	
	std::cout << "The number of elements of the 'a' matrix: " << a.size() << std::endl;
	std::cout << "The number of elements of the 'b' matrix: " << b.size() << std::endl;
	std::cout << "The number of elements of the 'c' matrix: " << c.size() << std::endl;
	std::cout << "The number of elements of the 'd' matrix: " << d.size() << std::endl;
	std::cout << "The number of elements of the 'e' matrix: " << e.size() << std::endl;
	
	std::cout << std::endl;
	
	//4
	
	std::cout << "Enter some integers" << std::endl;
	std::vector<int> v;
	int in;
	
	while(std::cin >> in)
		v.push_back(in);
	std::cout << std::endl;
	
	std::cout << "The sqrt of the numbers" << std::endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0)
			std::cout << v[i] << '\t' << "No square root" << std::endl;
		else
			std::cout << v[i] << '\t' << sqrt(v[i]) << std::endl;
	}
	
	//5
	
	Numeric_lib::Matrix <double> mat(10);
	float value;
	for(int i = 0; i < mat.size(); i++)
	{
		value = 0;
		std::cin >> value;
		mat[i] = value;
	}
	
	std::cout << mat << std::endl;
	
	//6
	
	int m; int n;
	
	std::cout << "Enter the values of m and n: ";
	std::cin >> m >> n;
	std::cout << std::endl; 
	
	Numeric_lib::Matrix<int, 2> mat2(m,n);
	
	for(int i = 0; i < mat2.dim1(); i++)
	{
		for(int j = 0; j < mat2.dim2(); j++)
			mat2(i, j) = (i+1) * (j+2);
	}
	std::cout << mat2 << std::endl;
	
	//7
	
	std::cout << "Enter 10 complex values" << std::endl;
	
	Numeric_lib::Matrix <std::complex<double>> mat3 (10);
	for(int i = 0; i < mat3.size(); i++)
		std::cin >> mat3[i];
	
	std::complex<double> sum = 0;
	
	for(int i = 0; i < mat3.size(); i++)
		sum += mat3[i];
	std::cout << "The sum of the complex values: " << sum << std::endl;
	
	//8
	
	std::cout << "Enter 6 values" << std::endl;
	
	Numeric_lib::Matrix<int, 2> mat4(2, 3);
	
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
			std::cin >> mat4(i, j);
	}
	
	std::cout << mat4;
}
