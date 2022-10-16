#include <iostream>
#include "Array1D.h"
int main()
{
  try
  {
    Array1D<int> X(10), Y, Z;
    for (int i = 0; i < 10; i++)
    {
      X[i] = i;
    }
    std::cout << "X[3] = " << X[3] << std::endl;
    std::cout << "X is " << X << std::endl;
    Y = X;
    std::cout << "Y is " << Y << std::endl;
    X += 2;
    std::cout << "X incremented by 2 is " << X << std::endl;
    Z = (Y + X) * Y;
    std::cout << "(Y + X) * Y is " << Z << std::endl;
    std::cout << "-(Y + X) * Y is " << -Z << std::endl;
  }
  catch (...)
  {
    std::cerr << "An execption has occurred" << std::endl;
  }
  return 0;
}

