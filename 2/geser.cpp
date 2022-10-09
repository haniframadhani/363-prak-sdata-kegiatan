#include <iostream>
#include <fstream>
#define MAKS 5

class Array1D
{
  friend std::ostream &operator<<(std::ostream &, const Array1D &);
  friend std::istream &operator>>(std::istream &, Array1D &);

public:
  Array1D();
  void cetak();
  void geserKiri();
  void geserKanan();

private:
  char A[MAKS];
};

Array1D::Array1D()
{
  for (int i = 0; i < MAKS; i++)
  {
    A[i] = 'O';
  }
}

void Array1D::cetak()
{
  for (int i = 0; i < MAKS; i++)
  {
    std::cout << A[i] << " ";
  }
}

std::ostream &operator<<(std::ostream &out, const Array1D &x)
{
  for (int i = 0; i < MAKS; i++)
  {
    std::cout << x.A[i] << " ";
  }
  return out;
}

std::istream &operator>>(std::istream &in, Array1D &x)
{
  int posisi;
  std::cout << "mengisikan array pada posisi : ";
  std::cin >> posisi;
  if (posisi > 0 && posisi < MAKS)
  {
    std::cout << "masukkan nilai : ";
    in >> x.A[posisi - 1];
  }
  else
  {
    std::cout << "anda memasukkan posisi diluar range" << std::endl;
  }
  return in;
}

void Array1D::geserKanan()
{
  int n = MAKS;
  int temp = A[n - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    A[i + 1] = A[i];
  }
  A[0] = temp;
}

void Array1D::geserKiri()
{
  int n = MAKS;
  int temp = A[0];
  for (int i = 0; i < n; i++)
  {
    A[i] = A[i + 1];
  }
  A[n - 1] = temp;
}

int main()
{
  Array1D x;
  std::cout << "Array masih kosong : " << x << std::endl;
  std::cin >> x;
  std::cout << "Isi array saat ini : " << x << std::endl;
  x.geserKiri();
  std::cout << "Isi array setelah digeser ke kiri : " << x << std::endl;
  x.geserKanan();
  std::cout << "Isi array setelah digeser ke kanan : " << x << std::endl;

  return 0;
}