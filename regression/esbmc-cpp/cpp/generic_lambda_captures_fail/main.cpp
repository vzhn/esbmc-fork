#include <cassert>

// A generic lambda's call operator is a template; its specialization must
// see the lambda's captures (`this` and a variable by reference).
struct S
{
  int x = 0;
  void f()
  {
    int y = 2;
    [this, &y](auto a) {
      x = a;
      y += a;
    }(1);
    assert(y == 3);
  }
};

int main()
{
  S s;
  s.f();
  assert(s.x == 2);
  return 0;
}
