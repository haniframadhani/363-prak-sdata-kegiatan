#include <iostream>
#include <fstream>
#include <typeinfo>

class Bilangan
{
  friend std::ostream &operator<<(std::ostream &, const Bilangan &);
  friend std::istream &operator>>(std::istream &, Bilangan &);

public:
  Bilangan(int a0 = 0, float b0 = 0.0) : a(a0), b(b0) {}
  void banding_int(const Bilangan &, const Bilangan &);
  Bilangan &operator=(const Bilangan &);
  Bilangan operator+(const Bilangan &) const;
  Bilangan operator-() const;

private:
  int a;
  float b;
};

std::ostream &operator<<(std::ostream &out, const Bilangan &x)
{
  out << "bagian integer: " << x.a << std::endl;
  out << "bagian float: " << x.b << std::endl;
  return out;
}

void Bilangan::banding_int(const Bilangan &x, const Bilangan &y)
{
  (x.a > y.a) ? std::cout << x.a << "::x lebih besar dari " << y.a << "::y" : std::cout << x.a << "::x lebih kecil dari " << y.a << "::y";
}

Bilangan &Bilangan::operator=(const Bilangan &x)
{
  a = x.a;
  b = x.b;
  return *this;
}

std::istream &operator>>(std::istream &in, Bilangan &x)
{
  std::cout << "\nMasukkan bagian integer: ";
  in >> x.a;
  std::cout << "Masukkan bagian float: ";
  in >> x.b;
  return in;
}

Bilangan Bilangan::operator+(const Bilangan &x) const
{
  Bilangan cc;
  cc.a = a + x.a;
  cc.b = b + x.b;
  return cc;
}

Bilangan Bilangan::operator-() const
{
  Bilangan x;
  x.a = -a;
  x.b = -b;
  return x;
}

int main()
{
  Bilangan s, t(2, 3.14), d;
  std::cout << "Nilai awal s\n"
            << s;
  std::cout << "Nilai awal t dari deklarasi\n"
            << t;
  s = t;
  std::cout << "Setelah s di-assign t\n";
  std::cout << "Nilai s\n"
            << s;
  std::cout << "Masukkan nilai-nilai objek d: ";
  std::cin >> d;
  std::cout << "Setelah d + t => \n"
            << d + t;
  std::cout << "Nilai d dinegatifkan\n"
            << -d;
}