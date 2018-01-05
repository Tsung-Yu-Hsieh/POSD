$ cat Shell.cc
#include <iostream>
int main(int argc, char **argv)
{
  std::cout << "Hello, World!!\n"
            << argc << "\n" << argv[1] << " " << argv[2]
            << std::endl;
  return 0;
}
