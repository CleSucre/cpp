#include <iostream>

int	main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  for (int i = 1; argv[i]; i++)
  {
    for (int j = 0; argv[i][j]; j++)
      std::cout << (char)std::toupper(argv[i][j]);
    if (i < argc - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
  return (0);
}
