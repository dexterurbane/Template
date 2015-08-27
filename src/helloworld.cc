#include <Template.h>

#include <iostream>

int main()
{
   std::cout << "Hello, world." << std::endl;
   Foo foo;
   foo.foo();
#ifdef WITH_FEATURE
   Bar bar;
   bar.bar();
#endif
}
