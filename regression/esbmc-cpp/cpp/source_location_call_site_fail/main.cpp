#include <cassert>
#include <cstring>
#include <source_location>

// The defaults of std::source_location::current() (__builtin_LINE() etc.)
// evaluate at the call, not where the operational model writes them.
void check(std::source_location loc = std::source_location::current())
{
  assert(loc.line() == 15);
  assert(std::strcmp(loc.function_name(), "main") == 0);
}

int main()
{
  check();
  auto loc = std::source_location::current();
  assert(loc.line() != 16);
  return 0;
}
