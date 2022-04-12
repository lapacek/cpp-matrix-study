# cpp-matrix-study

The matrix data structure design &amp; implementation study

## warning

This is the naive implementation, therefore this code should not be used in production environment. There is no warranty.

## motivation

Study of a basics of matrix data structure design using a c++11 metaprogramming techniques.

## build

```bash
$ clang++ -Wall --std=c++11 -c Matrix.hpp main.cpp
$ clang++ -Wall --std=c++11 -o matrix *.o
```

## usage

```bash
$ ./matrix <source_file> <target_file>
```

### arguments

The `<source_file>` represents file that contains the configuration of matrix. It should contains two integers values separated by space.

* first integer number means a count of matrix rows
* second integer value means a count of matrix columns

The `<output_file>` represents file where result matrix will be saved.

### output

Program will generate the matrix of random numbers with dimensions passed in from `<source_file>` and also will print prime numbers form that matrix.
The result will be sent to `STDOUT` and into the `<output_file>`.

Just for fun.
