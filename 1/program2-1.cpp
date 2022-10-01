#include <iostream>

void tampil(int n)
{
  static int i = 0;
  if (n <= 0)
    return;
  std::cout << "pemanggilan ke-" << ++i << std::endl;
  tampil(n - 1);
}
int main()
{
  int n = 3;
  tampil(n);
  // system("PAUSE");
  // return EXIT_SUCCESS;
}