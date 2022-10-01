#include <iostream>

void cari(int x, int n)
{
  static int i;
  if (n == 0)
  {
    std::cout << "bilangan tidak ditemukan" << std::endl;
  }
  else if (x == n)
  {
    std::cout << "bilangan ditemukan setelah perulangan ke-" << i << std::endl;
  }
  else
  {
    i++;
    cari(x, n - 1);
  }
}

int main()
{
  cari(14, 9);
}