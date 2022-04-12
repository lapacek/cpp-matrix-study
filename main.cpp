#include <iostream>
#include <fstream>

#include "Matrix.hpp"

using matrix::Matrix;
using matrix::Dynamic;

int main(int argc, char *argv[])
{
    if (argc != 3)
	{
		std::cout << "error: any argument is not passed." << std::endl;
		return EXIT_FAILURE;
	}

    std::string inputFileName(argv[1]);
	std::ifstream source;

    source.open(inputFileName);

	if (! source.is_open())
	{
        std::cout << "error: source file is not opened." << std::endl;
		return EXIT_FAILURE;
	}

    std::string outputFileName(argv[2]);
    std::ofstream log;

    log.open(outputFileName);

    if (! log.is_open())
    {
        std::cout << "error: log file is not opened." << std::endl;
        return EXIT_FAILURE;
	}

	std::string m;
	std::string n;

	std::getline(source, m, ' ');
	std::getline(source, n);

	source.close();

	std::string::size_type sz;
	int rowsCount;
	int columnsCount;

	try
	{
		rowsCount = std::stoi(m, &sz);
		columnsCount = std::stoi(n, &sz);
	}
	catch ( ... )
	{
		std::cout << "error: parsing: string to int conversion failed." << std::endl;
		return EXIT_FAILURE;
	}

	Matrix<int, Dynamic, Dynamic> matrix(rowsCount, columnsCount);
	matrix.generate(0, 5000);

	matrix.dump(std::cout);
	matrix.dump(log);

	std::cout << std::endl << std::endl << "Primes:" << std::endl;
	log << std::endl << std::endl << "Primes:" << std::endl;

	auto isPrime = [](int n)
	{
		if (n <= 1) return false;
		if (n % 2 == 0 && n > 2) return false;
		for(int i = 3; i < n / 2; i+= 2)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	};

	matrix.dump(std::cout, isPrime);
	matrix.dump(log, isPrime);

	// matrix::Matrix<int, -3, 2> mat2;		// disallowed
	// using vec_3 = matrix::Matrix<int, 3, 1>;	// allowed

	return EXIT_SUCCESS;
}
