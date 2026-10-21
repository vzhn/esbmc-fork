#include <cassert>
#include <cstring>

// __builtin_source_location() (what libstdc++'s std::source_location::current()
// uses) is the address of an unnamed constant holding the call site, which no
// declaration introduces.
namespace std
{
struct source_location
{
  struct __impl
  {
    const char *_M_file_name;
    const char *_M_function_name;
    unsigned _M_line;
    unsigned _M_column;
  };
};
} // namespace std

int main()
{
  const std::source_location::__impl *loc = __builtin_source_location();
  assert(loc->_M_line != 23);
  assert(std::strcmp(loc->_M_function_name, "int main()") == 0);
  return 0;
}
