#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <random>
#include <vector>

namespace matrix {

constexpr int Dynamic = -1;

class MatrixBase
{

protected:
	unsigned int m_rows;
	unsigned int m_cols;
};

template <
        typename T,
        int ROWS,
        int COLS
        >
class Matrix : protected MatrixBase
{

public:
	using ColsPolicy = typename std::enable_if<(COLS>0)>::type;
	using RowsPolicy = typename std::enable_if<(ROWS>0)>::type;
	using type = T;

public:
	Matrix ()
	{
		m_rows = ROWS;
		m_cols = COLS;
	}
};

template <typename T>
class Matrix<T, Dynamic, Dynamic> : protected MatrixBase
{

public:
	using type   = T;
	using data_t = std::vector<Matrix::type>;

public:

	explicit Matrix (
	         unsigned int m,
	         unsigned int n
	         )
	{
		     m_data.reset(new data_t(m*n, 0));
	}

	// TODO: (Refactoring)
	// Exclude this method from the Matrix class template.
	inline void generate(
	        T min,
	        T max
	        )
	{
		std::random_device rd;
		std::default_random_engine gen;
		// TODO: (Refactoring)
		// Remove dependecy on integer type within method exclusion
		std::uniform_int_distribution<> dist{min, max};
		gen.seed(rd());

		std::generate(
		            m_data->begin(),
		            m_data->end(),
		            [&dist, &gen]() { return dist(gen); }
		            );
	}

	inline void set (
	        unsigned short int i,
	        unsigned short int j,
	        Matrix::type param
	        )
	{ ; }

	inline void dump (
	        std::ostream & stream,
	        const std::function<bool(T)> & pred = nullptr
	        )
	{
        	if (pred)
		{
			std::copy_if(m_data->cbegin(), m_data->cend(), std::ostream_iterator<T>(stream, " "), pred);

			return;
        	}

		std::copy(m_data->begin(), m_data->end(), std::ostream_iterator<T>(stream, " "));
	}

protected:
	std::unique_ptr<data_t>         m_data;

	int				 m_max;
	int                              m_min;
};


} // namespaces

#endif // MATRIX_HPP
