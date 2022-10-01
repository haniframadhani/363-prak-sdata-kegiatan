#include <iostream>

float pangkat(float x, float n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n == 1)
  {
    return x;
  }
  else if (int(n) % 2 == 1)
  {
    std::cout << "masuk bagian ganjil" << std::endl;
    return pangkat(x, n - 1) * x;
  }
  else
  {
    std::cout << "masuk bagian genap" << std::endl;
    return pangkat(x * x, n / 2);
  }
}

int main()
{
  std::cout << "2 pangkat 5" << std::endl;
  pangkat(2, 5);
  std::cout << "2 pangkat 6" << std::endl;
  pangkat(2, 6);
  return 0;
}